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

// NeoQwertz for Kyria

#include QMK_KEYBOARD_H
#include "keymap_german.h"

#include "sendstring_german.h"

enum layers
{
    _NEO = 0,
    _LAYER_3,
    _LAYER_4,
    _LAYER_5,
    _LAYER_6,
    _FUNC
};

// enum for greek and mathematical unicode characters
enum unicode_names {
    BANG,
    IRONY,
    SNEK,

    // Number row
    bra, // ⟨
    ket, // ⟩
    infinity, // ∞
    emptyset, // ∅
    parallel, // ∥
    angle, // ∡
    Grk_KAPPA, // ∡
    superskript_0, // ₀
    superskript_1, // ₁
    superskript_2, // ₂
    superskript_3, // ₃

    // Layer 5
    // third row
    Grk_xi,
    Grk_lambda,
    Grk_chi,
    Grk_omega,
    Grk_kappa,
    Grk_psi,
    Grk_gamma,
    Grk_phi,
    Grk_phi_2,
    Grk_finalsmallsigma, // ς under ß
    // second row
    Grk_iota,
    Grk_alpha,
    Grk_epsilon,
    Grk_omicron,
    Grk_sigma,
    Grk_nu,
    Grk_rho,
    Grk_tau,
    Grk_delta,
    Grk_upsilon,
    // first row
    Grk_eta,
    Grk_psi_2,
    Grk_pi,
    Grk_zeta,
    Grk_beta,
    Grk_mu,
    Grk_rho_2,
    Grk_theta,
    Grk_theta_2,

    // Layer 6

    // third row
    Greek_XI, // Ξ
    radical, // √
    Greek_LAMBDA, // Λ
    komplex, // ℂ
    Greek_OMEGA, // Ω
    times, // ×
    Greek_PSI, // Ψ
    Greek_GAMMA, // Γ
    Greek_PHI, // Φ
    rational, // ℚ
    ring_operator, // ∘
    // second row
    includedin, // ⊂
    integral, // ∫
    for_all, // ∀
    there_exists, // ∃
    elementof, // ∈
    Greek_SIGMA, // Σ
    natural, // ℕ
    real, // ℝ
    partialderivative, // ∂
    Greek_DELTA, // Δ
    nabla, // ∇
    // first row
    _union, // ∪
    intersection, // ∩
    U2135, // ℵ
    Greek_PI, // Π
    integers, // ℤ
    U21D0, // ⇐
    ifonlyif, // ⇔
    implies, // ⇒
    U21A6, // ↦
    Greek_THETA // Θ

};

const uint32_t PROGMEM unicode_map[] = {
    // Number row
    [bra]  = 0x27E8, // ⟨
    [ket]  = 0x27E9, // ⟩
    [infinity]  = 0x221E, // ∞
    [emptyset]  = 0x2205, // ∅
    [parallel]  = 0x2225, // ∥
    [angle]  = 0x2221, // ∡
    [Grk_KAPPA]  = 0x3F0, // ∡
    [superskript_0]  = 0x3F0, // ₀
    [superskript_1]  = 0x3F0, // ₁
    [superskript_2]  = 0x3F0, // ₂
    [superskript_3]  = 0x3F0, // ₃

    // Layer 5

    // third row
    [Grk_xi]  = 0x3BE, // ξ
    // []  = 0x, // vvv unset
    [Grk_lambda]  = 0x3BB, // λ
    [Grk_chi]  = 0x3C7, // χ
    [Grk_omega]  = 0x3C9, // ω
    [Grk_kappa]  = 0x3BA, // κ
    [Grk_psi]  = 0x3C8, // ψ
    [Grk_gamma]  = 0x3B3, // γ
    [Grk_phi]  = 0x3C6, // φ
    [Grk_phi_2]  = 0x3D5, // ϕ
    [Grk_finalsmallsigma]  = 0x3C2, // ς under ß
    // second row
    // []  = 0x, // uuu unset
    [Grk_iota]  = 0x3B9, // ι
    [Grk_alpha]  = 0x3B1, // α
    [Grk_epsilon]  = 0x3B5, // ε
    [Grk_omicron]  = 0x3BF, // ο
    [Grk_sigma]  = 0x3C3, // σ
    [Grk_nu]  = 0x3BD, // ν
    [Grk_rho]  = 0x3C1, // ρ
    [Grk_tau]  = 0x3C4, // τ
    [Grk_delta]  = 0x3B4, // δ
    [Grk_upsilon]  = 0x3C5, // υ
    // first row
    // []  = 0x, // üüü unset
    [Grk_eta]  = 0x3F5, // ϵ
    [Grk_psi_2]  = 0x3F5, // η
    [Grk_pi]  = 0x3C0, // π
    [Grk_zeta]  = 0x3B6, // ζ
    [Grk_beta]  = 0x3B2, // β
    [Grk_mu]  = 0x3BC, // μ
    [Grk_rho_2]  = 0x3F1, // ϱ
    [Grk_theta]  = 0x3D1, // ϑ
    [Grk_theta_2]  = 0x3B8, // θ

    // Layer 6
    
    // third row
    [Greek_XI]  = 0x39E, // Ξ
    [radical]  = 0x221A, // √
    [Greek_LAMBDA]  = 0x39B, // Λ
    [komplex]  = 0x2102, // ℂ
    [Greek_OMEGA]  = 0x3A9, // Ω

    [times]  = 0xD7, // ×
    [Greek_PSI]  = 0x3A8, // Ψ
    [Greek_GAMMA]  = 0x393, // Γ
    [Greek_PHI]  = 0x3A6, // Φ
    [rational]  = 0x211A, // ℚ
    [ring_operator]  = 0x2218, // ∘
    // []  = , //
    // second row
    [includedin]  = 0x2282, // ⊂
    [integral]  = 0x222B, // ∫
    [for_all]  = 0x2200, // ∀
    [there_exists]  = 0x2203, // ∃
    [elementof]  = 0x2208, // ∈
    [Greek_SIGMA]  = 0x3A3, // Σ
    [natural]  = 0x2115, // ℕ
    [real]  = 0x211D, // ℝ
    [partialderivative]  = 0x2202, // ∂
    [Greek_DELTA]  = 0x394, // Δ
    [nabla]  = 0x2207, // ∇
    // first row
    [_union]  = 0x222A, // ∪
    [intersection]  = 0x2229, // ∩
    [U2135]  = 0x2135, // ℵ
    [Greek_PI]  = 0x3A0, // Π
    [integers]  = 0x2124, // ℤ
    [U21D0]  = 0x21D0, // ⇐
    [ifonlyif]  = 0x21D4, // ⇔
    [implies]  = 0x21D2, // ⇒
    [U21A6]  = 0x21A6, // ↦
    [Greek_THETA]  = 0x398, // Θ

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * Base Layer: QWERTZ
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |LAY3/tab|   X  |   V  |   L  |   C  |   W  |                              |   K  |   H  |   G  |   F  |   Q  |ß/AltGr |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * | LShift |   U  |   I  |  A   |   E  |   O  |                              |   S  |   N  |   R  |   T  |   D  |Y/RShift|
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * | LCtrl  |   Ü  |   Ö  |   Ä  |   P  |   Z  | LAY5 | LAY6 |  | LAY5 | LAY6 |   B  |   M  | , ;  | . :  |   J  |-_ /RCtl|
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *   encoder: skip tracks | Play | GUI  | LALT | Space| Enter|  | Enter| Space| Bksp | Del  | Mute | encoder: volume
    *                        |      |      |      | LAY3 | LAY4 |  | LAY3 | LAY4 |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_NEO] = LAYOUT(
        LT(_LAYER_3, KC_TAB), KC_X, KC_V,   KC_L,   KC_C,   KC_W,                                                             DE_K, KC_H, KC_G,    KC_F,    KC_Q, ALGR_T(DE_SS),
        KC_LSFT,            KC_U,   KC_I,   KC_A,   KC_E,   KC_O,                                                             KC_S, KC_N, KC_R,    KC_T,    KC_D, RSFT_T(DE_Y),
        KC_LCTRL,          DE_UDIA, DE_ODIA, DE_ADIA, KC_P, DE_Z, MO(_LAYER_5), MO(_LAYER_6),/**/ MO(_LAYER_5), MO(_LAYER_6), KC_B, KC_M, KC_COMM, KC_DOT,  KC_J, RCTL_T(DE_MINS),
        
              KC_MPLY, KC_LGUI, KC_LALT, LT(_LAYER_3, KC_SPC), LT(_LAYER_4, KC_ENT), /* */ LT(_LAYER_3, KC_ENT), LT(_LAYER_4, KC_SPC), KC_BSPC,  KC_DEL, KC_MUTE
    ),//LALT_T(KC_ESC)

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
    * |        | home | left | down | right| end  |                              |   /  |   4  |   5  |   6  |   ,  |   .    |
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * |        |  esc |  tab |insert| enter|undo  |      |      |  |      |   0  |   :  |   1  |   2  |   3  |   ;  |   =    |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *                        |      |      |      |      |      |  |      |   0  |      |      |      |
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_LAYER_4] = LAYOUT(
        KC_ESCAPE, KC_PGUP, KC_BSPC, KC_UP, KC_DELETE, KC_PGDOWN,                                  DE_ASTR, KC_7, KC_8, KC_9, DE_PLUS, DE_MINS,
        _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,                                      DE_SLSH, KC_4, KC_5, KC_6, KC_COMM, KC_DOT,
        _______, KC_ESCAPE, KC_TAB, KC_INSERT, KC_ENTER, KC_UNDO, _______, _______, _______, KC_0, DE_COLN, KC_1, KC_2, KC_3, DE_SCLN, DE_EQL,
                                  _______, _______, _______, _______, _______, _______, KC_0, _______, _______, _______
    ),


    /*
    * Layer 5 small greek letters
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |    ₁   |   ξ  |   ϰ  |   λ  |   χ  |   ω  |                              |   κ  |   ψ  |   γ  |   φ  |   ϕ  |    ς   |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * |    ₂   |   θ  |   ι  |   α  |   ε  |   ο  |                              |   σ  |   ν  |   ρ  |   τ  |   δ  |    υ   |
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * |    ₃   |   ₀  |   ϵ  |   η  |   π  |   ζ  |      |      |  |      |      |   β  |   μ  |   ϱ  |   ϑ  |   ⟨  |    ⟩   |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_LAYER_5] = LAYOUT(
        X(superskript_1), X(Grk_xi), X(Grk_KAPPA), X(Grk_lambda), X(Grk_chi), X(Grk_omega),                                       X(Grk_kappa), X(Grk_psi), X(Grk_gamma), X(Grk_phi), X(Grk_phi_2), X(Grk_finalsmallsigma),
        X(superskript_2), X(Grk_theta_2), X(Grk_iota), X(Grk_alpha), X(Grk_epsilon), X(Grk_omicron),                              X(Grk_sigma), X(Grk_nu), X(Grk_rho), X(Grk_tau), X(Grk_delta), X(Grk_upsilon),
        X(superskript_3), X(superskript_0), X(Grk_eta), X(Grk_psi_2), X(Grk_pi), X(Grk_zeta), _______, _______, _______, _______, X(Grk_beta), X(Grk_mu), X(Grk_rho_2), X(Grk_theta), X(bra), X(ket),
                                                     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /*
    * Layer 6 big greek letters and mathematical symbols
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |    ∞   |   Ξ  |   √  |   Λ  |   ℂ  |   Ω  |                              |   ×  |   Ψ  |   Γ  |   Φ  |   ℚ  |    ∘   |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * |    ∅   |   ⊂  |   ∫  |   ∀  |   ∃  |   ∈  |                              |   Σ  |   ℕ  |   ℝ  |   ∂  |   Δ  |    ∇   |
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * |    ∥   |   ∪  |   ∩  |   ℵ  |   Π  |   ℤ  |      |      |  |      |      |   ⇐  |   ⇔  |   ⇒  |   ↦  |   Θ  |    ∡   |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
     [_LAYER_6] = LAYOUT(
        X(infinity), X(Greek_XI), X(radical), X(Greek_LAMBDA), X(komplex), X(Greek_OMEGA),                               X(times), X(Greek_PSI), X(Greek_GAMMA), X(Greek_PHI), X(rational), X(ring_operator),
        X(emptyset), X(includedin), X(integral), X(for_all), X(there_exists), X(elementof),                              X(Greek_SIGMA), X(natural), X(real), X(partialderivative), X(Greek_DELTA), X(nabla),
        X(parallel), X(_union), X(intersection), X(U2135), X(Greek_PI), X(integers), _______, _______, _______, _______, X(U21D0), X(ifonlyif), X(implies), X(U21A6), X(Greek_THETA), X(angle),
                                                          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),


    /*
    * Adjust Layer: Function keys, RGB, media
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |   esc  | F1   |  F2  | F3   | F4   | F5   |                              | F6   |  F7  |  F8  |  F9  | F10  |  F11   |
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
        KC_ESCAPE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     KC_VOLU, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_F12,
        _______, XXXXXXX, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, KC_VOLD, KC_F1,   KC_F2,   KC_F3,   KC_F12, XXXXXXX,
                                   _______, KC_MPRV, KC_MNXT, _______, _______, _______, _______, KC_MPRV, KC_MNXT, _______
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


layer_state_t layer_state_set_user(layer_state_t state)
{
    // this will switch to layer _FUNC, if any of those configurations got pressed.
    layer_state_t tmp = state;
    state = update_tri_layer_state(state, _LAYER_3, _LAYER_5, _FUNC);
    if (state == tmp)
    {
        state = update_tri_layer_state(state, _LAYER_4, _LAYER_6, _FUNC);
        if (state == tmp)
        {
            state = update_tri_layer_state(state, _LAYER_3, _LAYER_4, _FUNC);
        }
    }

    return state;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void)
{
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void)
{
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

    oled_write_P(qmk_logo, false);
}

static void render_status(void)
{
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("NeoQwertz\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Lay: "), false);
    switch (get_highest_layer(layer_state))
    {
        case _NEO:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LAYER_3:
            oled_write_P(PSTR("3: Symbols\n"), false);
            break;
        case _LAYER_4:
            oled_write_P(PSTR("4: Nav, Num\n"), false);
            break;
        case _LAYER_5:
            oled_write_P(PSTR("5: Greek\n"), false);
            break;
        case _LAYER_6:
            oled_write_P(PSTR("6: Math\n"), false);
            break;
        case _FUNC:
            oled_write_P(PSTR("Func: F,Med,RGB\n"), false);
            break;

        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void)
{
    if (is_keyboard_master())
    {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else
    {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise)
{
    /*
    rotaries
    0: left
    1: right
    */
    if (index == 0)
    {
        if (clockwise)
        {
            tap_code(KC_MEDIA_PREV_TRACK);
        } else
        {
            tap_code(KC_MEDIA_NEXT_TRACK);
        }
    }
    else if (index == 1)
    {
        if (clockwise)
        {
            tap_code(KC_AUDIO_VOL_DOWN);
        } else
        {
            tap_code(KC_AUDIO_VOL_UP);
        }
    }
}
#endif

