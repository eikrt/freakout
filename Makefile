CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lSDL2 -lm

SRCS = util.h perlin.c draw.c coll.c elem.c mov.c main.c 
OBJS = $(SRCS:.c=.o)
	EXEC = freakout 

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	    $(CC) $(CFLAGS) $(OBJS) -o $(EXEC) $(LDFLAGS)

%.o: %.c
	    $(CC) $(CFLAGS) -c $< -o $@

clean:
	    rm -f $(EXEC) $(OBJS)

