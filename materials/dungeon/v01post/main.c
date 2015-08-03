#include <stdio.h>
#include <stdlib.h>

enum {
    WIDTH = 20,
    HEIGHT = 10
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
};

struct coord next_coords[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct entity *player = NULL;
struct entity *monster1 = NULL;
struct entity *monster2 = NULL;

void handle_input(char input, char *running);
void move_player(enum direction dir);
void draw_board();
int out_of_bounds(struct coord check);
struct entity *init_entity(int x_pos, int y_pos, int health, char symbol);

int main(int argc, char *argv[]) {
    player = init_entity(5, 8, 100, 'J');
    monster1 = init_entity(2, 3, 100, '*');
    monster2 = init_entity(9, 1, 100, '~');
    draw_board();
    for (char running = 1, input; running == 1; input = getchar()) {
        handle_input(input, &running);
        draw_board();
    }
    free(player);
    free(monster1);
    free(monster2);
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
    if (!out_of_bounds(new_pos))
        player->pos = new_pos;
}

void draw_board() {
    system("clear");
    for (int x = -1; x < WIDTH; x++)
        printf("=");
    printf("=\n");
    for (int y = 0; y < HEIGHT; y++) {
        printf("|");
        for (int x = 0; x < WIDTH; x++) {
            if (player->pos.x == x && player->pos.y == y)
                printf("%c", player->symbol);
            else if (monster1->pos.x == x && monster1->pos.y == y)
                printf("%c", monster1->symbol);
            else if (monster2->pos.x == x && monster2->pos.y == y)
                printf("%c", monster2->symbol);
            else
                printf(" ");
        }
        printf("|\n");
    }
    for (int x = -1; x < WIDTH; x++)
        printf("=");
    printf("=\n");
}

int out_of_bounds(struct coord check) {
    return check.x < 0 || check.x >= WIDTH || check.y < 0 || check.y >= HEIGHT;
}

struct entity *init_entity(int x_pos, int y_pos, int health, char symbol) {
    struct entity *new_ent = malloc(sizeof *new_ent);
    if (new_ent == NULL)
        exit(EXIT_FAILURE);
    struct coord new_pos = {x_pos, y_pos};
    if (!out_of_bounds(new_pos))
        new_ent->pos = new_pos;
    else
        exit(EXIT_FAILURE);
    new_ent->health = health;
    new_ent->symbol = symbol;
    return new_ent;
}
