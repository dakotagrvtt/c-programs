#include <unistd.h>

int main(int argc, char* argv[]){
	//char * cmd [] = {"ls", "-alh", "..", NULL}; //initialization list; runs 'ls -alh of parent directory"

	printf("%s\n", argv[0]);
	printf("%s\n", argv[1]);

	execvp(argv[1], &argv[1]); //call beginning of array again to avoid recursively calling main()
	return 0;
}
