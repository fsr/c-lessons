#ifndef SAVESTATE_H
#define SAVESTATE_H

#include <string.h>
#include "datastructures.h"

void save_game_state(void);
int load_game_state(void);
void serialize_entity(struct entity *ent);
struct entity *deserialize_entity(char *line);

#endif
