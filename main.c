#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_timer.h>
#include<SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "graphics.h"

int main( int argc, char * argv[])
{
    struct SDL_Window * window;
    struct SDL_Renderer * renderer;

    renderer = NULL;
    window = NULL;


    init();
    create_Window_and_Renderer( &renderer, &window, "GAME" );
    return 0;
}

