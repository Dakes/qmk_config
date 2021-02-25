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

enum layers
{
    _NEO = 0,
    _QWERTZ,
    _GAMING,
    _LAYER_3,
    _LAYER_4,
    _LAYER_5,
    _LAYER_6,
    _FUNC
};

uint8_t base_layers[3] = {_NEO, _QWERTZ, _GAMING};
uint8_t current_base_layer = _NEO;

// enum for greek and mathematical unicode characters
// Unicode stuff including layers costs ~300 bytes
enum unicode_names {
    // Number row
    bra, // ⟨
    ket, // ⟩
    infinity, // ∞
    emptyset, // ∅
    parallel, // ∥
    angle, // ∡
    Grk_KAPPA, // ϰ
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
    // []  = 0x, // v unset
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
    // []  = 0x, // u unset
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
    // []  = 0x, // ü unset
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
    * Base Layer: Neo
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
    ),

    /*
    * Base Layer: QWERTZ
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |LAY3/tab|   Q  |   W  |   E  |   R  |   T  |                              |   Z  |   U  |   I  |   O  |   P  |Ü/AltGr |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * | LShift |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  |   Ö  |Ä/RShift|
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * | LCtrl  |   Y  |   X  |   C  |   V  |   B  | LAY5 | LAY6 |  | LAY5 | LAY6 |   N  |   M  | , ;  | . :  | - _  | ß/RCtl |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *   encoder: skip tracks | Play | GUI  | LALT | Space| Enter|  | Enter| Space| Bksp | Del  | Mute | encoder: volume
    *                        |      |      |      | LAY3 | LAY4 |  | LAY3 | LAY4 |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_QWERTZ] = LAYOUT(
            LT(_LAYER_3, KC_TAB), KC_Q, KC_W,   KC_E,   KC_R,   KC_T,                                                             DE_Z, KC_U, KC_I,    KC_O,    KC_P,    ALGR_T(DE_UDIA),
            KC_LSFT,            KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                                             KC_H, KC_J, KC_K,    KC_L,    DE_ODIA, RSFT_T(DE_ADIA),
            KC_LCTRL,           DE_Y,   KC_X,   KC_C,   KC_V,   KC_B, MO(_LAYER_5), MO(_LAYER_6),/**/ MO(_LAYER_5), MO(_LAYER_6), KC_N, KC_M, KC_COMM, KC_DOT,  DE_MINS, RCTL_T(DE_SS),

            KC_MPLY, KC_LGUI, KC_LALT, LT(_LAYER_3, KC_SPC), LT(_LAYER_4, KC_ENT), /* */ LT(_LAYER_3, KC_ENT), LT(_LAYER_4, KC_SPC), KC_BSPC,  KC_DEL, KC_MUTE
    ),

    /*
    * Base Layer: Gaming
    *
    * ,-------------------------------------------.                              ,-------------------------------------------.
    * |LAY3/tab|   Q  |   W  |   E  |   R  |   T  |                              |   Z  |   U  |   I  |   O  |   P  |Ü/AltGr |
    * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    * | LShift |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  |   Ö  |Ä/RShift|
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * | LCtrl  |   Y  |   X  |   C  |   V  |   B  | LAY5 | LAY6 |  | LAY5 | LAY6 |   N  |   M  | , ;  | . :  | - _  | ß/RCtl |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *   encoder: skip tracks | Play | GUI  | LALT | Space| Enter|  | Enter| Space| Bksp | Del  | Mute | encoder: volume
    *                        |      |      |      | LAY3 | LAY4 |  | LAY3 | LAY4 |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_GAMING] = LAYOUT(
            LT(_LAYER_3, KC_TAB), KC_Q, KC_W,   KC_E,   KC_R,   KC_T,                                                             DE_Z, KC_U, KC_I,    KC_O,    KC_P,    ALGR_T(DE_UDIA),
            KC_LSFT,            KC_A,   KC_A,   KC_W,   KC_D,   KC_G,                                                             KC_H, KC_J, KC_K,    KC_L,    DE_ODIA, RSFT_T(DE_ADIA),
            KC_LCTRL,           DE_Y,   KC_X,   KC_S,   KC_V,   KC_B, MO(_LAYER_5), MO(_LAYER_6),/**/ MO(_LAYER_5), MO(_LAYER_6), KC_N, KC_M, KC_COMM, KC_DOT,  DE_MINS, RCTL_T(DE_SS),

            KC_MPLY, KC_LGUI, KC_LALT, LT(_LAYER_3, KC_SPC), LT(_LAYER_4, KC_ENT), /* */ LT(_LAYER_3, KC_ENT), LT(_LAYER_4, KC_SPC), KC_BSPC,  KC_DEL, KC_MUTE
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
    * |        | home | left | down | right| end  |                              |   /  |   4  |   5  |   6  |   ,  |   .    |
    * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    * |        |  esc |  tab |insert| enter|undo  |      |      |  |      |      |   :  |   1  |   2  |   3  |   ;  |   =    |
    * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    *                        |      |      |      |      |      |  |      |   0  |      |      |      |
    *                        |      |      |      |      |      |  |      |      |      |      |      |
    *                        `----------------------------------'  `----------------------------------'
    */
    [_LAYER_4] = LAYOUT(
        KC_ESCAPE, KC_PGUP, KC_BSPC, KC_UP, KC_DELETE, KC_PGDOWN,                                       DE_ASTR, KC_7, KC_8, KC_9, DE_PLUS, DE_MINS,
        _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,                                         DE_SLSH, KC_4, KC_5, KC_6, KC_COMM, KC_DOT,
        _______, KC_ESCAPE, KC_TAB, KC_INSERT, KC_ENTER, KC_UNDO, _______, _______, _______, _______, DE_COLN, KC_1, KC_2, KC_3, DE_SCLN, DE_EQL,
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
    * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   |  F7  |  F8  |  F9  | F10  |  F11   |
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
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
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

//check numlock and turn off if on
static void numlock_off(void)
{
    //Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    if (led_state.num_lock)
    {
        tap_code16(KC_NLCK);
    }
}

// called on led status change
void led_set_keymap(uint8_t usb_led)
{
    numlock_off();
}

// called on every keypress
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    numlock_off();
    return true;
}


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
    }

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Lay: "), false);
    if(highest_layer == _LAYER_3)
        oled_write_P(PSTR("3: Symbols\n"), false);
    else if(highest_layer == _LAYER_4)
        oled_write_P(PSTR("4: Nav, Num\n"), false);
    else if(highest_layer == _LAYER_5)
        oled_write_P(PSTR("5: Greek\n"), false);
    else if(highest_layer == _LAYER_6)
        oled_write_P(PSTR("6: Math\n"), false);
    else if(highest_layer == _FUNC)
        oled_write_P(PSTR("Func: F,Med,RGB\n"), false);
    else
    {
        if(current_base_layer == _NEO)
            oled_write_P(PSTR("Neo\n"), false);
        else if(current_base_layer == _QWERTZ)
            oled_write_P(PSTR("NeoQwertz\n"), false);
        else if(current_base_layer == _GAMING)
            oled_write_P(PSTR("Gaming\n"), false);
        else
            oled_write_P(PSTR("Undefined\n"), false);
    }
    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

// originally by j-inc: https://github.com/qmk/qmk_firmware/blob/master/keyboards/kyria/keymaps/j-inc/keymap.c
// Adapted to modular system and diffs using uint16_t arrays by Dakes (Daniel Ostertag).

// WPM-responsive animation stuff here
#define IDLE_FRAMES 5 // 5
#define IDLE_SPEED 40 // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#define TAP_FRAMES 2
#define TAP_SPEED 60 // above this wpm value typing animation to triggere

#define PREP_FRAMES 1

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms 200
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing

// OLED width
#define WIDTH 128

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
uint8_t current_tap_frame = 0;

char wpm_str[8];

// Images credit j-inc(/James Incandenza) and pixelbenny. Credit to obosob for initial animation approach.

static void render_anim(void)
{
    // saves the pixel index in bits 1-13 and pixel on, off in bit 16. 1: on 0: off (+2^15)
    // first element is the size of the array , without the size itself
    static const uint16_t base[] PROGMEM = {223, 32968, 32969, 32970, 33095, 33099, 33222, 33228, 33346, 33347, 33348, 33349, 33356, 33470, 33471, 33472, 33473, 33484, 33596, 33597, 33613, 33723, 33742, 33789, 33790, 33791, 33844, 33845, 33850, 33871, 33872, 33913, 33914, 33915, 33916, 33971, 33974, 33975, 33976, 33977, 34001, 34036, 34037, 34038, 34039, 34040, 34098, 34130, 34160, 34161, 34162, 34163, 34226, 34259, 34283, 34284, 34285, 34286, 34287, 34354, 34379, 34380, 34388, 34407, 34408, 34409, 34410, 34483, 34507, 34508, 34517, 34530, 34531, 34532, 34533, 34534, 34611, 34638, 34639, 34640, 34641, 34646, 34654, 34655, 34656, 34657, 34740, 34751, 34752, 34762, 34766, 34767, 34768, 34769, 34775, 34779, 34780, 34781, 34868, 34879, 34880, 34884, 34887, 34888, 34889, 34890, 34903, 34904, 34905, 34906, 34996, 35013, 35014, 35032, 35123, 35132, 35133, 35134, 35135, 35150, 35151, 35160, 35250, 35260, 35261, 35262, 35263, 35273, 35274, 35275, 35276, 35277, 35280, 35281, 35288, 35378, 35397, 35398, 35399, 35400, 35410, 35411, 35412, 35413, 35414, 35415, 35506, 35522, 35523, 35524, 35633, 35649, 35761, 35778, 35889, 35892, 35893, 35894, 35895, 35896, 35897, 35906, 36016, 36017, 36018, 36019, 36026, 36027, 36034, 36142, 36143, 36156, 36157, 36162, 36266, 36267, 36268, 36269, 36286, 36287, 36288, 36289, 36390, 36391, 36392, 36393, 36514, 36515, 36516, 36517, 36638, 36639, 36640, 36641, 36762, 36763, 36764, 36765, 36886, 36887, 36888, 36889, 37010, 37011, 37012, 37013, 37134, 37135, 37136, 37137, 37258, 37259, 37260, 37261, 37382, 37383, 37384, 37385, 37506, 37507, 37508, 37509, 37632, 37633};

    // Add your own logos here, or remove to save firmware size

    static const uint8_t kyria_logo_width = 31;
    static const uint16_t kyria_logo[] PROGMEM = {466, 32769, 32770, 32773, 32774, 32800, 32801, 32803, 32804, 32807, 32808, 32811, 32812, 32814, 32815, 32816, 32817, 32820, 32821, 32825, 32826, 32827, 32828, 32831, 32832, 32833, 32834, 32838, 32839, 32842, 32843, 32848, 32849, 32851, 32852, 32855, 32856, 32858, 32859, 32862, 32863, 32864, 32865, 32870, 32871, 32872, 32873, 32876, 32877, 32878, 32879, 32882, 32883, 32885, 32886, 32889, 32890, 32893, 32894, 32896, 32897, 32902, 32903, 32907, 32910, 32911, 32913, 32914, 32916, 32917, 32918, 32919, 32920, 32921, 32924, 32925, 32928, 32929, 32933, 32934, 32938, 32941, 32942, 32944, 32945, 32947, 32948, 32951, 32952, 32995, 32996, 32997, 32998, 32999, 33000, 33001, 33002, 33003, 33004, 33005, 33024, 33025, 33026, 33027, 33035, 33036, 33037, 33038, 33053, 33054, 33055, 33069, 33070, 33071, 33083, 33084, 33102, 33103, 33113, 33114, 33120, 33121, 33122, 33123, 33124, 33125, 33126, 33127, 33128, 33134, 33135, 33143, 33144, 33149, 33150, 33151, 33154, 33155, 33156, 33159, 33160, 33161, 33166, 33167, 33173, 33174, 33179, 33180, 33185, 33186, 33187, 33192, 33193, 33198, 33199, 33204, 33209, 33210, 33215, 33217, 33219, 33224, 33225, 33230, 33234, 33235, 33239, 33240, 33246, 33248, 33250, 33256, 33257, 33261, 33262, 33265, 33269, 33270, 33276, 33279, 33282, 33288, 33289, 33293, 33295, 33296, 33300, 33301, 33302, 33303, 33304, 33305, 33306, 33307, 33310, 33313, 33314, 33315, 33316, 33317, 33318, 33319, 33320, 33324, 33325, 33326, 33327, 33330, 33331, 33332, 33333, 33334, 33339, 33341, 33343, 33348, 33349, 33350, 33351, 33352, 33355, 33356, 33357, 33361, 33363, 33366, 33367, 33370, 33372, 33374, 33377, 33378, 33381, 33383, 33387, 33388, 33392, 33395, 33399, 33400, 33401, 33402, 33403, 33404, 33405, 33406, 33407, 33411, 33414, 33418, 33419, 33423, 33426, 33432, 33433, 33434, 33435, 33436, 33442, 33445, 33449, 33450, 33454, 33458, 33459, 33460, 33461, 33462, 33463, 33464, 33465, 33466, 33467, 33468, 33469, 33470, 33471, 33472, 33476, 33480, 33481, 33485, 33488, 33494, 33495, 33496, 33497, 33498, 33504, 33507, 33511, 33512, 33516, 33519, 33523, 33524, 33525, 33526, 33527, 33528, 33529, 33530, 33531, 33535, 33538, 33542, 33543, 33547, 33549, 33552, 33553, 33556, 33558, 33560, 33563, 33564, 33567, 33569, 33573, 33574, 33575, 33578, 33579, 33580, 33581, 33582, 33587, 33589, 33591, 33596, 33597, 33598, 33599, 33600, 33603, 33604, 33605, 33606, 33610, 33611, 33612, 33613, 33614, 33615, 33616, 33617, 33620, 33623, 33624, 33625, 33626, 33627, 33628, 33629, 33630, 865, 33634, 33635, 33637, 33641, 33642, 33648, 33651, 33654, 33660, 33661, 894, 895, 33665, 33668, 33669, 33673, 33674, 33680, 33682, 33684, 919, 920, 921, 33690, 33691, 924, 33695, 33696, 33700, 33705, 33706, 33711, 33713, 33715, 948, 949, 33720, 33721, 33726, 33731, 33732, 33737, 33738, 973, 974, 33743, 33744, 33745, 978, 33750, 33751, 33756, 33757, 33763, 33764, 1000, 33769, 33770, 33771, 33774, 33775, 33776, 33779, 33780, 33781, 33786, 33787, 33795, 33796, 1029, 1030, 33802, 33803, 33804, 33805, 33806, 33807, 33808, 33809, 33810, 33816, 33817, 33827, 33828, 33846, 33847, 33859, 33860, 33861, 33875, 33876, 33877, 33892, 33893, 33894, 33895, 33903, 33904, 33905, 33906, 33925, 33926, 33927, 33928, 33929, 33930, 33931, 33932, 33933, 33934, 33935};

    static const uint8_t qmk_logo_width = 15;
    static const uint16_t qmk_logo[] PROGMEM = {176, 32771, 32773, 32775, 32777, 32779, 32786, 32788, 32790, 32792, 32794, 32800, 32801, 32802, 32803, 32804, 32805, 32806, 32807, 32808, 32809, 32810, 32813, 32814, 32815, 32816, 32817, 32818, 32819, 32820, 32821, 32822, 32823, 32824, 32825, 32830, 32831, 32833, 32834, 32836, 32837, 32839, 32840, 32841, 32842, 32843, 32844, 32845, 32846, 32848, 32849, 32851, 32852, 32854, 32855, 32860, 32861, 32863, 32864, 32866, 32867, 32869, 32870, 32871, 32872, 32873, 32874, 32875, 32876, 32877, 32879, 32881, 32883, 32884, 32885, 32890, 32891, 32892, 32893, 32897, 32898, 32899, 32900, 32901, 32902, 32903, 32904, 32905, 32906, 32907, 32908, 32909, 32911, 32912, 32913, 32914, 32915, 32920, 32921, 32922, 32923, 32924, 32926, 32927, 32928, 32929, 32930, 32931, 32932, 32933, 32934, 32935, 32936, 32937, 32938, 32939, 32940, 32941, 32942, 32943, 32944, 32945, 32950, 32951, 32952, 32953, 32954, 32955, 32956, 32957, 32958, 32959, 32960, 32966, 32968, 32970, 32972, 32974, 32981, 32983, 32985, 32987, 32989, 33024, 33025, 33028, 33032, 33034, 33037, 33038, 33041, 33043, 33044, 33046, 33047, 33049, 33051, 33053, 33056, 33058, 33060, 33062, 33064, 33065, 33068, 33071, 33073, 33077, 33079, 33081, 33084, 33085, 33088, 33092, 33094, 33097, 33101};

    // diffs rendered after base frame, turns on/off certain pixels
    // unfortunately C Arrays can't have a variable second dimension
    static const uint16_t idle_diff_0[] PROGMEM = {0};
    static const uint16_t idle_diff_2[] PROGMEM = {22, 32841, 32842, 201, 202, 32971, 331, 33100, 588, 33357, 716, 33485, 33716, 33717, 33843, 1076, 1077, 33846, 33847, 33970, 1203, 1206, 1207};
    static const uint16_t idle_diff_3[] PROGMEM = {104, 200, 327, 33096, 454, 33223, 578, 579, 580, 581, 33350, 702, 703, 704, 705, 33474, 33475, 33476, 33477, 716, 33485, 828, 829, 33598, 33599, 33600, 33601, 955, 33724, 33725, 33741, 974, 1082, 33851, 33870, 1103, 1104, 1208, 1209, 33978, 33999, 34000, 1233, 34104, 34105, 34129, 1362, 34258, 1491, 1611, 1612, 34387, 1620, 34482, 1715, 34516, 1749, 34635, 34636, 1870, 1871, 1872, 1873, 34645, 1878, 34739, 1972, 1983, 1984, 1994, 34774, 2007, 2116, 2119, 2120, 2121, 34894, 34895, 34896, 34897, 35007, 35008, 35012, 2245, 2246, 35015, 35016, 35017, 35018, 2355, 35124, 2364, 2365, 2366, 2367, 35141, 35142, 2482, 35251, 35388, 35389, 35390, 35391, 2865, 35634};
    static const uint16_t idle_diff_4[] PROGMEM = {20, 200, 201, 202, 327, 33096, 33097, 33098, 331, 454, 33223, 33227, 460, 33350, 1076, 1077, 1203, 33972, 33973, 1330, 34099};
    static const uint16_t *idle_diff[IDLE_FRAMES] = {
            idle_diff_0,
            idle_diff_0, // first two frames are identical
            idle_diff_2,
            idle_diff_3,
            idle_diff_4
    };

    static const uint16_t prep_diff_0[] PROGMEM = {107, 32841, 32842, 201, 202, 32971, 331, 33100, 588, 33357, 716, 33485, 33716, 33717, 33843, 1076, 1077, 33846, 33847, 33875, 33876, 33877, 33878, 33970, 1203, 1206, 1207, 34002, 34007, 34133, 34136, 34257, 34263, 34264, 34385, 34389, 34392, 34512, 34516, 34520, 1870, 1871, 1873, 1878, 34648, 34746, 34747, 34748, 1998, 1999, 2001, 34873, 34875, 34877, 35000, 35005, 35027, 35028, 35029, 35030, 2264, 35128, 35129, 2365, 2367, 35152, 35153, 35154, 2392, 35255, 35258, 35259, 2492, 2493, 2495, 2512, 2513, 2520, 35383, 35386, 35387, 35390, 2642, 2643, 2644, 2645, 2646, 2647, 35518, 35646, 35647, 35648, 35770, 35771, 35772, 35773, 3010, 3138, 3258, 3259, 3266, 3388, 3389, 3394, 3518, 3519, 3520, 3521};
    static const uint16_t *prep_diff[PREP_FRAMES] = {
            prep_diff_0
    };

    static const uint16_t tap_diff_0[] PROGMEM = {187, 32841, 32842, 201, 202, 32971, 331, 33100, 33238, 33239, 33240, 33241, 588, 33357, 33366, 33367, 33368, 33369, 716, 33485, 33494, 33495, 33496, 33497, 33622, 33623, 33624, 33625, 33716, 33717, 33750, 33751, 33752, 33753, 33759, 33760, 33843, 1076, 1077, 33846, 33847, 33878, 33879, 33880, 33881, 33886, 33887, 33888, 33889, 33970, 1203, 1206, 1207, 34006, 34007, 34008, 34013, 34014, 34015, 34016, 34017, 34135, 34136, 34140, 34141, 34142, 34143, 34144, 34145, 34146, 34264, 34267, 34268, 34269, 34270, 34271, 34272, 34273, 34274, 34395, 34396, 34397, 34398, 34399, 34400, 34523, 34524, 1870, 1871, 1872, 1873, 34746, 34747, 34748, 1998, 1999, 2000, 2001, 34873, 34875, 34877, 2135, 35000, 35005, 35128, 35129, 2365, 2367, 35162, 35163, 35164, 35165, 35166, 35167, 35168, 35169, 35170, 35255, 35258, 35259, 2492, 2493, 2495, 35290, 35291, 35292, 35293, 35294, 35295, 35296, 35297, 35298, 35383, 35386, 35387, 35390, 35418, 35419, 35420, 35421, 35422, 35423, 35424, 35425, 35518, 35546, 35547, 35548, 35549, 35550, 35551, 35552, 35553, 35646, 35647, 35648, 35675, 35676, 35677, 35678, 35679, 35680, 35770, 35771, 35772, 35773, 3010, 35804, 35805, 35806, 35807, 35808, 3138, 35933, 35934, 35935, 3258, 3259, 3266, 36062, 36063, 3388, 3389, 3394, 3518, 3519, 3520, 3521};
    static const uint16_t tap_diff_1[] PROGMEM = {187, 32841, 32842, 201, 202, 32971, 331, 33100, 588, 33357, 716, 33485, 33716, 33717, 33843, 1076, 1077, 33846, 33847, 33875, 33876, 33877, 33878, 33970, 1203, 1206, 1207, 34002, 34007, 34133, 34136, 34257, 34263, 34264, 34385, 34389, 34392, 34512, 34516, 34520, 1870, 1871, 1873, 1878, 34648, 1998, 1999, 2001, 35027, 35028, 35029, 35030, 2264, 2364, 2365, 2366, 2367, 35152, 35153, 35154, 2392, 2492, 2493, 2494, 2495, 2512, 2513, 2520, 2642, 2643, 2644, 2645, 2646, 2647, 36274, 36275, 36276, 36277, 36278, 36279, 36280, 36402, 36403, 36404, 36405, 36406, 36407, 36408, 36409, 36530, 36531, 36532, 36533, 36534, 36535, 36536, 36537, 36658, 36659, 36660, 36661, 36662, 36663, 36800, 36801, 36802, 36803, 36922, 36923, 36924, 36928, 36929, 36930, 36931, 36932, 37049, 37050, 37051, 37052, 37056, 37057, 37058, 37059, 37060, 37061, 37176, 37177, 37178, 37179, 37180, 37184, 37185, 37186, 37187, 37188, 37189, 37190, 37303, 37304, 37305, 37306, 37307, 37312, 37313, 37314, 37315, 37316, 37317, 37318, 37319, 37430, 37431, 37432, 37433, 37434, 37435, 37440, 37441, 37442, 37443, 37444, 37445, 37446, 37447, 37558, 37559, 37560, 37561, 37562, 37563, 37568, 37569, 37570, 37571, 37572, 37573, 37687, 37688, 37689, 37690, 37696, 37697, 37698, 37699, 37817, 37818, 37824, 37825};
    static const uint16_t *tap_diff[TAP_FRAMES] = {
            tap_diff_0,
            tap_diff_1
    };

    /**
     * renders a PROGMEM uint16_t array, smaller or equal in size than the OLED
     * x, y: top left position of the image
     * width: width of the image
     */
    void render_short_array_pos(const uint16_t* frame, uint8_t x, uint8_t y, uint8_t width)
    {
        uint16_t size = pgm_read_word(&(frame[0])) + 1;
        for(uint16_t i=1; i<size; i++)
        {
            uint16_t cur_px = pgm_read_word(&(frame[i]));

            // get pixel state bit
            bool on = (cur_px & ( 1 << 15 )) >> 15;
            // remove pixel state bit
            cur_px &= ~(1UL << 15);

            uint8_t x_cur = (cur_px % width) + x;
            uint8_t y_cur = (cur_px / width) + y;
            oled_write_pixel(x_cur, y_cur, on);
        }
    }

    /**
     * Shortcut to render images of the size of the OLED
     */
    void render_short_array(const uint16_t* frame)
    {
        render_short_array_pos(frame, 0, 0, WIDTH);
    }

    //assumes 1 frame prep stage
    void animation_phase(void)
    {
        oled_clear();
        if (get_current_wpm() <= IDLE_SPEED)
        {
            current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
            // first render base frame
            render_short_array(base);
            // only add or remove changed pixels
            render_short_array(idle_diff[ current_idle_frame ]);
        }
        if (get_current_wpm() > IDLE_SPEED && get_current_wpm() < TAP_SPEED)
        {
            render_short_array(base);
            render_short_array(prep_diff[0]);
        }
        if (get_current_wpm() >= TAP_SPEED)
        {
            current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
            render_short_array(base);
            render_short_array(tap_diff[ current_tap_frame ]);
        }

        // Add your own logos here, or remove to save firmware size
        render_short_array_pos(qmk_logo, 108, 14, qmk_logo_width);
        render_short_array_pos(kyria_logo, 6, 2, kyria_logo_width);
    }

    if(get_current_wpm() != 000)
    {
        oled_on(); // not essential but turns on animation OLED with any alpha keypress
        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION)
        {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else
    {
        if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT)
        {
            oled_off();
        } else
        {
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION)
            {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}

void render_wpm(void)
{
    char wpm_number_str[3];
    itoa(get_current_wpm(), wpm_number_str, 10);
    oled_set_cursor(7,6);
    strcpy(wpm_str, "WPM: ");
    strcat(wpm_str, wpm_number_str);
    oled_write(wpm_str, false);
}

void oled_task_user(void)
{
    if (is_keyboard_master())
    {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else
    {
        render_anim();
        render_wpm();
    }
}
#endif

#ifdef ENCODER_ENABLE

uint8_t selected_layer = 0;
uint8_t base_layers_size = sizeof(base_layers)/sizeof(base_layers[0]);

void encoder_update_user(uint8_t index, bool clockwise)
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
}

#endif

