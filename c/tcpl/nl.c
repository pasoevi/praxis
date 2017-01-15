/* Count lines in input */

#include <stdio.h>

int main(int argc, char *argv[]){
	double nl = 0;

	int c;
	while((c = getchar()) != EOF){
		if(c == '\n'){
			nl++;
		}
	}

	printf("%.0f\n", nl);

	return 0;

}
