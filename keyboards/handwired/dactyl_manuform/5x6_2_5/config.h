/*
Copyright 2020 Jan Christoph Ebersbach

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 12
#define MATRIX_COLS 6

// From doc, right to left on columns (As col0 from underneath is col5 from top)
#define MATRIX_COL_PINS { E6, D7, C6, D4, D2, D3 }
#define MATRIX_ROW_PINS { B4, B5, B6, B2, B3, B1 }

// HIGH: LEFT.    LOW: RIGHT
#define SPLIT_HAND_PIN F7

#define USE_I2C


#define DIODE_DIRECTION COL2ROW

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

#define BOOTMAGIC_LITE_ROW_RIGHT 6
#define BOOTMAGIC_LITE_COLUMN_RIGHT 5

