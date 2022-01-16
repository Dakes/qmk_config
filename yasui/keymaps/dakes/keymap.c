/* Copyright 2021 Daniel Ostertag (Dakes) <dakes@vivaldi.net>
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
    _NEO = 0,
    _QWERTZ,
    _GAMING,
    _LAYER_3,
    _LAYER_4,
    _FUNC
};

uint8_t base_layers[3] = {_NEO, _QWERTZ, _GAMING};
uint8_t current_base_layer = _NEO;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_NEO] = LAYOUT(
		KC_X, KC_V, KC_L, KC_C, KC_W, KC_K, KC_H, KC_G,    KC_F,   KC_Q,
		KC_U, KC_I, KC_A, KC_E, KC_O, KC_S, KC_N, KC_R,    KC_T,   KC_D,
		DE_MINS, _______, KC_Y, KC_P, DE_Z, KC_B, KC_M, KC_COMM, KC_DOT, KC_J,
		#ifdef TWO_2U
		OSM(KC_LCTL), OSM(KC_LSFT), KC_LGUI, LT(_LAYER_4, KC_ENT), _______, _______, LT(_LAYER_3, KC_SPC), OSM(KC_LALT), KC_BSPC, OSM(KC_LSFT)
        #endif
    ),
	
	[_QWERTZ] = LAYOUT(
		KC_Q, KC_W, KC_E, KC_R, KC_T, DE_Z, KC_U, KC_I, KC_O, KC_P,
		KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, _______,
		KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, DE_MINS,
		#ifdef TWO_2U
		KC_LCTL, KC_LSFT, KC_LGUI, LT(_LAYER_4, KC_ENT), _______, _______, LT(_LAYER_3, KC_SPC), KC_LALT, KC_BSPC, KC_LSFT
        #endif
	),

	[_GAMING] = LAYOUT(
		KC_ESC, _______,  KC_Q, KC_W, KC_E, DE_R, KC_T, KC_Y, KC_U, KC_I,
		KC_TAB, KC_LSFT,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,
		_______, _______, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, DE_COMM,
		#ifdef TWO_2U
		KC_LCTL, KC_LSFT, KC_LGUI, LT(_LAYER_4, KC_ENT), _______, _______, KC_SPC, KC_LALT, LT(_LAYER_4, KC_BSPC), LT(_LAYER_3, KC_LSFT)
	    #endif
	),

    // Layer 3 symbols
    [_LAYER_3] = LAYOUT(
        DE_DEG,  DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC, DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR,
        DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN,
        DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_GRV , DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, 
		DE_SECT, DE_EURO, DE_AT,   _______, _______, _______, _______, _______, _______, _______
    ),

    // Layer 4 Nav and Numpad
    [_LAYER_4] = LAYOUT(
        KC_PGUP,    KC_BSPC, KC_UP,     KC_DELETE, KC_PGDOWN, DE_ASTR, KC_7, KC_8, KC_9, DE_PLUS,
        KC_HOME,    KC_LEFT, KC_DOWN,   KC_RIGHT,  KC_END,    DE_SLSH, KC_4, KC_5, KC_6, KC_COMM,
        KC_ESCAPE,  KC_TAB,  KC_INSERT, KC_ENTER,  KC_UNDO,   DE_COLN, KC_1, KC_2, KC_3, KC_DOT,
        #ifdef TWO_2U
		_______, _______, _______, _______, _______, _______, KC_0, DE_EQL, DE_MINS, DE_SCLN
        #endif
	),
		
	// Function Layer: F-keys, media, layer switch
    [_FUNC] = LAYOUT(
        DF(_NEO), DF(_QWERTZ), DF(_GAMING), XXXXXXX, XXXXXXX, KC_MUTE, KC_F7,   KC_F8,   KC_F9,   KC_F10,
        XXXXXXX,    XXXXXXX,     KC_MPRV,     KC_MNXT, KC_MPLY, KC_VOLU, KC_F4,   KC_F5,   KC_F6,   KC_F11,
        RESET,      XXXXXXX,     XXXXXXX,     XXXXXXX, XXXXXXX, KC_VOLD, KC_F1,   KC_F2,   KC_F3,   KC_F12,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

};


// called on every keypress
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    numlock_off();
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state)
{
    // this will switch to layer _FUNC, if any of those configurations got pressed.
    /* layer_state_t tmp = state; */
    state = update_tri_layer_state(state, _LAYER_3, _LAYER_4, _FUNC);

    return state;
}
