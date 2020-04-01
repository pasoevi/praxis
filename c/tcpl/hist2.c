#include <stdio.h>

/* A historgram of the frequencies of different 
   characters in input */

int main(int argc, char *argv[]){
  int i, c;
  int freq[256];

  for(i = 0; i < 256; i++)
    freq[i] = 0;
   
  while((c = getchar()) != EOF)
    ++freq[c];

  for(i = 0; i < 255; i++)
    printf("%c --------- %d\n", i, freq[i]);
  
  return 0;
}

  
