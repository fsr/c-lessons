#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include "datastructures.h"
#include "board.h"
#include "io.h"
#include "globals.h"

void move_player(enum direction dir);
void handle_input(int input, int *running);
void game_setup(void);
void game_end(void);
void attack(struct entity *attacker, enum direction dir);
int is_dead(struct entity *ent);

struct entity *player = NULL;
struct monster_list *monsters = NULL;
const int monster_count = 7;

int main(void) {
    game_setup();
    int running = 1;
    int input;
    while (running) {
        input = getch();
        handle_input(input, &running);
        // clear_monster_list(monsters);
        monster_list_filter(monsters, is_dead);
        update_board_map();
        /* insert fancy ai and respawning and state checking */
        draw_board();
    }
    game_end();
    return 0;
}

void game_setup(void) {
    init_term();
    srand(time(NULL));
    player = init_entity(WIDTH / 2, HEIGHT / 2, 100, 'J');
    update_board_map();
    monsters = init_monster_list();
    for (int i = 0; i < monster_count; i++) {
        struct entity *new_monster;
        int x, y;
        do {
            x = rand() / (RAND_MAX / WIDTH + 1);
            y = rand() / (RAND_MAX / HEIGHT + 1);
        } while ((new_monster = init_entity(x, y, 100, '*')) == NULL);
        add_monster(monsters, new_monster);
        update_board_map();
    }
    draw_board();
}

void game_end(void) {
    free(player);
    free_monster_list(monsters);
    endwin();
}

void move_player(enum direction dir) {
    struct coord new_pos = {
        player->pos.x + next_coords[dir].x,
        player->pos.y + next_coords[dir].y
    };
    if (!out_of_bounds(new_pos) && !position_covered(new_pos))
        player->pos = new_pos;
}

void handle_input(int input, int *running) {
    switch (input) {
        case 'x': *running = 0; break;
        case 'w': move_player(NORTH); break;
        case 's': move_player(SOUTH); break;
        case 'a': move_player(WEST); break;
        case 'd': move_player(EAST); break;
        case KEY_UP: attack(player, NORTH); break;
        case KEY_DOWN: attack(player, SOUTH); break;
        case KEY_LEFT: attack(player, WEST); break;
        case KEY_RIGHT: attack(player, EAST); break;
    }
}

void attack(struct entity *attacker, enum direction dir) {
    struct coord target = {
        attacker->pos.x + next_coords[dir].x,
        attacker->pos.y + next_coords[dir].y
    };
    if (!out_of_bounds(target) && position_covered(target)) {
        struct entity *defender = board_map[target.y][target.x];
        unsigned int damage = attacker->attack - defender->defense;
        if (damage > defender->health)
            defender->health = 0;
        else if (damage > 0)
            defender->health -= damage;
    flash_entity(defender);
    }
}

int is_dead(struct entity *ent) {
    return ent != NULL && ent->health == 0;
}
