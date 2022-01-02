#include "jatreus.h"

enum layer {
    _BASE,
    _SYMBOLS,
    _SPECIAL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT(
		KC_Q, KC_W, KC_E, KC_R, KC_T,                                   KC_Y, KC_U, KC_I, KC_O, KC_P,
		KC_A, KC_S, KC_D, KC_F, KC_G,                                   KC_H, KC_J, KC_K, KC_L, KC_SCLN,
		MT(KC_LEFT_CTRL,KC_Z), KC_X, KC_C, KC_V, KC_B, KC_LCTL,         KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
		KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, MO(_SPECIAL), KC_SPC, KC_ENTER, MO(_SYMBOLS), KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_LALT),

	[_SYMBOLS] = LAYOUT(
		KC_1, KC_2, KC_3, KC_4, KC_5,                       KC_6, KC_7, KC_8, KC_9, KC_0,
		KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, S(KC_BSLS),      KC_TRNS, KC_PGUP, KC_UP, KC_PGDN, KC_INS,
		KC_NUHS, KC_BSLS, S(KC_9), S(KC_0), KC_GRV,         KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_SPECIAL] = LAYOUT(
	    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                          KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
	    CK_LED_ANIM_TOGGLE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_VOLU, KC_TRNS, KC_TRNS, KC_F11, KC_F12,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_VOLD, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {
}