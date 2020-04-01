PREFIX=/usr/
CC=gcc
W=-Wall -Wextra -Wstrict-prototypes -Wshadow -Wwrite-strings \
-Wold-style-definition -Wredundant-decls -Wnested-externs \
-Wmissing-include-dirs
CFLAGS=-lallegro -lallegro_primitives -lm -p -g $(W)
objects = blasteroids.o spaceship.o asteroid.o blast.o list.o collision.o

blasteroids : $(objects)
	$(CC) $(CFLAGS) -o blasteroids $(objects)

blasteroids.o : blasteroids.h collision.h

spaceship.o : blasteroids.h

asteroid.o : blasteroids.h

blast.o : blasteroids.h

list.o : list.h

collision.o : collision.h

.PHONY : cleano

run :
	./blasteroids

install :
	cp ./blasteroids $(PREFIX)/bin

clean :
	rm blasteroids $(objects)
