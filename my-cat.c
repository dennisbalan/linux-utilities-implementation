//my-cat takes a command line arguement of file input name(s) and prints the contents of the file
#include <stdio.h>
#include <stdlib.h>
//argc is the number of items on the command line arg, argv is the array where command line arguements are stored as strings
int main (int argc, char **argv){
	//if there is no command line arguement, just exit and return 0
	if(argc < 2){
		return 0;
	}
	//else just print the files and return 0 on success
	else{
		//for loop in case of multiple files, each file gets printed one time
		for(int i = 1; i < argc; i++){
			//filename is the command line arguement
			char *filename = argv[i];
			//open the file and exit with 1 if error occurs
			FILE *fp = fopen(filename, "r");
			if(fp == NULL){
				printf("my-cat:cannot open file\n");
				exit(1);
			}
			//create a buffer string anduse fgets to save the file lines in buffer and print the buffer while fgets can still read the file
			char buffer[255];
			while(fgets(buffer,255,fp) != NULL){
				printf("%s",buffer);
			}
		}
		return 0;
	}
}
