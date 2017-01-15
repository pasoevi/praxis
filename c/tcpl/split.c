/* print input one word per line */

#include <stdio.h>

#define OUT 0
#define IN 1

int main(int argc, char *argv[]){
  int c, state;
  state = IN;
  while((c = getchar()) != EOF){
    if(c == ' ' || c == '\t' || c == '\n')
      state = OUT;
    else if(state == OUT){
      state = IN;
      putchar('\n');
    }
    putchar(c);
  }
  
  return 0;
}
