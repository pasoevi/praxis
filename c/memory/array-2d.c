#include <stdio.h>

int add(int, int);

int main(void){
  int m[10][10];
  int i, j;
  for(i = 0; i < 10; i++){
    for(j = 0; j < 10; j++){
      m[i][j] = i * j + 11;
    }
  }

  for(i = 0; i < 10; i++){
    for(j = 0; j < 10; j++){
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }

  return 0;
}

int add(int a, int b){
  return a + b;
}
