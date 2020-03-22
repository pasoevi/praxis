#include <stdio.h>
/* print the longest line from input 

   Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.
   
*/
#define MAXLINE 200
#define THRESHHOLD 80

int readline(char s[], int len);
void copy(char from[], char to[]);

int main(int argc, char *argv[]){
  int len; /* current and max line lengths */
  char line[MAXLINE]; /* current line */
  
  while((len = readline(line, MAXLINE)) > 0)
    if(len > THRESHHOLD)
      printf("%s", line);

  return 0;
}

/* read a line into s. return length */
int readline(char s[], int lim){
  int c, i, j;
  j = 0;
  for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    if(i < lim - 2){
      s[j] = c;
      ++j;
    }
  if(c == '\n'){
    s[j] = c;
    ++j;
    ++i;
  }
  s[j] = '\0';
  return i;
}

/* copy from 'from' to 'to' assuming it's big enough */
void copy(char from[], char to[]){
  int i = 0;
  while((to[i] = from[i]) != '\0')
    ++i;
}
