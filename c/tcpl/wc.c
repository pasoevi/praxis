/* Count characters, words and lines in input */

#include <stdio.h>

#define OUT 0
#define IN 1

int main(int argc, char *argv[]){
  int c, nc, nw, nl, state;

  nc = nw = nl = 0;
  state = OUT;
  
  while((c = getchar()) != EOF){
    ++nc;
    if(c == '\n')
	++nl;
    if(c == ' ' || c == '\t' || c == '\n')
      state = OUT;
    else if(state == OUT){
      state = IN;
      nw++;
    }
  }
  printf("\t%d\t%d\t%d\n", nl, nw, nc);
  return 0;
}
