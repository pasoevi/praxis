#include <stdio.h>
#include <stdlib.h>

/* lookup: sequential search for a word in an array */
int lookup(char *word, char *array[]){
  int i;
  for(i = 0; array[i] != NULL; i++){
    if(strcmp(word, array[i]) == 0){
      return i;
    }
   }
  return -1;
}

int binary(char *name, char *array[], size_t nelem){
  int low, mid, high, cmp;
  low = 0;
  high = nelem - 1;
  
  while(low <= high){
    mid = (low + high) / 2;
    cmp = strcmp(name, array[mid]);
    if(cmp < 0){
      high = mid - 1;
    }else if(cmp > 0){
      low = mid + 1;
    }else{
      return mid;
    }
  }
  return -1;
}

double fahr2c(double temperature){
  return ((temperature - 32)*5)/9;
}

int main(int argc, char *argv[]){
  char *flag[] = {
    "actually",
    "just",
    "quite",
    "really",
    NULL
  };
  
  printf("%The word really %d\n", lookup("just", flag));
  printf("%The word really binary %d\n", binary("really", flag, sizeof(flag) / sizeof(flag[0])));
  printf("0 F = %f C\n", fahr2c(0));
  return 0;
}
