#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void matrixRead(int dimen, int matrix[][dimen]){
  int i, j;
  for(i = 0; i < dimen; i++){
    for(j = 0; j < dimen; j++){
      scanf("%d", &matrix[i][j]);
    }
  }
}

void matrixPrint(int dimen, int matrix[][dimen]){
  int i, j;
  for(i = 0; i < dimen; i++){
    for(j = 0; j < dimen; j++){
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void matrixFlip(int dimen, int a[][dimen],  int b[][dimen]){
  int i, j, k;
  for(i = 0; i < dimen; i++){
    for(j = 0, k = dimen - 1 ; j < dimen - 1, k >= 0; j++, k--){
      b[i][k] = a[i][j];
    }
  }
}
  

int matrixSumDiagonals(int dimen, int matrix[][dimen]){
  int diagSum1 = 0;
  int diagSum2 = 0;

  /* Calculate the sum of the first diagonal */
  int i, j;
  for(i = 0; i < dimen; i++){
    for(j = 0; j < dimen; j++){
      if(i == j){
	diagSum1 += matrix[i][j];
      }
    }
  }

  return diagSum1;
}
  

int main(){
  int n;
  scanf("%d", &n);

  int a[n][n];
  int b[n][n];
  
  matrixRead(n, a);


  matrixFlip(n, a, b);


  int sum1, sum2;
  sum1 = matrixSumDiagonals(n, a);
  sum2 = matrixSumDiagonals(n, b);
  /*
  printf("Main diagonal: : %d\n", sum1);
  printf("Opposite diagonal: : %d\n", sum2);
  */
  printf("%d\n", abs(sum1 - sum2));
  return 0;
}
  
  
