#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char *argv[]){
	char *notice_fname = "notice.txt";
	int index, c;

	opterr = 0;
	
	while((c = getopt(argc, argv, "b:")) != -1){
		switch(c){
		case 'b':
			backupflag = 1;

	return 0;
}
