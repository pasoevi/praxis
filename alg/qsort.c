#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "search.h"

/*
 *  sorts the array of elements in data. Returns 0 if sorting is
 *  successful, or -1 otherwise. O(n lg n).
 */

/* Compare two integers (used during median-of-three partitioning).  */
int compareInt(const void *int1, const void *int2){
    /* if(*(const int *)int1 < *(const int *)int2){
       return 1;
       }else if(*(const int *)int1 > *(const int *)int2){
       return -1;
       }else{
       return 0;
       }
    */
    if((*(const int *)int1 % 2) == 0)
        return -1;
    else
        return 1;
}
    
static int partition(void *data, size_t esize, int start, int end,
                     int (*compare)(const void *key1, const void *key2)){
    char *a = data;
    void *pval, *temp;
    int r[3];
    /* Allocate storage for the partition value and swapping.  */

    if ((pval = malloc(esize)) == NULL) {
        return -1;
    }

    if ((temp = malloc(esize)) == NULL) {
        free(pval);
        return -1;
    }

    /* Use  the median-of-three method to find the partition value. */

    r[0] = (rand() % (end - start + 1)) + start;
    r[1] = (rand() % (end - start + 1)) + start;
    r[2] = (rand() % (end - start + 1)) + start;

    issort(r, 3, sizeof(int), compareInt);
    memcpy(pval, &a[r[1] * esize], esize);

    /* Create two partitions around the partition value. */

    start--;
    end++;
  
    while (1) {
        /* Move left until an element is found in the wrong partition.  */
        do {
            end--;
        } while (compare(&a[end * esize], pval) > 0);

        do {
            /* Move right until an element is found in the wrong position */
            start++;
        } while (compare(&a[start * esize], pval) < 0);

        if (start >= end) {
            break;
        } else {
            /* Swap the elements under the left and right counters */
            memcpy(temp, &a[start * esize], esize);
            memcpy(&a[start * esize], &a[end * esize], esize);
            memcpy(&a[end * esize], temp, esize);
        }
    }

    /* Free the space allocated for partitioning */
    free(pval);
    free(temp);

    return end;
}

int qksort(void *data, size_t length, size_t esize, int start,  int end,
           int (*compare)(const void *key1, const void *key2)){
    int j;

    /* Stop recursion when it isn't possible to partition further */
    while (start < end) {
        /* Determine where to partition elements */
        if ((j = partition(data, esize, start, end, compare)) < 0) {
            return -1;
        }
 

        /* Recursively sort the left partition */
        if (qksort(data, length, esize, start, j, compare) < 0) {
            return -1;
        }

        /* Iterate and sort the right partition */
        start = j + 1;
    }
    
    return 0;
}
