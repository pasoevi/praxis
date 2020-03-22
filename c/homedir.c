#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_homedir(void)
{
    char homedir[MAX_PATH];
#ifdef _WIN32
    snprintf(homedir, MAX_PATH, "%s%s", getenv("HOMEDRIVE"), getenv("HOMEPATH"));
#else
    snprintf(homedir, MAX_PATH, "%s", getenv("HOME"));
#endif
    return strdup(homedir);
}

char *program_name = "dict";
char *version = "0.01b";
char *hist_fname = strcat(get_homedir(), "/.weehist");


int main(int argc, char *argv[]) {
    printf("%s\n", hist_fname);
}