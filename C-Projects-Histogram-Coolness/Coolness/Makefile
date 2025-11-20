CC = gcc
LFLAGS = -lm

SOURCES = $(wildcard *.c)
OBJECTS = $(subst .c,.o,$(SOURCES))

.PHONY: clean

all : coolness

coolness : coolness.o
	$(CC) -o coolness $(OBJECTS) $(LFLAGS) 

%.o : %.c
	$(CC) -c $< 
clean:
	rm $(OBJECTS) coolness

