#include "jatreus.h"

#define char_len(x)  (sizeof(x) / sizeof(char))

void set_layer_led_0(void);
void set_layer_led_1(void);
void set_layer_led_2(void);
void led_animation_update(void);
void set_leds(char);
void toggle_led_animation(void);

// Layer Indicators:
// ILED0 - Left  Red   : F6
// ILED1 - Right Green : B3
//
// Back Display:
// LED0 - Left Blue  : F5
// LED1 - Left Green : F4
// LED2 - Right Red  : B2
// LED3 - Right Blue : B1
#define LED_LEFT_BLUE       F5
#define LED_LEFT_GREEN      F4
#define LED_RIGHT_RED       B2
#define LED_RIGHT_BLUE      B1
#define LED_LAYER_RIGHT     B3
#define LED_LAYER_LEFT      F6

#define LED_ANIMATION_TICK 500

enum layer_names {
    _BASE,
    _SYMBOLS,
    _SPECIAL
};

/*
enum custom_keycodes {
    CK_LED_ANIM_TOGGLE = SAFE_RANGE
};
 */

const char *animation_programs;


// const? it upsets the compiler...
char flash[] = {0b0000, 0b1111};
char fancy_flash[] = {0b1001, 0b0110, 0b0000, 0b1111, 0b0000};

static uint16_t led_animation_timer;
bool led_animation_on = false;
int led_animation_counter = 0;
int led_animation_mode = 0;
int led_animation_counter_max = 0;
char *current_led_animation;


void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up
}

void matrix_scan_kb(void) {
    // put your looping keyboard code here
    // runs every cycle (a lot)
    led_animation_update();
}

void keyboard_pre_init_kb(void) {
    // Set LED pins as output
    setPinOutput(LED_LAYER_LEFT);
    setPinOutput(LED_LAYER_RIGHT);
    setPinOutput(LED_LEFT_BLUE);
    setPinOutput(LED_LEFT_GREEN);
    setPinOutput(LED_RIGHT_RED);
    setPinOutput(LED_RIGHT_BLUE);
    writePinLow(LED_LAYER_LEFT);
    writePinLow(LED_LAYER_RIGHT);
    writePinLow(LED_LEFT_BLUE);
    writePinLow(LED_LEFT_GREEN);
    writePinLow(LED_RIGHT_RED);
    writePinLow(LED_RIGHT_BLUE);
}

void led_animation_update(void) {
    if (led_animation_on) {
        if (timer_elapsed(led_animation_timer) > LED_ANIMATION_TICK) {
            led_animation_timer = timer_read();
            led_animation_counter++;
            if (led_animation_counter >= led_animation_counter_max) {
                led_animation_counter = 0;
            }
            set_leds(current_led_animation[led_animation_counter]);
        }
    }
}

void toggle_led_animation(void) {
    led_animation_mode++;
    if (led_animation_mode > 3) {
        led_animation_mode = 0;
    }

    led_animation_timer = timer_read();
    switch (led_animation_mode) {
        case 0:
            led_animation_on = 0;
            set_leds(0b0000);
            break;
        case 1:
            led_animation_on = 0;
            set_leds(0b1111);
            break;
        case 2:
            current_led_animation = flash;
            led_animation_counter_max = 2;
            led_animation_on = 1;
            break;
        case 3:
            current_led_animation = fancy_flash;
            led_animation_counter_max = 5;
            led_animation_on = 1;
            break;
    }
}

void set_leds(char leds) {
    if (leds & 0b1000) {
        writePinHigh(LED_LEFT_BLUE);
    } else {
        writePinLow(LED_LEFT_BLUE);
    }
    if (leds & 0b0100) {
        writePinHigh(LED_LEFT_GREEN);
    } else {
        writePinLow(LED_LEFT_GREEN);
    }
    if (leds & 0b0010) {
        writePinHigh(LED_RIGHT_RED);
    } else {
        writePinLow(LED_RIGHT_RED);
    }
    if (leds & 0b0001) {
        writePinHigh(LED_RIGHT_BLUE);
    } else {
        writePinLow(LED_RIGHT_BLUE);
    }
}


bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_LED_ANIM_TOGGLE:
            if (record->event.pressed) {
                toggle_led_animation();
                // Do something when pressed
            } else {
                // Do something else when release
            }
            return false; // Skip all further processing of this key
        default:
            return true; // Process all other keycodes normally
    }
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
    writePinLow(LED_LAYER_LEFT);
    writePinLow(LED_LAYER_RIGHT);

    // DEBUG
    //writePinLow(LED_LEFT_BLUE);
    //writePinLow(LED_LEFT_GREEN);
    //writePinLow(LED_RIGHT_RED);
    //writePinLow(LED_RIGHT_BLUE);
}
void set_layer_led_1(void) {
    writePinHigh(LED_LAYER_LEFT);
    writePinLow(LED_LAYER_RIGHT);

    // DEBUG
    //writePinHigh(LED_LEFT_BLUE);
    //writePinHigh(LED_LEFT_GREEN);
    //writePinHigh(LED_RIGHT_RED);
    //writePinHigh(LED_RIGHT_BLUE);
}
void set_layer_led_2(void) {
    writePinLow(LED_LAYER_LEFT);
    writePinHigh(LED_LAYER_RIGHT);
}