#include "draw.h"

static unsigned short int PERLIN_MAP[640*360][3]; 
void initPerlin() {
        for (int i = 0; i < SCREEN_WIDTH-1; i++) {
            for (int j = 0; j < SCREEN_HEIGHT-1; j++) {
                double p = perlin2d(i, j, 0.2f, (int)(10)); 
                unsigned int r = (int)(0xf0 * p); 
                unsigned int g = (int)(0xf0 * p); 
                unsigned int b = (int)(0xf0 * p); 
                PERLIN_MAP[j * SCREEN_WIDTH + i][0] = r;
                PERLIN_MAP[j * SCREEN_WIDTH + i][1] = g;
                PERLIN_MAP[j * SCREEN_WIDTH + i][2] = b;
            } 
        } 
}
long long currentTimeStamp() {
    struct timeval te; 
    gettimeofday(&te, NULL); // Get current time
    long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000; // Calculate milliseconds
    return milliseconds;
}
void drawTile(Tile* tile, SDL_Renderer* renderer, SDL_Texture* tex) {
        SDL_Rect tileR = { tile->p.x, tile->p.y, 32, 16 }; // x, y, width, height
        SDL_RenderCopy(renderer, tex, NULL, &tileR); 
}
void drawBG(SDL_Renderer* renderer) {
        #ifdef __EMSCRIPTEN__
            return;
        #endif
        return;
        time_t t;
        time(&t);
        srand(time(NULL));
        int pxscale = 8;
        float scale = sin(currentTimeStamp());
        for (int i = 0; i < SCREEN_WIDTH / 8; i++) {
            for (int j = 0; j < SCREEN_HEIGHT / 8; j++) {
                SDL_Rect tileR = {i*pxscale, j*pxscale, 1*pxscale, 1*pxscale }; // x, y, width, height
                unsigned int r = PERLIN_MAP[i][0];
                unsigned int g = PERLIN_MAP[i][1];
                unsigned int b = PERLIN_MAP[i][2];
                SDL_SetRenderDrawColor(renderer, r, g, b, 255);
                SDL_RenderFillRect(renderer, &tileR);
            } 
        } 
}
