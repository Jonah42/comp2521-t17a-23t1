CC=gcc
CFLAGS=-g

reach: reach.o graph.o list.o
	$(CC) reach.o graph.o list.o -o reach

reach.o: reach.c graph.h
	$(CC) $(CFLAGS) reach.c -o reach.o -c

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) graph.c -o graph.o -c

list.o: list.c list.h
	$(CC) $(CFLAGS) list.c -o list.o -c