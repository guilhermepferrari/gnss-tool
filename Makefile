CC = gcc
CFLAGS = -Wall -Iinclude

SRCS = src/main.c \
       src/coord.c \
       src/dop.c \
       src/gnssutils.c \
       src/orbit.c \
       src/pseudorange.c \
       src/rinex.c

OBJS = $(SRCS:.c=.o)

gnss-tool: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -lm

clean:
	rm -f src/*.o gnss-tool

