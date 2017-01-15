PREFIX=/usr/
CC=gcc
W=-Wall -Wextra -Wstrict-prototypes -Wshadow -Wwrite-strings \
-Wold-style-definition -Wredundant-decls -Wnested-externs \
-Wmissing-include-dirs
CFLAGS=-p -g $(W)

blasteroids : $(objects)
	$(CC) $(CFLAGS) -c list.c $(objects)

list.o : list.h

.PHONY : cleano

install :
	cp ./list.o $(PREFIX)/bin

clean :
	rm list.o $(objects)
