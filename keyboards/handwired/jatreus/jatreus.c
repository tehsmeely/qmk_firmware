#include "jatreus.h"

void set_layer_led_0(void);
void set_layer_led_1(void);
void set_layer_led_2(void);

enum layer_names {
    _BASE,
    _SYMBOLS,
    _SPECIAL
};

void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up
}

void matrix_scan_kb(void) {
    // put your looping keyboard code here
    // runs every cycle (a lot)
}

void keyboard_pre_init_kb(void) {
    // Set LED pins as output
    // Layer Indicators:
    // ILED0 - Left  Red   : F6
    // ILED1 - Right Green : B3
    //
    // Back Display:
    // LED0 - Left Blue  : F5
    // LED1 - Left Green : F4
    // LED2 - Right Red  : B2
    // LED3 - Right Blue : B1
    setPinOutput(F6);
    setPinOutput(B3);
    setPinOutput(F5);
    setPinOutput(F4);
    setPinOutput(B2);
    setPinOutput(B1);
    writePinLow(F6);
    writePinLow(B3);
    writePinLow(F5);
    writePinLow(F4);
    writePinLow(B2);
    writePinLow(B1);
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _BASE:
            set_layer_led_0();
            break;
        case _SYMBOLS:
            set_layer_led_1();
            break;
        case _SPECIAL:
            set_layer_led_2();
            break;
        default:
            set_layer_led_0();
            break;
    }
    return state;
}

void set_layer_led_0(void) {
    writePinLow(F6);
    writePinLow(B3);

    // DEBUG
    writePinLow(F5);
    writePinLow(F4);
    writePinLow(B2);
    writePinLow(B1);
}
void set_layer_led_1(void) {
    writePinHigh(F6);
    writePinLow(B3);

    // DEBUG
    writePinHigh(F5);
    writePinHigh(F4);
    writePinHigh(B2);
    writePinHigh(B1);
}
void set_layer_led_2(void) {
    writePinLow(F6);
    writePinHigh(B3);
}