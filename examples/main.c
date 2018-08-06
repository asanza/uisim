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
#include <unistd.h>
#include <ugui/ugui.h>

#define WIDTH 112
#define HEIGHT 64

/* this example creates an 112x64 lcd window and renders
 * "Hello World!" on it, with help of the ugui library.
 */

int main(int argc, char* argv[]) {

    enum uisim_event evt; 

    /* create a ugui context*/
    UG_GUI gui;

    /* initialize ugui. pass the uisim_drawpoint as driver */
    UG_Init(&gui, uisim_drawpoint, WIDTH, HEIGHT);

    /* create the virtual lcd display */
    uisim_create(WIDTH, HEIGHT, 5);
    uisim_fill(UISIM_LCD_GREEN_BACKGROUND);

    UG_FontSelect(&FONT_8X8);
    UG_SetBackcolor(UISIM_LCD_GREEN_BACKGROUND);
    UG_SetForecolor(UISIM_RGB(0,0,0));

    UG_PutString(6, 24, "Hello World");

    while( 1 ) 
    {
        evt = uisim_poll();
        if(evt == UISIM_WINDOW_CLOSED) 
        {
            break;
        }
        if( evt == UISIM_KEY_PRESS ) {
            switch(uisim_getkey()) {
                case UISIM_KEY_LEFT:
                    UG_PutString(6, 32, "<-   ");
                break;
                case UISIM_KEY_RIGHT:
                    UG_PutString(6, 32, "->   ");
                break;
                case UISIM_KEY_UP:
                    UG_PutString(6, 32, "UP!  ");
                break;
                case UISIM_KEY_DOWN:
                    UG_PutString(6, 32, "Down!");
                break;
            }
        } else if ( evt == UISIM_KEY_RELEASE ) {

        }
    }
    uisim_destroy();
    return 0;
}
