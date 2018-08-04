// Example program:
// Using SDL2 to create an application window

#include <uisim.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

    uisim_create(112, 64, 5);
    uisim_fill(UISIM_LCD_GREEN_BACKGROUND);
    uisim_setpixel(0,0, UISIM_RGB(0,0,0));
    sleep(3);
    uisim_destroy();
    return 0;
}
