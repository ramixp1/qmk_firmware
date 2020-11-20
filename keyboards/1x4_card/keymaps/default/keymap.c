#include QMK_KEYBOARD_H

enum keyboard_layers{
    _BASE = 0,
    _Ll
};

enum custom_keycodes {
  C_S_T = SAFE_RANGE
};



// Tap Dance Declarations
enum tap_dance { TD_TO_L0 = 0, TD_TO_L1 = 1 };

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for standard key, twice to toggle to control layer
    [TD_TO_L0]     = ACTION_TAP_DANCE_DUAL_ROLE(KC_MUTE, _Ll),
    [TD_TO_L1] = ACTION_TAP_DANCE_DUAL_ROLE(KC_5, _BASE)};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
------------ 
|key1, key2|   
|key3, key4|
------------
*/

[_BASE] =LAYOUT

(TD(TD_TO_L0), KC_VOLU, KC_MPLY, KC_VOLD),



[_Ll] =LAYOUT

(TD(TD_TO_L1), C_S_T, KC_F20, KC_F21),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
     case C_S_T:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LSFT("t")));
		
      }

	  case KC_F20:
      if (record->event.pressed) {
       SEND_STRING(SS_LALT("a"));;
	   break;
		
      }			


	  case KC_F21:
      if (record->event.pressed) {
       SEND_STRING(SS_LALT("f"));;
	   break;
		
      }	  
	  
	  	  else
      return false;
      break;
  }
  return true;
}

