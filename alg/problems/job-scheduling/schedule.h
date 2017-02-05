#include <stdbool.h>
#include <time.h>
#include <stdbool.h>

struct job {
    time_t start;
    time_t end;
    float salary; /* to complitae things later */
    char *name;
    int declined;
};

int schedule(struct job jobs[], int job_count);
bool not_declined(struct job j);
int count_matching(bool(*pred)(struct job), struct job jobs[], int job_count);
