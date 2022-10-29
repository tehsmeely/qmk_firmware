/* Copyright 2021 Jan Christoph Ebersbach
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
void set_layer_led_0(void);
void set_layer_led_1(void);
void set_layer_led_2(void);

#include "5x6_2_5.h"

#define LED_LAYER_SYM    F6
#define LED_LAYER_MED    F5

enum layer_names {
    _BASE,
    _SYMBOLS,
    _MEDIA
};

void keyboard_pre_init_kb(void) {
    // Set LED pins as output
    setPinOutput(LED_LAYER_SYM);
    setPinOutput(LED_LAYER_MED);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _BASE:
            set_layer_led_0();
            break;
        case _SYMBOLS:
            set_layer_led_1();
            break;
        case _MEDIA:
            set_layer_led_2();
            break;
        default:
            set_layer_led_0();
            break;
    }
    return state;
}

void set_layer_led_0(void) {
    writePinLow(LED_LAYER_SYM);
    writePinLow(LED_LAYER_MED);
}
void set_layer_led_1(void) {
    writePinHigh(LED_LAYER_SYM);
    writePinLow(LED_LAYER_MED);
}
void set_layer_led_2(void) {
    writePinLow(LED_LAYER_SYM);
    writePinHigh(LED_LAYER_MED);
}
