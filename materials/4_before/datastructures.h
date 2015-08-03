#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

struct coord {
    int x, y;
};

struct entity {
    struct coord pos;
    unsigned int health;
    char symbol;
    unsigned int attack;
    unsigned int defense;
    struct entity *next;
    struct entity *prev;
};

struct monster_list {
    int length;
    struct entity *first;
    struct entity *last;
};

struct entity *init_entity(int x_pos, int y_pos, int health, char symbol);
struct monster_list *init_monster_list(void);
void free_monster_list(struct monster_list *list);
int add_monster(struct monster_list *list, struct entity *monster);
void monster_list_map(struct monster_list *list, void (*func)(struct entity *monster));
void monster_list_filter(struct monster_list *list, int (*func)(struct entity *monster));
#endif
