#include <stdlib.h>
#include <string.h>

int bisearch(void *sorted, void *target, size_t length, size_t esize, int (*compare)(const void *key1, const void *key));
