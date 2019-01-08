#include <time.h>

struct dict {
        char *filename;         /* without extension */
        char *version;
        char *bookname;
        int wordcount;
        int idxfile_size;
        char *author;
        char *email;
        char *website;
        char *description;
        time_t date;
        char sametypesequence;
};

/* 
 * Returns a dictionary with options set. Filename is without
 * extension.
 */
struct dict makedict(const char *filename);
/* 
 * Load all dictionaries that can be found in *directory* into *dicts*
 * array.
 */
struct dict *load_dicts(const char *directory);
