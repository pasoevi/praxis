/* */

#include <stdio.h>

#define len(x) (sizeof(x) / sizeof(type(x)))

int main(int argc, char *argv[]){
  int a[11];

  int len = len(a);
  printf("%d\n", len);
  return 0;
}
