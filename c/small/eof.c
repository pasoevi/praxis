#include <stdio.h>

int main(int argc, char *argv0[])
{

  int c;
  int nc, nb, nt, nn;
  nc = nb = nt = nn = 0;
  while ((c = getchar()) != EOF)
    {
      ++nc;
      if (c == ' ')
	++nb;
      if (c == '\t')
	++nt;
      if (c == '\n')
	{
	  ++nn;
	}
    }


  printf("%d %d %d %d\n", nc, nb, nt, nn);
  return 0;
}

