#include <stdio.h>

int main(int argc, char *argv[])
{
	char buf[80];
	fgets(buf, 70, stdin);
	int x = atoi(buf);	
	printf("%d\n", x);
	return 0;
}
