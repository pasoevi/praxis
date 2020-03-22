#include <limits.h>
#include <float.h>
#include <stdio.h>

void printIntLims(void){
  printf("int max: %d\n", INT_MAX);
  printf("int min: %d\n", INT_MIN);
  printf("unsigned int max %d\n", UINT_MAX);  
}

void printCharLims(void){
  printf("char bit: %d\n", CHAR_BIT);
  printf("char max: %d\n", CHAR_MAX);
  printf("char min: %d\n", CHAR_MIN);
  printf("signed char max: %d\n", SCHAR_MAX);
  printf("signed char min: %d\n", SCHAR_MIN);
  printf("unsigned char max: %d\n", UCHAR_MAX);
}

void printLongLims(void){
  printf("long min: %d\n", LONG_MIN);
  printf("long max: %d\n", LONG_MAX);
  printf("unsigned long max: %d\n", ULONG_MAX); 
}

void printShortLims(void){
  printf("short max: %d\n", SHRT_MAX);
  printf("short min: %d\n", SHRT_MIN);
  printf("unsigned short max: %d\n", USHRT_MAX);
}

void printFloatLims(void){
  printf("Floating point limits\n");

  printf("Rradix of exponent representation, e.g., 2, 16: %d\n", FLT_RADIX);
  printf("Floating point rounding mode for addition: %d\n", FLT_ROUNDS);
  printf("Decimal digits of precision: %d\n", FLT_DIG);
  printf("Smallest number x such that 1.0 + x != 1.0: %d\n", FLT_EPSILON);
  printf("Number of base FLT_RADIX digits in mantissa: %d\n", FLT_MANT_DIG);
  printf("Maximum floating point number: %f\n", FLT_MAX);
  printf("Maximum n such that FLT_RADIX^n-1 is representable: %d\n", FLT_MAX_EXP);
  printf("Minimum normalized floating-point number: %d\n", FLT_MIN);
  printf("Minimum n such that 10^n is a normalized number: %d\n", FLT_MIN_EXP);
  printf(": %d\n", FLT_RADIX);
  
}

void printDoubleLims(void){
  printf("Floating point limits (double precision) \n");

  printf("Decimal digits of precision: %d\n", DBL_DIG);
  printf("Smallest number x such that 1.0 + x != 1.0: %d\n", DBL_EPSILON);
  printf("Number of base FLT_RADIX digits in mantissa: %d\n", DBL_MANT_DIG);
  printf("Maximum double floating point number: %f\n", DBL_MAX);
  printf("Maximum n such that FLT_RADIX^n-1 is representable: %d\n", DBL_MAX_EXP);
  printf("Minimum normalized double floating-point number: %d\n", DBL_MIN);
  printf("Minimum n such that 10^n is a normalized number: %d\n", DBL_MIN_EXP);
}

int main(void){
  printCharLims();
  printIntLims();
  printLongLims();
  printShortLims();
  printFloatLims();
  printDoubleLims();
  return 0;
}
