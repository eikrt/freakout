emcc util.c perlin.c draw.c coll.c elem.c mov.c main.c -c -sFETCH -s USE_SDL=2 -s USE_SDL_MIXER=2 -s USE_SDL_IMAGE=2 -s USE_SDL_TTF=2 
emcc util.o perlin.o draw.o coll.o elem.o mov.o main.o -s -sFETCH -s USE_SDL=2 -USE_SDL_MIXER=2 -s USE_SDL_IMAGE=2 -s USE_SDL_TTF=2 -sALLOW_MEMORY_GROWTH -sASYNCIFY -o freakout.html --use-preload-plugins --preload-file assets/

