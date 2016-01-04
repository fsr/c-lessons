TARGET =main
SOURCES =datastructures.c io.c main.c
OBJECTS =$(SOURCES:.c=.o)
DEPS =$(SOURCES:.c=.d)
CFLAGS =-Wall -Wextra -Werror -Wmissing-declarations -O3 -std=c99

all: $(TARGET)

debug: CFLAGS += -g
debug: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c Makefile
	$(CC) -MMD -c $(CFLAGS) -o $@ $<

.PHONY : clean all debug
clean:
	rm -f $(TARGET) $(OBJECTS) $(DEPS)

-include $(DEPS)
