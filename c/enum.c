#include <stdio.h>

int main(int argc, char* argv[]){
	enum conditions{
		DEBUG, RELEASE};
	int d = DEBUG;

	if(d == DEBUG){
		printf("DEBUG\n");
		}

	return 0;

	}
