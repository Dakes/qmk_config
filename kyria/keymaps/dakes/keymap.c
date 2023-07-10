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

// Dakes' keymap for Kyria

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include <string.h>

#include "dakes.h"

#ifdef POINTING_DEVICE_ENABLE
/* #    include "pointing_device.h" */
#endif

#ifdef PIMORONI_TRACKBALL_ENABLE
/* #    include "pimoroni_trackball.h" */
#endif

#ifdef MODULAR_BONGOCAT_ENABLE
#    include "modular_bongocat.h"
#endif

#ifdef CONWAY_ENABLE
#    include "conway.h"
#endif

enum layers
{
    _COLEMAK_DH = 0,
    _QWERTZ,
    _GAMING,
    _SYM,
    _NAV_NUM,
    _FUNC
};


uint8_t base_layers[5] = {_COLEMAK_DH, _QWERTZ, _GAMING};
uint8_t current_base_layer = _COLEMAK_DH;

/*
// Tap Dance declarations
enum {
    TD_GUI_STRG,
    TD_ALT_SHIFT,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_GUI_STRG] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_LCTL),
    [TD_ALT_SHIFT] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LSFT),
};
*/

// Combos
#ifdef COMBO_ENABLE
#define COMBO_ONLY_FROM_LAYER _COLEMAK_DH
/* const uint16_t PROGMEM c_tab[] = {KC_F, KC_P, COMBO_END}; */
const uint16_t PROGMEM c_tab[] = {LALT_T(KC_S), LCTL_T(KC_T), COMBO_END};
const uint16_t PROGMEM c_esc[] = {KC_F, KC_P, COMBO_END};
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

#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
    * Base Layer: Colemak-DH
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |LAY2/tab|   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |   Z  |Ü/AltGr |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * | LShift |SHFT/A|GUI/R | ALT/S|STRG/T|   G  |                              |   M  |STRG/N| ALT/E|GUI/I |SHFT/O|Ä/RShift|
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * | LCtrl  |   /  |   X  |   C  |   D  |   V  |L2/ESC|L3/ESC|  |L3/F5 |L2/F5 |   K  |   H  | , ;  | . :  |  - _ | ß/RCtl |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *   encoder: skip tracks | Play | GUI  | LALT | Space| Enter|  | Enter| Space| Bksp | Del  | Mute | encoder: volume
    *                        |      |      | SHIFT| LAY2 | LAY3 |  | SHFT | SHFT |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_COLEMAK_DH] = LAYOUT(
            LT(_SYM, KC_TAB), KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,                                                   /**/                                         DE_J,    KC_L,          KC_U,         DE_Y,         DE_Z,         ALGR_T(DE_UDIA),
            KC_LSFT,          LSFT_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LCTL_T(KC_T), KC_G,                                                   /**/                                         KC_M,    LCTL_T(KC_N),  LALT_T(KC_E), LGUI_T(KC_I), RSFT_T(KC_O), RSFT_T(DE_ADIA),
            KC_LCTL,          DE_SLSH,      KC_X,         KC_C,         KC_D,         KC_V,     LT(_NAV_NUM, KC_ESCAPE), LT(_SYM, KC_ESCAPE), /**/ LT(_NAV_NUM, KC_F5),  LT(_SYM, KC_F5),  KC_K,    KC_H, KC_COMM, KC_DOT,       DE_MINS,      RCTL_T(DE_SS),
                                                          KC_MPLY,      KC_LGUI,      KC_LALT,  LT(_SYM, KC_SPC),        LT(_NAV_NUM, KC_ENT),/**/ LSFT_T(KC_ENT),       LSFT_T(KC_SPC),   KC_BSPC, KC_DEL,        KC_MUTE
    ),


    /*
    * Base Layer: QWERTZ
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |LAY2/tab|   Q  |   W  |   E  |  R   |   T  |                              |   Z  |  U   |   I  |   O  |   P  |Ü/AltGr |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * | LShift |SHFT/A|GUI/S |ALT/D |STRG/F| L3/G |                              | L3/H |STRG/J| ALT/K| GUI/L|SHFT/Ö|Ä/RShift|
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * | LCtrl  |   Y  |   X  |   C  | L2/V |   B  |L2/ESC|L3/ESC|  |L3/F5 |L2/F5 |   N  | L2/M | , ;  | . :  | - _  | ß/RCtl |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *   encoder: skip tracks | Play | GUI  | LALT | Space| Enter|  | Enter| Space| Bksp | Del  | Mute | encoder: volume
    *                        |      |      | SHIFT| LAY2 | LAY3 |  | LAY2 | LAY3 |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_QWERTZ] = LAYOUT(
            LT(_SYM, KC_TAB), KC_Q,         KC_W,         KC_E,         KC_R,           KC_T,                                                           /**/                                            DE_Z,               KC_U,               KC_I,         KC_O,         KC_P,            ALGR_T(DE_UDIA),
            KC_LSFT,          LSFT_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F),   LT(_NAV_NUM, KC_G),                                             /**/                                            LT(_NAV_NUM, KC_H), LCTL_T(KC_J),       LALT_T(KC_K), LGUI_T(KC_L), RSFT_T(DE_ODIA), RSFT_T(DE_ADIA),
            KC_LCTL,          DE_Y,         KC_X,         KC_C,         LT(_SYM, KC_V), KC_B,               LT(_NAV_NUM, KC_ESC), LT(_SYM, KC_ESC),     /**/ LT(_NAV_NUM, KC_F5), LT(_SYM, KC_F5),      KC_N,               LT(_SYM, KC_M),     KC_COMM,      KC_DOT,       DE_MINS,         RCTL_T(DE_SS),
                                                          KC_MPLY,      KC_LGUI,        KC_LALT,            LT(_SYM, KC_SPC),     LT(_NAV_NUM, KC_ENT), /**/ LT(_SYM, KC_ENT),    LT(_NAV_NUM, KC_SPC), KC_BSPC,            KC_DEL,             KC_MUTE
    ),


    /*
    * Base Layer: Gaming; Anno, Surviving Mars, Overwatch, Isaac
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |        |   Q  |   W  |   E  |   R  |   T  |                              |   Z  |   ←  |   ↑  |   →  |   P  |Ü/AltGr |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * |        |LShift|   A  |   W  |   D  |   G  |                              |   H  |   ←  |   ↓  |   →  |   Ö  |Ä/RShift|
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * |        |LCtrl |   X  |   S  |   V  |   B  |   H  | esc  |  | LAY5 | FUNC |   N  |   M  | , ;  | . :  | - _  | ß/RCtl |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *   encoder: skip tracks | Play | GUI  | LALT | Space| Enter|  | P Ent| Space| Bksp | Del  | Mute | encoder: volume
    *                        |      |      |      | SHFT |NAVNUM|  | SYM  |NAVNUM|      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_GAMING] = LAYOUT(
            XXXXXXX, KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,                                 /**/                                             DE_Z,  KC_LEFT, KC_UP,   KC_RIGHT, KC_P,    ALGR_T(DE_UDIA),
            XXXXXXX, KC_LSFT,  KC_A,    KC_W,    KC_D,    KC_G,                                 /**/                                             KC_H,  KC_LEFT, KC_DOWN, KC_RIGHT, DE_ODIA, RSFT_T(DE_ADIA),
            XXXXXXX, KC_LCTL,  KC_X,    KC_S,    KC_V,    KC_B, KC_H,     KC_ESCAPE,            /**/ MO(_FUNC),         LT(_SYM, KC_F5),  KC_N,  KC_M,  KC_COMM, KC_DOT,   DE_MINS, RCTL_T(DE_SS),
                               KC_MPLY, KC_LGUI, KC_LALT, LSFT_T(KC_SPC), LT(_NAV_NUM, KC_ENT), /**/ LT(_SYM, KC_PENT), LT(_NAV_NUM, KC_SPC), KC_BSPC,  KC_DEL,  KC_MUTE
    ),

    /*
    * Layer 2 symbols
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |        |   °  |   _  |   [  |   ]  |   ^  |                              |   !  |   <  |   >  |   =  |   &  |   §    |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * |        |   \  |   /  |   {  |   }  |   *  |                              |   ?  |   (  |   )  |   -  |   :  |   @    |
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * |        |   #  |   $  |   |  |   ~  |   `  |   €  |  §   |  |   @  |      |   +  |   %  |   "  |   '  |   ;  |   €    |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *                        |      |   @  |  €   |      |      |  |      |      |      |      |      |
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_SYM] = LAYOUT(
        _______, DE_DEG,  DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,                                     DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR, DE_SECT,
        _______, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                                     DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_AT,
        _______, DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_GRV , DE_EURO, DE_SECT, DE_AT,   _______, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, DE_EURO,
                                   _______, DE_AT  , DE_EURO, _______, _______, _______, _______, _______, _______, _______
    ),

    /*
    * Layer 3 Nav and Numpad
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |   esc  | PgUp | Bksp |  up  | del  | PgDn |                              |   *  |   7  |   8  |   9  |   +  |   -    |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * |        | home | left | down | right| end  |                              |   /  |   4  |   5  |   6  |   .  |   ;    | // TODO: Tap Dance ./, -> :/;
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * |        |  tab | copy | paste|Mouse1|MS up | MS r |      |  |      |      |   :  |   1  |   2  |   3  |   ,  |   =    |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *                        |      |Mouse2| MS l | MS d |      |  |      |   0  |      |      |      |
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_NAV_NUM] = LAYOUT(
        KC_ESCAPE, KC_PGUP, KC_BSPC, KC_UP,     KC_DELETE, KC_PGDN,                   /**/                   DE_ASTR, KC_7, KC_8, KC_9, DE_PLUS, DE_MINS,
        _______,   KC_HOME, KC_LEFT, KC_DOWN,   KC_RIGHT,  KC_END,                      /**/                   DE_SLSH, KC_4, KC_5, KC_6, KC_DOT,  DE_SCLN,
        _______,   KC_TAB,  KC_COPY, KC_PSTE,   KC_BTN1,   KC_MS_U,   KC_MS_R, _______, /**/ _______, _______, DE_COLN, KC_1, KC_2, KC_3, KC_COMM, DE_EQL,
                                       _______, KC_BTN2,   KC_MS_L,   KC_MS_D, _______, /**/ _______, KC_0,    _______, _______, _______
    ),


    /*
    * Layer 4 / Adjust Layer: Function keys, RGB, media
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |        | sleep|      |      |BRI DN|BRI UP|                              |      |  F7  |  F8  |  F9  | F10  |  F11   |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              | VolUp|  F4  |  F5  |  F6  | F11  |  F12   |
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      | VolDn|  F1  |  F2  |  F3  | F12  |        |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *                        |      | Prev | Next |      |      |  |      |      | Prev | Next |      |
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_FUNC] = LAYOUT(
        _______, KC_SLEP, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU,                   /**/                   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                   /**/                   KC_VOLU, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_F12,
        _______, XXXXXXX, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, /**/ _______, _______, KC_VOLD, KC_F1,   KC_F2,   KC_F3,   KC_F12, XXXXXXX,
                                   _______, KC_MPRV, KC_MNXT, _______, _______, /**/ _______, _______, KC_MPRV, KC_MNXT, _______
    ),

};

/*
void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable   = false;
    debug_matrix   = false;
    debug_keyboard = false;
    //debug_mouse=true;
}
*/


// called on led status change
void led_set_keymap(uint8_t usb_led)
{
    numlock_off();
}


// called on every keypress
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    // slim fake WPM
#   if !defined(WPM_ENABLE) && defined(MODULAR_BONGOCAT_ENABLE)
    bongo_fake_wpm_increment();
#   endif

    numlock_off();

#   ifdef CONWAY_ENABLE
#   ifdef MASTER_HALF
        conway_process_record_user(keycode, record);
#   endif
#   endif

    return true;
}


void matrix_scan_user(void)
{
#   if !defined(WPM_ENABLE) && defined(MODULAR_BONGOCAT_ENABLE)
    bongo_fake_wpm_decay();
#   endif


}

#ifdef POINTING_DEVICE_ENABLE
static bool scrolling_mode = false;
#endif  // POINTING_DEVICE_ENABLE
layer_state_t layer_state_set_user(layer_state_t state)
{
    // this will switch to layer _FUNC, if  L3 & L4 got pressed
    state = update_tri_layer_state(state, _SYM, _NAV_NUM, _FUNC);


#ifdef POINTING_DEVICE_ENABLE
    static bool cursor_slow_down = true;
    switch (get_highest_layer(state))
    {
        case _NAV_NUM:  // _NAV_NUM layer enables scrolling mode
            scrolling_mode = true;
            pointing_device_set_cpi(500);
            break;
        case _SYM:
            pointing_device_set_cpi(100);
            cursor_slow_down = true;
        default:
            if (scrolling_mode || cursor_slow_down)
            {
                scrolling_mode = false;
                cursor_slow_down = false;
                pointing_device_set_cpi(15000);
            }
            break;
    }
#endif  // POINTING_DEVICE_ENABLE
    return state;
}

#ifdef ENCODER_ENABLE

uint8_t selected_layer = 0;
uint8_t base_layers_size = sizeof(base_layers)/sizeof(base_layers[0]);


bool encoder_update_user(uint8_t index, bool clockwise)
{
    /*
        rotaries
        0: left
        1: right
    */
    switch (get_highest_layer(layer_state))
    {
        // on func layer switch base layer with encoder
        case _FUNC:
            if (index == 0 || index == 1)
            {
                if (clockwise)
                    if(selected_layer < base_layers_size - 1)
                        selected_layer ++;
                    else
                        selected_layer = 0;
                else
                    if(selected_layer != 0)
                        selected_layer --;
                    else
                        selected_layer = base_layers_size - 1;
                set_single_persistent_default_layer(base_layers[selected_layer]);
                current_base_layer = base_layers[selected_layer];
            }
            break;
        // Page up/down left. Mouse Scroll right.
        case _SYM:
        case _NAV_NUM:
            if (index == 0)
                if (clockwise)
                    tap_code(KC_PGUP);
                else
                    tap_code(KC_PGDN);
            else
                if (clockwise)
                    tap_code(KC_WH_U);
                else
                    tap_code(KC_WH_D);

            break;
        default:
            if (index == 0)
                if (clockwise)
                    tap_code(KC_MEDIA_NEXT_TRACK);
                else
                    tap_code(KC_MEDIA_PREV_TRACK);
            else
                if (clockwise)
                    tap_code(KC_AUDIO_VOL_UP);
                else
                    tap_code(KC_AUDIO_VOL_DOWN);
            break;

    }
    return false;
}

#endif

#ifdef POINTING_DEVICE_ENABLE

// TODO: FIX
void trackball_set_rgbw(uint8_t red, uint8_t green, uint8_t blue, uint8_t white)
{
    /* uint8_t data[] = {0x00, red, green, blue, white}; */
    /* i2c_transmit(TRACKBALL_WRITE, data, 5, TB_I2C_TIMEOUT); */
}


report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scrolling_mode) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = -mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}
#endif  // POINTING_DEVICE_ENABLE


#if defined(OLED_ENABLE) || defined(OLED_DRIVER_ENABLE)

// OLED width
#define WIDTH 128

oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
	return OLED_ROTATION_180;
}

#ifndef CONWAY_RENDER
static void render_current_layer(void)
{
    if(current_base_layer == _COLEMAK_DH)
        oled_write_P(PSTR("Colemak-DH\n"), false);
    else if(current_base_layer == _QWERTZ)
        oled_write_P(PSTR("Qwertz\n"), false);
    else if (current_base_layer == _GAMING)
        oled_write_P(PSTR("Gaming\n"), false);
}

/**
 ** return: if true, start scrolling, to reduce burn in
 ** return: if false, content changed, do not scroll
 */
static bool render_status(void)
{
    static uint8_t scroll_timer = 0;

    // return value bool, scroll or not
    // QMK Logo and version information
    // render_qmk_logo();
    oled_write_P(PSTR("Dakes\n"), false);
    uint8_t highest_layer = get_highest_layer(layer_state);

    // Func Layer can cycle between base Layers, Display new Layer
    if(highest_layer != _FUNC)
        oled_write_P(PSTR("\n"), false);
    else
    {
        oled_write_P(PSTR("New Base: "), false);
        render_current_layer();
        scroll_timer = 0;
    }

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Lay: "), false);
    if(highest_layer == _SYM)
    {
        oled_write_P(PSTR("3: Symbols\n"), false);
        scroll_timer = 0;
    }
    else if(highest_layer == _NAV_NUM)
    {
        oled_write_P(PSTR("4: Nav, Num\n"), false);
        scroll_timer = 0;
    }
    else if(highest_layer == _FUNC)
    {
        oled_write_P(PSTR("Func: F,Med,RGB\n"), false);
        scroll_timer = 0;
    }
    else
    {
        render_current_layer();
    }
    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("      "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("      "), false);


    if (scroll_timer < 255)
        scroll_timer++;

    if (scroll_timer < 255)
        return false;
    else
        return true;
}

bool oled_task_user(void)
{

    #if defined(OLED_ENABLE) || defined(OLED_DRIVER_ENABLE)
    static bool logos_rendered = false;
    // SLAVE_DEBUG renders slave on master, to debug without having to reattach the USB cable all the time
    #ifdef SLAVE_DEBUG
    if (!is_keyboard_master())
    #endif
    #ifndef SLAVE_DEBUG
    // normal case
    if (is_keyboard_master())
    #endif
    {
        // Will scroll OLED, if "home" screen was displayed for 255 refreshes
        // TODO: random vertical offset
        if(!logos_rendered)
        {
            #ifdef QMK_LOGO_ENABLE
            render_short_array_pos(qmk_logo, 0, 0, qmk_logo_width);
            #endif
            #ifdef KYRIA_LOGO_ENABLE
            render_short_array_pos(kyria_logo, WIDTH-kyria_logo_width, -6, kyria_logo_width);
            #endif
            logos_rendered = true;

        }
        oled_set_cursor(0,4);
        bool render_stat_ret = render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
        if (render_stat_ret)
            oled_scroll_left();
        else
            oled_scroll_off();
    } else
    {
        #ifdef MODULAR_BONGOCAT_ENABLE
        render_anim();
        #ifdef WPM_ENABLE
        render_wpm();
        #endif
        #endif
        #ifndef MODULAR_BONGOCAT_ENABLE
        /* render_status();
        oled_scroll_left(); */
        #endif
    }

    #endif // defined(OLED_ENABLE) || defined(OLED_DRIVER_ENABLE)
    return false;
}
#endif // CONWAY_ENABLE


#endif // defined(OLED_ENABLE) || defined(OLED_DRIVER_ENABLE)
