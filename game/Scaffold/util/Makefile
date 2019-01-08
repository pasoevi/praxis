PREFIX=/usr/
CC=gcc
W=-Wall -Wextra -Wstrict-prototypes -Wshadow -Wwrite-strings \
-Wold-style-definition -Wredundant-decls -Wnested-externs \
-Wmissing-include-dirs -Wstrict-aliasing
CFLAGS=-O -I/usr/include/libxml2 -lSDL2 -lSDL2_image -lSDL2_gfx -lSDL2_ttf -lm -g $(W) -lxml2 
objects = list.o yxml.o parselvl.o fsm.o geometry.o sprite.o ledge.o enemy.o player.o text.o texture.o scaffold.o menustate.o playstate.o pausestate.o gameoverstate.o

scaffold : $(objects)
	$(CC) $(CFLAGS) -o scaffold $(objects)

list.o : list.h
yxml.o : yxml.h
parselvl.o: parselvl.h
gameoverstate.o : gamestate.h texture.h geometry.h
geometry.o : geometry.h
menustate.o : gamestate.h texture.h geometry.h
pausestate.o : gamestate.h texture.h geometry.h
ledge.o : ledge.h texture.h
enemy.o : enemy.h
player.o: player.h
playstate.o : gamestate.h text.h texture.h geometry.h player.h sprite.h
scaffold.o : list.h scaffold.h gamestate.h
fsm.o : gamestate.h geometry.h list.h
sprite.o : sprite.h geometry.h
text.o : text.h
texture.o : texture.h

.PHONY : cleano

run :
	./scaffold

install :
	cp ./scaffold $(PREFIX)/bin

clean :
	rm scaffold $(objects)
