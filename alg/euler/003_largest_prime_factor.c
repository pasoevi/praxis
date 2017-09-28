#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool
is_prime(long n)
{
  if (n <= 1) {
    return false;
  } else if (n <= 3) {
    return true;
  } else if (n % 2 == 0 || n % 3 == 0) {
    return false;
  }

  for (long i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

long
find_largest_prime_factor(long n)
{
  for (long div = 2; div < n; div++) {
    if (n % div == 0) {
      n = n / div;
      div--;
    }
  }

  return n;
}

int
main(int argc, char* argv[])
{
  if (argc < 2) {
    return 1;
  }

  long num = atol(argv[1]);
  long factor = find_largest_prime_factor(num);

  printf("The largest prime factor of the number %ld is %ld\n", num, factor);
  return 0;
}
