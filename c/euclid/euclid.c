#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

/* Euclid: Return the greatest common divisor */
long euclid(long m, long n){
  if(n > 0){
    return euclid(n, m%n);
  }else{
    return m;
  }
}

int main(long argc, char *argv[]){
  char *endptr, *str1, *str2;
  long m, n;
  if(argc != 3){
    fprintf(stderr, "Usage: %s m n\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  str1 = argv[1];
  str2 = argv[2];
  
  errno = 0;
  m = strtol(str1, &endptr, 10);
  n = strtol(str2, &endptr, 10);
  
  if ((errno == ERANGE && (m == LONG_MAX || m == LONG_MIN))
      || (errno != 0 && m == 0)) {
    perror("strtol");
    exit(EXIT_FAILURE);
  }

  if ((errno == ERANGE && (n == LONG_MAX || n == LONG_MIN))
      || (errno != 0 && n == 0)) {
    perror("strtol");
    exit(EXIT_FAILURE);
  }

  if (endptr == str1 || endptr == str2) {
    fprintf(stderr, "No digits were found\n");
    exit(EXIT_FAILURE);
  }

  long gcd = euclid(m, n);
  
  
  if (*endptr != '\0'){
    /* Not necessarily an error... */
    printf("Further characters after number: %s\n", endptr);
  }
  printf("%ld\n", gcd);
  
  return 0;
}
    
  
