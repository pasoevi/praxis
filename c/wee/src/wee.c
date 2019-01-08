/*
 * wee.c
 *
 *  Created on: 17 Nov 2015
 *      Author: sergi
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <getopt.h>
#include "wee.h"
/* #include <wordexp.h> */
#include "distance.h"

const char *program_version = "0.1";
const char *program_name = "wee";

void print_version(void)
{
    printf("%s - Command line dictionary, version %s\n",
           program_name, program_version);
}

int main(int argc, char **argv)
{
    struct dict *dicts;

    char *hist_fname = "/home/sergi/.weehist";
    int add_to_hist_flag = 0;
    int show_version_flag = 0;
    char *dicts_dir = NULL;

    int index;
    int c;

    opterr = 0;

    while ((c = getopt(argc, argv, "vhc:")) != -1) {
        switch (c) {
            case 'h':
                add_to_hist_flag = 1;
                break;
            case 'v':
                show_version_flag = 1;
                break;
            case 'c':
                dicts_dir = optarg;
                break;
            case '?':
                if (optopt == 'c')
                    fprintf(stderr,
                            "Option -%c requires an argument.\n",
                            optopt);
                else if (isprint(optopt))
                    fprintf(stderr,
                            "Unknown option `-%c'.\n", optopt);
                else
                    fprintf(stderr,
                            "Unknown option character `\\x%x'.\n",
                            optopt);

                return 1;
            default:
                abort();
        }
    }

    if (show_version_flag) {
        print_version();
        return EXIT_SUCCESS;
    }

    printf("add_to_hist_flag = %d, dicts_dir = %s\n",
           add_to_hist_flag, dicts_dir);

    struct dict dict = makedict("stardict-test_dict-2.4.2/test_dict.ifo");
    dicts = load_dicts(dicts_dir);

    for (index = optind; index < argc; index++) {
        printf("Non-option argument %s\n", argv[index]);
        if (add_to_hist_flag) {
        }
    }

    return 0;
}

struct dict makedict(const char *filename)
{
    struct dict dict;


    const int MAX_LINE = 80;
    char buff[MAX_LINE];
    FILE *fin = fopen (filename, "r");
    if (fin != NULL) {
        while (fgets(buff, MAX_LINE, fin)) {
            char key[MAX_LINE];
            char val[MAX_LINE];
            fscanf(fin, "%[^=]=%s", key, val);
            printf("%s\n", buff);
        }
        fclose (fin);
    }
    return dict;
}

struct dict *load_dicts(const char *directory)
{

}

int lookup(char *word, char **definition, int dictionary)
{
    return 0;
}
