#ifndef KB_H
#define KB_H

#include "quantum.h"

#define LAYOUT( \
	K000, K001, K002, K003, K004,             K006, K007, K008, K009, K010, \
	K100, K101, K102, K103, K104,             K106, K107, K108, K109, K110, \
	K200, K201, K202, K203, K204,             K206, K207, K208, K209, K210, \
	K300, K301, K302, K303, K304, K205, K305, K306, K307, K308, K309, K310  \
) { \
	{ K000,  K001,  K002,  K003,  K004,  KC_NO, K006,  K007,  K008,  K009,  K010 }, \
	{ K100,  K101,  K102,  K103,  K104,  KC_NO, K106,  K107,  K108,  K109,  K110 }, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210 }, \
	{ K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310 }  \
}

enum custom_keycodes {
    CK_LED_ANIM_TOGGLE = SAFE_RANGE
};

#endif