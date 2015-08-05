#include <stdio.h>
#include <ncurses.h>
#include "io.h"
#include "globals.h"
#include "board.h"
#include "datastructures.h"

void init_term(void) {
    initscr();
    curs_set(0);
    start_color();
    clear();
    noecho();
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
    refresh();
}

void print_entity(struct entity *ent) {
    move(ent->pos.y + 1, ent->pos.x + 1);
    printw("%c", ent->symbol);
    move(HEIGHT + 2, 0);
}
