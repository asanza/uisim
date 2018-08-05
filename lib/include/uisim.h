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
    UISIM_KEY_RELEASE,
    UISIM_NONE
};

enum uisim_key {
    UISIM_KEY_UNKNOWN = 0,

    UISIM_KEY_A = 4,
    UISIM_KEY_B = 5,
    UISIM_KEY_C = 6,
    UISIM_KEY_D = 7,
    UISIM_KEY_E = 8,
    UISIM_KEY_F = 9,
    UISIM_KEY_G = 10,
    UISIM_KEY_H = 11,
    UISIM_KEY_I = 12,
    UISIM_KEY_J = 13,
    UISIM_KEY_K = 14,
    UISIM_KEY_L = 15,
    UISIM_KEY_M = 16,
    UISIM_KEY_N = 17,
    UISIM_KEY_O = 18,
    UISIM_KEY_P = 19,
    UISIM_KEY_Q = 20,
    UISIM_KEY_R = 21,
    UISIM_KEY_S = 22,
    UISIM_KEY_T = 23,
    UISIM_KEY_U = 24,
    UISIM_KEY_V = 25,
    UISIM_KEY_W = 26,
    UISIM_KEY_X = 27,
    UISIM_KEY_Y = 28,
    UISIM_KEY_Z = 29,

    UISIM_KEY_1 = 30,
    UISIM_KEY_2 = 31,
    UISIM_KEY_3 = 32,
    UISIM_KEY_4 = 33,
    UISIM_KEY_5 = 34,
    UISIM_KEY_6 = 35,
    UISIM_KEY_7 = 36,
    UISIM_KEY_8 = 37,
    UISIM_KEY_9 = 38,
    UISIM_KEY_0 = 39,

    UISIM_KEY_RETURN = 40,
    UISIM_KEY_ESCAPE = 41,
    UISIM_KEY_BACKSPACE = 42,
    UISIM_KEY_TAB = 43,
    UISIM_KEY_SPACE = 44,

    UISIM_KEY_MINUS = 45,
    UISIM_KEY_EQUALS = 46,
    UISIM_KEY_LEFTBRACKET = 47,
    UISIM_KEY_RIGHTBRACKET = 48,
    UISIM_KEY_BACKSLASH = 49, /**< Located at the lower left of the return
                                  *   key on ISO keyboards and at the right end
                                  *   of the QWERTY row on ANSI keyboards.
                                  *   Produces REVERSE SOLIDUS (backslash) and
                                  *   VERTICAL LINE in a US layout, REVERSE
                                  *   SOLIDUS and VERTICAL LINE in a UK Mac
                                  *   layout, NUMBER SIGN and TILDE in a UK
                                  *   Windows layout, DOLLAR SIGN and POUND SIGN
                                  *   in a Swiss German layout, NUMBER SIGN and
                                  *   APOSTROPHE in a German layout, GRAVE
                                  *   ACCENT and POUND SIGN in a French Mac
                                  *   layout, and ASTERISK and MICRO SIGN in a
                                  *   French Windows layout.
                                  */
    UISIM_KEY_NONUSHASH = 50, /**< ISO USB keyboards actually use this code
                                  *   instead of 49 for the same key, but all
                                  *   OSes I've seen treat the two codes
                                  *   identically. So, as an implementor, unless
                                  *   your keyboard generates both of those
                                  *   codes and your OS treats them differently,
                                  *   you should generate UISIM_KEY_BACKSLASH
                                  *   instead of this code. As a user, you
                                  *   should not rely on this code because SDL
                                  *   will never generate it with most (all?)
                                  *   keyboards.
                                  */
    UISIM_KEY_SEMICOLON = 51,
    UISIM_KEY_APOSTROPHE = 52,
    UISIM_KEY_GRAVE = 53, /**< Located in the top left corner (on both ANSI
                              *   and ISO keyboards). Produces GRAVE ACCENT and
                              *   TILDE in a US Windows layout and in US and UK
                              *   Mac layouts on ANSI keyboards, GRAVE ACCENT
                              *   and NOT SIGN in a UK Windows layout, SECTION
                              *   SIGN and PLUS-MINUS SIGN in US and UK Mac
                              *   layouts on ISO keyboards, SECTION SIGN and
                              *   DEGREE SIGN in a Swiss German layout (Mac:
                              *   only on ISO keyboards), CIRCUMFLEX ACCENT and
                              *   DEGREE SIGN in a German layout (Mac: only on
                              *   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
                              *   French Windows layout, COMMERCIAL AT and
                              *   NUMBER SIGN in a French Mac layout on ISO
                              *   keyboards, and LESS-THAN SIGN and GREATER-THAN
                              *   SIGN in a Swiss German, German, or French Mac
                              *   layout on ANSI keyboards.
                              */
    UISIM_KEY_COMMA = 54,
    UISIM_KEY_PERIOD = 55,
    UISIM_KEY_SLASH = 56,

    UISIM_KEY_CAPSLOCK = 57,

    UISIM_KEY_F1 = 58,
    UISIM_KEY_F2 = 59,
    UISIM_KEY_F3 = 60,
    UISIM_KEY_F4 = 61,
    UISIM_KEY_F5 = 62,
    UISIM_KEY_F6 = 63,
    UISIM_KEY_F7 = 64,
    UISIM_KEY_F8 = 65,
    UISIM_KEY_F9 = 66,
    UISIM_KEY_F10 = 67,
    UISIM_KEY_F11 = 68,
    UISIM_KEY_F12 = 69,

    UISIM_KEY_PRINTSCREEN = 70,
    UISIM_KEY_SCROLLLOCK = 71,
    UISIM_KEY_PAUSE = 72,
    UISIM_KEY_INSERT = 73, /**< insert on PC, help on some Mac keyboards (but
                                   does send code 73, not 117) */
    UISIM_KEY_HOME = 74,
    UISIM_KEY_PAGEUP = 75,
    UISIM_KEY_DELETE = 76,
    UISIM_KEY_END = 77,
    UISIM_KEY_PAGEDOWN = 78,
    UISIM_KEY_RIGHT = 79,
    UISIM_KEY_LEFT = 80,
    UISIM_KEY_DOWN = 81,
    UISIM_KEY_UP = 82,

    UISIM_KEY_NUMLOCKCLEAR = 83, /**< num lock on PC, clear on Mac keyboards
                                     */
    UISIM_KEY_KP_DIVIDE = 84,
    UISIM_KEY_KP_MULTIPLY = 85,
    UISIM_KEY_KP_MINUS = 86,
    UISIM_KEY_KP_PLUS = 87,
    UISIM_KEY_KP_ENTER = 88,
    UISIM_KEY_KP_1 = 89,
    UISIM_KEY_KP_2 = 90,
    UISIM_KEY_KP_3 = 91,
    UISIM_KEY_KP_4 = 92,
    UISIM_KEY_KP_5 = 93,
    UISIM_KEY_KP_6 = 94,
    UISIM_KEY_KP_7 = 95,
    UISIM_KEY_KP_8 = 96,
    UISIM_KEY_KP_9 = 97,
    UISIM_KEY_KP_0 = 98,
    UISIM_KEY_KP_PERIOD = 99,

    UISIM_KEY_NONUSBACKSLASH = 100, /**< This is the additional key that ISO
                                        *   keyboards have over ANSI ones,
                                        *   located between left shift and Y.
                                        *   Produces GRAVE ACCENT and TILDE in a
                                        *   US or UK Mac layout, REVERSE SOLIDUS
                                        *   (backslash) and VERTICAL LINE in a
                                        *   US or UK Windows layout, and
                                        *   LESS-THAN SIGN and GREATER-THAN SIGN
                                        *   in a Swiss German, German, or French
                                        *   layout. */
    UISIM_KEY_APPLICATION = 101, /**< windows contextual menu, compose */
    UISIM_KEY_POWER = 102, /**< The USB document says this is a status flag,
                               *   not a physical key - but some Mac keyboards
                               *   do have a power key. */
    UISIM_KEY_KP_EQUALS = 103,
    UISIM_KEY_F13 = 104,
    UISIM_KEY_F14 = 105,
    UISIM_KEY_F15 = 106,
    UISIM_KEY_F16 = 107,
    UISIM_KEY_F17 = 108,
    UISIM_KEY_F18 = 109,
    UISIM_KEY_F19 = 110,
    UISIM_KEY_F20 = 111,
    UISIM_KEY_F21 = 112,
    UISIM_KEY_F22 = 113,
    UISIM_KEY_F23 = 114,
    UISIM_KEY_F24 = 115,
    UISIM_KEY_EXECUTE = 116,
    UISIM_KEY_HELP = 117,
    UISIM_KEY_MENU = 118,
    UISIM_KEY_SELECT = 119,
    UISIM_KEY_STOP = 120,
    UISIM_KEY_AGAIN = 121,   /**< redo */
    UISIM_KEY_UNDO = 122,
    UISIM_KEY_CUT = 123,
    UISIM_KEY_COPY = 124,
    UISIM_KEY_PASTE = 125,
    UISIM_KEY_FIND = 126,
    UISIM_KEY_MUTE = 127,
    UISIM_KEY_VOLUMEUP = 128,
    UISIM_KEY_VOLUMEDOWN = 129,

    UISIM_KEY_KP_COMMA = 133,
    UISIM_KEY_KP_EQUALSAS400 = 134,

    UISIM_KEY_INTERNATIONAL1 = 135, /**< used on Asian keyboards, see
                                            footnotes in USB doc */
    UISIM_KEY_INTERNATIONAL2 = 136,
    UISIM_KEY_INTERNATIONAL3 = 137, /**< Yen */
    UISIM_KEY_INTERNATIONAL4 = 138,
    UISIM_KEY_INTERNATIONAL5 = 139,
    UISIM_KEY_INTERNATIONAL6 = 140,
    UISIM_KEY_INTERNATIONAL7 = 141,
    UISIM_KEY_INTERNATIONAL8 = 142,
    UISIM_KEY_INTERNATIONAL9 = 143,
    UISIM_KEY_LANG1 = 144, /**< Hangul/English toggle */
    UISIM_KEY_LANG2 = 145, /**< Hanja conversion */
    UISIM_KEY_LANG3 = 146, /**< Katakana */
    UISIM_KEY_LANG4 = 147, /**< Hiragana */
    UISIM_KEY_LANG5 = 148, /**< Zenkaku/Hankaku */
    UISIM_KEY_LANG6 = 149, /**< reserved */
    UISIM_KEY_LANG7 = 150, /**< reserved */
    UISIM_KEY_LANG8 = 151, /**< reserved */
    UISIM_KEY_LANG9 = 152, /**< reserved */

    UISIM_KEY_ALTERASE = 153, /**< Erase-Eaze */
    UISIM_KEY_SYSREQ = 154,
    UISIM_KEY_CANCEL = 155,
    UISIM_KEY_CLEAR = 156,
    UISIM_KEY_PRIOR = 157,
    UISIM_KEY_RETURN2 = 158,
    UISIM_KEY_SEPARATOR = 159,
    UISIM_KEY_OUT = 160,
    UISIM_KEY_OPER = 161,
    UISIM_KEY_CLEARAGAIN = 162,
    UISIM_KEY_CRSEL = 163,
    UISIM_KEY_EXSEL = 164,

    UISIM_KEY_KP_00 = 176,
    UISIM_KEY_KP_000 = 177,
    UISIM_KEY_THOUSANDSSEPARATOR = 178,
    UISIM_KEY_DECIMALSEPARATOR = 179,
    UISIM_KEY_CURRENCYUNIT = 180,
    UISIM_KEY_CURRENCYSUBUNIT = 181,
    UISIM_KEY_KP_LEFTPAREN = 182,
    UISIM_KEY_KP_RIGHTPAREN = 183,
    UISIM_KEY_KP_LEFTBRACE = 184,
    UISIM_KEY_KP_RIGHTBRACE = 185,
    UISIM_KEY_KP_TAB = 186,
    UISIM_KEY_KP_BACKSPACE = 187,
    UISIM_KEY_KP_A = 188,
    UISIM_KEY_KP_B = 189,
    UISIM_KEY_KP_C = 190,
    UISIM_KEY_KP_D = 191,
    UISIM_KEY_KP_E = 192,
    UISIM_KEY_KP_F = 193,
    UISIM_KEY_KP_XOR = 194,
    UISIM_KEY_KP_POWER = 195,
    UISIM_KEY_KP_PERCENT = 196,
    UISIM_KEY_KP_LESS = 197,
    UISIM_KEY_KP_GREATER = 198,
    UISIM_KEY_KP_AMPERSAND = 199,
    UISIM_KEY_KP_DBLAMPERSAND = 200,
    UISIM_KEY_KP_VERTICALBAR = 201,
    UISIM_KEY_KP_DBLVERTICALBAR = 202,
    UISIM_KEY_KP_COLON = 203,
    UISIM_KEY_KP_HASH = 204,
    UISIM_KEY_KP_SPACE = 205,
    UISIM_KEY_KP_AT = 206,
    UISIM_KEY_KP_EXCLAM = 207,
    UISIM_KEY_KP_MEMSTORE = 208,
    UISIM_KEY_KP_MEMRECALL = 209,
    UISIM_KEY_KP_MEMCLEAR = 210,
    UISIM_KEY_KP_MEMADD = 211,
    UISIM_KEY_KP_MEMSUBTRACT = 212,
    UISIM_KEY_KP_MEMMULTIPLY = 213,
    UISIM_KEY_KP_MEMDIVIDE = 214,
    UISIM_KEY_KP_PLUSMINUS = 215,
    UISIM_KEY_KP_CLEAR = 216,
    UISIM_KEY_KP_CLEARENTRY = 217,
    UISIM_KEY_KP_BINARY = 218,
    UISIM_KEY_KP_OCTAL = 219,
    UISIM_KEY_KP_DECIMAL = 220,
    UISIM_KEY_KP_HEXADECIMAL = 221,

    UISIM_KEY_LCTRL = 224,
    UISIM_KEY_LSHIFT = 225,
    UISIM_KEY_LALT = 226, /**< alt, option */
    UISIM_KEY_LGUI = 227, /**< windows, command (apple), meta */
    UISIM_KEY_RCTRL = 228,
    UISIM_KEY_RSHIFT = 229,
    UISIM_KEY_RALT = 230, /**< alt gr, option */
    UISIM_KEY_RGUI = 231, /**< windows, command (apple), meta */

    UISIM_KEY_MODE = 257,   

    UISIM_KEY_AUDIONEXT = 258,
    UISIM_KEY_AUDIOPREV = 259,
    UISIM_KEY_AUDIOSTOP = 260,
    UISIM_KEY_AUDIOPLAY = 261,
    UISIM_KEY_AUDIOMUTE = 262,
    UISIM_KEY_MEDIASELECT = 263,
    UISIM_KEY_WWW = 264,
    UISIM_KEY_MAIL = 265,
    UISIM_KEY_CALCULATOR = 266,
    UISIM_KEY_COMPUTER = 267,
    UISIM_KEY_AC_SEARCH = 268,
    UISIM_KEY_AC_HOME = 269,
    UISIM_KEY_AC_BACK = 270,
    UISIM_KEY_AC_FORWARD = 271,
    UISIM_KEY_AC_STOP = 272,
    UISIM_KEY_AC_REFRESH = 273,
    UISIM_KEY_AC_BOOKMARKS = 274,
    UISIM_KEY_BRIGHTNESSDOWN = 275,
    UISIM_KEY_BRIGHTNESSUP = 276,
    UISIM_KEY_DISPLAYSWITCH = 277, 
    UISIM_KEY_KBDILLUMTOGGLE = 278,
    UISIM_KEY_KBDILLUMDOWN = 279,
    UISIM_KEY_KBDILLUMUP = 280,
    UISIM_KEY_EJECT = 281,
    UISIM_KEY_SLEEP = 282,

    UISIM_KEY_APP1 = 283,
    UISIM_KEY_APP2 = 284,
    UISIM_KEY_AUDIOREWIND = 285,
    UISIM_KEY_AUDIOFASTFORWARD = 286
};

int uisim_create(uint16_t xres, uint16_t yres, uint8_t scale);

void uisim_destroy();

void uisim_drawpoint(uint16_t xpos, uint16_t ypos, uint32_t color);

void uisim_drawpoints(uint16_t* x, uint16_t* y, uint32_t len, uint32_t color);

void uisim_clear( void );

void uisim_fill( uint32_t color );

enum uisim_event uisim_poll( void );

enum uisim_key  uisim_getkey( void );

#ifdef __cplusplus
}
#endif

#endif