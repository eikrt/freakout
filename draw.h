#ifndef DRAW_H
#define DRAW_H
#include "elem.h" 
#include "perlin.h" 
#include "sys/time.h"
#include "util.h"
#include <SDL2/SDL.h>
#include <math.h>


static unsigned short int BASIC_TILE_BITMAP[][3] = {
    {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00}, {0x00,0x00,0x00},
    {0x00,0x00,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0xff},
    {0x00,0x00,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0xff},
    {0x00,0x00,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0xff},
    {0x00,0x00,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0xff},
    {0x00,0x00,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00},
    {0x00,0x00,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0xff},
    {0x00,0x00,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0xff},
    {0x00,0x00,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0xff},
    {0x00,0x00,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00},
    {0x00,0x00,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0xff},
    {0x00,0x00,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0xff},
    {0x00,0x00,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0xff},
    {0x00,0x00,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0xff},
    {0x00,0x00,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00},
    {0x00,0x00,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0xff},
    {0x00,0x00,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0x00}, {0xff,0xff,0xff},

};
void drawTile(Tile* tile, SDL_Renderer* renderer);
void drawBG(SDL_Renderer* renderer);
void initPerlin();
#endif 
