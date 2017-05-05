/*

  Copyright (C) 2013 Sergi Pasoev.

  This pragram is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.

  Written by Sergi Pasoev <s.pasoev@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include "list.h"

#define BOUNCER_SIZE 64
#define FPS 80
#define NUM_STARS 600
#define TARGET_FPS 900
#define SCREEN_W 1024
#define SCREEN_H 768
#define NUMBER_ASTEROIDS 10
#define ORIGIN_X (SCREEN_W / 2)
#define ORIGIN_Y (SCREEN_H / 2)

typedef struct{
  float sx;
  float sy;
  float heading;
  float speed;
  int gone;
  ALLEGRO_COLOR color;
  ALLEGRO_BITMAP *bitmap;
} Spaceship;

typedef struct {
  float sx;
  float sy;
  float heading;
  float speed;
  int gone;
  ALLEGRO_COLOR color;
} Blast;

typedef struct aster {
  float sx;
  float sy;
  float heading;
  float twist;
  float speed;
  float rot_velocity;
  float scale;
  int gone;
  ALLEGRO_COLOR color;
} Asteroid;

typedef struct Position {
  float x;
  float y;
} Position;

void draw_asteroids(List *);
Spaceship *init_ship(void);
void draw_ship(Spaceship *);
void fly_ship(Spaceship* ship);
Blast *init_blast(float, float, float);
void draw_blast(Blast *);
void destroy_asteroid(void *aster);
List* summon_asteroids(int);
void change_color(ALLEGRO_BITMAP *, ALLEGRO_COLOR, ALLEGRO_BITMAP *);
void destroy_resources(void);
float head2theta(float heading);
