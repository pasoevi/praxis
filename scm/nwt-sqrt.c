/* computer square root of n */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define closeenough(guess, x) (abs(x - square(guess)) < 0.0001)

#define improve(guess, x) (average(guess, (x/guess)))


double square(double x);
int average(int x, int y);

double nwt_sqrt(double guess, int x);

int main(int argc, char **argv)
{
  unsigned int nbytes = 40;
  char *input = (char *) malloc(nbytes + 1);
  int x;
  getline(&input, &nbytes, stdin);
  sscanf(input, "%d", &x);
  double sqrtx = nwt_sqrt(1, x);

  printf("Square root of %d = %f\n", x,  sqrtx);
  return 0;
}


double square(double x)
{
  return (x * x);
}

int average(int x, int y)
{
  return (x + y) / 2;
}


double nwt_sqrt(double guess, int x)
{
  if(closeenough(guess, x))
     return guess;
  else
    return nwt_sqrt(improve(guess, x), x);
}
