#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside of it */

int main(int argc, char* argv[])
{
  int c, cn, wn, ln, state;
  
  state = OUT;
  cn = wn = ln = 0;
  
  while ((c = getchar()) != EOF)
    {
      ++cn;
      if ('\n' == c)
	++ln;
      if (' ' == c || '\t' == c || '\n' == c)
	state = OUT;
      else if (state == OUT)
	{
	  state = IN;
	  ++wn;
	}
    }
  printf("%d %d %d\n", cn, wn, ln);
  return 0;
}
