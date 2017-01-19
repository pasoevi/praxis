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
 * Return the distance between two locations.
 */
float find_distance(struct point loc1, struct point loc2)
{
    return sqrtf(pow((loc2.x - loc1.x), 2) + pow((loc2.y - loc1.y), 2));
}

/*
 * Find the index of the point that is closest to point at index loc_index
 * in the array of locations.
 */
int find_closest(int loc_index, struct point points[], int plane_size)
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

bool is_unvisited(struct point p)
{
    return !(p.visited);
}

/*
 * Return the number of points that match a predicate.
 */
int count_matching(bool(*pred)(struct point), struct point points[], int plane_size)
{
    int nmatching = 0;
    int i;
    for (i = 0; i < plane_size; i++) {
        if (pred(points[i])) {
            nmatching++;
        }
    }

    return nmatching;
}

/*
 * Let the robot travel to all the points on plane by visiting each point only
 * once and making the shortest trip possible.
 */
int robotour(int start_idx, struct point plane[], int plane_size)
{
    plane[start_idx].visited = true;
    while (count_matching(is_unvisited, plane, plane_size) > 0) {
        start_idx = find_closest(start_idx, plane, plane_size);
        plane[start_idx].visited = true;
        printf("X=%d,Y=%d\n", plane[start_idx].x, plane[start_idx].y);
    }
}

int robotour_old()
{
    char plane_old[PLANE_W][PLANE_H] = {
        { 'A', 'B', '0', '0', '0', 'C', 'D', '0', '0', 'E' },
        { 'F', '0', '0', '0', 'G', '0', '0', '0', '0', 'H' },
        { 'I', 'J', '0', '0', 'K', 'L', '0', '0', '0', 'M' },
        { 'N', 'O', '0', '0', 'P', '0', '0', '0', 'Q', '0' },
        { 'R', '0', '0', '0', '0', 'S', '0', 'T', '0', 'U' },
        { 'V', '0', '0', 'W', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' },
        { '0', '0', '0', '0', '0', '0', '0', '0', 'X', '0' },
        { '0', '0', '0', '0', '0', 'Y', '0', 'Z', '0', '0' }
    };

    int i, j;
    for (i = 0; i < PLANE_W; i++) {
        for (j = 0; j < PLANE_H; j++) {
            printf("%c\t", plane_old[i][j]);
        }
        printf("\n");
    }
}
