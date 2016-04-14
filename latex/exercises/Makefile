TARGET =main
SOURCES =$(wildcard *.c)
OBJECTS =$(SOURCES:.c=.o)
DEPS =$(SOURCES:.c=.d)
CFLAGS =-Wall -Wextra -Werror -Wmissing-declarations -O3 -std=c99
LDFLAGS =-lncurses

.PHONY : clean all debug

all: $(TARGET)

debug: CFLAGS += -g
debug: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

-include $(DEPS)

%.d: %.c Makefile
	$(CC) -MM $(CFLAGS) $*.c > $*.d

clean:
	rm -f $(TARGET) $(OBJECTS) $(DEPS)

debug: CFLAGS += -g
debug: $(TARGET)
