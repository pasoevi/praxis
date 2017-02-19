#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "robotour.h"

#define PLANE_W 10
#define PLANE_H 10

#define PLANE_SIZE 6
#define MAX_DISTANCE 10000

/*
 * Problem: Movie Scheduling Problem
 * Input: A set I of n intervals on the line.
 * 
 * Output: What is the largest subset of mutually non-overlapping
 * intervals that can be selected from I?
 */
int schedule(struct job jobs[], int job_count);
{
    
    while (count_matching(not_declined, jobs, job_count) > 0) {
        start_idx = find_soonest_ending(jobs, job_count);
        plane[start_idx].visited = true;
        printf("%s\n", job.name);
    }
}

bool not_declined(struct job j)
{
    return !(j.declined);
}

/*
 * Return the number of jobs that match a predicate.
 */
int count_matching(bool(*pred)(struct job), struct job jobs[], int job_count)
{
    int nmatching = 0;
    int i;
    for (i = 0; i < job_count; i++) {
        if (pred(jobs[i])) {
            nmatching++;
        }
    }

    return nmatching;
}

/*
 * Find the index of the job that ends soonest
 */
int find_soonest_ending(int loc_index, struct point points[], int plane_size)
{
    if (loc_index < 0) {
        return loc_index;
    }

    struct point loc = points[loc_index];
    int closest_index = loc_index;
    float closest_distance = MAX_DISTANCE;

    int i;
    for (i = 0; i < plane_size; i++) {
        float distance = find_distance(loc, points[i]);

        if (i != loc_index &&
            distance < closest_distance &&
            points[i].visited == false) {
            closest_index = i;
            closest_distance = distance;
        }
    }

    return closest_index;
}

