#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//my-uniq takes a command line input of filename input(s) and prints the file without duplicate adjacent lines to stdout
//Argc and argv signify command line args are enabled in program
int main(int argc, char **argv){
	//for loop for multiple files
	for(int i = 1; i < argc; i++){
		//open file
		FILE *fp = fopen(argv[i],"r");
		//error check file
		if(fp == NULL){
			printf("my-uniq: cannot open file\n");
			exit(1);
		}
		//initalize variables,buffer1 is line 1, buffer 2 is next line to compare
		char *buffer1;
		char *buffer2;
		size_t len1;
		size_t len2;
		//read first line(buffer1) from text and print. Save the line
		if(getline(&buffer1,&len1,fp) != -1){
			printf("%s",buffer1);
		}
		//while file pointer can be read,read a line and compare to previous line. If previous line is 	not similar to the current line, print. Set current to previous and continue to read the fp until NULL
		while(getline(&buffer2,&len2,fp) != -1){
			if(strcmp(buffer1,buffer2) != 0){
				printf("%s",buffer2);
			}
			strcpy(buffer1,buffer2);
		}

	}
}
