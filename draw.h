#ifndef DRAW_H
#define DRAW_H
#include "elem.h" 
#include "perlin.h" 
#include "sys/time.h"
#include "util.h"
#include <SDL2/SDL.h>
#include <math.h>

void drawTile(Tile* tile, SDL_Renderer* renderer, SDL_Texture* tex);
void drawBG(SDL_Renderer* renderer);
void initPerlin();
#endif 
