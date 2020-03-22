/*
  Copyright (C) 2015, 2016 Sergi Pasoev.

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

#include "collision.h"
#include "powerup.h"

bool colliding(struct Sprite *bullet, struct Sprite *brick){
        bool colliding = false;

        int bulletX = bullet->body.x;
        int bulletY = bullet->body.y;
        int brickX = brick->body.x;
        int brickY = brick->body.y;

        if(brick == NULL || brick->lives == 0){
                colliding = false;
        }else if(bulletX + bullet->body.w >= brickX &&
                 bulletX <= brickX + brick->body.w &&
                 bulletY + bullet->body.h >= brickY &&
                 bulletY <= brickY + brick->body.h){
                colliding = true;
        }

        return colliding;
}

void handleShipEnemyCollisions(struct Sprite *ship, List *enemies){
        ListElmt *elmt;
        for(elmt = list_head(enemies); elmt != NULL; elmt = list_next(elmt)){
                struct Sprite *enemy = list_data(elmt);
                if(colliding(ship, enemy)){
                        /* Take away one life from the ship */
                        ship->hp -= enemy->damage;
                        if(ship->hp <= 0){
                                ship->lives--;
                                ship->hp = 100;
                                SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                                            "Player died.");
                        }
                        if(ship->lives == 0){
                                SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                                            "Game over");
                                exit(EXIT_SUCCESS);
                        }
                        /* Take away one life from the enemy */
                        enemy->hp--;
                        if(enemy->hp == 0){
                                enemy->lives--;
                        }
                        if(enemy->lives == 0){
                                list_rem(enemies, elmt);
				break;
                        }
                }
        }
}

void handleShipPowerupCollisions(struct Sprite *ship, List *powerups){
        ListElmt *elmt;
        for(elmt = list_head(powerups); elmt != NULL; elmt = list_next(elmt)){
                struct Sprite *powerup = list_data(elmt);
                if(colliding(ship, powerup)){
                        /* Activate the powerup for the ship */
                        activatePowerup(ship, powerup);
                        list_rem(powerups, elmt);
			break;
                }
        }
}

int handleBulletBrickCollisions(List *bullets, List *bricks){
        ListElmt *bulletElmt = list_head(bricks);
        ListElmt *brickElmt = list_head(bricks);
        for(bulletElmt = list_head(bullets); bulletElmt != NULL; bulletElmt = list_next(bulletElmt)){
                struct Sprite *bullet = list_data(bulletElmt);
                for(brickElmt = list_head(bricks); brickElmt != NULL; brickElmt = list_next(brickElmt)){
                        struct Sprite *brick = list_data(brickElmt);
                        if(colliding(bullet, brick)){
                                /* Reduce brick HP */
                                brick->hp -= bullet->damage;
                                /* Kill the brick if no hp left */
                                if(brick->hp <= 0){
                                        brick->lives--;
                                        brick->hp = 3;
                                }

                                /* Delete bullet */
                                list_rem(bullets, bulletElmt);
                                if(brick->lives == 0){
                                        /* Delete brick */
                                        list_rem(bricks, brickElmt);
                                        SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION
                                                    ,"Enemy defeated. Remaining: %d\n",
                                                    list_size(bricks));
                                }
                                return true;
                        }
                }
        }
        return false;
}
