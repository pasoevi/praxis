#include <string.h>
#include "distance.h"

int min2(int a, int b)
{
	if (a < b) {
		return a;
	} else {
		return b;
	}
}

int min3(int a, int b, int c)
{
	int min_val = min_val = min2(a, b);
	return min2(min_val, c);
}

int levenstein_distance(char *s, char *t)
{
	/* Test if the computation has to be made. */
	if (s == t) {
		return 0;
	}

	int len_s = strlen(s);
	int len_t = strlen(t);

	if (len_s == 0 || len_t == 0) {
		return 0;
	}


	/* vectors of integer distances */
	int v0[len_t];
	int v1[len_t];

	/* Initialise the v0 (the previous row of distances. This row
	   is A[0][i]: edit distance for an empty s the distance is
	   just the number of characters to delete from t
	 */
	int i;
	for (i = 0; i < len_t; i++) {
		v0[i] = i;
	}


	for (i = 0; i < len_s; i++) {
		/* Calculate v1 (current row distances) from the previous row v0.
		 * The first element of v1 is A[i+1][0]
		 * edit distance is delete (i+1) chars from s to match empty t 
		 */

		v1[0] = i + 1;

		/* Use the formula to fill in the rest of the row */
		int j;
		for (j = 0; j < len_t; j++) {
			int cost = (s[i] == t[j]) ? 0 : 1;
			v1[j + 1] =
			    min3(v1[i] + 1, v0[j + 1] + 1, v0[j] + cost);
		}

		/* Copy v1 (current row) to v0 (previous row) for next
		   iteration
		 */
		for (j = 0; j < len_t; j++) {
			v0[j] = v1[j];
		}
	}
	return v1[len_t];
}
