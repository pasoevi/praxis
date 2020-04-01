#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
  int bytes_read;
  size_t nbytes = 100;
  char *my_string;

  my_string = (char *)malloc(nbytes + 1);
  bytes_read = getline(&my_string, &nbytes, stdin);

  if(nbytes == -1)
    {
      puts("Error occured");
      return -1;
    }
  else
    {
      puts("You typed:");
      puts(my_string);
    }
  return 0;
}
