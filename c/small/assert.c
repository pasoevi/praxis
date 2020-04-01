#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void say_goodbye(void)
{
  printf("Bye\n");
}
void *p = &say_goodbye;
int main(int argc, char *argv[])
{
  FILE *afile;
  char *csource;
  char *filename = "/home/user/playingwithc/assert.c";
  afile = fopen(filename, "r");

  /* how to assert 
  assert(*argv[1] == 'u');
  assert(1 == 3);
  */
  atexit(p) ;
  printf("%f\n", atof(argv[2]));
  time_t timer = time(NULL);
  printf("%s\n", ctime(&timer));
  printf("%s\n", getenv("SHELL"));
  return 0;
}
