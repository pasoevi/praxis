#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char *filename = "data.bin";

    fp = fopen("data.bin", "r+");
    if (fp == NULL)
    {
        fprintf(stderr, "cannot open target file %s\n", name);
        exit(1);
    }
    int ch;
    int i = 1;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (i % 7 == 0)
        {
            fseek(fp, -1, SEEK_CUR);
            fputc('', fp);
            fseek(fp, 0, SEEK_CUR);
        }
    }
    fclose(fp);
}