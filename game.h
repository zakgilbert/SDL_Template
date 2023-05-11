#ifndef GAME_H
#define GAME_H

typedef struct _Game
{
    int (*loop)(struct _Game *this);
    SDL_Renderer * renderer;
    SDL_Window * window;
    int quit;
    union SDL_Event ev;
    /* data */
}Game;

Game * CREATE_GAME(SDL_Renderer * renderer, SDL_Window * window);


#endif /*GAME_H*/


