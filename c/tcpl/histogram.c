#include <stdio.h>

/* histogram of the lengths of words in input */

#define MAX_LENGTH 20
#define OUT 0
#define IN 1

int main(int argc, char *argv[]){
  int i, c, len, state;
  int lengths[MAX_LENGTH];

  len = 0;
  state = OUT;
  
  for(i = 0; i < MAX_LENGTH; i++)
    lengths[i] = 0;
   
  while((c = getchar()) != EOF){
    if(c == ' ' || c == '\t' || c == '\n'){
      state = OUT;
      ++lengths[len];
      len = 0;
    }
    else if(state == OUT){
      state = IN;
      ++len;
    }else
      ++len;
  }

  for(i = 1; i < MAX_LENGTH; i++)
    printf("%d --------- %d\n", i, lengths[i]);

  return 0;
}

  
