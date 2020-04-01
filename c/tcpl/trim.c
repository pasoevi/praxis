#include "getline.h"
/*
  Exercise 1-18. Write a program to remove trailing blanks and tabs from
  each line of input, and to delete entirely blank lines.
*/
#define MAXLINE 200

int trim(char[]);

int main(int argc, char *argv[]){
  char line[MAXLINE]; /* current line */
  while(readline(line, MAXLINE) > 0){
    if(trim(line) > 0)
      printf("%s", line);
  }
  return 0;
}

int trim(char s[]){
  int i = 0;
  while(s[i] != '\n')
    ++i;
  --i;
  while(i >= 0 && (s[i] == ' ' || s[i] == '\t'))
    --i;
  if(i >= 0){
    s[++i] = '\n';
    s[++i] = '\0';
  }
  return i;
}
