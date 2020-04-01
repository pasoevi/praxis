#include <stdio.h>

char* rstrip(char*);

int main(int argc, char *argv[])
{
  FILE *dosier;
  int state;
  char *filename, *stripped;

  int bytes_read, nbytes = 100;

  filename = (char *) malloc(nbytes + 1);
  getline(&filename, &nbytes, stdin);
  stripped = rstrip(filename);
  puts(filename);
  dosier = fopen(stripped, "w");
  fputs("Il faut cultiver notre jardin\n", dosier);
  state = fflush(dosier);
  if (state != 0)
    puts("IO Error");
  fclose(dosier);
  return 0;
}

char* rstrip(char str[])
{
  char stripped[strlen(str)];
  int i;
  for(i = 0; i < strlen(str); ++i)
    if (str[i] == '\n')
      break;
    else
      stripped[i] = str[i];
  return stripped;
}
