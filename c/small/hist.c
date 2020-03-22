/* Exercise 1-14. Write a program to print a histogram of the
   frequencies of different characters in its input.
*/

#include <stdio.h>

int main()
{
  int c, i;
  int length = 0;
  i = 0;

  while ((c = getchar()) != EOF)
    {
      ++length;

      if (' ' == c || '\t' == c || '\n' == c)
	{
	  printf("\t\t");
	  --length;
	  while(i < length)
	    {
	      putchar('-');
	      ++i;
	    }

	      putchar('\n');
	      length = i = 0;

	}
      if (' ' == c)
	;
      else
	putchar(c);
    }
  return 0;
}

