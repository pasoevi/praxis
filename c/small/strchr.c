#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strchr(char *, char);

int main(int argc, char **argv)
{
  char buf[80];
  char *first_ptr;
  char *last_ptr;

  fgets(buf, sizeof(buf), stdin);
  if(first_ptr = my_strchr(buf, ' '))
    {
      first_ptr++;

      last_ptr = 
    }
  else
    fprintf(stderr, "Error: unexpected input.\n");
      
}

char *my_strchr(char *string_ptr, char find)
{
  while(*string_ptr != find)
    {
      if(*string_ptr == '\n')
	return (NULL);

      string_ptr++;
    }
  return string_ptr;
}


    
