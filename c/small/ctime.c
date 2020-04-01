#include <time.h>
#include <stdio.h>

int main()
{
  time_t timer, t0, t1;

  time(&timer);
  time(&t0);

  time(&t1);

  printf("%d\n", difftime(t0, timer ));
  
  printf("%d\n", timer);

  char buf[100];
  struct tm tstruct;
  
  strftime(buf,  sizeof buf, "%A, %x", localtime(&timer));
  printf("%s\n", buf);
  return 0;
}
