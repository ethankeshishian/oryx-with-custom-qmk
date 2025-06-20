#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  ST_MACRO_15,
  ST_MACRO_16,
  ST_MACRO_17,
  ST_MACRO_18,
  ST_MACRO_19,
  ST_MACRO_20,
  ST_MACRO_21,
  ST_MACRO_22,
  ST_MACRO_23,
  ST_MACRO_24,
  ST_MACRO_25,
  ST_MACRO_26,
  ST_MACRO_27,
  ST_MACRO_28,
  ST_MACRO_29,
  ST_MACRO_30,
  ST_MACRO_31,
  ST_MACRO_32,
  ST_MACRO_33,
  ST_MACRO_34,
  ST_MACRO_35,
  ST_MACRO_36,
  ST_MACRO_37,
  ST_MACRO_38,
  ST_MACRO_39,
  ST_MACRO_40,
  ST_MACRO_41,
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    LCTL(KC_TAB),   KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           LGUI(LCTL(KC_Q)),
    LALT(KC_TAB),   KC_Q,           KC_W,           ALL_T(KC_F),    MEH_T(KC_P),    KC_B,                                           KC_J,           MEH_T(KC_L),    ALL_T(KC_U),    KC_Y,           KC_SCLN,        KC_BSLS,        
    KC_ESCAPE,      MT(MOD_LCTL, KC_A),MT(MOD_LALT, KC_R),MT(MOD_LGUI, KC_S),MT(MOD_LSFT, KC_T),KC_G,                                           KC_M,           MT(MOD_RSFT, KC_N),MT(MOD_RGUI, KC_E),MT(MOD_RALT, KC_I),MT(MOD_RCTL, KC_O),KC_QUOTE,       
    CW_TOGG,        KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                                           KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_DELETE,      
                                                    LT(4, KC_ENTER),KC_TAB,                                         KC_BSPC,        KC_SPACE
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ALL_T(KC_F),    MEH_T(KC_P),    KC_TRANSPARENT,                                 KC_TRANSPARENT, MEH_T(KC_L),    ALL_T(KC_U),    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, MT(MOD_LCTL, KC_A),MT(MOD_LALT, KC_R),MT(MOD_LGUI, KC_S),MT(MOD_LSFT, KC_T),KC_TRANSPARENT,                                 KC_TRANSPARENT, MT(MOD_RSFT, KC_N),MT(MOD_RGUI, KC_E),MT(MOD_RALT, KC_I),MT(MOD_RCTL, KC_O),KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 LT(5, KC_BSPC), LT(4, KC_SPACE)
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(LGUI(LSFT(KC_LEFT_CTRL))),LALT(LSFT(KC_LEFT_CTRL)),KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    KC_LEFT_SHIFT,  KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 LT(5, KC_BSPC), LT(4, KC_SPACE)
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LALT(LSFT(KC_LEFT_CTRL)),LALT(LGUI(LSFT(KC_LEFT_CTRL))),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_RIGHT_SHIFT, KC_RIGHT_GUI,   KC_RIGHT_ALT,   KC_RIGHT_CTRL,  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 LT(5, KC_BSPC), LT(4, KC_SPACE)
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TILD,        KC_GRAVE,       KC_LBRC,        KC_RBRC,        KC_NO,                                          KC_NO,          KC_MINUS,       KC_PLUS,        KC_NO,          KC_COLN,        KC_PIPE,        
    KC_TRANSPARENT, KC_MINUS,       KC_UNDS,        KC_LPRN,        KC_RPRN,        KC_NO,                                          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,          KC_DQUO,        
    KC_CAPS,        LALT(KC_MINUS), LALT(LSFT(KC_MINUS)),KC_LCBR,        KC_RCBR,        KC_NO,                                          KC_NO,          KC_EQUAL,       KC_LABK,        KC_RABK,        KC_QUES,        KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_DELETE,      KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, RGB_VAD,        RGB_VAI,        KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,LGUI(LCTL(KC_SPACE)),                                KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_F12,         
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,     ST_MACRO_3,     ST_MACRO_4,                                     KC_NO,          ST_MACRO_11,    ST_MACRO_12,    ST_MACRO_13,    ST_MACRO_14,    KC_NO,          
    KC_TRANSPARENT, ST_MACRO_5,     ST_MACRO_6,     ST_MACRO_7,     ST_MACRO_8,     ST_MACRO_9,                                     ST_MACRO_15,    ST_MACRO_16,    ST_MACRO_17,    ST_MACRO_18,    ST_MACRO_19,    ST_MACRO_20,    
    ST_MACRO_10,    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          LGUI(KC_1),     LGUI(KC_2),     LGUI(KC_3),     LGUI(KC_4),     LGUI(KC_5),     
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, RGB_VAD,        RGB_VAI,        KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,LGUI(LCTL(KC_SPACE)),                                KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_F12,         
    KC_TRANSPARENT, ST_MACRO_21,    ST_MACRO_22,    ST_MACRO_23,    ST_MACRO_24,    ST_MACRO_25,                                    ST_MACRO_32,    ST_MACRO_33,    ST_MACRO_34,    ST_MACRO_35,    ST_MACRO_36,    ST_MACRO_37,    
    ST_MACRO_26,    ST_MACRO_27,    ST_MACRO_28,    ST_MACRO_29,    ST_MACRO_30,    ST_MACRO_31,                                    KC_TRANSPARENT, ST_MACRO_38,    ST_MACRO_39,    ST_MACRO_40,    ST_MACRO_41,    KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  '*', '*', '*', '*'
);

const uint16_t PROGMEM combo0[] = { KC_SPACE, LT(4, KC_ENTER), COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_BSPC, KC_TAB, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, OSL(4)),
    COMBO(combo1, TT(7)),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_X:
            return TAPPING_TERM + 35;
        case KC_C:
            return TAPPING_TERM + 35;
        case KC_D:
            return TAPPING_TERM + 35;
        case LT(4, KC_ENTER):
            return TAPPING_TERM -15;
        case KC_TAB:
            return TAPPING_TERM -45;
        case KC_H:
            return TAPPING_TERM + 35;
        case KC_COMMA:
            return TAPPING_TERM + 35;
        case KC_DOT:
            return TAPPING_TERM + 35;
        case KC_BSPC:
            return TAPPING_TERM + 15;
        case KC_SPACE:
            return TAPPING_TERM + 15;
        case KC_NO:
            return TAPPING_TERM + 35;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245} },

    [1] = { {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {74,255,255}, {74,255,255}, {139,220,245}, {139,220,245}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {74,255,255}, {74,255,255}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {74,255,255}, {74,255,255} },

    [2] = { {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {74,255,255}, {74,255,255}, {139,220,245}, {139,220,245}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {74,255,255}, {74,255,255} },

    [3] = { {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {74,255,255}, {74,255,255}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {139,220,245}, {74,255,255}, {74,255,255} },

    [4] = { {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255} },

    [5] = { {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_1));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_2));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_3));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_4));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_5));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_1));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_2));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_3));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_4));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_5));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_B))SS_DELAY(100)  SS_TAP(X_LBRC));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_LSFT(SS_TAP(X_5)));
    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_LSFT(SS_TAP(X_QUOTE)));
    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_LSFT(SS_TAP(X_E)));
    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_X));
    }
    break;
    case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_D));
    }
    break;
    case ST_MACRO_16:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_C));
    }
    break;
    case ST_MACRO_17:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_L));
    }
    break;
    case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_W));
    }
    break;
    case ST_MACRO_19:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_LSFT(SS_TAP(X_7)));
    }
    break;
    case ST_MACRO_20:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_S));
    }
    break;
    case ST_MACRO_21:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_1));
    }
    break;
    case ST_MACRO_22:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_2));
    }
    break;
    case ST_MACRO_23:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_3));
    }
    break;
    case ST_MACRO_24:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_4));
    }
    break;
    case ST_MACRO_25:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_5));
    }
    break;
    case ST_MACRO_26:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_B))SS_DELAY(100)  SS_TAP(X_LBRC));
    }
    break;
    case ST_MACRO_27:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_1));
    }
    break;
    case ST_MACRO_28:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_2));
    }
    break;
    case ST_MACRO_29:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_3));
    }
    break;
    case ST_MACRO_30:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_4));
    }
    break;
    case ST_MACRO_31:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_5));
    }
    break;
    case ST_MACRO_32:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_D));
    }
    break;
    case ST_MACRO_33:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_C));
    }
    break;
    case ST_MACRO_34:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_L));
    }
    break;
    case ST_MACRO_35:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_W));
    }
    break;
    case ST_MACRO_36:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_LSFT(SS_TAP(X_7)));
    }
    break;
    case ST_MACRO_37:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_S));
    }
    break;
    case ST_MACRO_38:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_LSFT(SS_TAP(X_5)));
    }
    break;
    case ST_MACRO_39:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_LSFT(SS_TAP(X_QUOTE)));
    }
    break;
    case ST_MACRO_40:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_LSFT(SS_TAP(X_E)));
    }
    break;
    case ST_MACRO_41:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_S))SS_DELAY(100)  SS_TAP(X_X));
    }
    break;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

/* CUSTOM */
/*───────────────────────────────────────────────────────────────────────────────
 *  Opposite-Hand Lock for Home-Row Mod-Taps
 *
 *  - First home-row mod-tap that outlasts TAPPING_TERM becomes “the holder”.
 *  - While a holder exists, every mod-tap on the *other* hand is forced to send
 *    its tap key immediately (no modifier) and is ignored for tap/hold logic.
 *  - Lock clears automatically when the last held mod-tap on the holder’s hand
 *    is released.
 *
 *  Drop this at the bottom of keymap.c (or a separate .c).  No edits elsewhere.
 *─────────────────────────────────────────────────────────────────────────────*/

typedef enum { HAND_NONE = 0, HAND_LEFT, HAND_RIGHT } hand_t;

/* Map matrix position to hand using your existing ‘chordal_hold_layout’. */
static inline hand_t hand_of(uint8_t r, uint8_t c) {
    char s = pgm_read_byte(&chordal_hold_layout[r][c]);
    return s == 'L' ? HAND_LEFT : s == 'R' ? HAND_RIGHT : HAND_NONE;
}

/* Helpers for identifying generic mod-taps (covers MT/ALL_T/MEH_T/…). */
static inline bool     is_mt(uint16_t kc)  { return (kc & 0xF000u) == QK_MOD_TAP; }
static inline uint16_t tapkc(uint16_t kc)  { return kc & 0x00FFu; }

/* ───────── state ───────── */
static hand_t   hold_hand        = HAND_NONE;   /* which hand is locked        */
static hand_t   candidate_hand   = HAND_NONE;   /* first key awaiting TT       */
static uint16_t candidate_timer  = 0;
static uint8_t  down_left        = 0;           /* held mod-taps per hand      */
static uint8_t  down_right       = 0;

/* ───────── key events ───────── */
bool process_record_kb(uint16_t kc, keyrecord_t *rec) {
    hand_t h = hand_of(rec->event.key.row, rec->event.key.col);

    /* If a lock is active and this is an opposite-hand mod-tap → tap & bail */
    if (rec->event.pressed && hold_hand != HAND_NONE &&
        h != hold_hand && is_mt(kc)) {
        tap_code16(tapkc(kc));
        return false;                 /* skip normal processing for this key   */
    }

    /* Normal bookkeeping for potential holders                           */
    if (is_mt(kc)) {
        if (rec->event.pressed) {
            if (h == HAND_LEFT)  down_left++;
            if (h == HAND_RIGHT) down_right++;

            if (hold_hand == HAND_NONE && candidate_hand == HAND_NONE) {
                candidate_hand  = h;
                candidate_timer = timer_read();
            }
        } else {                      /* key released                          */
            if (h == HAND_LEFT  && down_left)  down_left--;
            if (h == HAND_RIGHT && down_right) down_right--;

            if (h == hold_hand &&
                ((h == HAND_LEFT  && !down_left) ||
                 (h == HAND_RIGHT && !down_right)))
                hold_hand = HAND_NONE;                /* lock lifted          */

            if (h == candidate_hand) candidate_hand = HAND_NONE;
        }
    }
    return process_record_user(kc, rec);       /* fall through to your code     */
}

/* ───────── periodic check ───────── */
void matrix_scan_kb(void) {
    if (hold_hand == HAND_NONE && candidate_hand != HAND_NONE &&
        timer_elapsed(candidate_timer) > TAPPING_TERM) {
        hold_hand      = candidate_hand;       /* candidate becomes holder      */
        candidate_hand = HAND_NONE;
    }
    matrix_scan_user();                        /* preserve any user scan logic  */
}
