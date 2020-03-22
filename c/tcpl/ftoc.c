#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/* print Fahrenheit-Celsius table */

float fahrtoc(float fahr);

int main(int argc, char *argv[]){
  float fahr, celsius;
  fahr = LOWER;
  for(fahr = LOWER; fahr <= UPPER; fahr += STEP){
    celsius = fahrtoc(fahr);
    printf("%3.0f %6.1f\n", fahr, celsius);
  }
  return 0;
}

float fahrtoc(float fahr){
  return (5.0/9.0) * (fahr - 32.0);
}
