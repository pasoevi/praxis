#include <stdio.h>

/* Testing default values for the uninitialized variables */

int g1;

int main(int argc, char *argv[]){
  int auto1;
  static int sa;

  printf("Global - \nAuto - %d\nvar - %d\n", g1, auto1, sa);

  return 0;
}
