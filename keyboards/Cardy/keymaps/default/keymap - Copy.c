#include QMK_KEYBOARD_H

enum keyboard_layers{
    _BASE = 0,
    _Ll,
	
};

enum custom_keycodes {
  C_S_T = SAFE_RANGE
  ALT_A = 0,
  ALT_F=1
  
  
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  
    return OLED_ROTATION_180;  // flip 180 for offhand
  return rotation;
}




// Tap Dance Declarations
enum tap_dance { TD_TO_L1 = 0, TD_TO_L0 = 1 };

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for standard key, twice to toggle to control layer
    [TD_TO_L1]     = ACTION_TAP_DANCE_DUAL_ROLE(KC_MPLY, _Ll),
    [TD_TO_L0] = ACTION_TAP_DANCE_DUAL_ROLE(KC_5, _BASE),
	
	};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
------------ 
|key1, key2|   
|key3, key4|
------------
*/

[_BASE] =LAYOUT

(
	TD(TD_TO_L1), C_S_T,
	ALT_A, ALT_F
),


[_Ll] =LAYOUT

(
	TD(TD_TO_L0), C_S_T,
	ALT_A, ALT_F
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
     case C_S_T:
      if (record->event.pressed) {
		 
        SEND_STRING(SS_LCTRL(SS_LSFT("t")));
		
      }

	  case ALT_A:
      if (record->event.pressed) {
       SEND_STRING(SS_LALT("a"));;
	    
	   break;
		
      }			


	  case ALT_F:
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





//	screen:


//RD Logo
//16 char = 32 pix ==1/8
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
/*
static void render_logo(void) {
  static const char PROGMEM my_logo[] = {
0x1f, 0x0f, 0xc7, 0xe3, 0xe1, 0x01, 0xf8, 0xfc, 0xfc, 0x3e, 0x1e, 0x9e, 0x9e, 0x9e, 0x9e, 0x1e,
0x1e, 0x9e, 0x9e, 0x9e, 0x9e, 0x1e, 0x3e, 0x7e, 0xfc, 0xf8, 0x01, 0x01, 0xe3, 0xe7, 0x07, 0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x3f, 0x1c, 0x80, 0xc1, 0xf3, 0xf3, 0xf1, 0x00,
0x00, 0x7f, 0x7f, 0x7f, 0x3f, 0x1f, 0x80, 0xc0, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00, 0x00, 0x7f, 0x3f, 0x0f, 0xc0, 0x03, 0x07, 0xcf, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef,
0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xc7, 0x07, 0x20, 0x80, 0x0f, 0x3f, 0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xe0, 0xc0, 0x80, 0x8c, 0x83, 0x90, 0x9c, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f,
0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9e, 0x98, 0x80, 0x82, 0x8c, 0xc0, 0xe0
  };
  oled_write_raw_P(my_logo, sizeof(my_logo));
}
*/ 

//RD Logo x3
/*
static void render_logo(void) {
  static const char PROGMEM my_logo[] = {
0x1f, 0x0f, 0xc7, 0xe3, 0xe1, 0x01, 0xf8, 0xfc, 0xfc, 0x3e, 0x1e, 0x9e, 0x9e, 0x9e, 0x9e, 0x1e,
0x1e, 0x9e, 0x9e, 0x9e, 0x9e, 0x1e, 0x3e, 0x7e, 0xfc, 0xf8, 0x01, 0x01, 0xe3, 0xe7, 0x07, 0x1f,
0x1f, 0x0f, 0xc7, 0xe3, 0xe1, 0x01, 0xf8, 0xfc, 0xfc, 0x3e, 0x1e, 0x9e, 0x9e, 0x9e, 0x9e, 0x1e,
0x1e, 0x9e, 0x9e, 0x9e, 0x9e, 0x1e, 0x3e, 0x7e, 0xfc, 0xf8, 0x01, 0x01, 0xe3, 0xe7, 0x07, 0x1f,
0x1f, 0x0f, 0xc7, 0xe3, 0xe1, 0x01, 0xf8, 0xfc, 0xfc, 0x3e, 0x1e, 0x9e, 0x9e, 0x9e, 0x9e, 0x1e,
0x1e, 0x9e, 0x9e, 0x9e, 0x9e, 0x1e, 0x3e, 0x7e, 0xfc, 0xf8, 0x01, 0x01, 0xe3, 0xe7, 0x07, 0x1f,
0x1f, 0x0f, 0xc7, 0xe3, 0xe1, 0x01, 0xf8, 0xfc, 0xfc, 0x3e, 0x1e, 0x9e, 0x9e, 0x9e, 0x9e, 0x1e,
0x1e, 0x9e, 0x9e, 0x9e, 0x9e, 0x1e, 0x3e, 0x7e, 0xfc, 0xf8, 0x01, 0x01, 0xe3, 0xe7, 0x07, 0x1f,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//
0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x3f, 0x1c, 0x80, 0xc1, 0xf3, 0xf3, 0xf1, 0x00,
0x00, 0x7f, 0x7f, 0x7f, 0x3f, 0x1f, 0x80, 0xc0, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x3f, 0x1c, 0x80, 0xc1, 0xf3, 0xf3, 0xf1, 0x00,
0x00, 0x7f, 0x7f, 0x7f, 0x3f, 0x1f, 0x80, 0xc0, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x3f, 0x1c, 0x80, 0xc1, 0xf3, 0xf3, 0xf1, 0x00,
0x00, 0x7f, 0x7f, 0x7f, 0x3f, 0x1f, 0x80, 0xc0, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x3f, 0x1c, 0x80, 0xc1, 0xf3, 0xf3, 0xf1, 0x00,
0x00, 0x7f, 0x7f, 0x7f, 0x3f, 0x1f, 0x80, 0xc0, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//
0x00, 0x00, 0x7f, 0x3f, 0x0f, 0xc0, 0x03, 0x07, 0xcf, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef,
0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xc7, 0x07, 0x20, 0x80, 0x0f, 0x3f, 0x00, 0x00,
0x00, 0x00, 0x7f, 0x3f, 0x0f, 0xc0, 0x03, 0x07, 0xcf, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef,
0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xc7, 0x07, 0x20, 0x80, 0x0f, 0x3f, 0x00, 0x00,
0x00, 0x00, 0x7f, 0x3f, 0x0f, 0xc0, 0x03, 0x07, 0xcf, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef,
0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xc7, 0x07, 0x20, 0x80, 0x0f, 0x3f, 0x00, 0x00,
0x00, 0x00, 0x7f, 0x3f, 0x0f, 0xc0, 0x03, 0x07, 0xcf, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef,
0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xc7, 0x07, 0x20, 0x80, 0x0f, 0x3f, 0x00, 0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//
0xe0, 0xc0, 0x80, 0x8c, 0x83, 0x90, 0x9c, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f,
0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9e, 0x98, 0x80, 0x82, 0x8c, 0xc0, 0xe0,
0xe0, 0xc0, 0x80, 0x8c, 0x83, 0x90, 0x9c, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f,
0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9e, 0x98, 0x80, 0x82, 0x8c, 0xc0, 0xe0,
0xe0, 0xc0, 0x80, 0x8c, 0x83, 0x90, 0x9c, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f,
0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9e, 0x98, 0x80, 0x82, 0x8c, 0xc0, 0xe0,
0xe0, 0xc0, 0x80, 0x8c, 0x83, 0x90, 0x9c, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f,
0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9e, 0x98, 0x80, 0x82, 0x8c, 0xc0, 0xe0,
  };
  oled_write_raw_P(my_logo, sizeof(my_logo));
}
*/
// trigger screen

// OLED Rotation enum values are flags

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status

    switch (get_highest_layer(layer_state)) {
        case _BASE:
               oled_write_P(PSTR("Default\nPlay     |    C+S+T\nMute ZM  |  ZM F_SC\n"), false); 
            break;
	case _Ll:
            oled_write_P(PSTR("Layer 1\n"), false);
            break;


    }
	
	
	
	
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

}
#endif



/*
#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _Base:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _Ll:
            oled_write_P(PSTR("Layer 1\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}
#endif
*/


void dip_switch_update_user(uint8_t index, bool active) 
{ 

         if (index == 0){		//ENC0_SW2
        if(active) //ENC2_SW2 pressed
		{ 
			tap_code(KC_MUTE);
		} 
	else //ENC2_SW2 released
                {
					
			//do nothing
		}
		 }
		 else if (index == 1){		//ENC0_SW1
        if(active) //ENC2_SW1 pressed
		{ 
			tap_code(KC_F5);
		} 
	else //ENC2_SW1 released
                {
					
			//do nothing
		}
		
		 }

 }



void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
           // tap_code(KC_VOLD);
			tap_code(KC_VOLU);
        } else {
            //tap_code(KC_VOLU);
			tap_code(KC_VOLD);
        }
    }
	else if (index == 1) { /* Second encoder */
	
	        if (clockwise) {

			//tap_code16(C(S(KC_TAB))); //big roteries 
			tap_code16(C(KC_TAB)); //small roteries 
        } else {
            //tap_code16(C(KC_TAB)); //big roteries 
			tap_code16(C(S(KC_TAB))); //small roteries 
        }
		
							}
														}


 