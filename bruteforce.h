
void check(char* guess, char* hash, char* salt);

void brutestart(int length, char* hash, char* salt);

void alphabetbrute(char* password,int index, int length, char* hash, char* salt);

int dictionarybrute(char* hash, char* salt);
