#define WINDOW_WIDTH (1920)
#define WINDOW_HEIGHT (1080)

int init();
int checkWindow( struct SDL_Window *  );
int checkRenderer( struct SDL_Renderer *  , struct SDL_Window *  );
int checkSurface( struct SDL_Surface * , struct SDL_Renderer * , struct SDL_Window *  );
int checkTexture( struct SDL_Texture * , struct SDL_Renderer * , struct SDL_Window *  );
void create_Window_and_Renderer( struct SDL_Renderer ** , struct SDL_Window ** ,  char *  );