#include <stdio.h>

int main(void){
  int n = 1;
  printf("%d %d\n", n++, n++);
  /* 
     Possible outputs:
     1 2
     2 1
  */
  return 0;
}
