/* Copyright 2019 Josh Johnson
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Keyboard Layers
enum keyboard_layers{
    _BASE = 0,
    _CONTROL
};

// Tap Dance Declarations
enum tap_dance { TD_TO_LED = 0, TD_TO_DEFAULT = 1 };

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for standard key, twice to toggle to control layer
    [TD_TO_LED]     = ACTION_TAP_DANCE_DUAL_ROLE(KC_KP_PLUS, _CONTROL),
    [TD_TO_DEFAULT] = ACTION_TAP_DANCE_DUAL_ROLE(KC_KP_PLUS, _BASE)};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( /* Base */
        KC_F5,      KC_MUTE,    
    KC_7 , KC_8, KC_9, TD(TD_TO_LED), 
    KC_4, KC_5, KC_6, KC_KP_ASTERISK, 
    KC_1, KC_2, KC_3, KC_KP_MINUS, 
    KC_0, KC_0, KC_KP_DOT, KC_KP_SLASH 
  ),

  [_CONTROL] = LAYOUT( /* LED Control */
          KC_F5,            KC_MUTE,        
    RGB_TOG , RGB_MOD, RGB_RMOD, TD(TD_TO_DEFAULT), 
    KC_7, KC_8, KC_9, RGB_VAI, 
    KC_4, KC_5, KC_6, RGB_VAD, 
    KC_1, KC_2, KC_3, KC_0
  ),
};


void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* Left Encoder */
        if (clockwise) {
            tap_code16(C(S(KC_TAB)));
        } else {
            tap_code16(C(KC_TAB));
        }
    } else if (index == 1) { /* Right Encoder */
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Example of "pressing" CONTROL+SHIFT+V instead of "A" on keyboard
    // More info: https://docs.qmk.fm/#/feature_macros
    // case KC_A:
    //   if (record->event.pressed) {
    //     SEND_STRING(SS_LCTL(SS_LSFT("v")));
    //   } else {
    //   }
    //   break; 
  }
  return true;
};
