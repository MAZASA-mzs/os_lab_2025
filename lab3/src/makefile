CC=gcc
CFLAGS=-I.

all: sequential_min_max parallel_min_max launcher

sequential_min_max : utils.o find_min_max.o utils.h find_min_max.h sequential_min_max.c
	$(CC) -o sequential_min_max find_min_max.o utils.o sequential_min_max.c $(CFLAGS)

parallel_min_max : utils.o find_min_max.o utils.h find_min_max.h parallel_min_max.c
	$(CC) -o parallel_min_max utils.o find_min_max.o parallel_min_max.c $(CFLAGS)

launcher: launcher.c sequential_min_max
	$(CC) -o launcher launcher.c $(CFLAGS)

utils.o : utils.c utils.h
	$(CC) -o utils.o -c utils.c $(CFLAGS)

find_min_max.o : find_min_max.c utils.h find_min_max.h
	$(CC) -o find_min_max.o -c find_min_max.c $(CFLAGS)

clean :
	rm -f utils.o find_min_max.o sequential_min_max parallel_min_max launcher