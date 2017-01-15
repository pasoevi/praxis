#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>


const char* program_name;

void filecopy(FILE*, FILE*);

int main(int argc, char* argv[])
{
  /* const struct option long_options[]{
    {"help" 0, NULL, 'h'},
      {"file" 1, NULL, 'f'},
	{"verbose", 0, NULL, 'v'}};
  */

  FILE *fp;
  char *prog = argv[0];
  
  if(argc == 1)
    filecopy(stdin, stdout);

  while(--argc > 0)
    if((fp = fopen(*++argv, "r")) == NULL)
      {
	fprintf(stderr, "%s can't open %s\n", prog, *argv);
	exit(1);
      }
    else
      {
	filecopy(fp, stdout);
	fclose(fp);
      }
  if(ferror(stdout))
    {
      fprintf(stderr, "%s: error writing stdout \n", prog);
      exit(2);
    }
  return 0;
}

void filecopy(FILE *ifp, FILE *ofp)
{
  int c;

  while((c = getc(ifp)) != EOF)
    putc(c, ofp);
}
