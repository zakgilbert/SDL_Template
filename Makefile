SRCS = $(shell find -name '*.c')
OBJS = $(SRCS:.c=.o)
EXEC = prg
CFLAGS := -Wall -ggdb3 -fcommon
LDFLAGS := `sdl2-config --libs --cflags` -lSDL2_image -lSDL2_ttf -lm

CC = gcc
$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJS): $(SRCS)
	$(CC) -c $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJS) $(EXEC)