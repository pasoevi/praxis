#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "robotour.h"
#include "search.h"
#include "sort.h"

/* #define  LEN(x) (sizeof(x) / sizeof(type(x))) */

void sort_demo()
{
    int LEN = 7;
    int nums[] = {12, 4, 9, 3, 17, 0, 21};
    char *names[] = {"ani", "dato", "otari"};
    int i;
    
    for (i = 0; i < LEN; i++) {
        printf("%d, ", nums[i]);
    }

    putchar('\n');
    qksort(nums, 7, sizeof(int),  0, 6, compareInt);
    for (i = 0; i < LEN; i++) {
        printf("%d, ", nums[i]);
    }

    putchar('\n');
    int target = 12;
    /* Search for 12 using the binary search algorithm. */
    int pos = bisearch(nums, &target, LEN, sizeof(int), compareInt);
    // printf("Target is located at %d\n", pos);

    /* names */
    int j;
    for (j = 0; j < 3; i++) {
        printf("%s \n", names[i]);
    }
    putchar('\n');

    //  qksort(names, sizeof(names) / sizeof(int), sizeof(int), 0, 6, strcmp);

  
    for (j = 0; j < 3; i++) {
        printf("%s \n", names[i]);
    }

}

void search_demo()
{
    char *flag[] = {
        "actually",
        "just",
        "quite",
        "really",
        NULL
    };
  
    printf("%The word really %d\n", lookup("just", flag));
    printf("%The word really binary %d\n", binary("really", flag, sizeof(flag) / sizeof(flag[0])));
}

void robotour_demo()
{
    struct point plane[] = {
        { 1, 1, false },
        { 1, 2, false },
        { 4, 4, false },
        { 5, 1, false },
        { 2, 2, false },
        { 8, 5, false },
    };

    robotour(0, plane, 6);
}

int main(int argc, char *argv[])
{
    robotour_demo();
    search_demo();
    sort_demo();
    
    return 0;
}
