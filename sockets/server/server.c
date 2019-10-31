#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h> //cpu to network api
#include <pthread.h>

int main(int argc, char*argv[])
{
	int sock = socket(AF_INET /*ipv4 address*/, SOCK_STREAM /*UDP*/, 0); //we now have a socket
	struct sockaddr_in my_addr; //struct for socket creation
	my_addr.sin_family = AF_INET; //ipv4 of address
	my_addr.sin_port = htons(9999); //port: int to network representation of integer

	printf("%d %d\n", 9999, htons(9999)); //print port 9999 & network int of 9999

	my_addr.sin_addr.s_addr = INADDR_ANY; //addresses allowed to connect

	//error checking
	if(sock == -1){
		printf("Error creating socket\n");
		exit(1); //kill program
	}

	//binding socket to a port
	int success = bind(sock, (struct sockaddr*)&my_addr, sizeof(struct sockaddr_in));
	if(success == -1){
		printf("Error binding socket\n");
		close(sock); //ALWAYS close socket from now on if something goes wrong
		exit(1);
	}

	success = listen(sock, 10); //allows 10 backlogged connections

	if(success == -1){
		printf("Iam deaf, cannot listen\n");
		close(sock);
		exit(1);
	}

//      write(sock, (void*)mesg, strlen(mesg)+1);
//      printf("Message sent!\n");
        pthread_t r, w;
        void * result;
        pthread_create(&r, NULL, readthr, NULL);
        pthread_create(&w, NULL, writethr, NULL);
        pthread_join(r, &result);
        pthread_join(w, &result);
        close(sock);

        return 0;

	int client = accept(sock, NULL, NULL); //blocking function, can't continue until we get a connection
	char data[256];
	read(client, data, 256); //read max of 256 characters
	printf("Server got: %s", data);
	close(client);
	close(sock);
	return 0;
}

