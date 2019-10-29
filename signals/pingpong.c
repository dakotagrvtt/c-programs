#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h> //for sleep()

int cpid; //global var for pong()

void ping(int sig);
void pong(int sig);

int main(){
	cpid = fork();
	signal(SIGUSR1, ping);
	signal(SIGUSR2, pong);

	if (cpid == 0){
		//child
	}
	else{
		//parent
		printf("SERVICE!\n");
		kill(cpid, SIGUSR1);
	}

	while(1);
	return 0;
}

void ping(int sig){
	printf("ping\n");
	sleep(1);
	kill(getppid(), SIGUSR2);
}

void pong(int sig){
        printf("pong\n");
        sleep(1);
        kill(cpid, SIGUSR1);
}
