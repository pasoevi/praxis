#include <stdio.h>
/* print the longest line from input

   Exercise 1-16. Revise the main routine of the longest-line program so
   it will correctly print the length of arbitrary long input lines, and
   as much as possible of the text.
*/
#define MAXLINE 79

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
    printf("%d %s", maxlen, longest);
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
