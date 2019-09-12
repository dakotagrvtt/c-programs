#include <stdio.h>

void swap(int *x, int *y);

int main(){
	int x=5;
	int a = 10;
	int b = 15;	//pointers are 1 clock cycle slower to access
	int * ptr = &x;	//* is the dereference pointer
//	int ** ptrptr = &ptr;

	printf("%d\n", x);
	printf("%p\n", &x);
	printf("%p\n", ptr);
//	printf("%p\n", &ptr);
//	printf("%p\n", ptrptr);
	printf("%d\n", *ptr); //exactly THE value at that address
	*ptr = 10;
	printf("%d\n", x);

	//simple swap funtion using addresses
	printf("%d %d\n", a, b);
	swap(&a, &b);
	printf("%d %d\n", a, b);
	printf("%d\n", *((int*)x));	//find what is in address 5

	return 0;
}

void swap(int *x, int *y){	//only passes in addresses, not the numbers
	int temp = *x;
	*x = *y;
	*y = temp;
}
