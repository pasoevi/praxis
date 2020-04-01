#include <string.h>
#include <stdio.h>

char *tmp_name(void);

int main(int argc, char *argv[])
{
  char *filename = tmp_name();
  printf("name: %s\n", filename);

  return 0;
  /* */ 
}

char *tmp_name(void)
{
  char name[30];
  static int sequence = 0;

  ++sequence;

  strcpy(name, "tmp");

  name[3] = sequence + '0';

  name[4] = '\0';

  return name;
}
