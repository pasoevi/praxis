/* print input one word per line */

#include <stdio.h>

#define OUT 0
#define IN 1

int main(int argc, char *argv[]){
  int c, state;
  state = IN;
  while((c = getchar()) != EOF){
    if(c == ' ' || c == '\t') 
      	putchar('\n');
    else 
    	putchar(c);
  }
  
  return 0;
}
