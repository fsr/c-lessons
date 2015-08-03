#ifndef IO_H
#define IO_H
#include "datastructures.h"

void init_term(void);
void draw_board(void);
void print_entity(struct entity *ent);
void flash_entity(struct entity *ent);
void print_info(void);
#endif
