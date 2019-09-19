#include <stdio.h>
#include <stdlib.h> //for malloc()
#include <string.h> //for strlen(), strcpy(), strncpy(), strcat()
			//strncat(), strcmp() - compare, strtok() - tokenize
			//strtok() - returns up to first delimiter
int main(){
	char str[] = "Hello world!";
	printf("%s\n", str);
	printf("%ld\n", strlen(str));

	char * str2 = (char*) malloc(sizeof(char)*(1+strlen(str)));

	//char str2[10]; //only size of 10 when we need 13!
	strcpy(str2, str); //strcpy(destincation, source)
	printf("%s\n", str2);

	printf("Are they equal?\n");
	printf("%d\n", strcmp(str2, str)); //should return 0, meaning true
	printf("%d\n", strcmp("Hello", "World"));//will return -1
	printf("%d\n", strcmp("Hello", "Help")); //will return -1
	printf("%d\n", strcmp("Hello", "hello"));//will return -1

	//printf("%s\n", str);
		//str will be overwritten at some point with a null char
		//only part of str may be printed or none of it
	free(str2); //free str2 memory allocation

	printf("TOKENIZATION\n");
	char sent[] = "In a hole in the ground there lived a hobbit.";
	char * token;
	printf("%s\n", sent);
	token = strtok(sent, " "); // split on space
	printf("%s\n", token); //returns "In"
	while(token){
		printf("%s\n", token);
		token = strtok(NULL, " ");
	} //prints a word per line
	printf("%s\n", sent); //token modifies original string
		//strtok places NULL char at where it left off
		//results in better performance
	return 0;
}
/*
char ** vec;
vec malloc(2* sizeof(char*));
vec[0]=malloc((strlen(..))+1,*sizeof(char));
*/
