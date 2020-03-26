#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    char **result = malloc(sizeof(char*) * n);
    
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 3 == 0 && (i + 1) % 5 == 0) {
            result[i] = "FizzBuzz";
        } else if ((i + 1) % 3 == 0) {
            result[i] = "Fizz";
        } else if ((i + 1) % 5 == 0) {
            result[i] = "Buzz";
        } else {
            sprintf(result[i], "%d", i+1);
        }
    }
    
    *returnSize = n;
    
    return *result;
}

int main(int argc, char *argv[]) {
    int *arraySize;

    char **result = fizzBuzz(10, arraySize);
    printf("%d\n", arraySize);
    for (int i = 0; i < *arraySize; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}
