#ifndef COLL_H
#define COLL_H
#include "elem.h"
#include "SDL2/SDL_mixer.h"
int collideWith(Ball* t, Paddle* o);
int collideLaserWithTile(Ball* ball, Projectile* this, Tile* other,
                         Mix_Chunk* chunk);
int collideWithTile(Ball* t, Tile* other, Mix_Chunk* chunk);
int collidePaddleWithTile(Paddle* this, Tile* other, Mix_Chunk* chunk);
int checkTileStatus(Tile* other);
#endif
