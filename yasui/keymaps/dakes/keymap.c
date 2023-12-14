/* Copyright 2023 Daniel Ostertag (Dakes) <daniel.ostertag@dakes.de>
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

enum layers {
  _COLEMAK_DH = 0,
  _SYM,
  _NAV_NUM,
  _FUNC
};



// Combos
#ifdef COMBO_ENABLE
// #define COMBO_ONLY_FROM_LAYER _COLEMAK_DH
const uint16_t PROGMEM c_tab[] = {LALT_T(KC_S), LCTL_T(KC_T), COMBO_END};
const uint16_t PROGMEM c_esc[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM c_a_r[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM c_o_l[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM c_caps[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM c_mins[] = {LALT_T(KC_E), LGUI_T(KC_I), COMBO_END};
const uint16_t PROGMEM c_unds[] = {LCTL_T(KC_N), LALT_T(KC_E), COMBO_END};
// German Umlaute
const uint16_t PROGMEM c_ae[] =  {LSFT_T(KC_A), LGUI_T(KC_R), COMBO_END};
const uint16_t PROGMEM c_ue[] =  {KC_U, DE_Y, COMBO_END};
const uint16_t PROGMEM c_oe[] =  {LGUI_T(KC_I), RSFT_T(KC_O), COMBO_END};
const uint16_t PROGMEM c_ss[] =  {LGUI_T(KC_R), LALT_T(KC_S), COMBO_END};

combo_t key_combos[] = {
    COMBO(c_tab, KC_TAB),
    COMBO(c_esc, KC_ESC),
    COMBO(c_a_r, KC_A),
    COMBO(c_o_l, KC_O),
    COMBO(c_caps, QK_CAPS_WORD_TOGGLE),
    COMBO(c_mins, DE_MINS),
    COMBO(c_unds, DE_UNDS),
    COMBO(c_ae, DE_ADIA),
    COMBO(c_ue, DE_UDIA),
    COMBO(c_oe, DE_ODIA),
    COMBO(c_ss, DE_SS),
};

uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(key_combos[0]);

bool get_combo_must_tap(uint16_t index, combo_t *combo)
{
    // If you want all combos to be tap-only, just uncomment the next line
    // return true;

    // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, to be tap-only, this is for you:
    uint16_t key;
    uint8_t  idx = 0;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            // case QK_LAYER_TAP...QK_LAYER_TAP_MAX: // If this is enabled the LT(SHORCUTS,KC_F2) key does not work.
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
                return true;
        }
        idx += 1;
    }
    return false;
}

#endif // Combos



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK_DH] = LAYOUT(
        KC_Q,         KC_W,         KC_F,         KC_P,         KC_B, /**/ KC_J, KC_L,         KC_U,         DE_Y,         DE_Z,
        LSFT_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LCTL_T(KC_T), KC_G, /**/ KC_M, LCTL_T(KC_N), LALT_T(KC_E), LGUI_T(KC_I), RSFT_T(KC_O),
        QK_REP,       KC_X,         KC_C,         KC_D,         KC_V, /**/ DE_K, KC_H,         KC_COMM,      KC_DOT,       DE_MINS,
        #ifdef TWO_2U
        KC_ESC, OSM(MOD_LALT), KC_LGUI, LT(_NAV_NUM, KC_ENT), _______, /**/ _______, LT(_SYM, KC_SPC), KC_BSPC, KC_DEL, OSM(MOD_LCTL)
        #endif
    ),

    [_SYM] = LAYOUT(
        DE_DEG,  DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC, DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR,
        DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN,
        DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_GRV , DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN,
		DE_SECT, DE_EURO, DE_AT,   _______, _______, _______, _______, DE_AT,   DE_EURO, _______
    ),

    [_NAV_NUM] = LAYOUT(
        KC_PGUP,    KC_BSPC, KC_UP,     KC_DELETE, KC_PGDN,   DE_ASTR, KC_7, KC_8, KC_9, DE_PLUS,
        KC_HOME,    KC_LEFT, KC_DOWN,   KC_RIGHT,  KC_END,    DE_SLSH, KC_4, KC_5, KC_6, KC_COMM,
        KC_ESCAPE,  KC_TAB,  KC_INSERT, KC_ENTER,  KC_UNDO,   DE_COLN, KC_1, KC_2, KC_3, KC_DOT,
        #ifdef TWO_2U
        _______, _______, _______, _______, _______, _______, KC_0, _______, _______, KC_SPC
        #endif
	),

	// Function Layer: F-keys, media, layer switch
    [_FUNC] = LAYOUT(
        XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, KC_MUTE, KC_F7,   KC_F8,   KC_F9,   KC_F10,
        XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, KC_VOLU, KC_F4,   KC_F5,   KC_F6,   KC_F11,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_F1,   KC_F2,   KC_F3,   KC_F12,
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
    state = update_tri_layer_state(state, _NAV_NUM, _SYM, _FUNC);

    return state;
}
