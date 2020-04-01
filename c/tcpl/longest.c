#include <stdio.h>

/* print the longest line from input */

#define MAXLINE 1000

int readline(char s[], int len);
void copy(char from[], char to[]);

int main(int argc, char *argv[]){
  int i, len, maxlen; /* current and max line lengths */
  char line[MAXLINE]; /* current line */
  char longest[MAXLINE]; /* longest line */

  while((len = readline(line, MAXLINE)) > 0){
    if(len > maxlen){
      maxlen = len;
      copy(line, longest);
    }
  }

  if(maxlen > 0) /* there was a line */
    printf("%s", longest);
  return 0;
}

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

/* copy from 'from' to 'to' assuming it's big enough */
void copy(char from[], char to[]){
  int i = 0;
  while((to[i] = from[i]) != '\0')
    ++i;
}
