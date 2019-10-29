#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void handler(int sig);

int main(){
	signal(SIGINT, handler); //ignores ctrl-c
	signal(SIGTERM, handler); //ignores kill cmd (sig terminate)
	while(1);
	return 0;
	// kill(cpid, SIGINT); //kills a process; mostly used for child after a forking of processes
}

void handler(int sig){
	printf("YOU DIDN'T SAY THE MAGIC WORD!\n");
}
