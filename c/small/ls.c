#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char *argv[])
{
  DIR *dp;
  struct dirent * dirp;

  if(argc != 2)
    {
      perror("Usage:\n\tls directory_name");
      exit(1);
    }

  if((dp = opendir(argv[1])) == NULL)
     printf("Cannot open %s", argv[1]);

  while((dirp = readdir(dp)) != NULL)
    printf("%s\n", dirp->d_name);
     

  return 0;
}
