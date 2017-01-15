#include <stdio.h>
#include <stdlib.h>


#define MAX_INPUT 2048

#ifdef  _WIN32
#include <string.h>

static char buffer[MAX_INPUT];
/* fake readline function */
char* readline(char *prompt){
	fputs(prombt, stdout);
	fgets(buffer, MAX_INPUT, stdin);
	char *cpy = malloc(strlen(buffer) + 1);
	strpcpy(cpy, buffer);
	cpy[strlen(cpy)-1] = '\0';
	return cpy;
}

/* fake add_history function */
void add_history(char *unused){}

/* otherwise include the readline headers */

#else

#include <readline/readline.h>
#include <readline/history.h>

#endif

/* A static buffer for user input */
static char *input = (char *)NULL;

#define VERSION "0.0.1"
#define PROMPT "> "

void prompt();
/* 
 * Read a string and return a pointer to it. Return NULL on EOF. 
 */
char * getln();

int main(int argc, char argv[]){
	/* Print version and exit information */
	printf("Lisp2k version %s\nPress C-c to exit\n", VERSION);	

	/* REPL runs forever */
	while(1){
		/* Read a line of user input of MAX_INPUT size at most 
		 * if it didn't use readline, it would effectively do
		 * something like this: fgets(input, MAX_INPUT, stdin);
		 */
		getln();

		/* For the moment just echo the input back to the user */
		if(input && *input){
			printf("%s\n", input);
		}else{
			/* EOF, quit. */
			putchar('\n');
			break;
		}
		free(input);
		input = (char *)NULL;
	}
	return 0;
}

void prompt(){
	fputs(PROMPT, stdout);
}

char* getln(){
	/* if the bufer had already been allocated, return 
	 * the memory to the free pool.
	 */
	if(input){
		free(input);
		input = (char *)NULL;
	}

	/* Get a line from the programmer */
	input = readline(PROMPT);

	/* if the line has any text in it, record it in history. */
	if(input && *input){
		add_history(input);
	}
	return input;
}
