#ifndef MAIN_H
#define MAIN_H
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"
#include "elem.h"
#include "mov.h"
#ifdef __EMSCRIPTEN__
#else
#include <curl/curl.h>
#endif
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "coll.h"
#include "draw.h"
#include "elem.h"
#include "map.h"
#include "perlin.h"
#include "sys/time.h"
#include "util.h"
#endif
