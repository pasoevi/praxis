#include "getline.h"
/* find a blank in s[] if it appears between the `start` and the `n'th
   character. Return -1 if no blanks found. Negative n implies search
   between the start and the `n'th character /before/ that */
int find_blnk(char s[], int start, int n);
int find_last_blnk(char s[]);
