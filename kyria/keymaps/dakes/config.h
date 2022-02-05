/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#pragma once

#define MASTER_LEFT

#ifdef OLED_DRIVER_ENABLE
    #define OLED_DISPLAY_128X64
    #define OLED_TIMEOUT 90000
    /* #define OLED_SCROLL_TIMEOUT 10000 */
#endif

#ifdef RGBLIGHT_ENABLE
    /*
    // by j-inc: https://github.com/qmk/qmk_firmware/blob/master/keyboards/kyria/keymaps/j-inc/config.h
    #define RGBLIGHT_LED_MAP {0,1,2,9,8,7,4,3,5,6,19,18,17,10,11,12,15,16,14,13} // Orients Kyria LEDs to a circle around both halves.
    //#define RBGLIGHT_LED_MAP {9,8,6,7,5,3,2,4,1,0,10,12,13,11,14,16,17,15,18,19} // Orients Kyria LEDs for a left half-right half columnar progression.
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    //#define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_SLEEP
     */

    // #define RGBLIGHT_ANIMATIONS
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_HUE_STEP 16
    #define RGBLIGHT_SAT_STEP 16
    #define RGBLIGHT_VAL_STEP 16
    #define RGBLIGHT_LIMIT_VAL 175
#endif

#define ENCODER_RESOLUTION 2
#define ENCODER_DIRECTION_FLIP

#define UNICODE_SELECTED_MODES UC_LNX

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK


// optimizations from https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#ifndef NO_DEBUG
    #define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
    #define NO_PRINT
#endif // !NO_PRINT

// needed for tap code mod hold
// #define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
#define TAPPING_FORCE_HOLD
#define DISABLE_LEADER

#define DEBUG_MATRIX_SCAN_RATE

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 225
// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD


// Trackball
// #define TRACKBALL_NO_MATH
#define TRACKBALL_ANGLE_OFFSET 0
#define TRACKBALL_ORIENTATION 3
#define TRACKBALL_REVERSE_HSCROLL false
#define TRACKBALL_ACCELERATION_WINDOW 50000 // ms window to increase acceleration factor


