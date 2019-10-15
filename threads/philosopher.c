#include <stdio.h>
#include <pthread.h>
#include <unistd.h> //unix library: for usleep()
#include <semaphore.h>

#define PHILS 5 //like const int PHILS; but defines as a macro - PHILS will now always be replaced with 5
pthread_mutex_t chopsticks[PHILS];
const int PAUSE = 100000;
sem_t shared_chops; //initialize semaphore (only need one)

void * phil(void * args);
void * semphil(void * args);

int main(){
	pthread_t tids[PHILS];
	int ids[PHILS];
	void * result;

	//SEMAPHORE
	sem_init(&shared_chops, 0, PHILS/2);
	for (int i=0; i<PHILS; i++){
		ids[i]=i;
		pthread_create(&tids[i], NULL, semphil, &ids[i]); //creates semphil thread
	}


	//MUTEXES
/*	for (int i=0; i<PHILS; i++){
		pthread_mutex_init(&chopsticks[i], NULL);
	}*/
	for (int i=0; i<PHILS; i++){
		ids[i] = i;
		pthread_create(&tids[i], NULL, phil, &ids[i]);
	}
	for (int i=0; i<PHILS; i++){
		pthread_join(tids[i], &result);
	}
/*        for (int i=0; i<PHILS; i++){
		pthread_mutex_destroy(&chopsticks[i]);
	}*/
	sem_destroy(&shared_chops); //destroy semaphor
	return 0;
}

void * phil(void * args){
	int label = *((int *) args);
	printf("Phil &d is awake\n", label);
	//dijkstra
	int c1 = label;
	int c2 = (label + 1) % PHILS;
	if (c2<c1){
		c1 = c2;
		c2 = label;
	}
	for(int i=0; i<5; i++){
		pthread_mutex_lock(&chopsticks[c1]); //lock
                usleep(PAUSE); //pause in ms; SIMULATES DEADLOCK
		pthread_mutex_lock(&chopsticks[c2]); //lock for a second philosopher
                usleep(PAUSE); //pause in ms; SIMULATES DEADLOCK
		printf("Philosopher %d is eating: YUM!\n", label);
		usleep(PAUSE); //pause in ms
		pthread_mutex_unlock(&chopsticks[c1]); //release chopsticks to new philosphers
                pthread_mutex_unlock(&chopsticks[c2]); //release chopsticks to new philosphers
		printf("Phil %d is thinking deep thoughts\n", label);
	}
	pthread_exit(NULL);
}

void * semphil(void * args){
	int label = *((int *) args);
	printf("Phil &d is awake\n", label);
	for(int i=0; i<5; i++){
		sem_wait(&shared_chops);
                printf("Philosopher %d is eating: YUM!\n", label);
                usleep(PAUSE);
		sem_post(&shared_chops);
		printf("Phil %d is thinking deep thoughts\n", label);
        }
        pthread_exit(NULL);
}
