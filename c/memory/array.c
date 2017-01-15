#include <stdio.h>
#include <stdlib.h>

int add(int, int);

int main(void){
  /* Examine how the arrays of pointers to functions are
     initialised . 
     
     I read somewhere that while initializing the array of pointers to
     functions if the number of elements in the block is less than the
     number of the elements in the array, that value is used to
     initialize the rest of the array. However, the following
     declarations demonstrate that to not be the case at least with
     GCC's default invocation.

  */

  typedef int (*operator)(int, int);
  operator operators[10] = {NULL};
  operator operators1[10] = {};
  int i;
  for(i = 0; i < 10; i++){
    printf("%p\n", operators[i]);
  }

  for(i = 0; i < 10; i++){
    printf("%p\n", operators1[i]);
  }

  /* When an array name is used by itself, the address of the array is
     returned */
  int nums[10] = {0};
  printf("int nums[10] = {0}; = %p\n", nums);
  printf("int nums[10] = {0}; = %p\n", nums+0);

  /* Now we have a pointer to an int and we assign it the address of
     the array. And that pointer is now a pointing to the first
     element of the array and not to the array itself. 
  */
  int *pi = nums;
  

  /* 
     There is a difference when the sizeof operator is applied to the
     array and to the pointer to the same array.
     
     When applied to an array, the sizeof operator will return the
     number of bytes allocated for the array. While, when applied to
     the pointer to the pointer to an array it returns the size of the
     pointer.
  */
  
  int vector[5] = {1, 2, 3, 4, 5};
  int *pvec = vector;

  printf("sizeof(vector) = %d\n", sizeof(vector));
  printf("sizeof(pv) = %d\n", sizeof(pvec));

  /* 
     It is possible to allocate memory in heap using malloc and treat
     that memory as an array. 
  */
  
  int *pv = malloc(sizeof(vector));
  for(i = 0; i < 5; i++){
    pv[i] = i + 1;
  }

  for(i = 0; i < 5; i++){
    printf("pv[i] = %d\n", pv[i]);
  }

  printf("sizeof(pv) = %d\n", sizeof(pv));
  free(pv);
  printf("sizeof(vector) = %d\n", sizeof(vector));
  return 0;
}

int add(int a, int b){
  return a + b;
}
