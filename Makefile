CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDLIBS = -lm

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
BIN := program

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BIN)
