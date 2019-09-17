#include <stdio.h>
#include <stdlib.h>
#include <string.h> //for strlen()

int main(){
	char str[] = "Hello world!";
	printf("%s\n", str);
	printf("%d\n", strlen(str));

	return 0;
}
/*
char ** vec;
vec malloc(2* sizeof(char*));
cvec[0]=malloc((strlen(..))+1,*sizeof(char));
*/
