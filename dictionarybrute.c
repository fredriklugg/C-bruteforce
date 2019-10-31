#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>
#include "bruteforce.h"

int dictionarybrute(char* hash, char* salt){

	FILE *fp;
	fp = fopen("./dictionary.txt", "r");
	if(fp == NULL){
		printf("Could not open dictionary!\n");
		return -1;
	}
	
	char line[32];
	
	while(fgets(line, 31, fp) != NULL){
		line[strlen(line)-1] = '\0';
		if(!strcmp(hash, crypt(line, salt))){
			printf("Password found: %s \n",line);
			fclose(fp);
			return 0;
		}
	}	
	fclose(fp);
	return 1;
}
