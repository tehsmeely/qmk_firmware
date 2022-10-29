#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE  0
#define _SYM   1
#define _MEDIA 2

#define M_SYM MO(_SYM)
#define M_MED MO(_MEDIA)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [_BASE] = LAYOUT_5x6_2_5(
     KC_ESC , KC_1  , KC_2   , KC_3   , KC_4   , KC_5   ,                         KC_6   , KC_7  , KC_8   , KC_9  , KC_0   , KC_BSPC ,
     KC_TAB , KC_Q  , KC_W   , KC_E   , KC_R   , KC_T   ,                         KC_Y   , KC_U  , KC_I   , KC_O  , KC_P   , KC_MINS ,
     KC_LSFT, KC_A  , KC_S   , KC_D   , KC_F   , KC_G   ,                         KC_H   , KC_J  , KC_K   , KC_L  , KC_SCLN, KC_QUOT ,
     KC_LCTL, KC_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,                         KC_N   , KC_M  , KC_COMM, KC_DOT, KC_SLSH, KC_BSLASH,
                      KC_LEFT, KC_RGHT, KC_SPC , KC_BSPC, KC_HOME,       KC_PGUP, KC_BSPC, KC_ENT, KC_UP  , KC_DOWN
                                               , M_SYM  , KC_END,        KC_PGDN, M_MED
  ),

  [_SYM] = LAYOUT_5x6_2_5(
      KC_ESC , KC_1  , KC_2   , KC_3   , KC_4   , KC_5   ,                         KC_6   , KC_7  , KC_8   , KC_9  , KC_0   , KC_BSPC ,
      KC_TAB , KC_Q  , KC_W   , KC_E   , KC_R   , KC_T   ,                         KC_Y   , KC_U  , KC_I   , KC_O  , KC_P   , KC_MINS ,
      KC_LSFT, KC_A  , KC_S   , KC_D   , KC_F   , KC_G   ,                         KC_H   , KC_J  , KC_K   , KC_L  , KC_SCLN, KC_QUOT ,
      KC_LCTL, KC_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,                         KC_N   , KC_M  , KC_COMM, KC_DOT, KC_SLSH, KC_BSLASH,
                       KC_LEFT, KC_RGHT, KC_SPC , KC_BSPC, KC_HOME,       KC_PGUP, KC_BSPC, KC_ENT, KC_UP  , KC_DOWN
                                                , M_SYM  , KC_END,        KC_PGDN, M_MED
  ),

  [_MEDIA] = LAYOUT_5x6_2_5(
    KC_ESC , KC_1  , KC_2   , KC_3   , KC_4   , KC_5   ,                         KC_6   , KC_7  , KC_8   , KC_9  , KC_0   , KC_BSPC ,
    KC_TAB , KC_Q  , KC_W   , KC_E   , KC_R   , KC_T   ,                         KC_Y   , KC_U  , KC_I   , KC_O  , KC_P   , KC_MINS ,
    KC_LSFT, KC_A  , KC_S   , KC_D   , KC_F   , KC_G   ,                         KC_H   , KC_J  , KC_K   , KC_L  , KC_SCLN, KC_QUOT ,
    KC_LCTL, KC_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,                         KC_N   , KC_M  , KC_COMM, KC_DOT, KC_SLSH, KC_BSLASH,
                     KC_LEFT, KC_RGHT, KC_SPC , KC_BSPC, KC_HOME,       KC_PGUP, KC_BSPC, KC_ENT, KC_UP  , KC_DOWN
                                              , M_SYM  , KC_END,        KC_PGDN, M_MED
  ),
};


