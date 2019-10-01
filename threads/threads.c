#include <stdio.h>
#include <pthread.h>

void * my_thread(void * args);
int main(){
	pthread_t tid; //makes unique thread ID
	pthread_create(&tid, NULL, my_thread, NULL);

	return 0;
}

void * my_thread(void * args){
	for(int i=0; i<10; i++){
		printf("Hello world!\n!");
	}
}
