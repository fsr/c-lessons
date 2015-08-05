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
int position_covered(struct coord pos);
void update_board_map(void);
void store_position(struct entity *ent);
void move_entity(struct entity *ent, enum direction dir);

extern struct entity *board_map[HEIGHT][WIDTH];
extern struct coord next_coords[];
#endif
