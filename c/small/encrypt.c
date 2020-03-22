#include <stdio.h>

int main()
{
  int c; 

  while(c = getc(stdin))
    putc(c ^ 31, stdout);
  return 0;
}
