#include <stdlib.h>
#include <assert.h>
#include "datastructures.h"
#include "globals.h"
#include "board.h"

struct entity *init_entity(int x_pos, int y_pos, int health, char symbol) {
    struct coord new_pos = {x_pos, y_pos};
    if (out_of_bounds(new_pos) || position_covered(new_pos))
        return NULL;
    struct entity *new_ent = malloc(sizeof *new_ent);
    if (new_ent == NULL)
        exit(EXIT_FAILURE);
    new_ent->pos = new_pos;
    new_ent->health = health;
    new_ent->symbol = symbol;
    return new_ent;
}

struct monster_list *init_monster_list(void) {
    struct monster_list *list = malloc(sizeof *list);
    if (list == NULL)
        exit(EXIT_FAILURE);
    list->length = 0;
    list->first = NULL;
    list->last = NULL;
    return list;
}

void free_monster_list(struct monster_list *list) {
    assert(list != NULL);
    struct entity* current = list->first;
    while (current != NULL) {
        struct entity *bust = current;
        current = current->next;
        free(bust);
    }
    free(list);
}

int add_monster(struct monster_list *list, struct entity *monster) {
    assert(list != NULL);
    assert(monster != NULL);
    if (list->length == 0)
        list->first = monster;
    else
        list->last->next = monster;
    monster->prev = list->last;
    monster->next = NULL;
    list->last = monster;
    list->length++;
    return 1;
}

void monster_list_map(struct monster_list *list, void (*func)(struct entity *monster)) {
    assert(list != NULL);
    for (struct entity *current = list->first;
            current != NULL; current = current->next)
        func(current);
}

int position_covered(struct coord pos) {
    if (player != NULL && has_position(player, pos))
        return 1;
    if (monsters == NULL)
        return 0;
    for (struct entity *current = monsters->first; current != NULL;
            current = current->next) {
        if (has_position(current, pos))
            return 1;
    }
    return 0;
}

int has_position(struct entity *ent, struct coord pos) {
    assert(ent != NULL);
    return ent->pos.x == pos.x && ent->pos.y == pos.y;
}
