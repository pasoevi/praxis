#include <stdio.h>

int main(int argc, char *argv[]){
  /* Pointers to a constant */
  int i = 9;
  int ci = 10;
  int *pi;
  const int *pci;

  pi = &i;
  pci = &ci;

  /* Constant pointer to non-constant */
  int num = 80;

  int *const cpi = &num;

  /* This should compile */
  *cpi = 89;

  printf("%d, %d\n", num, *cpi);

  return 0;
}
