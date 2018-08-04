#ifndef UISIM_H_
#define UISIM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define UISIM_RGB(R, G, B) (R << 24 | G << 16 | B << 8)

#define UISIM_LCD_GREEN_BACKGROUND UISIM_RGB(0x00,0xF1,0x57)

enum uisim_event {
    UISIM_WINDOW_CLOSED,
    UISIM_KEY_PRESS,
    UISIM_KEY_RELEASE
};

int uisim_create(uint16_t xres, uint16_t yres, uint8_t scale);

void uisim_destroy();

void uisim_drawpoint(uint16_t xpos, uint16_t ypos, uint32_t color);

void uisim_clear( void );

void uisim_fill( uint32_t color );

int uisim_create_keyboard(uint16_t keycount);

void uisim_add_key(const char* keyname);

enum uisim_event uisim_poll( void );

void uisim_getkey(char* buffer);

#ifdef __cplusplus
}
#endif

#endif