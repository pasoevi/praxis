#include <stdio.h>

int average(const int nums[], const int size){
  int i, sum = 0;

  if(nums != NULL && size > 0){
    for(i = 0; i < size; i++){
      sum+=nums[i];
    }
  }

  return sum / size;
}

int main(void){
  int a[] = {10, 98, 2, 11};
  size_t len = sizeof(a) / sizeof(int);
  printf("Average = %d\n", average(a, len));

  return 0;

}

  
