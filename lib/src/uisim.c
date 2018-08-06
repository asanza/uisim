/*
 * uisim
 * Copyright (C) 2018  Diego Asanza <f.asanza@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <uisim.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <assert.h>

struct window_ctx
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Texture *overlay;
    uint32_t scale;
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

    display_ctx.scale = scale;

    display_ctx.renderer = SDL_CreateRenderer(display_ctx.window, -1, 
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

    display_ctx.texture = SDL_CreateTexture(display_ctx.renderer, 
        SDL_PIXELFORMAT_RGBA8888, 
        SDL_TEXTUREACCESS_TARGET, xres, yres);

    display_ctx.overlay = SDL_CreateTexture(display_ctx.renderer, 
        SDL_PIXELFORMAT_RGBA8888, 
        SDL_TEXTUREACCESS_TARGET, xres*scale, yres*scale);
    
    SDL_RenderClear(display_ctx.renderer);
    SDL_RenderPresent(display_ctx.renderer);

    return 0;
}

void uisim_fill(uint32_t color)
{
    int w, h;

    SDL_SetRenderTarget(display_ctx.renderer, display_ctx.texture);
    SDL_SetRenderDrawColor(display_ctx.renderer, color >> 24, 
            color >> 16, color >> 8, SDL_ALPHA_OPAQUE );
    SDL_RenderClear(display_ctx.renderer);

    /* create the lcdish texture */
    SDL_SetTextureBlendMode(display_ctx.overlay, SDL_BLENDMODE_BLEND);    
    SDL_SetRenderTarget(display_ctx.renderer, display_ctx.overlay);
    SDL_SetRenderDrawColor(display_ctx.renderer, 128, 128, 128, 50 );
    SDL_RenderClear(display_ctx.renderer);
    SDL_SetRenderDrawColor(display_ctx.renderer, 
        color >> 24, color >> 16, color >> 8, 200 );

    SDL_GetWindowSize(display_ctx.window, &w, &h);

    for( int i = 0; i < w; i+=  display_ctx.scale )
    {
        SDL_RenderDrawLine(display_ctx.renderer, i, 0, i, h);
        SDL_RenderDrawLine(display_ctx.renderer, 0, i, w, i);
    }

    SDL_SetRenderTarget(display_ctx.renderer, NULL);
    SDL_RenderCopy(display_ctx.renderer, display_ctx.texture, NULL, NULL);
    SDL_RenderCopy(display_ctx.renderer, display_ctx.overlay, NULL, NULL);
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
    SDL_RenderCopy(display_ctx.renderer, display_ctx.overlay, NULL, NULL);
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
    SDL_RenderCopy(display_ctx.renderer, display_ctx.overlay, NULL, NULL);
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