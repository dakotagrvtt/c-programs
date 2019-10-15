#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("Original Process: %d, Parent PID: %d\n", getpid(), getppid());
	int cpid = fork(); //create child pid
	if (cpid > 0){
		printf("Parent! Child: %d\n", cpid);
	}

	else{
		printf("I am the child! My PID: %d,  Parent PID: %d\n", getpid(), getppid());
	}

	return 0;
}
