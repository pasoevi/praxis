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

#include "blasteroids.h"

Asteroid* init_asteroid(Position pos){
  /* structs can be taken by pointers later */
  static Asteroid *evil;
  evil = (Asteroid *)malloc(sizeof(Asteroid));
  evil->sx = pos.x;
  evil->sy = pos.y;
  evil->heading = .4f;
  evil->twist = 4;
  evil->speed = 1.4;
  evil->rot_velocity = 4;
  evil->scale = 1.7;
  evil->gone = 0;
  evil->color = al_map_rgb(255, 255, 255);

  return evil;
}

List* summon_asteroids(int number){
  static List asteroids;
  list_init(&asteroids, &destroy_asteroid);

  ListElmt *anchor; 
  static Asteroid *aster;
  struct Position position = {0, 0};
  aster = init_asteroid(position);
  list_ins_next(&asteroids, NULL, aster);
  for(anchor = list_head(&asteroids); list_size(&asteroids) < number; anchor = list_next(anchor)){
    position.x = random() % 1024;
    position.y = random() % 768;

    /* printf("Random position # %d : %f %f\n", list_size(&asteroids), */
    /* 	   position.x, position.y); */
    static Asteroid *aster;
    aster = init_asteroid(position);
    list_ins_next(&asteroids, anchor, aster);
  }
  return &asteroids;
}

void draw_asteroids(List *asteroids){
  ListElmt *ast;

  for(ast = list_head(asteroids); ast != NULL; ast = list_next(ast)){

    ALLEGRO_TRANSFORM transform;

    Asteroid *a;
    if(list_next(ast) != NULL){
      a = list_next(ast)->aster;
    }else{
      a= ast->aster;
    }


    if(a->gone){
      /* if the asteroid is small, kill it */
      if(a->scale <= 1){
	/* TODO: it's hiding now! it's still in memory, 
	   it needs to be removed! */
	printf("Asteroids left: %d\n", list_size(asteroids));
	if(ast != NULL){
	  list_rem_next(asteroids, ast, a);
	}
	int scale = a->scale;
	printf("Asteroid scale: %d\n", scale);
	printf("Asteroids left: %d\n", list_size(asteroids));
      }else{
	int scale = a->scale;
	/* split it */
	printf("Asteroid scale: %d\n", scale);
	Position bpos = {a->sx + 25, a->sy + 25};
	Asteroid *b;
	b = init_asteroid(bpos);
	b->speed += 1.9;
	b->gone = 0;
	b->scale /= 2;
	list_ins_next(asteroids, ast, b);
	a->gone = 0;
	a->scale /= 2;
	printf("Asteroid scale: %d\n", scale);
      }
    }

    al_identity_transform(&transform);
    al_rotate_transform(&transform, a->twist);
    al_scale_transform(&transform, a->scale, a->scale);
    al_translate_transform(&transform, a->sx, a->sy);
    al_use_transform(&transform);

    al_draw_line(-20, 20, -25, 5, a->color, 2.0f);
    al_draw_line(-25, 5, -25, -10, a->color, 2.0f);
    al_draw_line(-25, -10, -5, -10, a->color, 2.0f);
    al_draw_line(-5, -10, -10, -20, a->color, 2.0f);
    al_draw_line(-10, -20, 5, -20, a->color, 2.0f);
    al_draw_line(5, -20, 20, -10,  a->color, 2.0f);
    al_draw_line(20, -10, 20, -5, a->color, 2.0f);
    al_draw_line(20, -5, 0, 0, a->color, 2.0f);
    al_draw_line(0, 0, 20, 10, a->color, 2.0f);
    al_draw_line(20, 10, 10, 20, a->color, 2.0f);
    al_draw_line(10, 20, 0, 15, a->color, 2.0f);
    al_draw_line(0, 15, -20, 20, a->color, 2.0f);

  }
}

void destroy_asteroid(void *aster){
  /* free memory */
}
    
