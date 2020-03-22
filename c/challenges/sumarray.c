#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int sumArray(int a[], int length){
    int sum = 0, i;
    for(i = 0; i < length; i++){
        sum += a[i];
    }

    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int i, n = 0;
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++){
      scanf("%d", &a[i]);
    }
    
    printf("%d\n", sumArray(a, n));
    return 0;
}
