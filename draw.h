#ifndef DRAW_H
#define DRAW_H
#include "util.h"
#include "elem.h"
#include "perlin.h"
#include "SDL2/SDL.h"
void drawTile(Tile* tile, SDL_Renderer* renderer, SDL_Texture* tex);
void drawBG(SDL_Renderer* renderer);
void initPerlin();
#endif
