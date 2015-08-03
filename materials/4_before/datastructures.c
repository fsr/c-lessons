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
    new_ent->attack = 20;
    new_ent->defense = 5;
    new_ent->prev = NULL;
    new_ent->next = NULL;
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
    if (list == NULL)
        return;
    for (struct entity *current = list->first;
            current != NULL; current = current->next)
        func(current);
}

void monster_list_filter(struct monster_list *list, int (*func)(struct entity *monster)) {
    if (list == NULL)
        return;
    struct entity **nl_cur = &list->first;
    struct entity *cur = list->first;
    while (cur != NULL) {
        if (func(cur) != 0) {
            struct entity *bust = cur;
            cur = cur->next;
            list->length--;
            free(bust);
        } else {
            list->last = *nl_cur = cur;
            nl_cur = &(*nl_cur)->next;
            cur = cur->next;
        }
    }
    if (list->length == 0)
        list->first = list->last = NULL;
    else
        list->last->next = NULL;
}
