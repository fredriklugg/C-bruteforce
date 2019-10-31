all:
	gcc -Wall -o cracker cracker.c alphabrute.c dictionarybrute.c -lcrypt
