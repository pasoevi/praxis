#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define PLANE_W 10
#define PLANE_H 10

#define PLANE_SIZE 5
#define MAX_DISTANCE 10000

struct location {
    int x;
    int y;
    bool visited;
};

/*
 * Return the distance between two locations.
 */
float find_distance(struct location loc1, struct location loc2)
{
    return sqrtf(pow((loc2.x - loc1.x), 2) + pow((loc2.y - loc1.y), 2));
}

/*
 * Find the index of the location that is closest to location at index loc_index
 * in the array of locations.
 */
int find_closest(int loc_index, struct location locations[])
{
    if (loc_index < 0) {
        return loc_index;
    }

    struct location loc = locations[loc_index];
    int closest_index = loc_index;
    float closest_distance = MAX_DISTANCE;

    for (int i = 0; i < PLANE_SIZE; i++) {
        float distance = find_distance(loc, locations[i]);

        if (i != loc_index &&
            distance < closest_distance &&
            locations[i].visited == false) {
            closest_index = i;
            closest_distance = distance;
        }
    }

    return closest_index;
}

bool is_unvisited(struct location loc)
{
    return !(loc.visited);
}

int count_matching(bool(*pred)(struct location), struct location locations[], int plane_size)
{
    int nmatching = 0;
    for (int i = 0; i < plane_size; i++) {
        if (pred(locations[i])) {
            nmatching++;
        }
    }

    return nmatching;
}

/*
 * Let the robot travel to all the points on plane by visiting each point only
 * once and making the shortest trip possible.
 */
int robotour(int start_idx, struct location plane[], int plane_size)
{
    while (count_matching(is_unvisited, plane, plane_size) > 0) {
        start_idx = find_closest(start_idx, plane);
        plane[start_idx].visited = true;
        printf("X=%d,Y=%d,", plane[start_idx].x, plane[start_idx].y);
    }
}


void robotour_demo()
{
    struct location plane[] = {
        { 1, 1, false },
        { 1, 2, false },
        { 5, 1, false },
        { 2, 2, false },
        { 8, 5, false },
    };

    robotour(0, plane, 5);
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

    for (int i = 0; i < PLANE_W; i++) {
        for (int j = 0; j < PLANE_H; j++) {
            printf("%c\t", plane_old[i][j]);
        }
        printf("\n");
    }
}
