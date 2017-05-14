#include <stdlib.h>

void insertion_sort(int s[], int n);
int qksort(void *data, size_t length, size_t esize, int start,  int end, int (*compare)(const void *key1, const void *key2));
int issort(void *data, size_t length, size_t esize, int (*compare)(const void  *key1, const void *key2));
int compareInt(const void *int1, const void *int2);
	     
