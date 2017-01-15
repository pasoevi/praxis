#include <stdio.h>
#include <stdlib.h>

#define ENTRYMAX 10000

int main(int argc, char *argv[])
{
  FILE *sdcv_pipe;
  FILE *fold_pipe;

  int bytes_read;
  int nbytes = ENTRYMAX;
  char *entry;
  char *word;  
  int maxwordlen = 50;

  sdcv_pipe = popen("sdcv -u oald", "rw");
  fold_pipe = popen("fold -s", "w");

  word = (char *) malloc(maxwordlen + 1);
  bytes_read = getdelim(&word, &maxwordlen, EOF, stdin);

  fprintf(sdcv_pipe, "%s\n", word);
  entry = (char *) malloc(ENTRYMAX + 1);
  bytes_read = getdelim(&entry, &nbytes, EOF, sdcv_pipe);
  pclose(sdcv_pipe);

  fprintf(fold_pipe, "%s\n\n", entry);

  return 0;
}
