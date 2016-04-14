#include <stdio.h>
#include <ncurses.h>
#include "io.h"
#include "globals.h"
#include "board.h"
#include "datastructures.h"

//void usleep(long sec);

void init_term(void) {
    initscr();
    curs_set(0);
    start_color();
    clear();
    noecho();
    keypad(stdscr, TRUE);
}

void draw_board(void) {
    clear();
    move(0, 0);
    for (int x = -1; x < WIDTH; x++)
        printw("=");
    printw("=\n");
    for (int y = 0; y < HEIGHT; y++) {
        printw("|");
        for (int x = 0; x < WIDTH; x++)
            printw(" ");
        printw("|\n");
    }
    for (int x = -1; x < WIDTH; x++)
        printw("=");
    printw("=\n");
    print_entity(player);
    monster_list_map(monsters, print_entity);
    print_info();
    refresh();
}

void print_entity(struct entity *ent) {
    move(ent->pos.y + 1, ent->pos.x + 1);
    printw("%c", ent->symbol);
    move(HEIGHT + 2, 0);
}

void flash_entity(struct entity *ent) {
#if 0
    move(ent->pos.y + 1, ent->pos.x + 1);
    addch(' ');
    move(HEIGHT + 2, 0);
    refresh();
#endif
    (void) ent;
}

void print_info(void) {
    char *dir_names[] = {"Right:", "Bottom:", "Left:", "Top:"};
    struct coord base_pos = player->pos;
    move(HEIGHT / 2, 2 * WIDTH);
    printw("%-8s %c", "Player:", player->symbol);
    move(HEIGHT / 2 + 1, 2 * WIDTH);
    printw("%7d HP", player->health);
    for(enum direction dir = EAST; dir <= NORTH; dir++) {
        struct coord cur_pos = {
            base_pos.x + next_coords[dir].x,
            base_pos.y + next_coords[dir].y
        };
        move(HEIGHT / 2 + 4 * next_coords[dir].y,
                2 * WIDTH + 16 * next_coords[dir].x);
        if (!out_of_bounds(cur_pos) && position_covered(cur_pos)) {
            struct entity *ent = board_map[cur_pos.y][cur_pos.x];
            printw("%-8s %c", dir_names[dir], ent->symbol);
            move(HEIGHT / 2 + 4 * next_coords[dir].y + 1,
                    2 * WIDTH + 16 * next_coords[dir].x);
            printw("%7d HP", ent->health);
        } else {
            printw("%-8s --", dir_names[dir]);
        }
    }
#if 0
    printw("                Top:     %c");
    printw("                %7d HP");
    printw("Left: %c         Player:  %c      Right: %c");
    printw("%7d HP           %7d HP      %7d HP");
    printw("                Bottom:  %c");
    printw("                %7d HP");
#endif
}
