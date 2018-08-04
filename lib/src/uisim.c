#include <uisim.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <assert.h>

static SDL_Window *window;
static SDL_Renderer *renderer;
static SDL_Texture *texture;
static uint32_t background;

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
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        xres * scale,
        yres * scale,
        SDL_WINDOW_OPENGL
    );

    if( window == NULL ) {
        return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_RenderSetScale(renderer, scale, scale);
    
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    return 0;
}

static void fill_screen(uint32_t color)
{
    SDL_SetRenderDrawColor(renderer, color >> 24, color >> 16, color >> 8, color );
    SDL_RenderClear(renderer);
}

void uisim_fill(uint32_t color)
{
    fill_screen(color);
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
    fill_screen(background);
    SDL_SetRenderDrawColor(renderer, color >> 24, color >> 16, color >> 8, SDL_ALPHA_OPAQUE );
    SDL_RenderDrawPoint(renderer, xpos, ypos);
    SDL_RenderPresent(renderer);
}

void uisim_clear( void ) 
{
    fill_screen(background);
    SDL_RenderPresent(renderer);
}