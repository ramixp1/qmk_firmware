#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x0002
#define PRODUCT_ID      0x0002
#define DEVICE_VER      0x0002
#define MANUFACTURER    Rami
#define PRODUCT         1x4_card
#define DESCRIPTION     Rami 2020

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 4

/* key matrix pins */
#define MATRIX_ROW_PINS { B5 }
#define MATRIX_COL_PINS { D7, C6, B4, E6}
#define UNUSED_PINS

/* Audio  */
#define B6_AUDIO
#ifdef AUDIO_ENABLE
  #define STARTUP_SONG SONG(AUDIO_OFF_SOUND)
#endif



/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

