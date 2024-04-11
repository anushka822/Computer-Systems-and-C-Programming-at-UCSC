CC= gcc
LFLAGS = -Wall -Wextra -Wpedantic

SOURCE= growing_arrays.c test_growing_arrays.c
OBJ= growing_arrays.o test_growing_arrays.o
HEADER= growing_arrays.h 

ll_cycle: ${OBJ} ${HEADER}
	$(CC) $(OBJ) -o growing_arrays $(LFLAGS) 

%.o: %.c $(HEADER)
	$(CC) $< -c

clean:
	rm -rf growing_arrays
	rm -rf *.o