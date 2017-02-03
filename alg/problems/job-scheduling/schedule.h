#include <stdbool.h>

struct point {
    int x;
    int y;
    bool visited;
};

int robotour(int start_idx, struct point plane[], int plane_size);
