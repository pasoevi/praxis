#include <stdio.h>

int main()
{
  int c;

  while ((c = getchar()) != EOF)
    {
      if(' ' == c)
	{
	  putchar(c);
	  while ((c = getchar()) == ' ') /* in case c is not a space,
					 at least it will be saved and
					 printed later */
	    ;
	  if (' ' != c)
	    putchar(c); /* here, that is. */

	}
	  else
	    putchar(c);
    }
  return 0;
}
	  
