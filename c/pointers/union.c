#include <stdio.h>

int main(void){
  typedef union _conversion{
    float fNum;
    unsigned int uiNum;
  } Conversion;

  int isPositive1(float number){
    Conversion convesion = {.fNum = number};
    return (convesion.uiNum & 0x8000000) == 0;
  }

  float num = -9;
  float num2 = 10;

  printf("%d - %d\n%d - %d\n", num, isPositive1(num), num2, isPositive1(num2));

  return 0;
}
