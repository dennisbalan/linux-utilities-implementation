//my-sed takes command line inputs of find_term replace_term file_name(s) and prints the contents of the file_names to stdout with replace_term in filename replaced by find_term
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char **argv){
	//global var for amount of times find 
	int replace_number = 1;
	//if not enough arguements supplied to command, print error message and return 1
	if(argc <= 2){
		printf("my-sed: find_term replace_term [file...]\n");
		exit(1);
	}
	//set the find_term and replace_term variables from argv, first command line arg is findterm, second is replaceterm
	char *find_term = argv[1];
	char *replace_term = argv[2];
	//if command line args are just find_term and replace_term, assume file is stdin. Thus if sustem prints the stdin to stdout with find_term in stdin replaced with replace_term
	if(argc == 3){
		//buffer variables for reading stdin from getline
		char *buffer;
               	size_t len;
		//while you can read file with getline,split string with strtok and find the find_term if it exists and print the replace term instead. Otherwise, just print he split word
                while(getline(&buffer,&len,stdin) != -1){
                	char *string = buffer;
                        char *word = strtok(string," , !");
                        while(word != NULL){
                        	if((strcmp(find_term,word) == 0) && replace_number == 1){
                                        printf("%s",replace_term);
                                        replace_number = 0;
					if(strcmp(replace_term, " ") != 0){
                                        	printf(" ");
					}
                                 }
                                 else{
                                        printf("%s",word);
                                        if(strchr(word,'\n') == NULL){
                                                printf(" ");
					}
                                        word = strtok(NULL," ");
                                }
				word = strtok(NULL," ");
                        }

                }
                return 0;

	}
	//if command line file arguements exist, print them
	else{
		//repeat as many time as you have command line args for files
		for(int i = 3;i < argc;i++){
			//open the files, exit 1 if fail
			FILE *fp = fopen(argv[i],"r");
			if(fp == NULL){
				printf("my-sed:cannot open file\n");
				exit(1);
			}
			//the process is now the same for finding and replacing words in file as was in stdin
			char *buffer;
			size_t len;
			while(getline(&buffer,&len,fp) != -1){
				char *string = buffer;
				char *word = strtok(string," ");
				while(word != NULL){
					if((strcmp(find_term,word) == 0) && replace_number == 1){
						printf("%s",replace_term);
						replace_number = 0;
						if(strcmp(replace_term," ") != 0){
							printf(" ");
						}
					}
					else{
						printf("%s",word);
						if(strchr(word,'\n') == NULL){
							printf(" ");
						}
					}
					word = strtok(NULL," ");
				}
			}

		}
		return 0;
	}
}
