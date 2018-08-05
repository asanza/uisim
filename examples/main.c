// Example program:
// Using SDL2 to create an application window

#include <uisim.h>
#include <stdio.h>
#include <unistd.h>
#include <ugui/ugui.h>

#define WIDTH 112
#define HEIGHT 64

int main(int argc, char* argv[]) {

    enum uisim_event evt; 

    UG_GUI gui;

    UG_Init(&gui, uisim_drawpoint, WIDTH, HEIGHT);

    uisim_create(WIDTH, HEIGHT, 5);

    UG_FontSelect(&FONT_8X8);

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
                break;
                case UISIM_KEY_RIGHT:
                break;
                case UISIM_KEY_UP:
                break;
                case UISIM_KEY_DOWN:
                break;
            }
        } else if ( evt == UISIM_KEY_RELEASE ) {

        }
    }
    uisim_destroy();
    return 0;
}
