#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include "datastructures.h"
#include "board.h"
#include "io.h"
#include "globals.h"

void move_player(enum direction dir);
void handle_input(char input, int *running);

struct entity *player = NULL;
struct monster_list *monsters = NULL;
const int monster_count = 7;

int main(void) {
    init_term();
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
    int running = 1;
    char input;
    while (running) {
        input = getch();
        handle_input(input, &running);
        /* insert fancy ai and respawning and state checking */
        draw_board();
    }
    free(player);
    free_monster_list(monsters);
    endwin();
    return 0;
}

void move_player(enum direction dir) {
    struct coord new_pos = {
        player->pos.x + next_coords[dir].x,
        player->pos.y + next_coords[dir].y
    };
    if (!out_of_bounds(new_pos) && !position_covered(new_pos))
        player->pos = new_pos;
}

void handle_input(char input, int *running) {
    switch (input) {
        case 'x': *running = 0; break;
        case 'w': move_player(NORTH); break;
        case 's': move_player(SOUTH); break;
        case 'a': move_player(WEST); break;
        case 'd': move_player(EAST); break;
    }
}
