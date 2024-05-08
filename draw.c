#include "draw.h"

void drawTile(Tile* tile, SDL_Renderer* renderer, SDL_Texture* tex) {
        SDL_Rect tileR = {tile->p.x, tile->p.y, 32, 16};  // x, y, width, height
        SDL_RenderCopy(renderer, tex, NULL, &tileR);
}
void drawBG(SDL_Renderer* renderer) {
#ifdef __EMSCRIPTEN__
        return;
#endif
        return;
}
