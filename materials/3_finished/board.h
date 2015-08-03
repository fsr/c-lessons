#ifndef BOARD_H
#define BOARD_H
#include "datastructures.h"

enum {
    WIDTH = 20,
    HEIGHT = 10,
    Y_OFF = 1
};

enum direction {
    EAST,
    SOUTH,
    WEST,
    NORTH
};

int out_of_bounds(struct coord check);

extern struct coord next_coords[];
#endif
