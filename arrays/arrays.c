#include <stdio.h>
#include <stdlib.h>	//include the standard library to use malloc

int main(){
	int my_array[4]; //generally, make array size a constant and not 'x' or 'a'...
	my_array[0] = 5; //place ints at these indexes
	my_array[1] = -1;

	printf("%d %d\n", my_array[0], 	my_array[1]);
	printf("%d\n", my_array[2]); //print at index 2 for memory

	int * dyn_arr;	//initialize dynamic array
	dyn_arr = (int *)malloc(5 * sizeof(int)); //asking for space for 5 integers in memory
	//malloc returns a pointers; malloc allocates block bytes of memory
	//casting malloc to int is prefferable
/*	for (int i=0; i<5; i++)
		printf("%d\n", dyn_arr[i]);*/
	free(dyn_arr);	//frees memory

	dyn_arr = (int *)calloc(10, sizeof(int)); //ask to make an array with size of 10
	//calloc guarantees to zero out memory

	realloc(dyn_arr, 20 * sizeof(int));	//reallocates memory; changes size of memory if needed

	free(dyn_arr);	//frees memory


	return 0;
}
