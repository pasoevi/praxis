CC=gcc
CFLAGS=-lm --std=c99 -g

demos : main.o issort.o qsort.o bisearch.o robotour.o
	$(CC) -o demos main.o issort.o qsort.o bisearch.o robotour.o $(CFLAGS)

main.o : main.c robotour.h search.h sort.h
	$(CC) -c main.c
issort.o : issort.c sort.h
	$(CC) -c issort.c
qsort.o : qsort.c sort.h search.h
	$(CC) -c qsort.c
bisearch.o : bisearch.c search.h
	$(CC) -c bisearch.c
robotour.o : robotour.c
	$(CC) -c robotour.c
clean :
	rm demos main.o issort.o qsort.o bisearch.o robotour.o
