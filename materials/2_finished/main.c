#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

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

struct coord {
    int x, y;
};

struct entity {
    struct coord pos;
    int health;
    char symbol;
    struct entity *next;
    struct entity *prev;
};

struct monster_list {
    int length;
    struct entity *first;
    struct entity *last;
};

struct coord next_coords[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct entity *player = NULL;
struct monster_list *monsters = NULL;
const int monster_count = 7;

void handle_input(char input, char *running);
void move_player(enum direction dir);
void draw_board();
int out_of_bounds(struct coord check);
struct entity *init_entity(int x_pos, int y_pos, int health, char symbol);
struct monster_list *init_monster_list();
void free_monster_list(struct monster_list *list);
int add_monster(struct monster_list *list, struct entity *monster);
void monster_list_map(struct monster_list *list, void (*func)(struct entity *monster));
int position_covered(struct coord pos);
int has_position(struct entity *ent, struct coord pos);
void print_entity(struct entity *ent);
void move(int y, int x);

int main(int argc, char *argv[]) {
    srand(time(NULL));
    player = init_entity(WIDTH / 2, HEIGHT / 2, 100, 'J');
    monsters = init_monster_list();
    for (int i = 0; i < monster_count; i++) {
        struct entity *new_monster;
        int x, y;
        do {
            x = rand() / (RAND_MAX / WIDTH + 1);
            y = rand() / (RAND_MAX / HEIGHT + 1);
        } while ((new_monster = init_entity(x, y, 100, '*')) == NULL);
        add_monster(monsters, new_monster);
    }
    draw_board();
    for (char running = 1, input; running == 1; input = getchar()) {
        handle_input(input, &running);
        /* insert fancy ai and respawning and state checking */
        draw_board();
    }
    free(player);
    free_monster_list(monsters);
    return 0;
}

void handle_input(char input, char *running) {
    switch (input) {
        case 'x': *running = 0; break;
        case 'w': move_player(NORTH); break;
        case 's': move_player(SOUTH); break;
        case 'a': move_player(WEST); break;
        case 'd': move_player(EAST); break;
    }
}

void move_player(enum direction dir) {
    struct coord new_pos = {
        player->pos.x + next_coords[dir].x,
        player->pos.y + next_coords[dir].y
    };
    if (!out_of_bounds(new_pos) && !position_covered(new_pos))
        player->pos = new_pos;
}

void draw_board() {
    system("clear");
    move(0, 0);
    for (int x = -1; x < WIDTH; x++)
        printf("=");
    printf("=\n");
    for (int y = 0; y < HEIGHT; y++) {
        printf("|");
        for (int x = 0; x < WIDTH; x++)
            printf(" ");
        printf("|\n");
    }
    for (int x = -1; x < WIDTH; x++)
        printf("=");
    printf("=\n");
    print_entity(player);
    monster_list_map(monsters, print_entity);
}

int out_of_bounds(struct coord check) {
    return check.x < 0 || check.x >= WIDTH || check.y < 0 || check.y >= HEIGHT;
}

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

struct monster_list *init_monster_list() {
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
}

void monster_list_map(struct monster_list *list, void (*func)(struct entity *monster)) {
    assert(list != NULL);
    for (struct entity *current = list->first;
            current != NULL; current = current->next)
        func(current);
}

void print_entity(struct entity *ent) {
    move(ent->pos.y + 1, ent->pos.x + 1);
    printf("%c", ent->symbol);
    move(HEIGHT + 2, 0);
}

void move(int y, int x) {
    printf("\033[%d;%dH", y + 1, x + 1);
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
