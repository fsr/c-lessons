CFLAGS=-MMD -c -Wall -Wextra -Wmissing-prototypes -Werror -std=c99 -g
LDFLAGS=-lncurses
CC=gcc

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
DEP=$(SRC:.c=.d)
EXE=dungeon

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c Makefile
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f $(EXE) $(OBJ) $(DEP)

-include $(DEP)
