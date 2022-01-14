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
#    include "pointing_device.h"
#endif

#ifdef PIMORONI_TRACKBALL_ENABLE
#    include "pimoroni_trackball.h"
#endif

#ifdef MODULAR_BONGOCAT_ENABLE
#    include "modular_bongocat.h"
#endif

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

/*
// Tap Dance declarations
enum {
    TD_GUI_STRG,
    TD_ALT_SHIFT,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_GUI_STRG] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_LCTRL),
    [TD_ALT_SHIFT] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LSFT),
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * Base Layer: Neo
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |LAY3/tab|   X  |   V  |   L  | L3/C |   W  |                              |   K  | L3/H |   G  |   F  |   Q  |ß/AltGr |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * | LShift |GUI/U |ALT/I |SHFT/A|STRG/E| L4/O |                              | L4/S |STRG/N|SHFT/R|ALT/T |GUI/D |Y/RShift|
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * | LCtrl  |   Ü  |   Ö  |   Ä  |   P  |   Z  |L3/ESC|L4/ESC|  |L4/F5 |L3/F5 |   B  |   M  | , ;  | . :  |   J  |-_ /RCtl|
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *   encoder: skip tracks | Play | GUI  | LALT | Space| Enter|  | Enter| Space| Bksp | Del  | Mute | encoder: volume
    *                        |      |      | SHIFT| LAY3 | LAY4 |  | LAY3 | LAY4 |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_NEO] = LAYOUT(
            LT(_LAYER_3, KC_TAB), KC_X,         KC_V,         KC_L,         LT(_LAYER_3, KC_C), KC_W,                                                              /**/                                             DE_K,               LT(_LAYER_3, KC_H), KC_G,         KC_F,         KC_Q,         ALGR_T(DE_SS),
            KC_LSFT,              LGUI_T(KC_U), LALT_T(KC_I), LSFT_T(KC_A), LCTL_T(KC_E),       LT(_LAYER_4, KC_O),                                                /**/                                             LT(_LAYER_4, KC_S), LCTL_T(KC_N),       RSFT_T(KC_R), LALT_T(KC_T), LGUI_T(KC_D), RSFT_T(DE_Y),
            KC_LCTRL,             DE_UDIA,      DE_ODIA,      DE_ADIA,      KC_P,               DE_Z,               LT(_LAYER_4, KC_ESCAPE), MO(_LAYER_3),         /**/ LT(_LAYER_4, KC_F5),  LT(_LAYER_3, KC_F5),  KC_B,               KC_M,               KC_COMM,      KC_DOT,       KC_J,         RCTL_T(DE_MINS),
                                                              KC_MPLY,      KC_LGUI,            KC_LALT,            LT(_LAYER_3, KC_SPC),    LT(_LAYER_4, KC_ENT), /**/ LT(_LAYER_3, KC_ENT), LT(_LAYER_4, KC_SPC), KC_BSPC,            KC_DEL,             KC_MUTE
    ),

    /*
    * Base Layer: QWERTZ
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |LAY3/tab|   Q  |   W  |   E  | L3/R |   T  |                              |   Z  | L3/U |   I  |   O  |   P  |Ü/AltGr |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * | LShift |GUI/A |ALT/S |SHFT/D|STRG/F| L4/G |                              | L4/H |STRG/J|SHFT/K|ALT/L |GUI/Ö |Ä/RShift|
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * | LCtrl  |   Y  |   X  |   C  |   V  |   B  |L3/ESC|L4/ESC|  |L4/F5 |L3/F5 |   N  |   M  | , ;  | . :  | - _  | ß/RCtl |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *   encoder: skip tracks | Play | GUI  | LALT | Space| Enter|  | Enter| Space| Bksp | Del  | Mute | encoder: volume
    *                        |      |      | SHIFT| LAY3 | LAY4 |  | LAY3 | LAY4 |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_QWERTZ] = LAYOUT(
            LT(_LAYER_3, KC_TAB), KC_Q,         KC_W,         KC_E,         LT(_LAYER_3, KC_R), KC_T,                                                           /**/                                             DE_Z,               LT(_LAYER_3, KC_U), KC_I,         KC_O,         KC_P,            ALGR_T(DE_UDIA),
            KC_LSFT,              LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F),       LT(_LAYER_4, KC_G),                                             /**/                                             LT(_LAYER_4, KC_H), LCTL_T(KC_J),       RSFT_T(KC_K), LALT_T(KC_L), LGUI_T(DE_ODIA), RSFT_T(DE_ADIA),
            KC_LCTRL,             DE_Y,         KC_X,         KC_C,         KC_V,               KC_B,               LT(_LAYER_4, KC_ESC), LT(_LAYER_3, KC_ESC), /**/ LT(_LAYER_4, KC_F5),  LT(_LAYER_3, KC_F5),  KC_N,               KC_M,               KC_COMM,      KC_DOT,       DE_MINS,         RCTL_T(DE_SS),
                                                              KC_MPLY,      KC_LGUI,            KC_LALT,            LT(_LAYER_3, KC_SPC), LT(_LAYER_4, KC_ENT), /**/ LT(_LAYER_3, KC_ENT), LT(_LAYER_4, KC_SPC), KC_BSPC,            KC_DEL,             KC_MUTE
    ),

    /*
    * Base Layer: Gaming, Overwatch
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |  tab   |   Q  |   Q  |   2  |   E  |   F  |                              |   Z  |   U  |   I  |   O  |   P  |Ü/AltGr |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * |    X   |LShift|   A  |   W  |   D  |   R  |                              |   H  |   J  |   K  |   L  |   Ö  |Ä/RShift|
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * |    Y   |LShift|   C  |   S  |   V  |   B  |  esc | LAY6 |  | LAY5 |L6/F5 |   N  |   M  | , ;  | . :  | - _  | ß/RCtl |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *   encoder: skip tracks | Play | GUI  | LALT | Space| Enter|  | Enter| Space| Bksp | Del  | Mute | encoder: volume
    *                        |      |      |      |      |      |  | LAY3 | LAY4 |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_GAMING] = LAYOUT(
            KC_TAB,   KC_Q,   KC_Q,   KC_2,   KC_E,   KC_F,                         /**/                                    DE_Z, KC_U, KC_I,    KC_O,    KC_P,    ALGR_T(DE_UDIA),
            KC_X,  KC_LSFT,   KC_A,   KC_W,   KC_D,   KC_R,                         /**/                                    KC_H, KC_J, KC_K,    KC_L,    DE_ODIA, RSFT_T(DE_ADIA),
            KC_Y, KC_LCTRL,   KC_C,   KC_S,   KC_V,   KC_B, KC_ESCAPE, MO(_LAYER_4),/**/ MO(_LAYER_4), LT(_LAYER_4, KC_F5), KC_N, KC_M, KC_COMM, KC_DOT,  DE_MINS, RCTL_T(DE_SS),
                                   KC_MPLY, KC_LGUI, KC_LALT, KC_SPC      , KC_ENT, /**/ LT(_LAYER_3, KC_ENT), LT(_LAYER_4, KC_SPC), KC_BSPC,  KC_DEL, KC_MUTE
    ),

    /*
    * Layer 3 symbols
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |        |   °  |   _  |   [  |   ]  |   ^  |                              |   !  |   <  |   >  |   =  |   &  |   §    |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * |        |   \  |   /  |   {  |   }  |   *  |                              |   ?  |   (  |   )  |   -  |   :  |   @    |
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * |        |   #  |   $  |   |  |   ~  |   `  |      |      |  |      |      |   +  |   %  |   "  |   '  |   ;  |   €    |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_LAYER_3] = LAYOUT(
        _______, DE_DEG, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,                                     DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR, DE_SECT,
        _______, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                                     DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_AT,
        _______, DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_GRV , _______, _______, _______, _______, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, DE_EURO,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /*
    * Layer 4 Nav and Numpad
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |   esc  | PgUp | Bksp |  up  | del  | PgDn |                              |   *  |   7  |   8  |   9  |   +  |   -    |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * |        | home | left | down | right| end  |                              |   /  |   4  |   5  |   6  |   .  |   ;    | // TODO: Tap Dance ./, -> :/;
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * |        |  esc |  tab |insert|Mouse1|MS up | MS r |      |  |      |      |   :  |   1  |   2  |   3  |   ,  |   =    |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *                        |      |Mouse2| MS l | MS d |      |  |      |   0  |      |      |      |
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_LAYER_4] = LAYOUT(
        KC_ESCAPE, KC_PGUP,   KC_BSPC, KC_UP,     KC_DELETE, KC_PGDOWN,                   /**/                   DE_ASTR, KC_7, KC_8, KC_9, DE_PLUS, DE_MINS,
        _______,   KC_HOME,   KC_LEFT, KC_DOWN,   KC_RIGHT,  KC_END,                      /**/                   DE_SLSH, KC_4, KC_5, KC_6, KC_DOT,  DE_SCLN,
        _______,   KC_ESCAPE, KC_TAB,  KC_INSERT, KC_BTN1,   KC_MS_U,   KC_MS_R, _______, /**/ _______, _______, DE_COLN, KC_1, KC_2, KC_3, KC_COMM, DE_EQL,
                                       _______,   KC_BTN2,   KC_MS_L,   KC_MS_D, _______, /**/ _______, KC_0,    _______, _______, _______
    ),


    /*
    * Adjust Layer: Function keys, RGB, media
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |        |      |      |      |BRI DN|BRI UP|                              |      |  F7  |  F8  |  F9  | F10  |  F11   |
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
        _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU,                   /**/                   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                   /**/                   KC_VOLU, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_F12,
        _______, XXXXXXX, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, /**/ _______, _______, KC_VOLD, KC_F1,   KC_F2,   KC_F3,   KC_F12, XXXXXXX,
                                   _______, KC_MPRV, KC_MNXT, _______, _______, /**/ _______, _______, KC_MPRV, KC_MNXT, _______
    ),



// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),

};

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    //debug_mouse=true;
}


// called on led status change
void led_set_keymap(uint8_t usb_led)
{
    numlock_off();
}


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

void matrix_scan_user(void)
{
    #if !defined(WPM_ENABLE) && defined(MODULAR_BONGOCAT_ENABLE)
    bongo_fake_wpm_decay();
    #endif
}

layer_state_t layer_state_set_user(layer_state_t state)
{
    // this will switch to layer _FUNC, if  L3 & L4 got pressed
    state = update_tri_layer_state(state, _LAYER_3, _LAYER_4, _FUNC);

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
                {
                    if(selected_layer < base_layers_size - 1)
                        selected_layer ++;
                    else
                        selected_layer = 0;
                } else
                {
                    if(selected_layer != 0)
                        selected_layer --;
                    else
                        selected_layer = base_layers_size - 1;
                }
                set_single_persistent_default_layer(base_layers[selected_layer]);
                current_base_layer = base_layers[selected_layer];
            }
            break;
        // Page up/down left. Mouse Scroll right. 
        case _LAYER_3:
        case _LAYER_4:
            if (index == 0)
            {
                if (clockwise)
                {
                    tap_code(KC_PGUP);
                } else
                {
                    tap_code(KC_PGDOWN);
                }
            }
            else if (index == 1)
            {
                if (clockwise)
                {
                    tap_code(KC_WH_U);
                } else
                {
                    tap_code(KC_WH_D);
                }
            }

            break;
        default:
            if (index == 0)
            {
                if (clockwise)
                {
                    tap_code(KC_MEDIA_NEXT_TRACK);
                } else
                {
                    tap_code(KC_MEDIA_PREV_TRACK);
                }
            }
            else if (index == 1)
            {
                if (clockwise)
                {
                    tap_code(KC_AUDIO_VOL_UP);
                } else
                {
                    tap_code(KC_AUDIO_VOL_DOWN);
                }
            }
            break;
    }
    return false;
}

#endif

#ifdef PIMORONI_TRACKBALL_ENABLE
void pointing_device_task() {
    report_mouse_t mouse_report = pointing_device_get_report();

    if (is_keyboard_master()) {
        process_mouse(&mouse_report);
    }

    switch (get_highest_layer(layer_state)) {
        case _NEO:
            trackball_set_rgbw(0, 200, 0, 0);
            break;
        case _QWERTZ:
            trackball_set_rgbw(200, 0, 0, 0);
            break;
        case _LAYER_3:
            trackball_set_rgbw(200, 0, 200, 0);
            break;
        case _LAYER_4:
            trackball_set_rgbw(0, 25, 200, 0);
            break;
        default:
            trackball_set_rgbw(0, 0, 0, 200);
    }


    if (layer_state_is(_LAYER_3) || layer_state_is(_LAYER_4)) {
        trackball_set_scrolling(true);
    } else {
        trackball_set_scrolling(false);
    }


    pointing_device_set_report(mouse_report);
    pointing_device_send();
}
#endif


#if defined(OLED_ENABLE) || defined(OLED_DRIVER_ENABLE)

// OLED width
#define WIDTH 128

oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
	return OLED_ROTATION_180;
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
        if(current_base_layer == _NEO)
            oled_write_P(PSTR("Neo\n"), false);
        else if(current_base_layer == _QWERTZ)
            oled_write_P(PSTR("Qwertz\n"), false);
        else if(current_base_layer == _GAMING)
            oled_write_P(PSTR("Gaming\n"), false);
        scroll_timer = 0;
    }

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Lay: "), false);
    if(highest_layer == _LAYER_3)
    {
        oled_write_P(PSTR("3: Symbols\n"), false);
        scroll_timer = 0;
    }
    else if(highest_layer == _LAYER_4)
    {
        oled_write_P(PSTR("4: Nav, Num\n"), false);
        scroll_timer = 0;
    }
    /*
    else if(highest_layer == _LAYER_5)
        oled_write_P(PSTR("5: Greek\n"), false);
    else if(highest_layer == _LAYER_6)
        oled_write_P(PSTR("6: Math\n"), false);*/
    else if(highest_layer == _FUNC)
    {
        oled_write_P(PSTR("Func: F,Med,RGB\n"), false);
        scroll_timer = 0;
    }
    else
    {
        if(current_base_layer == _NEO)
            oled_write_P(PSTR("Neo\n"), false);
        else if(current_base_layer == _QWERTZ)
            oled_write_P(PSTR("NeoQwertz\n"), false);
        else if (current_base_layer == _GAMING)
            oled_write_P(PSTR("Gaming\n"), false);
    }
    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);

    if (scroll_timer < 255)
        scroll_timer++;

    if (scroll_timer < 255)
        return false;
    else
        return true;
}

void oled_task_user(void)
{

    #if defined(OLED_ENABLE) || defined(OLED_DRIVER_ENABLE)
    static bool logos_rendered = false;
    #ifdef BONGO_DEBUG
    if (!is_keyboard_master())
    #endif
    #ifndef BONGO_DEBUG
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
        render_status();
        oled_scroll_left();
        #endif

    }

    #endif
}

#endif
