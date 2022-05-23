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
// #include <stdio.h>

#include "dakes.h"

enum layers
{
    _NEO = 0,
    _QWERTZ,
    _SYMBOL,
    _NAV_NUM,
    _FUNC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// TODO: _ ü, ö, ä, ß double tap
 [_NEO] = LAYOUT_split_3x5_3(
  //,----------------------------------------.                    ,--------------------------------------------.
     KC_X,    KC_V,    KC_L,    KC_C,    KC_W,                         KC_K,    KC_H,    KC_G,    KC_F,   KC_Q ,
  //|----+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
RSFT_T(KC_U), KC_I,    KC_A,    KC_E,    KC_O,                         KC_S,    KC_N,    KC_R,    KC_T,RSFT_T(KC_D),
  //|----+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
LCTL_T(DE_Y),DE_ODIA,DE_ADIA,   KC_P,    DE_Z,                         KC_B,    KC_M, KC_COMM, KC_DOT,RCTL_T(KC_J),
  //|----+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                KC_LGUI, KC_LALT, LT(_NAV_NUM, KC_ENT),   LT(_SYMBOL, KC_SPC), KC_BSPC, KC_DEL
                         //`--------------------------'  `--------------------------'

  ),

  [_QWERTZ] = LAYOUT_split_3x5_3(
  //,----------------------------------------.                    ,--------------------------------------------.
     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P ,
  //|----+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
RSFT_T(KC_A), KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, RSFT_T(KC_SCLN),
  //|----+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
LCTL_T(KC_Z), KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, RCTL_T(KC_SLSH),
  //|----+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                KC_LGUI, KC_LALT, LT(_NAV_NUM, KC_ENT),   LT(_SYMBOL, KC_SPC), KC_BSPC, KC_DEL
                         //`--------------------------'  `--------------------------'

  ),

  [_SYMBOL] = LAYOUT_split_3x5_3(
  //,-------------------------------------------.                    ,--------------------------------------------.
      DE_DEG, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,                      DE_EXLM, DE_LABK, DE_RABK,  DE_EQL, DE_AMPR,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                      DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_GRV ,                      DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                DE_AT  , DE_EURO, _______,    _______, DE_SECT, _______
                            //`--------------------------'  `--------------------------'
  ),

  [_NAV_NUM] = LAYOUT_split_3x5_3(
  //,-------------------------------------------.                    ,--------------------------------------------.
     KC_PGUP, KC_BSPC, KC_UP,KC_DELETE,KC_PGDOWN,                     DE_MINS,     KC_7,    KC_8,    KC_9, DE_PLUS,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,                     DE_SLSH,     KC_4,    KC_5,    KC_6, KC_DOT,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    KC_ESCAPE, KC_TAB,KC_INSERT,XXXXXXX, KC_UNDO,                      DE_ASTR,    KC_1,    KC_2,    KC_3, KC_COMM,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                _______, _______, _______,    KC_0   , DE_EQL , DE_SCLN
                            //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT_split_3x5_3(
  //,-------------------------------------------.                    ,--------------------------------------------.
    DF(_NEO),DF(_QWERTZ),KC_VOLD,KC_VOLU,KC_MUTE,                      KC_MUTE,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     XXXXXXX, KC_PAUS, KC_MPRV, KC_MNXT, KC_VOLU,                      KC_VOLU,   KC_F4,   KC_F5,   KC_F6,  KC_F11,
  //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, KC_PAUS, KC_VOLD,                      KC_VOLD,   KC_F1,   KC_F2,   KC_F3,  KC_F12,
  //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                _______, _______, _______,    _______, _______, _______
                            //`--------------------------'  `--------------------------'
  )
};

// called on every keypress
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    // slim fake WPM
    #if !defined(WPM_ENABLE) && defined(MODULAR_BONGOCAT_ENABLE)
    bongo_fake_wpm_increment();
    #endif

    numlock_off();
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state)
{
    // this will switch to layer _FUNC, if any of those configurations got pressed.
    layer_state_t tmp = state;
    state = update_tri_layer_state(state, _SYMBOL, _NAV_NUM, _FUNC);

    if (state == tmp)
    {
        state = update_tri_layer_state(state, _NAV_NUM, _SYMBOL, _FUNC);
    }
    
    return state;
}
