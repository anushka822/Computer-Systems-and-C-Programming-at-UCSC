CC= gcc
LFLAGS = -Wall -Wextra -Wpedantic

SOURCE= ll_cycle.c test_ll_cycle.c
OBJ= ll_cycle.o test_ll_cycle.o
HEADER= ll_cycle.h 

ll_cycle: ${OBJ} ${HEADER}
	$(CC) $(OBJ) -o check_cycle $(LFLAGS) 

%.o: %.c $(HEADER)
	$(CC) $< -c

clean:
	rm -rf check_cycle
	rm -rf *.o
