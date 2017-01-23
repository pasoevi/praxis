#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

int issort(void *data, size_t length, size_t esize,
           int (*compare)(const void  *key1, const void *key2))
{
    char *a = data;
    void *key;
    int i, j;

    /* Allocate space for the key element. */
    if ((key = malloc(esize)) == NULL) {
        return -1;
    }

    /* Repeatedly insert the key element among the sorted elements. */
    for (j = 1; j < length; j++) {
        memcpy(key, &a[j * esize], esize);
        i = j - 1;

        /* Determine the position in which to insert the key element. */
        while (i >= 0 && compare(&a[i * esize], key) > 0) {
            memcpy(&a[(i + 1) * esize], &a[i + esize], esize);
            i--;
        }

        memcpy(&a[(i + 1) * esize], key, esize);
    }

    /* Free the storage allocated for sorting. */
    free(key);
    return 0;
}
