#include <stdio.h>
#include <guile/gh.h>
#include "builtins.h"

SCM factorial(SCM s_n)
{
  int i;
  unsigned long result = 1;
  unsigned long n;

  n = gh_scm2ulong(s_n);
  
  gh_defer_ints();

  for(i = 1; i <= n; ++i)
    {
      result *= i;
    }

  gh_allow_ints();
  return gh_ulong2scm(result);
}
