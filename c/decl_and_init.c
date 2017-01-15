#include <stdio.h>

/* 
This file contains examples to demonstrate the various things to note
   about declaring and initializing variables in C
*/

int a;
int nums[12];
int main(void){
  /* Global and static variables start as zeros even without being
     explicitly initialized as such. */

  /* Automatic variables start as garbage. */
  static int b;
  auto int c; 
  printf("Global a = %d\n", a);
  printf("Static b = %d\n", b);
  printf("Automatic c = %d\n", c);

  printf("Global array nums = {");
  int i;
  size_t nmemb = sizeof(nums) / sizeof(nums[0]);
  for(i = 0; i < nmemb; i++){
    printf("%d", nums[i]);
    if(i != (nmemb -1)){
      putchar(',');
    }else{
      printf("}\n");
    }
  }

  /*
    Automatic arrays that have partial initializer, the remainder is
    initialized to 0, just as for statics.
  */

  int ns[2] = {1};
  printf("Automatic array with partial initializer ns = {%d, %d}\n", ns[0], ns[1]);
    
  return 0;
}


