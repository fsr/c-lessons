#include "ai.h"
#include "board.h"
#include "globals.h"
#include "datastructures.h"

void perform_next_turn(struct entity *ent) {
    for (enum direction dir = EAST; dir <= NORTH; dir++) {
        if (player->pos.x + next_coords[dir].x + ent->pos.x
               >= player->pos.x + ent->pos.x
               && player->pos.y + next_coords[dir].y + ent->pos.y
               >= player->pos.x + ent->pos.y) {
            move_entity(ent, dir);
            return;
        }
    }
}
