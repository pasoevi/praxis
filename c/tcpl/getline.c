#include <stdio.h>
#include "getline.h"

/* read a line into s. return length */
int readline(char s[], int len){
  int c, i;
  for(i = 0; i < len-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if(c == '\n'){
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}
