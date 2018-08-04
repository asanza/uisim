#include <uisim.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <assert.h>

static SDL_Window *window, *keyboard;
static SDL_Renderer *renderer;
static SDL_Texture *texture;
static uint32_t background;
static const int keysize = 50;

int uisim_create(uint16_t xres, uint16_t yres, uint8_t scale)
{
    assert(xres > 0);
    assert(yres > 0);
    assert(scale > 0);

    if( SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        return -1;
    }

    window = SDL_CreateWindow(
        "LCD Display",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_CENTERED,
        xres * scale,
        yres * scale,
        SDL_WINDOW_OPENGL
    );

    if( window == NULL ) {
        return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED 
        | SDL_RENDERER_TARGETTEXTURE);

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, 
        SDL_TEXTUREACCESS_TARGET, xres, yres);

    SDL_RenderSetScale(renderer, scale, scale);
    
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    return 0;
}

void uisim_fill(uint32_t color)
{
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, color >> 24, color >> 16, color >> 8, SDL_ALPHA_OPAQUE );
    SDL_RenderClear(renderer);

    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    background = color;
}

void uisim_destroy( void )
{
    SDL_DestroyWindow( window );
    SDL_Quit();
}

void uisim_drawpoint(uint16_t xpos, uint16_t ypos, uint32_t color)
{
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, color >> 24, color >> 16, color >> 8, SDL_ALPHA_OPAQUE );
    SDL_RenderDrawPoint(renderer, xpos, ypos);

    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void uisim_clear( void ) 
{
    uisim_fill(background);
}

int uisim_create_keyboard( uint16_t keycount )
{
    if( SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        return -1;
    }

    keyboard = SDL_CreateWindow(
        "KEYBOARD",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_CENTERED,
        keysize,
        keycount * (keysize + 5),
        SDL_WINDOW_OPENGL
    );

    if( window == NULL ) {
        return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    return 0;
}

void uisim_add_key(const char* keyname) {

}