#include <stdio.h>

/* count characters in input. 1st version. */

int main(int argc, char *argv[]){
  long nc, nl, nb;
  nl = nc = nb = 0;
  
  int c;
  while((c = getchar()) != EOF){
    /* count lines */
    if(c == '\n'){
      nl++;
      nb++;
    }
    if(c == ' ' || c == '\t'){
      nb++;
    }

    /* count ANY character */
    ++nc;
  }
  printf("%ld %ld %ld\n", nc, nl, nb);
  return 0;
}

