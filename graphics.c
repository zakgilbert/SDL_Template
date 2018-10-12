#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_timer.h>
#include<SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "graphics.h"


int init() 
{
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) != 0 )
    {
        printf("\nERROR: SDL initialization failed--\n%s\n", SDL_GetError());
        return 1;
    }
    printf("\nInitSuccess!!!\n");
}

void create_Window_and_Renderer( struct SDL_Renderer ** rend, struct SDL_Window ** window, char * windowName )
{
    Uint32 render_flags;

    *window = SDL_CreateWindow( windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    checkWindow( *window );

    render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    *rend         = SDL_CreateRenderer( *window, -1, render_flags );
    checkRenderer( *rend, *window );
}

int checkWindow( struct SDL_Window * window )
{
    if( !window ) 
    {
        printf("\nERROR: SDL window failed--\n%s\n", SDL_GetError());
    }
    return 0;
}

int checkRenderer( struct SDL_Renderer * rend , struct SDL_Window * window )
{
    if( !rend ) 
    {
      printf("error creating renderer: %s\n", SDL_GetError());
      SDL_DestroyWindow(window);
      SDL_Quit();
      return 1;
    }
    return 0;
}

int checkSurface( struct SDL_Surface * surface, struct SDL_Renderer * rend, struct SDL_Window * window )
{
    if ( !surface )
    {
        printf("error creating surface\n");
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    return 0;
}

int checkTexture( struct SDL_Texture * texture, struct SDL_Renderer * rend, struct SDL_Window * window )
{
    if ( !texture )
    {
        printf("error creating texture: %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    return 0;
}