#ifndef MOV_H
#define MOV_H
#include "elem.h"
#include "coll.h"
#include <stdio.h>
#include "SDL2/SDL_mixer.h"
Vector reflect(Vector incident, Vector normal);
void bounce(Ball *ballp, void* o);
void bounceV(Ball *ballp, Vector normal);
void moveBall(Ball* ball, Paddle* paddle, Mix_Chunk* chunk);
#endif
