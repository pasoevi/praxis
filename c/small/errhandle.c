#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void)
{
  char *ptr = malloc(200);
  FILE *x;

  if((x = fopen("aoeu", "r")) == NULL)
    fprintf(stderr, "%d %s\n", errno, strerror(errno));
    
  
  if(ptr == NULL){
    puts("malloc failed\n");
    puts(strerror(errno));
  }
  else
    free(ptr);
  exit(EXIT_SUCCESS);
}
