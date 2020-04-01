#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  const time_t biggest = 2147483647;

  printf("The END Comes in %s\n", ctime(&biggest));

  time_t current_time;
  time(&current_time);

  if (current_time == -1) {
    puts("Unable to determine currrent time");
    return -1;
  }

  printf("Current time is %s\n", ctime(&current_time));

  double secs_to_end = difftime(biggest, current_time);
				
  printf ("Number of seconds before the End: %f\n", secs_to_end);
  time_t till_end = secs_to_end * 1000;
  const struct tm *till_end_tm = gmtime(&till_end);
  char buf[100];
  strftime(buf, sizeof buf, "%Y years, %m months, %W weeks, %d days, %H hours, %M minutes\n", till_end_tm);
  printf("%s\n", buf);

  clock_t clk = clock();
  printf("%d\n%f\n", clk);

  return 0;
}
