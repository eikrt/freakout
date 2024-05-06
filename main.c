#include "main.h"
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
SDL_Window *window;
SDL_Renderer *renderer;

char map[] = {

    'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a',
    'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a',
    'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a',
    'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a',
    'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a',
    'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a',
    'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a',
    'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a',
    'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a',
    'a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a',

};

Ball ball = {
        {320, 340}, {8, 8}, StickOnce, 4.0, {1.0,1.0}
};

Paddle paddle = {
        {320, 340}, {128, 16}, StickOnce, 2.0, 0.0, 64 
};

        
Tile tiles[20*10];
int running = 1;

void initTiles() {
        int row=0;
        int col=0;
        for (int i = 0; i < MAP_HEIGHT * MAP_WIDTH; i++) {
                if (col >= MAP_WIDTH) {
                        col = 0;
                        row++;
                }
                Tile tile = {
                        {
                            col * 32, row * 16 
                        },
                        {
                            32, 16 
                        },
                        Def,
                        1,
                };
                col++;
                tiles[i] = tile;
        }
}
void resetGame() {
        ball.p.x = 320;
        ball.p.y = 340;
        ball.buff = StickOnce;
        paddle.p.x = 320;
        paddle.p.y = 340;
        ball.buff = StickOnce;
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
        ping = Mix_LoadWAV( "assets/korg_1/ping.wav" );
        tilePing = Mix_LoadWAV( "assets/korg_1/klo.wav" );
        deathPing = Mix_LoadWAV("assets/korg_1/glissando_high_low.wav");
        window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED,
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
        SDL_ShowCursor(0); 
        //SDL_SetWindowFullscreen(window, 1);
        initTiles();
        while (running) {
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
                        if (event.type == SDL_KEYUP) {
                                if (event.key.keysym.sym == SDLK_RIGHT) {
                                }
                        }
                        if (event.key.keysym.sym == SDLK_SPACE) {
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

                drawBG(renderer);
                // paddle
                SDL_Rect paddleR = { paddle.p.x, paddle.p.y, paddle.size.x, paddle.size.y }; // x, y, width, height
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); 
                SDL_RenderFillRect(renderer, &paddleR);
                
                for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
                        Tile* tile = &tiles[i];
                        if (tile->alive == 0) {
                                continue;
                        }
                        drawTile(tile, renderer);
                        collideWithTile(&ball, tile, tilePing);
                        if (ball.p.y > SCREEN_HEIGHT) {
                                Mix_PlayChannel(-1, deathPing, 0);
                                resetGame();
                        }
                }
                // ball
                SDL_Rect ballR = { ball.p.x, ball.p.y, ball.size.y, ball.size.y }; // x, y, width, height
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
                SDL_RenderFillRect(renderer, &ballR);
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
