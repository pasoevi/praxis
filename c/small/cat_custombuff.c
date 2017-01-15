#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>


#define BUFFSIZE 4096
char *readline (const char *PROMPT);
int main(void)
{
  
  int n;
  char buf[BUFFSIZE];

  while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
    if(write(STDOUT_FILENO, buf, n) != n)
      perror("Write error.\n");
  if(n < 0)
    {
      perror("Read error.\n");
      exit(1);
    }
  printf("%d\n", getpid());

  
  exit(0);
}
