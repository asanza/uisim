// Example program:
// Using SDL2 to create an application window

#include <uisim.h>
#include <stdio.h>
#include <unistd.h>

#define WIDTH 112
#define HEIGHT 64

int main(int argc, char* argv[]) {

    enum uisim_event evt; 
    int x=0, y=0;

    uisim_create(WIDTH, HEIGHT, 5);

    uisim_fill(UISIM_LCD_GREEN_BACKGROUND);

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
                    x--;
                break;
                case UISIM_KEY_RIGHT:
                    x++;
                break;
                case UISIM_KEY_UP:
                    y--;
                break;
                case UISIM_KEY_DOWN:
                    y++;
                break;
            }
            if( x >= WIDTH ) x = WIDTH - 1;
            if( x < 0 ) x = 0;
            if( y >= HEIGHT ) y = HEIGHT - 1;
            if( y < 0 ) y = 0;
            uisim_drawpoint(x, y, UISIM_RGB(0,0,0));                    
        } else if ( evt == UISIM_KEY_RELEASE ) {

        }
    }
    uisim_destroy();
    return 0;
}
