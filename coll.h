#include "elem.h" 
#include "mov.h" 
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#ifndef COLL_H
#define COLL_H
int collideWith(Ball* t, Paddle* o);
int collideWithTile(Ball* t, Tile* other, Mix_Chunk* chunk); 
#endif 
