#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>
#include "bruteforce.h"

const char passchars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+\"#&/()=?!@|[]{}";

const int charsSize = (sizeof(passchars) -1);
//const int charsSize = (26); //test with only lowercase letters

void check(char* guess, char* hash, char* salt){

	if(!strcmp(hash, crypt(guess, salt))){
		printf("Password found! \nPassword: %s \n", guess);
		free(guess);
		exit(0);
	}
}

void alphabetbrute(char* password, int index, int length, char* hash, char* salt){

	for(int i = 0; i<charsSize; i++){
	
		password[index] = passchars[i];
			
		if(index == length - 1){ 
		check(password, hash, salt);
		//printf("Password: %s \n", password);
		}
		else alphabetbrute(password, index+1, length, hash, salt);
	}
}

void brutestart(int length, char* hash, char* salt){

	char* buffer = calloc(length +1 ,sizeof(char));
	
	for(int i = 1; i <= length; i++){
		memset(buffer, 0, length+1);
		alphabetbrute(buffer, 0, i, hash, salt);
	}
	
	free(buffer);
}
