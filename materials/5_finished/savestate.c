#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datastructures.h"
#include "savestate.h"
#include "globals.h"

static FILE *save;
static char *line;

int load_game_state(void) {
    save = fopen("save", "r");
    size_t size = 0;
    if (getline(&line, &size, save) == EOF) {
        fclose(save);
        return 0;
    }
    player = deserialize_entity(line);
    monsters = init_monster_list();
    while (getline(&line, &size, save) != EOF) {
        add_monster(monsters, deserialize_entity(line));
    }
    free(line);
    fclose(save);
    return 1;
}

void save_game_state(void) {
    save = fopen("save", "w");
    serialize_entity(player);
    monster_list_map(monsters, serialize_entity);
    fclose(save);
}

void serialize_entity(struct entity *ent) {
    fprintf(save, "%d,%d,%u,%c,%u,%u\n", ent->pos.x, ent->pos.y, ent->health,
            ent->symbol, ent->attack, ent->defense);
}

struct entity *deserialize_entity(char *line) {
    struct entity *ent;
    int x_pos, y_pos;
    unsigned int health;
    char symbol;
    line = strtok(line, ",");
    x_pos = atoi(line);
    line = strtok(NULL, ",");
    y_pos = atoi(line);
    line = strtok(NULL, ",");
    health = atoi(line);
    line = strtok(NULL, ",");
    symbol = line[0];
    ent = init_entity(x_pos, y_pos, health, symbol);
    return ent;
}
