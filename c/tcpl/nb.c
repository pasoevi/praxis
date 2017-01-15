/* Count blanks, tabs and newlines in input */

#include <stdio.h>

int main(int argc, char *argv[]){
	double nb = 0, nt = 0, nl = 0;

	int c;
	while((c = getchar()) != EOF){
		if(c == ' ')
			++nb;
		if(c == '\t')
			++nt;
		if(c == '\n')
			++nl;
		
	}

	printf("%.0f %.0f %.0f\n", nb, nt, nl);

	return 0;

}
