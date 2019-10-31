#include <stdio.h>
#include "bruteforce.h"

const int max_length = 8;

int main(int argc, char* argv[]){
	
	if(argc != 2) return -1;

	char* hash = argv[1];
		
	char salt[13];
	for(int i=0; i < 12; i++){
		salt[i] = argv[1][i];
	}
	
	printf("Searching for hash: %s \n", hash);
	
	if(dictionarybrute(hash, salt) == 0) return 0;
	else{
	printf("Not found in directory, trying manualy...\n");
	brutestart(max_length, hash, salt);
	}
		
	return 0;
	
}
