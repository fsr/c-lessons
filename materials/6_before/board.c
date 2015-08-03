#include <stdlib.h>
#include <string.h>
#include "datastructures.h"
#include "board.h"
#include "globals.h"

struct coord next_coords[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
struct entity *board_map[HEIGHT][WIDTH] = { {0} };

int out_of_bounds(struct coord check) {
    return check.x < 0 || check.x >= WIDTH || check.y < 0 || check.y >= HEIGHT;
}

int position_covered(struct coord pos) {
    return board_map[pos.y][pos.x] != NULL;
}

void store_position(struct entity *ent) {
    board_map[ent->pos.y][ent->pos.x] = ent;
}

void update_board_map(void) {
    memset(board_map, 0, sizeof board_map);
    store_position(player);
    monster_list_map(monsters, store_position);
}

void move_entity(struct entity *ent, enum direction dir) {
    struct coord new_pos = {
        ent->pos.x + next_coords[dir].x,
        ent->pos.y + next_coords[dir].y
    };
    if (!out_of_bounds(new_pos) && !position_covered(new_pos))
        ent->pos = new_pos;
}
