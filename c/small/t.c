#include <stdio.h>

int main ()
{
  double a[] = {1.0, 2.0};
  double *p = a;
  double sqr(x) {return (x*x);}
#define sqr(x) x*x

  printf("%f\n", sqr(3.0));

  printf("%d\n", sqr(3));

  printf("%f\n", !sqr(3.0));

  printf("%f\n", sqr(*p++));
  printf("%f\n", (sqr)(3+3));

  return 0;

}
