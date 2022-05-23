/* Copyright 2022 Daniel Ostertag (Dakes) <dakes@vivaldi.net>
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
#include QMK_KEYBOARD_H
#include "keymap_german.h"

#include "dakes.h"

enum layers
{
    _COLEMAK_DH = 0,
    _TARMAK,
    _QWERTZ,
    _GAMING,
    _SYM,
    _NAV_NUM,
    _FUNC
};

enum custom_keycodes {
    COLEMAK_DH = SAFE_RANGE,
    TARMAK,
    QWERTZ,
    GAMING,
};

uint8_t base_layers[4] = {_COLEMAK_DH, _TARMAK, _QWERTZ, _GAMING};
uint8_t current_base_layer = _TARMAK;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* COLEMAK_DH
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | Ö      | Backsp |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | F      | P      | B      | 7      | 8      | 9      | J      | L      | U      | Y      | - _    | Ü/AltGr|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | LSHIFT | A/SHFT | R/GUI  | S/ALT  | T/STRG | G      | 4      | 5      | 6      | M      | N/STRG | E/ALT  | I/GUI  | O/SHFT | Ä/SHFT |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | STRG   | Z      | X      | C      | D      | V      | 1      | 2      | 3      | K      | H      | ,      | .      | UP     | ß/STRG |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | SYM LAY|NEXTSONG| PLAY/P.| GUI    | ALT    | SPACE  | ESC    | 0      | ENTER  | SPACE  | BACKSP | DEL    | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

    [_COLEMAK_DH] = LAYOUT_ortho_5x15(
    KC_ESC,   KC_F1,        KC_F2,        KC_F3,        KC_F4,          KC_F5,               KC_F6,                 KC_F7,           KC_F8,             KC_F9,                KC_F10,         KC_F11,       KC_F12,       DE_SS,        KC_BSPC,  \
    KC_TAB,   KC_Q,         KC_W,         KC_F,         KC_P,           KC_B,                KC_7,                  KC_8,            KC_9,              KC_J,                 KC_L,           KC_U,         DE_Y,         DE_MINS,      ALGR_T(DE_UDIA), \
    KC_LSFT,  LSFT_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LCTL_T(KC_T),   LT(_NAV_NUM, KC_G),  KC_4,                  KC_5,            KC_6,              LT(_NAV_NUM, KC_M),   LCTL_T(KC_N),   LALT_T(KC_E), LGUI_T(KC_I), RSFT_T(KC_O), RSFT_T(DE_ADIA), \
    KC_LCTRL, DE_Z,         KC_X,         KC_C,         LT(_SYM, KC_D), KC_V,                KC_1,                  KC_2,            KC_3,              KC_K,                 LT(_SYM, KC_H), KC_COMM,      KC_DOT,       KC_UP,        KC_RCTRL, \
    MO(_SYM), KC_MNXT,      KC_MPLY,      KC_LGUI,      KC_LALT,        LT(_SYM, KC_SPC),    LT(_NAV_NUM, KC_ENT),  LT(_FUNC, KC_0), LT(_SYM, KC_ENT),  LT(_NAV_NUM, KC_SPC), KC_BSPC,        KC_DEL,       KC_LEFT,      KC_DOWN,      KC_RIGHT  \
    ),

/* TARMAK (Transitional Tarmak)
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | ß      | Backsp |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | F      | Z      | B      | 7      | 8      | 9      | J      | U      | I      | O      | P      | Ü/AltGr|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | LSHIFT | A/SHFT | R/GUI  | S/ALT  | T/STRG | G      | 4      | 5      | 6      | H      | N/STRG | E/ALT  | L/GUI  | Ö/SHFT | Ä/SHFT |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | STRG   | Y      | X      | C      | D      | V      | 1      | 2      | 3      | K      | M      | ,      | .      | UP     |-_/STRG |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | SYM LAY|NEXTSONG| PLAY/P.| GUI    | ALT    | SPACE  | ESC    | 0      | ENTER  | SPACE  | BACKSP | DEL    | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

    [_TARMAK] = LAYOUT_ortho_5x15(
    KC_ESC,   KC_F1,        KC_F2,        KC_F3,        KC_F4,          KC_F5,               KC_F6,                 KC_F7,           KC_F8,             KC_F9,                KC_F10,         KC_F11,       KC_F12,       DE_SS,        KC_BSPC,  \
    KC_TAB,   KC_Q,         KC_W,         KC_F,         DE_Z,           KC_B,                KC_7,                  KC_8,            KC_9,              KC_J,                 KC_U,           KC_I,         KC_O,         KC_P,         ALGR_T(DE_UDIA), \
    KC_LSFT,  LSFT_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LCTL_T(KC_T),   LT(_NAV_NUM, KC_G),  KC_4,                  KC_5,            KC_6,              LT(_NAV_NUM, KC_H),   LCTL_T(KC_N),   LALT_T(KC_E), LGUI_T(KC_L), RSFT_T(DE_ODIA), RSFT_T(DE_ADIA), \
    KC_LCTRL, DE_Y,         KC_X,         KC_C,         LT(_SYM, KC_D), KC_V,                KC_1,                  KC_2,            KC_3,              KC_K,                 LT(_SYM, KC_M), KC_COMM,      KC_DOT,       KC_UP,        RCTL_T(DE_MINS), \
    MO(_SYM), KC_MNXT,      KC_MPLY,      KC_LGUI,      KC_LALT,        LT(_SYM, KC_SPC),    LT(_NAV_NUM, KC_ENT),  LT(_FUNC, KC_0), LT(_SYM, KC_ENT),  LT(_NAV_NUM, KC_SPC), KC_BSPC,        KC_DEL,       KC_LEFT,      KC_DOWN,      KC_RIGHT \
    ),

/* QWERTZ
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | ß      | Backsp |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | 7      | 8      | 9      | Z      | U      | I      | O      | P      | Ü/AltGr|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | LSHIFT | A/SHFT | S/GUI  | D/ALT  | F/STRG | G      | 4      | 5      | 6      | H      | J/STRG | K/ALT  | L/GUI  | Ö/SHFT | Ä/SHFT |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | STRG   | Y      | X      | C      | V      | B      | 1      | 2      | 3      | N      | M      | ,      | .      | UP     |-_/STRG |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | SYM LAY|NEXTSONG| PLAY/P.| GUI    | ALT    | SPACE  | ESC    | 0      | ENTER  | SPACE  | BACKSP | DEL    | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

    [_QWERTZ] = LAYOUT_ortho_5x15(
    KC_ESC,   KC_F1,        KC_F2,        KC_F3,        KC_F4,           KC_F5,               KC_F6,                 KC_F7,           KC_F8,             KC_F9,                KC_F10,         KC_F11,       KC_F12,       DE_SS,           KC_BSPC,  \
    KC_TAB,   KC_Q,         KC_W,         KC_E,         KC_R,            KC_T,                KC_7,                  KC_8,            KC_9,              DE_Z,                 KC_U,           KC_I,         KC_O,         KC_P,            ALGR_T(DE_UDIA), \
    KC_LSFT,  LSFT_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F),    LT(_NAV_NUM, KC_G),  KC_4,                  KC_5,            KC_6,              LT(_NAV_NUM, KC_H),   LCTL_T(KC_J),   LALT_T(KC_K), LGUI_T(KC_L), RSFT_T(DE_ODIA), RSFT_T(DE_ADIA), \
    KC_LCTRL, DE_Y,         KC_X,         KC_C,         LT(_SYM,  KC_V), KC_B,                KC_1,                  KC_2,            KC_3,              KC_N,                 LT(_SYM, KC_M), KC_COMM,      KC_DOT,       KC_UP,           RCTL_T(DE_MINS), \
    MO(_SYM), KC_MNXT,      KC_MPLY,      KC_LGUI,      KC_LALT,         LT(_SYM, KC_SPC),    LT(_NAV_NUM, KC_ENT),  LT(_FUNC, KC_0), LT(_SYM, KC_ENT),  LT(_NAV_NUM, KC_SPC), KC_BSPC,        KC_DEL,       KC_LEFT,      KC_DOWN,         KC_RIGHT \
    ),


/* GAMING
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | F10    | F11    | F12    | ß      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T/ALT  | F7     | F8     | F9     | Z      | U      | I      | O      | P      | Ü/AltGr|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | LSHIFT | A      | S      | D      | F      | G/SHFT | F4     | F5     | F6     | H      | J      | K      | L      | Ö      |ENTR/SHF|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | STRG   | Y      | X      | C      | V      | B/CTRL | F1     | F2     | F3     | N      | M      | ,      | .      | UP     |-_/STRG |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | STRG   |NEXTSONG| PLAY/P.| R      | ALT    | SPACE  | SHFT   | 0      | ALT    | SHFT   |SPC/CTRL| DEL    | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
    [_GAMING] = LAYOUT_ortho_5x15(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,            KC_8,     KC_9,    KC_F10,        KC_F11,  KC_F12,  DE_SS,   KC_BSPC,  \
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    LALT_T(KC_T),  KC_F7,   KC_F8,           KC_F9,    DE_Z,    KC_U,          KC_I,    KC_O,    KC_P,    ALGR_T(DE_UDIA), \
    KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    LSFT_T(KC_G),  KC_F4,   KC_F5,           KC_F6,    KC_H,    KC_J,          KC_K,    KC_L,    DE_ODIA, RSFT_T(KC_ENT), \
    KC_LCTRL, DE_Y,    KC_X,    KC_C,    KC_V,    LCTL_T(KC_B),  KC_F1,   KC_F2,           KC_F3,    KC_N,    KC_M,          KC_COMM, KC_DOT,  KC_UP,   RCTL_T(DE_MINS), \
    KC_OPER,  KC_MNXT, KC_MPLY, KC_R,    KC_LALT, KC_SPC,        KC_LSFT, LT(_FUNC, KC_0), KC_LALT,  KC_LSFT, LCTL_T(KC_SPC),KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT \
    ),

/* SYM
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |  °     |   _    |   [    |   ]    |   ^    |        |        |        |  !     |   <    |   >    |   =    |   &    |   §    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |  \     |   /    |   {    |   }    |   *    |        |        |        |  ?     |   (    |   )    |   -    |   :    |   @    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |  #     |   $    |   |    |   ~    |   `    |        |        |        |  +     |   %    |   "    |   '    |   ;    |   €    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
    [_SYM] = LAYOUT_ortho_5x15(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, DE_DEG,  DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC, KC_LBRC, KC_BSLS, KC_RBRC, DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR, DE_SECT, \
    _______, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, _______, _______, _______, DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_AT, \
    _______, DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_GRV,  _______, _______, _______, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, DE_EURO, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
    ),

/* NAV & NUMPAD
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |  PgUp  | Bksp   |  up    | del    | PgDn   |        |  MS up |        |  *     |   7    |   8    |   9    |   +    |   -    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |  home  | left   | down   | right  | end    | MS left|  MS up |MS right|  /     |   4    |   5    |   6    |   .    |   ;    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |  esc   |  tab   | insert | Mouse 1| Mouse 1| MS down|MS right|        |  :     |   1    |   2    |   3    |   ,    |   =    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        | Mouse 2|        |   X    |        |        |  0     |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
    [_NAV_NUM] = LAYOUT_ortho_5x15(
    _______, _______, _______, _______,  _______,  _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_PGUP, KC_BSPC, KC_UP,    KC_DELETE,KC_PGDOWN, _______, _______, _______, DE_ASTR, KC_7,    KC_8,    KC_9,    DE_PLUS, DE_MINS, \
    _______, KC_HOME, KC_LEFT, KC_DOWN,  KC_RIGHT, KC_END,    KC_MS_L, KC_MS_U, _______, DE_SLSH, KC_4,    KC_5,    KC_6,    KC_DOT,  DE_SCLN, \
    _______, KC_ESC,  KC_TAB,  KC_INSERT,KC_BTN1,  KC_BTN1,   KC_MS_D, KC_MS_R, _______, DE_COLN, KC_1,    KC_2,    KC_3,    KC_COMM, DE_EQL, \
    _______, _______, _______, _______,  KC_BTN2,  _______,   _______, _______, _______, KC_0,    _______, _______, _______, _______, _______  \
    ),

/* FUNC
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |RESET |COLEMAK_DH| TARMAK | QWERTZ | GAMING |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        | RESET  |        |        | BRI DN | BRI UP |        |        |        |        |  F7    |  F8    |  F9    | F10    |  F11   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        | TOG    | SAI    | HUI    | VAI    | MOD    |        |        |        | VolUp  |  F4    |  F5    |  F6    | F11    |  F12   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        | SAD    | HUD    | VAD    | RMOD   |        |        |        | VolDn  |  F1    |  F2    |  F3    | F12    |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        | Prev   | Next   |        |        |        |  Prev  | Next   |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
    [_FUNC] = LAYOUT_ortho_5x15(
    RESET,   COLEMAK_DH, TARMAK, QWERTZ, GAMING, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, _______, _______, _______, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
    _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, _______, _______, _______, KC_VOLU, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_F12, \
    _______, XXXXXXX, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, KC_VOLD, KC_F1,   KC_F2,   KC_F3,   KC_F12,  XXXXXXX, \
    _______, _______, _______, _______, KC_MPRV, KC_MNXT, _______, _______, _______, KC_MPRV, KC_MNXT, _______, _______, _______, _______ \
    ),


};

// called on led status change
void led_set_keymap(uint8_t usb_led)
{
    numlock_off();
}

// called on every keypress
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    numlock_off();
    switch (keycode)
    {
        case COLEMAK_DH:
            if (record->event.pressed)
                set_single_persistent_default_layer(_COLEMAK_DH);
            break;
        case TARMAK:
            if (record->event.pressed)
                set_single_persistent_default_layer(_TARMAK);
            break;
        case QWERTZ:
            if (record->event.pressed)
                set_single_persistent_default_layer(_QWERTZ);
            break;
        case GAMING:
            if (record->event.pressed)
                set_single_persistent_default_layer(_GAMING);
            break;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state)
{
    // this will switch to layer _FUNC, if any of those configurations got pressed.
    /* layer_state_t tmp = state; */
    /* if (get_highest_layer(state) == _FUNC) */
    /*     return state; */
    /* else */
    /*     state = update_tri_layer_state(state, _SYM, _NAV_NUM, _FUNC); */

    return state;
}

