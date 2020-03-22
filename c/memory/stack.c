#include <stdio.h>

int sum(int a[], size_t len){
  int sum = 0;
  printf("%p\n", a);
  printf("%p\n", &len);
  printf("%p\n", &sum);
  return sum;
}
int  main(void){
  int nums[] = {1, 2, 3};

  sum(nums, sizeof(nums) / sizeof(int));
  return 0;
}
  
