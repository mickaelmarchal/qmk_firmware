/* Copyright 2015-2016 Jack Humbert
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

#pragma once

#ifndef KEYMAP_FRENCH_H
#define KEYMAP_FRENCH_H

#include "keymap.h"

// clang-format off

/*
 * WINDOWS
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ ² │ & │ é │ " │ ' │ ( │ - │ è │ _ │ ç │ à │ ) │ = │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ A │ Z │ E │ R │ T │ Y │ U │ I │ O │ P │ ^ │ $ │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │ Q │ S │ D │ F │ G │ H │ J │ K │ L │ M │ ù │ * │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │ < │ W │ X │ C │ V │ B │ N │ , │ ; │ : │ ! │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 *
 *
 * MAC OS
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ @ │ & │ é │ " │ ' │ ( │ § │ è │ ! │ ç │ à │ ) │ - │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ A │ Z │ E │ R │ T │ Y │ U │ I │ O │ P │ ^ │ $ │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │ Q │ S │ D │ F │ G │ H │ J │ K │ L │ M │ ù │ ` │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │ < │ W │ X │ C │ V │ B │ N │ , │ ; │ : │ = │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */


// Row 1
#define FW_SUP2 KC_NUBS // ²
#define FW_AMPR KC_1    // &
#define FW_EACU KC_2    // é
#define FW_DQUO KC_3    // "
#define FW_QUOT KC_4    // '
#define FW_LPRN KC_5    // (
#define FW_MINS KC_6    // -
#define FW_EGRV KC_7    // è
#define FW_UNDS KC_8    // _
#define FW_CCED KC_9    // ç
#define FW_AGRV KC_0    // à
#define FW_RPRN KC_MINS // )
#define FW_EQL  KC_EQL  // =

#define FM_AT   KC_NUBS // @
#define FM_AMPR KC_1    // &
#define FM_EACU KC_2    // é
#define FM_DQUO KC_3    // "
#define FM_QUOT KC_4    // '
#define FM_LPRN KC_5    // (
#define FM_SECT KC_6    // §
#define FM_EGRV KC_7    // è
#define FM_EXLM KC_8    // !
#define FM_CCED KC_9    // ç
#define FM_AGRV KC_0    // à
#define FM_RPRN KC_MINS // )
#define FM_MINS KC_EQL  // -


// Row 2
#define FW_A    KC_Q    // A
#define FW_Z    KC_W    // Z
#define FW_E    KC_E    // E
#define FW_R    KC_R    // R
#define FW_T    KC_T    // T
#define FW_Y    KC_Y    // Y
#define FW_U    KC_U    // U
#define FW_I    KC_I    // I
#define FW_O    KC_O    // O
#define FW_P    KC_P    // P
#define FW_CIRC KC_LBRC // ^ (dead)
#define FW_DLR  KC_RBRC // $

#define FM_A    KC_Q    // A
#define FM_Z    KC_W    // Z
#define FM_E    KC_E    // E
#define FM_R    KC_R    // R
#define FM_T    KC_T    // T
#define FM_Y    KC_Y    // Y
#define FM_U    KC_U    // U
#define FM_I    KC_I    // I
#define FM_O    KC_O    // O
#define FM_P    KC_P    // P
#define FM_CIRC KC_LBRC // ^ (dead)
#define FM_DLR  KC_RBRC // $


// Row 3
#define FW_Q    KC_A    // Q
#define FW_S    KC_S    // S
#define FW_D    KC_D    // D
#define FW_F    KC_F    // F
#define FW_G    KC_G    // G
#define FW_H    KC_H    // H
#define FW_J    KC_J    // J
#define FW_K    KC_K    // K
#define FW_L    KC_L    // L
#define FW_M    KC_SCLN // M
#define FW_UGRV KC_QUOT // ù
#define FW_ASTR KC_NUHS // *

#define FM_Q    KC_A    // Q
#define FM_S    KC_S    // S
#define FM_D    KC_D    // D
#define FM_F    KC_F    // F
#define FM_G    KC_G    // G
#define FM_H    KC_H    // H
#define FM_J    KC_J    // J
#define FM_K    KC_K    // K
#define FM_L    KC_L    // L
#define FM_M    KC_SCLN // M
#define FM_UGRV KC_QUOT // ù
#define FM_GRV KC_NUHS  // `


// Row 4
#define FW_LABK KC_GRV  // <
#define FW_W    KC_Z    // W
#define FW_X    KC_X    // X
#define FW_C    KC_C    // C
#define FW_V    KC_V    // V
#define FW_B    KC_B    // B
#define FW_N    KC_N    // N
#define FW_COMM KC_M    // ,
#define FW_SCLN KC_COMM // ;
#define FW_COLN KC_DOT  // :
#define FW_EXLM KC_SLSH // !

#define FM_LABK KC_GRV // <
#define FM_W    KC_Z    // W
#define FM_X    KC_X    // X
#define FM_C    KC_C    // C
#define FM_V    KC_V    // V
#define FM_B    KC_B    // B
#define FM_N    KC_N    // N
#define FM_COMM KC_M    // ,
#define FM_SCLN KC_COMM // ;
#define FM_COLN KC_DOT  // :
#define FM_EQL KC_SLSH  // =



/* Shifted symbols
 *
 * WINDOWS
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │   │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ° │ + │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │   │   │   │   │   │   │   │   │ ¨ │ £ │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │   │   │   │   │   │   │ % │ µ │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │ > │   │   │   │   │   │   │ ? │ . │ / │ § │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 *
 *
 * MAC OS
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ # │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ° │ _ │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ A │ Z │ E │ R │ T │ Y │ U │ I │ O │ P │ ¨ │ * │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │ Q │ S │ D │ F │ G │ H │ J │ K │ L │ M │ % │ £ │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │ > │ W │ X │ C │ V │ B │ N │ ? │ . │ / │ + │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */

// Row 1
#define FW_1    S(FW_AMPR) // 1
#define FW_2    S(FW_EACU) // 2
#define FW_3    S(FW_DQUO) // 3
#define FW_4    S(FW_QUOT) // 4
#define FW_5    S(FW_LPRN) // 5
#define FW_6    S(FW_MINS) // 6
#define FW_7    S(FW_EGRV) // 7
#define FW_8    S(FW_UNDS) // 8
#define FW_9    S(FW_CCED) // 9
#define FW_0    S(FW_AGRV) // 0
#define FW_DEG  S(FW_RPRN) // °
#define FW_PLUS S(FW_EQL)  // +

#define FM_HASH S(FM_AT)   // #
#define FM_1    S(FM_AMPR) // 1
#define FM_2    S(FM_EACU) // 2
#define FM_3    S(FM_DQUO) // 3
#define FM_4    S(FM_QUOT) // 4
#define FM_5    S(FM_LPRN) // 5
#define FM_6    S(FM_SECT) // 6
#define FM_7    S(FM_EGRV) // 7
#define FM_8    S(FM_EXLM) // 8
#define FM_9    S(FM_CCED) // 9
#define FM_0    S(FM_AGRV) // 0
#define FM_DEG  S(FM_RPRN) // °
#define FM_UNDS S(FM_MINS) // _


// Row 2
#define FW_DIAE S(FW_CIRC) // ¨ (dead)
#define FW_PND  S(FW_DLR)  // £

#define FM_DIAE S(FM_CIRC) // ¨ (dead)
#define FM_ASTR S(FM_DLR)  // *


// Row 3
#define FW_PERC S(FW_UGRV) // %
#define FW_MICR S(FW_ASTR) // µ

#define FM_PERC S(FM_UGRV) // %
#define FM_PND  S(FM_GRV) // £


// Row 4
#define FW_RABK S(FW_LABK) // >
#define FW_QUES S(FW_COMM) // ?
#define FW_DOT  S(FW_SCLN) // .
#define FW_SLSH S(FW_COLN) // /
#define FW_SECT S(FW_EXLM) // §

#define FM_RABK S(FM_LABK) // >
#define FM_QUES S(FM_COMM) // ?
#define FM_DOT  S(FM_SCLN) // .
#define FM_SLSH S(FM_COLN) // /
#define FM_PLUS S(FM_EQL)  // +



/* AltGr symbols
 *
 * WINDOWS
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │   │   │ ~ │ # │ { │ [ │ | │ ` │ \ │   │ @ │ ] │ } │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │ € │   │   │   │   │   │   │   │   │ ¤ │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │   │   │   │   │   │   │   │   │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │   │   │   │   │   │   │   │   │   │   │   │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 *
 *
 * MAC OS
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │   │   │   │   │   │ { │   │   │   │   │   │ } │   │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │ € │   │   │   │   │   │   │   │   │   │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │   │   │   │   │   │   │   │   │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │   │   │   │   │   │   │ ~ │   │   │   │   │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */

// Row 1
#define FW_TILD ALGR(FW_EACU) // ~ (dead)
#define FW_HASH ALGR(FW_DQUO) // #
#define FW_LCBR ALGR(FW_QUOT) // {
#define FW_LBRC ALGR(FW_LPRN) // [
#define FW_PIPE ALGR(FW_MINS) // |
#define FW_GRV  ALGR(FW_EGRV) // ` (dead)
#define FW_BSLS ALGR(FW_UNDS) // (backslash)
#define FW_AT   ALGR(FW_AGRV) // @
#define FW_RBRC ALGR(FW_RPRN) // ]
#define FW_RCBR ALGR(FW_EQL)  // }

#define FM_LCBR ALGR(FM_LPRN) // {
#define FM_RCBR ALGR(FM_RPRN) // }


// Row 2
#define FW_EURO ALGR(FW_E)   // €
#define FW_CURR ALGR(FW_DLR) // ¤

#define FM_EURO ALGR(FM_E)   // €


// Row 4
#define FM_TILD ALGR(FM_N)   // ~



/* Shift+AltGr symbols
 *
 * MAC OS
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │   │   │   │   │   │ [ │   │   │   │   │   │ ] │   │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │   │   │   │   │   │   │   │   │ | │   │   │   │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │   │   │   │   │   │   │   │   │   │ \ │   │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */

// Row 1
#define FM_LBRC S(ALGR(FM_LPRN))    // [
#define FM_RBRC S(ALGR(FM_RPRN))    // ]


// Row 3
#define FM_PIPE S(ALGR(FM_L))       // |


// Row 4
#define FM_BSLS S(ALGR(FM_COLN))   // (backslash)

#endif
