CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c18 -ggdb
LFLAGS = -lm -lcurl


# Not helpful in this case :(
# SRC = $(wildcard *.c)
# OBJ = $(subst .c,.o,$(SRC))
SOURCES = $(wildcard *.c)
OBJECTS = $(subst .c,.o,$(SOURCES))
HEADER = crawler.h


.PHONY: clean

all : crawler
# Specifying exactly what foo needs
crawler: $(OBJECTS)
	$(CC) -o  crawler $(OBJECTS) $(CFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f crawler $(OBJECTS)