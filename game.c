#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "game.h"

static void _destroy(Game *this)
{
    if (NULL != this)
    {
        SDL_DestroyRenderer(this->renderer);
        SDL_DestroyWindow(this->window);
        free(this);
    }
}

static int _loop(Game *this)
{
    while (!this->quit)
    {
        while (SDL_PollEvent(&this->ev) != 0)
        {
            switch (this->ev.type)
            {
            case SDL_QUIT:
                this->quit = 1;
                break;

            default:
                break;
            }
        }
    }
    return 1;
}

Game *CREATE_GAME(SDL_Renderer *renderer, SDL_Window *window)
{
    Game *this = malloc(sizeof(*this));
    this->renderer = renderer;
    this->window = window;
    this->quit = 0;

    this->loop = _loop;
    this->destroy = _destroy;

    return this;
}