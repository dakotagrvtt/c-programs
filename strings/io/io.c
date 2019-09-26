#include <stdio.h>
#include <stdlib.h>
#include <string.h> //be sure to import string.h

int main(){
	char * inputline = NULL;
	size_t size = 0; //can also be called buffLen or buffSize since it's a buffer
	printf("Enter a sentence: ");
	int nread;
	nread = getline(&inputline, &size, stdin);
	printf("%d characters read\n", nread);
	printf("size is: %ld\n", size);
	printf("Input strng: %s\n", inputline);

	char * tok;
	tok = strtok(inputline, " \n");
	while (tok)
	{
		printf("%s\n", tok);
		tok = strtok(NULL, " \n");
	}
	free(inputline);
	return 0;
}
