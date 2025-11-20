CC = gcc
LFLAGS = -lm

SOURCES = $(wildcard *.c)
OBJECTS = $(subst .c,.o,$(SOURCES))

.PHONY: clean

all : histogram

histogram : histogram.o 
	$(CC) -o histogram $(OBJECTS) $(LFLAGS) 

%.o : %.c 
	$(CC) -c $< 
clean:
	rm $(OBJECTS) histogram

