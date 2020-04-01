#include <stdlib.h>
#include <string.h>

int binary(char *name, char *array[], size_t nelem);
int lookup(char *word, char *array[]);
int bisearch(void *sorted, void *target, size_t length, size_t esize, int (*compare)(const void *key1, const void *key));
