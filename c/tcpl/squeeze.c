/* Copy input to output, replacing each string of one or 
   more blanks by a single blank.
*/

#include <stdio.h>

#define BLANK 1
#define NON_BLANK 0

int main(int argc, char *argv[]){
  int c, state;

  while((c = getchar()) != EOF){
    if(c == ' '){
      if(state != BLANK){
	putchar(' ');
      }
      state = BLANK;
    }
    else{
      state = NON_BLANK;
      putchar(c);
    }
  }
  return 0;
}

    
    
