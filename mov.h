#ifndef MOV_H
#define MOV_H
#include "elem.h"
#include "coll.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL2/SDL_mixer.h"
Vector reflect(Vector incident, Vector normal, float slope);
void bounce(Ball *ballp, void* o, int reverse);
void bounceV(Ball *ballp, Vector normal);
void moveBall(Ball* ball, Paddle* paddle, Mix_Chunk* chunk, Mix_Chunk* chunk2);
#endif
