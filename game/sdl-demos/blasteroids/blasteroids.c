/*

  Copyright (C) 2013, 2014 Sergi Pasoev.

  This pragram is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or (at
  your option) any later version.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.

  Written by Sergi Pasoev <s.pasoev@gmail.com>

*/

#include "blasteroids.h"
#include "collision.h"

enum KEYS {
  UP, RIGHT, DOWN, LEFT, SPACE
};
  
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;

/* There is no plain black sky in the galaxy */

Point stars[3][NUM_STARS/3];
float speeds[3] = { 0.0001f, 0.05f, 0.15f };
ALLEGRO_COLOR colors[3];
long start, now, elapsed, frame_count;
int total_frames = 0;
double program_start;
double length;
int layer, star;

const float PROGRAM_VERSION = 0.1;
const char* HELP = "Use the arrow keys to fly the ship, \
hit SPACE to fire.";

int main(int argc, char *argv[]){

  int c;
  
  while((c = getopt(argc, argv, "hv")) != -1){
    switch(c){
    case 'h':
      puts(HELP);
      return 0;
    case 'v':
      printf("version %.1f\n", PROGRAM_VERSION);
      return 0;
    }
  }
		
  if(!al_init()){
    fprintf(stderr, "failed to initialize allegro!\n");
    return -1;
  }

  if(argc == 2 && !strcmp(argv[1], "-v")){
    printf("version %.1f\n", PROGRAM_VERSION);
    return 0;
  }

  bool key[5] = {false, false, false, false, false};
  bool doexit = false;  
  bool redraw = true;

  timer = al_create_timer(1.0 / FPS);
  if(!timer){
    fprintf(stderr, "couldn't initialize timer.\n");
    return -1;
  }

  display = al_create_display(SCREEN_W, SCREEN_H);
  if(!display){
    fprintf(stderr, "failed to create the display.\n");
    al_destroy_timer(timer);

    return -1;
  }
  
  al_set_window_title(display, "blasteroids");
  
  al_init_primitives_addon();
  
  if(!al_install_keyboard()){
    fprintf(stderr, "failed to initialize keyboard.\n");
    al_destroy_display(display);
    al_destroy_timer(timer);

    return -1;
  }

  /* Making the sky look like sky */

  colors[0] = al_map_rgba(255, 100, 255, 128);
  colors[1] = al_map_rgba(255, 100, 100, 255);
  colors[2] = al_map_rgba(100, 100, 255, 255);
         
  for (layer = 0; layer < 3; layer++) {
    for (star = 0; star < NUM_STARS/3; star++) {
      Point *p = &stars[layer][star];
      p->x = rand() % SCREEN_W;
      p->y = rand() % SCREEN_H;
    }
  }


  start = al_get_time() * 1000;
  now = start;
  elapsed = 0;
  frame_count = 0;
  program_start = al_get_time();

   
   /* done with the sky. Now making the ship. */ 
  Spaceship *ship = init_ship();
  List *a = (List *)summon_asteroids(NUMBER_ASTEROIDS);
  ListElmt *astElmt = list_head(a);


  if(!ship){
    fprintf(stderr, "couldn't create bitmap.\n");
    al_destroy_timer(timer);
    al_destroy_display(display);
    return -1;
  }

  Blast *blast = init_blast(ship->sx, ship->sy, ship->heading);

  event_queue = al_create_event_queue();
  if(!event_queue){
    fprintf(stderr, "failed to create event queue.\n");
    al_destroy_display(display);
    al_destroy_timer(timer);
    return -1;
  }

  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  
  al_start_timer(timer);

  while(!doexit){
    /* animate the sky, just sky, starts, but NOT objects. */
    
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
          
    if(ev.type == ALLEGRO_EVENT_TIMER){

      if(key[UP])
	ship->speed += 0.04;

      if(key[RIGHT])
	ship->heading += 1.0f;

      if(key[DOWN])
	if(ship->speed > 0.05)
	  ship->speed -= 0.04;

      if(key[LEFT])
	ship->heading -= 1.0f;

      fly_ship(ship);
      // fire ze missile

      if(key[SPACE]){
	blast->sx = ship->sx;
	blast->sy = ship->sy;
	blast->heading = ship->heading;
	blast->gone = 0;
      }
      
      float theta = head2theta(blast->heading);
      blast->sx += blast->speed * cos(theta);
      if(blast->sx <= 0 || blast->sx >= SCREEN_W){
	blast->gone = 1;
      }

      blast->sy += blast->speed * sin(theta);
      if(blast->sy <= 0 || blast->sy >= SCREEN_H){
	blast->gone = 1;
      }

      /* loop through the list of asteroids */
      
      astElmt = (astElmt->next)?astElmt->next : list_head(a);
      Asteroid *aster = astElmt->aster;

      /* asteroid eternity */
      if(aster->sx < 0 || aster->sx > SCREEN_W - 33)
	aster->sx = 0;
	  
      if(aster->sy < 0 || aster->sy > SCREEN_H)
	aster->sy = 0;


      
      aster->twist += aster->rot_velocity; 
	  
      /* Fuzzy movement */ 
      if((int)aster->sx % 3 == 0)
	aster->sx += aster->speed;
      aster->sx += 0.9;
      if((int)aster->sy % 5 == 3)
	aster->sy += aster->speed;
      aster->sy += 0.9;

      aster->twist += 0.4;

      /* detect alteroid collision, but only if 5 seconds have
       passed since the last Death */

      Box s = {{ship->sx, ship->sy}, 16.0f, 20.0f};
      Box a = {{aster->sx, aster->sy}, 45.0f, 40.0f};

      if(ship->heading != -90.0f){
	if(!aster->gone && !ship->gone && is_collision(&s, &a)){
	  ship->color = al_map_rgb(0, 0, 255);
	}
      }
      
      /* detect asteroid being shot */

      Box b = {{blast->sx, blast->sy}, 120.0f, 3.0f};
      if(!(blast->gone) && !(aster->gone) && is_collision(&b, &a)){
	aster->gone = 1;
	}
      redraw = true;
   }
    else if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
	  
      switch(ev.keyboard.keycode){
      case ALLEGRO_KEY_UP:
	key[UP] = true;
	break;
      case ALLEGRO_KEY_RIGHT:
	key[RIGHT] = true;
	break;
      case ALLEGRO_KEY_DOWN:
	key[DOWN] = true;
	break;
      case ALLEGRO_KEY_LEFT:
	key[LEFT] = true;
	break;
      case ALLEGRO_KEY_SPACE:
	key[SPACE] = true;
	break;
      }
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_UP){
      switch(ev.keyboard.keycode){
      case ALLEGRO_KEY_UP:
	key[UP] = false;
	break;
      case ALLEGRO_KEY_RIGHT:
	key[RIGHT] = false;
	break;
      case ALLEGRO_KEY_DOWN:
	key[DOWN] = false;
	break;
      case ALLEGRO_KEY_LEFT:
	key[LEFT] = false;
	break;
      case ALLEGRO_KEY_SPACE:
	key[SPACE] = false;
	break;
      case ALLEGRO_KEY_Q:
      case ALLEGRO_KEY_ESCAPE:
	doexit = true;
	break;
      }
    } 
    
    if(redraw && al_is_event_queue_empty(event_queue)){
      redraw = false;
      al_clear_to_color(al_map_rgb(0, 0, 0));

      if (frame_count < (1000/TARGET_FPS)) {
	frame_count += elapsed;
      }
      else {
	int X, Y;

	frame_count -= (1000/TARGET_FPS);

	for (star = 0; star < NUM_STARS/3; star++) {
	  Point *p = &stars[0][star];
	  al_draw_pixel(p->x, p->y, colors[0]);
	}
	/*	al_lock_bitmap(al_get_backbuffer(display), ALLEGRO_PIXEL_FORMAT_ANY, 0); */

	for (layer = 1; layer < 3; layer++) {
	  for (star = 0; star < NUM_STARS/3; star++) {
	    Point *p = &stars[layer][star];
	    // put_pixel ignores blending
	    al_put_pixel(p->x, p->y, colors[layer]);
	  }
	}

	/* Check that dots appear at the window extremes. */
	X = SCREEN_W - 1;
	Y = SCREEN_H - 1;
	al_put_pixel(0, 0, al_map_rgb_f(1, 1, 1));
	al_put_pixel(X, 0, al_map_rgb_f(1, 1, 1));
	al_put_pixel(0, Y, al_map_rgb_f(1, 1, 1));
	al_put_pixel(X, Y, al_map_rgb_f(1, 1, 1));

	/* al_unlock_bitmap(al_get_backbuffer(display)); */
	total_frames++;
      }

      now = al_get_time() * 1000;
      elapsed = now - start;
      start = now;

      for (layer = 0; layer < 3; layer++) {
	for (star = 0; star < NUM_STARS/3; star++) {
	  Point *p = &stars[layer][star];
	  p->y -= speeds[layer] * elapsed;
	  if (p->y < 0) {
	    p->x = rand() % SCREEN_W;
	    p->y = SCREEN_H;
	  }
	}
      }
      draw_ship(ship);

      if(!blast->gone){
	draw_blast(blast);
      }
      draw_asteroids(a);
      al_flip_display();
    }
  }

  length = al_get_time() - program_start;

  /* printf("Length = %f\n", length); */

  al_destroy_timer(timer);
  al_destroy_display(display);
  al_destroy_event_queue(event_queue);

  return 0;
}

void change_color(ALLEGRO_BITMAP *obj, ALLEGRO_COLOR color, ALLEGRO_BITMAP *context){
  al_set_target_bitmap(obj);
  al_clear_to_color(color);
  al_set_target_bitmap(context);
  al_flip_display();
}
