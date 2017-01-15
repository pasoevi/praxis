/* Copy input to output, replacing each tab by \t, each
   backspace by \b, and each backslash by \\. 
   more blanks by a single blank.
*/

#include <stdio.h>

int main(int argc, char *argv[]){
  int c;

  while((c = getchar()) != EOF){
    switch(c){
    case '\t':
      printf("\\t");
      break;
    case '\b':
      printf("\\b");
      break;
    case '\\':
      printf("\\\\");
      break;
    case '\n':
      printf("\\n");
      break;
    default:
      putchar(c);
    }
  }
  return 0;
}

    
    
