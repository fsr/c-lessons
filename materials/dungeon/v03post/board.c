#include "datastructures.h"
#include "board.h"
#include "globals.h"

struct coord next_coords[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int out_of_bounds(struct coord check) {
    return check.x < 0 || check.x >= WIDTH || check.y < 0 || check.y >= HEIGHT;
}
