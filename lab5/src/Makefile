CC = gcc
CFLAGS = -Wall
LIBS = -lpthread

all: mutex_unsafe mutex_safe factorial deadlock

mutex_unsafe: mutex.c
	$(CC) $(CFLAGS) -o mutex_unsafe mutex.c $(LIBS)

mutex_safe: mutex.c
	$(CC) $(CFLAGS) -DUSE_MUTEX -o mutex_safe mutex.c $(LIBS)

factorial: factorial.c
	$(CC) $(CFLAGS) -o factorial factorial.c $(LIBS)

deadlock: deadlock.c
	$(CC) $(CFLAGS) -o deadlock deadlock.c $(LIBS)

clean:
	rm -f mutex_unsafe mutex_safe factorial deadlock