#include QMK_KEYBOARD_H

enum custom_keycodes {
  UP_URL = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  LAYOUT_ortho_2x2(
    KC_F, KC_E,
    KC_P, UP_URL
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case UP_URL:
      if (record->event.pressed) {
        SEND_STRING("Rami "); 
		      return false;
      break;
	  }
	  else
	      case KC_P:
      if (record->event.pressed) {
        SEND_STRING("text 1 ");
		      return false;
      break;
	  }

	  else
	      case KC_F:
      if (record->event.pressed) {
        SEND_STRING("text 2");
		      return false;
      break;
      }
	 else 
	  
      return false;
      break;
	  
	  
  }
  return true;
}
