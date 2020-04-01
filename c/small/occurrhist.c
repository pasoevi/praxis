/* Exercise 1-14. Write a program to print a histogram of the
   frequencies of different characters in its input. */

#include <stdio.h>
#define NUM_OF_CHARS 128

int main()
{
  int c, i;
  int chars[NUM_OF_CHARS];

  for (i = 0; i < NUM_OF_CHARS; ++i)
    chars[i] = 0;

  while ((c = getchar()) != EOF)
    if (c >= 'A' && c <= 'z')
      ++chars[c-'0'];

  for (i = 'A'; i < 'Z'; ++i)
    if (0 != chars[i-'0'])
      printf("%c %d\n", i, chars[i-'0']);

  return 0;
}
