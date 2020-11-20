#include QMK_KEYBOARD_H

enum custom_keycodes {
  UP_URL = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT_ortho_2x2(
    SEND_STRING("My name is Rami and this service request was assined to my care ");, SEND_STRING("In order to furtuer invastigate our issue please reffer to the following");,
    KC_P, UP_URL
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case UP_URL:
      if (record->event.pressed) {
        SEND_STRING("Rami ");
      }
      return false;
      break;
  }
  return true;
}
