/* This program writes a random number in a file given as an argument. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  FILE *f;
  f = fopen(argv[1],"w");
  fprintf(f,"%d\n",rand());
  fclose(f);
  return 0;

}
