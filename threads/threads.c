#include <stdio.h>
#include <pthread.h>

void * my_thread(void * args);
int main(){
	const int THREADS = 3;

	pthread_t tids[THREADS];
	int label[THREADS];

//OLD	pthread_t tid; //makes unique thread ID
//OLD	int label = 1;

	void * result;
//OLD	printf("%lu\n", tid); //prints useless thread ID

	for(int i=0; i<THREADS; i++) //Makes 3 threads instead of just one
	{
		label[i] = i;
		pthread_create(&tids[i], NULL, my_thread, (void *)&label/*memory address of label*/);
	}

//OLD	printf("%lu\n", tids); //tids's new ID after thread is initialized
	for(int i=0; i<THREADS; i++)
		pthread_join(tids[i], &result); //pauses main to finish my_thread

	printf("All done!\n");
	return 0;
}

void * my_thread(void * args){
	int * intarg=(int *)args;

	for(int i=0; i<10; i++){
		printf("Hello world!%d\n", *intarg);
	}
	pthread_exit(NULL); //tells pthread_join that this function is done and main can continue
}
