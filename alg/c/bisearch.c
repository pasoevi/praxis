#include "search.h"

/* 

Returns the index of the search target if found. -1 otherwise. Uses
binary search to locate target in sorted, a sorted array of
elements. O(lgn)

 */

int bisearch(void *sorted, void *target, size_t length, size_t esize, int (*compare)(const void *key1, const void *key2)){
  int left, middle, right;

  /* Continue search until the left and right indices cross. */
  left = 0;
  right = length - 1;

  while(left <= right){
    middle = (left + right) / 2;

    switch(compare(((char *)sorted + (esize * middle)), target)){
    case -1:
      /* Prepare to search to the  right of the middle index. */
      left = middle + 1;
      break;
    case 1:
      /*  Prepare to search to the left of the middle index. */
      right = middle - 1;
      break;
    case 0:
      /* Return the exact index where the data has been found. */
      return middle;
    }
  }
  return -1;
}	 
