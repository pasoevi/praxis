#include <stdio.h>

/* count digits, white space, others */

int main()
{
  int c, i, nwhite, nother;
  int ndigits[10];

  c = i = nwhite = nother = 0;
  for (i = 0; i < 10; ++i)
    ndigits[i] = 0;

  while ((c = getchar()) != EOF)
    if (c>= '0' && c<= '9')
      ++ndigits[c-'0']; /* - '0' to get the numerical value */
    else if (' ' == c || '\t' == c || '\n' == c)
      ++nwhite;
    else
      ++nother;
  printf("digits=");
  for (i = 0; i<10; ++i)
    printf(" %d", ndigits[i]);
  printf(", whitespaces = %d, other characters = %d\n", nwhite, nother);
  return 0;
}
