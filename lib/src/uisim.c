#include <uisim.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <assert.h>

struct window_ctx
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    uint32_t background;
};


static struct window_ctx display_ctx;

static uint32_t background;

static enum uisim_key last_key;

#define DESTROY_CONTEXT( ctx ) do {         \
        SDL_DestroyWindow( ctx.window );  \
        SDL_DestroyTexture( ctx.texture );  \
    } while(0)

int uisim_create(uint16_t xres, uint16_t yres, uint8_t scale)
{
    assert(xres > 0);
    assert(yres > 0);
    assert(scale > 0);

    if( SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        return -1;
    }

    display_ctx.window = SDL_CreateWindow(
        "LCD Display",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_CENTERED,
        xres * scale,
        yres * scale,
        SDL_WINDOW_OPENGL
    );

    if( display_ctx.window == NULL ) {
        return -1;
    }

    display_ctx.renderer = SDL_CreateRenderer(display_ctx.window, -1, 
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

    display_ctx.texture = SDL_CreateTexture(display_ctx.renderer, 
        SDL_PIXELFORMAT_RGBA8888, 
        SDL_TEXTUREACCESS_TARGET, xres, yres);

    SDL_RenderSetScale(display_ctx.renderer, scale, scale);
    
    SDL_RenderClear(display_ctx.renderer);
    SDL_RenderPresent(display_ctx.renderer);

    return 0;
}

void uisim_fill(uint32_t color)
{
    SDL_SetRenderTarget(display_ctx.renderer, display_ctx.texture);
    SDL_SetRenderDrawColor(display_ctx.renderer, color >> 24, 
            color >> 16, color >> 8, SDL_ALPHA_OPAQUE );
    SDL_RenderClear(display_ctx.renderer);

    SDL_SetRenderTarget(display_ctx.renderer, NULL);
    SDL_RenderCopy(display_ctx.renderer, display_ctx.texture, NULL, NULL);
    SDL_RenderPresent(display_ctx.renderer);

    background = color;
}

void uisim_destroy( void )
{
    DESTROY_CONTEXT(display_ctx);
    SDL_Quit();
}

void uisim_drawpoint(uint16_t xpos, uint16_t ypos, uint32_t color)
{
    SDL_SetRenderTarget(display_ctx.renderer, display_ctx.texture);
    SDL_SetRenderDrawColor(display_ctx.renderer, 
        color >> 24, color >> 16, color >> 8, SDL_ALPHA_OPAQUE );
    SDL_RenderDrawPoint(display_ctx.renderer, xpos, ypos);

    SDL_SetRenderTarget(display_ctx.renderer, NULL);
    SDL_RenderCopy(display_ctx.renderer, display_ctx.texture, NULL, NULL);
    SDL_RenderPresent(display_ctx.renderer);
}

void uisim_drawpoints(uint16_t* x, uint16_t* y, uint32_t* color, uint32_t len)
{
    SDL_SetRenderTarget(display_ctx.renderer, display_ctx.texture);

    for( int i = 0; i < len; i++) {
        SDL_SetRenderDrawColor(display_ctx.renderer, 
            *color >> 24, *color >> 16, *color >> 8, SDL_ALPHA_OPAQUE );
        SDL_RenderDrawPoint(display_ctx.renderer, *x, *y);
        color++; x++; y++;
    }

    SDL_SetRenderTarget(display_ctx.renderer, NULL);
    SDL_RenderCopy(display_ctx.renderer, display_ctx.texture, NULL, NULL);
    SDL_RenderPresent(display_ctx.renderer);
}

void uisim_clear( void ) 
{
    uisim_fill(background);
}

enum uisim_event uisim_poll( void )
{
    SDL_Event evt;
    if( SDL_PollEvent(&evt) == 1 )
    {
        if(evt.type == SDL_WINDOWEVENT && 
            evt.window.event == SDL_WINDOWEVENT_CLOSE) 
        {
            return UISIM_WINDOW_CLOSED;
        } else if (evt.type == SDL_KEYDOWN) {
            last_key = evt.key.keysym.scancode;
            return UISIM_KEY_PRESS;
        } else if (evt.type == SDL_KEYUP ) {
            last_key = evt.key.keysym.scancode;
            return UISIM_KEY_RELEASE;
        }
    }
    return UISIM_NONE;
}

enum uisim_key uisim_getkey( void )
{
    return last_key;
}