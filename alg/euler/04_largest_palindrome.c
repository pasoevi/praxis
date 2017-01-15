#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_palindrome(int n)
{
    return true;
}

int find_largest_palindrome(int num_digits)
{
    
    for (int i = 999; i > 0; i--) {
        
    }

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        return 1;
    }
    
    int num_digits = atol(argv[1]);
    int factor = find_largest_palindrome(num_digits);
    
    printf("The largest prime factor of the number %ld is %ld\n", num, factor);
    return 0;
}
