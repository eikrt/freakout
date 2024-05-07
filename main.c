#include "main.h"
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
SDL_Window *window;
SDL_Renderer *renderer;
int level = 0;
int tilesLeft = 0;
int score = 0;
int lives = 3;
Ball ball = {
        {320, 340}, {8, 8}, StickOnce, 4.0, {1.0,1.0},0,0
};

Paddle paddle = {
        {320, 340}, {64, 16}, StickOnce, 2.0, 0.0, 64,0 
};
static const int projectilesSize = 16;
Projectile projectiles[16]; 
int projIndex = 0;
Tile tiles[20*16];
int running = 1;
int levelTransparency = 255;
void explode(Tile* tile, Mix_Chunk* explosionPing) {

        Mix_PlayChannel(-1, explosionPing, 0);
        int tileX = tile->p.x / 32;
        int tileY = tile->p.y / 16;
        tiles[tileX + tileY * MAP_WIDTH].alive = 0;
        if (tileX > 0 && tileX < MAP_WIDTH - 1) {
            if (tiles[(tileX+1) + tileY * MAP_WIDTH].alive == 1 && tiles[(tileX+1) + tileY * MAP_WIDTH].ttype == Explosion) { 
                    explode(&tiles[(tileX+1) + tileY * MAP_WIDTH], explosionPing);
            }
            if (tiles[(tileX-1) + tileY * MAP_WIDTH].alive == 1 && tiles[(tileX-1) + tileY * MAP_WIDTH].ttype == Explosion) { 
                    explode(&tiles[(tileX-1) + tileY * MAP_WIDTH], explosionPing);
            }
            tiles[(tileX-1) + tileY * MAP_WIDTH].alive = 0;
            tiles[(tileX+1) + tileY * MAP_WIDTH].alive = 0;
        }

        if (tileY > 0 && tileY < MAP_HEIGHT) {
            if (tiles[(tileX) + (tileY+1) * MAP_WIDTH].alive == 1 && tiles[(tileX) + (tileY+1) * MAP_WIDTH].ttype == Explosion) { 
                    explode(&tiles[(tileX) + (tileY+1) * MAP_WIDTH], explosionPing);
            }
            if (tiles[(tileX) + (tileY-1) * MAP_WIDTH].alive == 1 && tiles[(tileX) + (tileY-1) * MAP_WIDTH].ttype == Explosion) { 
                    explode(&tiles[(tileX) + (tileY-1) * MAP_WIDTH], explosionPing);
            }
            tiles[tileX + (tileY - 1) * MAP_WIDTH].alive = 0;
            tiles[tileX + (tileY + 1) * MAP_WIDTH].alive = 0;
        }                             
}
void initTiles() {
        int row=0;
        int col=0;
        tilesLeft = 0;
        for (int i = 0; i < MAP_HEIGHT * MAP_WIDTH; i++) {
                TileType ttype = Def;
                int hits = 1;
                if (col >= MAP_WIDTH) {
                        col = 0;
                        row++;
                }
                if (levels[level][col + row * MAP_WIDTH] == 't') {
                    hits = 3;
                    ttype = Three;
                }
                else if (levels[level][col + row * MAP_WIDTH] == 'I') {
                    hits = 16;
                    ttype = Invulnerable;
                }
                else if (levels[level][col + row * MAP_WIDTH] == 'i'){
                    hits = 2;
                    ttype = Invisible;
                }
                else if (levels[level][col + row * MAP_WIDTH] == 'e'){
                    hits = 1;
                    ttype = Explosion;
                }
                else if (levels[level][col + row * MAP_WIDTH] == ' '){
                    ttype = Nonexistent;
                }
                if (ttype != Nonexistent) {
                }
                Tile tile = {
                        {
                            col * 32, row * 16 
                        },
                        {
                            32, 16 
                        },
                        {0,0},
                        ttype,
                        DefBuff,
                        DefaultStatus,
                        hits,
                        1,
                };
                col++;
                tiles[i] = tile;
        }
}
void softenBricks() {
        int row=0;
        int col=0;
        for (int i = 0; i < MAP_HEIGHT * MAP_WIDTH; i++) {
                tiles[i].hits = 1;
        }

}
void resetGame() {
        ball.p.x = 320;
        ball.p.y = 340;
        ball.buff = StickOnce;
        paddle.p.x = 320;
        paddle.p.y = 340;
        paddle.size.x = 64;
        paddle.shoot = 0;
        ball.pen = 0;
        ball.vel = 4;
        ball.explosive = 0;
        ball.buff = StickOnce;
        levelTransparency = 255;
        initTiles();
}
void game() {
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
                printf("SDL_Init Error: %s\n", SDL_GetError());
        }
        if (SDL_Init(SDL_INIT_AUDIO) != 0) {
            SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
            return;
        }
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        }
        Mix_Chunk* ping = NULL;
        Mix_Chunk* tilePing = NULL;
        Mix_Chunk* deathPing= NULL;
        Mix_Chunk* buffPing = NULL;
        Mix_Chunk* explosionPing = NULL;
        Mix_Chunk* successPing = NULL;
        Mix_Chunk* laserPing = NULL;
        ping = Mix_LoadWAV( "assets/ping.wav" );
        tilePing = Mix_LoadWAV( "assets/klo.wav" );
        deathPing = Mix_LoadWAV("assets/glissando_high_low.wav");
        buffPing = Mix_LoadWAV("assets/glissando_up.wav");
        explosionPing = Mix_LoadWAV("assets/explosion_1.wav");
        successPing = Mix_LoadWAV("assets/glissando_tenor.wav");
        laserPing = Mix_LoadWAV("assets/ring.wav");
        window = SDL_CreateWindow("FreakOut", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);
        if (window == NULL) {
                printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
                SDL_Quit();
        }

        renderer = SDL_CreateRenderer(
            window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer == NULL) {
                SDL_DestroyWindow(window);
                printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
                SDL_Quit();
        }
        SDL_Texture* paddleTex = IMG_LoadTexture(renderer, "assets/paddle.png");
        SDL_Texture* paddleLaserTex = IMG_LoadTexture(renderer, "assets/paddle_laser.png");
        SDL_Texture* ballTex = IMG_LoadTexture(renderer, "assets/ball.png");
        SDL_Texture* defBrickTex = IMG_LoadTexture(renderer, "assets/bbrick.png");
        SDL_Texture* inviBrickTex = IMG_LoadTexture(renderer, "assets/pbrick.png");
        SDL_Texture* invuBrickTex = IMG_LoadTexture(renderer, "assets/ybrick.png");
        SDL_Texture* expBrickTex = IMG_LoadTexture(renderer, "assets/obrick.png");
        SDL_Texture* threeBrickTex = IMG_LoadTexture(renderer, "assets/rbrick.png");
        SDL_Texture* buffTex= IMG_LoadTexture(renderer, "assets/buff.png");
        SDL_Texture* debuffTex= IMG_LoadTexture(renderer, "assets/debuff.png");
        SDL_Texture* bgTex = IMG_LoadTexture(renderer, "assets/calling.png");
       
        SDL_ShowCursor(0); 
        initTiles();
        TTF_Init();
        TTF_Font* font = TTF_OpenFont("assets/8bitOperatorPlus-Regular.ttf", 8);

        while (running) {
                if (levelTransparency > 1) {
                    levelTransparency--;
                }
                char *tilesChar = (char*)malloc(64* sizeof(char));
                sprintf(tilesChar, "TILES LEFT: %i", tilesLeft);
                char *scoreChar = (char*)malloc(64* sizeof(char));
                sprintf(scoreChar, "SCORE: %i", score);
                char *levelChar= (char*)malloc(64* sizeof(char));
                sprintf(levelChar, "Level %i: %s", level, levelNames[level]);
                SDL_Surface* tilesLeftSurface = TTF_RenderText_Solid(font,tilesChar , (SDL_Color){255,255,255,255});
                SDL_Texture* tlText = SDL_CreateTextureFromSurface(renderer, tilesLeftSurface);
                SDL_Surface* scoreSurface= TTF_RenderText_Solid(font, scoreChar, (SDL_Color){255,255,255,255});
                SDL_Texture* scoreText = SDL_CreateTextureFromSurface(renderer, scoreSurface);
                SDL_Surface* levelSurface= TTF_RenderText_Solid(font, levelChar, (SDL_Color){255,255,255,levelTransparency});
                SDL_Texture* levelText = SDL_CreateTextureFromSurface(renderer, levelSurface);
                SDL_Surface* gameOverSurface= TTF_RenderText_Solid(font, "Game Over!", (SDL_Color){255,255,255,255});
                SDL_Texture* gameOverText = SDL_CreateTextureFromSurface(renderer, gameOverSurface);
                SDL_Surface* gameDoneSurface= TTF_RenderText_Solid(font, "Game Won!", (SDL_Color){255,255,255,255});
                SDL_Texture* gameDoneText = SDL_CreateTextureFromSurface(renderer, gameDoneSurface);
                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                        if (event.type == SDL_QUIT) {
                                running = 0;
                        }
                        if (event.key.keysym.sym == SDLK_UP) {
                        }
                        if (event.type == SDL_MOUSEMOTION) {
                            if (event.motion.x >= 0 && event.motion.x < SCREEN_WIDTH - paddle.size.x) {
                                paddle.p.x = event.motion.x;
                            }
                        }
                        if (event.type == SDL_MOUSEBUTTONDOWN) {
                                ball.buff = DefBuff;
                        }
                        if (event.type == SDL_KEYUP) {
                                if (event.key.keysym.sym == SDLK_UP) {
                                }
                        }
                        if (event.key.keysym.sym == SDLK_DOWN) {
                        }
                        if (event.type == SDL_KEYUP) {
                                if (event.key.keysym.sym == SDLK_DOWN) {
                                }
                        }
                        if (event.key.keysym.sym == SDLK_LEFT) {
                            if (event.motion.x >= 0 && event.motion.x < SCREEN_WIDTH - paddle.size.x) {
                            paddle.p.x -= 16;

                            }
                        }

                        if (event.type == SDL_KEYUP) {
                                if (event.key.keysym.sym == SDLK_LEFT) {
                                }
                        }
                        if (event.key.keysym.sym == SDLK_RIGHT) {
                            if (event.motion.x >= 0 && event.motion.x < SCREEN_WIDTH - paddle.size.x) {
                                paddle.p.x += 16;

                            }
                        }
                        if (event.type == SDL_KEYDOWN) {
                                if (event.key.keysym.sym == SDLK_ESCAPE) {
                                }
                                if (event.key.keysym.sym == SDLK_f) {
                                    SDL_SetWindowFullscreen(window, 1);
                                }
                                if (event.key.keysym.sym == SDLK_n) {
                                        level++;
                                        resetGame();
                                }
                                if (event.key.keysym.sym == SDLK_SPACE) {
                                        if (lives <= 0) {
                                                resetGame();
                                                level = 0;
                                                score = 0;
                                                lives = 3;
                                                // todo! post score
                                        }
                                        if (paddle.shoot == 1) {
                                                Mix_PlayChannel(-1, laserPing, 0);
                                                projectiles[projIndex] = (Projectile) {
                                                    {paddle.p.x + paddle.size.x/2, paddle.p.y},{3,7}, {0,-1}, 10, 1 

                                                };
                                                projIndex++;
                                                if (projIndex > projectilesSize -1 ) {
                                                    projIndex = 0;
                                                }
                                        }
                                }
                        }
                        if (event.type == SDL_KEYUP) {
                                if (event.key.keysym.sym == SDLK_SPACE) {
                                }
                        }
                }
                // move ball
                //
                if (ball.buff != StickOnce) {
                    moveBall(&ball, &paddle, ping);
                }
                else {
                        ball.p.x = paddle.p.x + paddle.size.x / 2;
                }
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, bgTex, NULL, NULL);
                drawBG(renderer);
                // paddle
                SDL_Rect paddleR = { paddle.p.x, paddle.p.y, paddle.size.x, paddle.size.y }; 
                if (paddle.shoot == 1) {
                    SDL_RenderCopy(renderer, paddleLaserTex, NULL, &paddleR); 
                }
                else {

                    SDL_RenderCopy(renderer, paddleTex, NULL, &paddleR); 
                }
                tilesLeft = 0;
                for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
                        Tile* tile = &tiles[i];
                        if (tile->ttype == Nonexistent) {
                                continue;
                        }
                        if (tile->status != Falling){

                            tilesLeft++;
                        }
                        for (int j = 0; j < projIndex; j++) {
                                Projectile *p = &projectiles[j];
                                if (p->alive == 0) {
                                        continue;
                                }
                                int lCollision= collideLaserWithTile(&ball, p, tile, tilePing);
                                if (lCollision) {
                                        tile->hits--;
                                        if (ball.pen == 0) {
                                            p->alive = 0;
                                        }
                                        if (tile->hits <= 0 && tiles->ttype != Explosion && tile->status != Falling) {
                                            score += 25;
                                            tile->alive = 0;
                                        }
                                }

                                if (lCollision == 2) {
                                    explode(tile, explosionPing);
                                    score += 100;
                                }
                                
                        }
                        if (tile->alive == 0) {
                                tile->vel.y = -4;
                                tile->vel.x = -2 + randI() % 4;
                                tile->status = Falling;
                                tile->alive = 1;
                                int rand = randI();
                                int r = randI() % 10;
                                if (r == 0) {
                                    tile->buff = Wide; 
                                }
                                else if (r == 1) {
                                    tile->buff = Kill; 
                                }
                                else if (r == 2) {
                                    tile->buff = Shrink; 
                                }
                                else if (r == 3) {
                                    tile->buff = Explosive; 
                                }
                                else if (r == 4) {
                                    tile->buff = Soften; 
                                }
                                else if (r == 5) {
                                    tile->buff = Double; 
                                }
                                else if (r == 6) {
                                    tile->buff = Pen; 
                                }
                                else if (r == 7) {
                                    tile->buff = Laser; 
                                }
                                else {

                                }
                        }
                        fallTile(tile); 
                        if (tile->buff == DefBuff) {
                            if (tile->ttype == Def) {
                                drawTile(tile, renderer, defBrickTex);
                            }
                            else if (tile->ttype == Invulnerable) {

                                drawTile(tile, renderer, invuBrickTex);
                            }
                            else if (tile->ttype == Invisible) {
                                if (tile->hits == 1) {
                                    drawTile(tile, renderer, inviBrickTex);
                                }
                            }
                            else if (tile->ttype == Explosion) {

                                drawTile(tile, renderer, expBrickTex);
                            }
                            else if (tile->ttype == Three) {

                                drawTile(tile, renderer, threeBrickTex);
                            }
                        }
                        else if (tile->buff == Shrink || tile-> buff == Kill) {
                            drawTile(tile, renderer, debuffTex);
                        }
                        else {

                            drawTile(tile, renderer, buffTex);
                        }
                        int collision = collideWithTile(&ball, tile, tilePing);
                        if (collision == 2) {
                            explode(tile, explosionPing);
                            score += 100;
                        }
                        if (collision == 1 && tile->status != Falling) {
                            score += 25;
                        } 
                        BuffType coll = collidePaddleWithTile(&paddle, tile, buffPing); 
                        if (coll == Wide) {

                                Mix_PlayChannel(-1, buffPing, 0);
                                paddle.size.x += 8;

                        }

                        else if (coll == Shrink) {

                                Mix_PlayChannel(-1, buffPing, 0);
                                paddle.size.x -= 8;

                        }
                        else if (coll == Explosive) {

                                Mix_PlayChannel(-1, buffPing, 0);
                                ball.explosive = 1;

                        }
                        else if (coll == Pen) {

                                Mix_PlayChannel(-1, buffPing, 0);
                                ball.pen = 1;

                        }
                        else if (coll == Soften) {

                                Mix_PlayChannel(-1, buffPing, 0);
                                softenBricks();
                        }
                        else if (coll == Double) {
                                Mix_PlayChannel(-1, buffPing, 0);
                        }
                        else if (coll == Laser) {
                                paddle.shoot = 1;
                        }
                        else if (coll == Kill) {
                                Mix_PlayChannel(-1, deathPing, 0);
                                resetGame();
                                lives--;
                        }
                        else if (collidePaddleWithTile(&paddle, tile, buffPing) == Wide) {

                                Mix_PlayChannel(-1, buffPing, 0);
                                paddle.size.x += 8;

                        }
                        if (ball.p.y > SCREEN_HEIGHT) {
                                Mix_PlayChannel(-1, deathPing, 0);
                                resetGame();
                                lives--;
                        }
                }

                if (tilesLeft <= 0) {
                    level++;
                    resetGame();
                    Mix_PlayChannel(-1, successPing, 0);
                }
                for (int i = 0; i < projectilesSize; i++) {
                    Projectile* p = &projectiles[i];
                    if (p->alive == 0) {
                            continue;
                    }
                    SDL_Rect laserR = { p->p.x, p->p.y, p->size.x, p->size.y }; 
                    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 175); 
                    SDL_RenderFillRect(renderer, &laserR);
                    p->p.y += p->vel.y * p->speed;
                }

                // ball
                SDL_Rect ballR = { ball.p.x, ball.p.y, ball.size.y, ball.size.y }; 
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
                SDL_RenderCopy(renderer, ballTex, NULL, &ballR); 
                // hud
                SDL_Rect tlTextRect = {2, 0, 64, 30};
                SDL_RenderCopy(renderer, tlText, NULL, &tlTextRect);

                SDL_Rect scoreTextRect = {2,24, 40, 30};
                SDL_RenderCopy(renderer, scoreText, NULL, &scoreTextRect);

                SDL_Rect levelTextRect= {SCREEN_WIDTH/2-34,SCREEN_HEIGHT/2+70, 80, 30};
                SDL_RenderCopy(renderer, levelText, NULL, &levelTextRect);
                if (lives <= 0) {
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, bgTex, NULL, NULL);
                    SDL_Rect gameOverTextRect = {SCREEN_WIDTH/2-34,SCREEN_HEIGHT/2+70, 80, 30};
                    SDL_RenderCopy(renderer, gameOverText, NULL, &gameOverTextRect);
                }
                if (level >= 8) {
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, bgTex, NULL, NULL);
                    SDL_Rect gameDoneScreenRect = {SCREEN_WIDTH/2-34,SCREEN_HEIGHT/2+70, 80, 30};
                    SDL_RenderCopy(renderer, gameDoneText, NULL, &gameDoneScreenRect);
                }
                SDL_RenderPresent(renderer);
                #ifdef __EMSCRIPTEN__
                emscripten_sleep(10);
                #endif
        }
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
}
int main() {
        initPerlin();
        #ifdef __EMSCRIPTEN__
        emscripten_set_main_loop(game, 0, 1);
        #else
        game();
        #endif
        return 1;
}
