// Example program:
// Using SDL2 to create an application window

#include <uisim.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    enum uisim_event evt; 

    uisim_create(112, 64, 5);
    uisim_create_keyboard(4);
    uisim_fill(UISIM_LCD_GREEN_BACKGROUND);
    uisim_drawpoint(0,0, UISIM_RGB(0,0,0));
    uisim_drawpoint(0,5, UISIM_RGB(0,0,0));
    while( 1 ) 
    {
        evt = uisim_poll();
        if(evt == UISIM_WINDOW_CLOSED) 
        {
            break;
        }
    }
    uisim_destroy();
    return 0;
}
