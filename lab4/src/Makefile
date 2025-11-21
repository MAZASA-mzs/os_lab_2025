CC=gcc
CFLAGS=-I. -g

all: parallel_min_max process_memory zombie parallel_sum

# Задание 1:
parallel_min_max: utils.o find_min_max.o parallel_min_max.c
	$(CC) -o parallel_min_max utils.o find_min_max.o parallel_min_max.c $(CFLAGS)

utils.o: utils.h utils.c
	$(CC) -o utils.o -c utils.c $(CFLAGS)

find_min_max.o: utils.h find_min_max.h find_min_max.c
	$(CC) -o find_min_max.o -c find_min_max.c $(CFLAGS)

# Задание 2:
zombie: zombie.c
	$(CC) -o zombie zombie.c $(CFLAGS)

# Задание 3:
process_memory: process_memory.c
	$(CC) -o process_memory process_memory.c $(CFLAGS)

# Задание 5:
sum.o: sum.h sum.c
	$(CC) -o sum.o -c sum.c $(CFLAGS)

parallel_sum: utils.o sum.o parallel_sum.c
	$(CC) -o parallel_sum utils.o sum.o parallel_sum.c -lpthread $(CFLAGS)

clean:
	rm -f *.o parallel_min_max process_memory zombie parallel_sum