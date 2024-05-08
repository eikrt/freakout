CC = gcc 
CFLAGS = -ISDL-release-2.30.3/include/ -Wall -Wextra -std=c99
LDFLAGS = -lcurl -lSDL2 -lSDL -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lm 

SRCS =  map.c util.c perlin.c draw.c coll.c elem.c mov.c main.c 
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

