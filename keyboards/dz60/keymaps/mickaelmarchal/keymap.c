#include "keymap_french.c"
#include QMK_KEYBOARD_H
#include "layout.h"

enum keyboard_layers {
  _BASE,
  _SYM,
};

enum custom_keycodes {
  M_1_EXCL = SAFE_RANGE,
  M_2_AROB,
  M_3_SHRP,
  M_4_DOLL,
  M_5_PCNT,
  M_6_CIRC,
  M_7_AND,
  M_8_STAR,
  M_9_LPAR,
  M_0_RPAR,
  M_SLSH,
  M_BSLSH,
  M_SCOL,
  M_LBR,
  M_RBR,
  M_QUOT,
  M_COMMA,
  M_DOT,
  M_EACU,
  M_GRV,
  M_KVM1,
  M_KVM2,
};


void norm_shift(uint16_t normal_code, uint16_t shifted_code, keyrecord_t *record) {
    if ((keyboard_report->mods & MOD_BIT (KC_LSFT)) || (keyboard_report->mods & MOD_BIT (KC_RSFT)) ) {
        if (record->event.pressed) {
            register_code(shifted_code);
        } else {
            unregister_code(shifted_code);
        }
    } else {
        if (record->event.pressed) {
            register_code(normal_code);
        } else {
            unregister_code(normal_code);
        }
    }
}

void shift_shift(uint16_t normal_code, uint16_t shifted_code, keyrecord_t *record) {
    if ((keyboard_report->mods & MOD_BIT (KC_LSFT)) || (keyboard_report->mods & MOD_BIT (KC_RSFT)) ) {
        if (record->event.pressed) {
            register_code(shifted_code);
        } else {
            unregister_code(shifted_code);
        }
    } else {
        if (record->event.pressed) {
            register_code(KC_LSFT);
            register_code(normal_code);
            unregister_code(KC_LSFT);
        } else {
            unregister_code(normal_code);
        }
    }
}

void shift_norm(uint16_t normal_code, uint16_t shifted_code, keyrecord_t *record) {
    if ((keyboard_report->mods & MOD_BIT (KC_LSFT)) || (keyboard_report->mods & MOD_BIT (KC_RSFT)) ) {
        if (record->event.pressed) {
            if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                unregister_code(KC_LSFT);
                register_code(shifted_code);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_RSFT);
                register_code(shifted_code);
                register_code(KC_RSFT);
            }
        } else {
            unregister_code(shifted_code);
        }
    } else {
        if (record->event.pressed) {
            register_code(KC_LSFT);
            register_code(normal_code);
            unregister_code(KC_LSFT);
        } else {
            unregister_code(normal_code);
        }
    }
}

void norm_norm(uint16_t normal_code, uint16_t shifted_code, keyrecord_t *record) {
    if ((keyboard_report->mods & MOD_BIT (KC_LSFT)) || (keyboard_report->mods & MOD_BIT (KC_RSFT)) ) {
        if (record->event.pressed) {
            if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                unregister_code(KC_LSFT);
                register_code(shifted_code);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_RSFT);
                register_code(shifted_code);
                register_code(KC_RSFT);
            }
        } else {
            unregister_code(shifted_code);
        }
    } else {
        if (record->event.pressed) {
            register_code(normal_code);
        } else {
            unregister_code(normal_code);
        }
    }
}

void shiftalt_shiftalt(uint16_t normal_code, uint16_t shifted_code, keyrecord_t *record) {
    if ((keyboard_report->mods & MOD_BIT (KC_LSFT)) || (keyboard_report->mods & MOD_BIT (KC_RSFT)) ) {
        if (record->event.pressed) {
            register_code(KC_RALT);
            register_code(shifted_code);
            unregister_code(KC_RALT);
        } else {
            unregister_code(shifted_code);
        }
    } else {
        if (record->event.pressed) {
            register_code(KC_LSFT);
            register_code(KC_RALT);
            register_code(normal_code);
            unregister_code(KC_RALT);
            unregister_code(KC_LSFT);
        } else {
            unregister_code(normal_code);
        }
    }
}

void shiftalt_alt(uint16_t normal_code, uint16_t shifted_code, keyrecord_t *record) {
    if ((keyboard_report->mods & MOD_BIT (KC_LSFT)) || (keyboard_report->mods & MOD_BIT (KC_RSFT)) ) {
        if (record->event.pressed) {
            if (keyboard_report->mods & MOD_BIT (KC_LSFT)) {
                unregister_code(KC_LSFT);
                register_code(KC_RALT);
                register_code(shifted_code);
                unregister_code(KC_RALT);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_RSFT);
                register_code(KC_RALT);
                register_code(shifted_code);
                unregister_code(KC_RALT);
                register_code(KC_RSFT);
            }
        } else {
            unregister_code(shifted_code);
        }
    } else {
        if (record->event.pressed) {
            register_code(KC_LSFT);
            register_code(KC_RALT);
            register_code(normal_code);
            unregister_code(KC_RALT);
            unregister_code(KC_LSFT);
        } else {
            unregister_code(normal_code);
        }
    }
}

void alt_shift(uint16_t normal_code, uint16_t shifted_code, keyrecord_t *record) {
    if ((keyboard_report->mods & MOD_BIT (KC_LSFT)) || (keyboard_report->mods & MOD_BIT (KC_RSFT)) ) {
        if (record->event.pressed) {
            register_code(shifted_code);
        } else {
            unregister_code(shifted_code);
        }
    } else {
        if (record->event.pressed) {
            register_code(KC_RALT);
            register_code(normal_code);
            unregister_code(KC_RALT);
        } else {
            unregister_code(normal_code);
        }
    }
}

void shiftalt_shift(uint16_t normal_code, uint16_t shifted_code, keyrecord_t *record) {
    if ((keyboard_report->mods & MOD_BIT (KC_LSFT)) || (keyboard_report->mods & MOD_BIT (KC_RSFT)) ) {
        if (record->event.pressed) {
            register_code(shifted_code);
        } else {
            unregister_code(shifted_code);
        }
    } else {
        if (record->event.pressed) {
            register_code(KC_LSFT);
            register_code(KC_RALT);
            register_code(normal_code);
            unregister_code(KC_RALT);
            unregister_code(KC_LSFT);
        } else {
            unregister_code(normal_code);
        }
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * BASE LAYER (_BASE)
 * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
 * │ESC    │1 !    │2 @    │3 #    │4 $    │5 %    │6 ^    │7 &    │8 *    │9 (    │0 )    │- _    │= +    │/ ?    │\ |    │
 * ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
 * │TAB        │b      │p      │o      │f      │w      │j      │q      │l      │y      │;      │[      │]      │BACKSP     │
 * ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
 * │→SYM         │a      │u      │i      │e      │d      │g      │t      │s      │r      │n      │'      │ENTER            │
 * ├──────────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴───────┴─┬───────┬───────┤
 * │LSHIFT    │é è    │z      │x      │c      │v      │k      │h      │m      │,      │.      │RSHIFT      │UP     │` ¨    │
 * ├──────────┼───────┴──┬────┴─────┬─┴───────┴───────┼───────┴──┬────┴───────┴────┬──┴────┬──┴────┬───────┼───────┼───────┤
 * │LCTRL     │LALT      │LCMD      │SPACE            │→SYM      │SPACE            │RCMD   │RALT   │LEFT   │DOWN   │RIGHT  │
 * └──────────┴──────────┴──────────┴─────────────────┴──────────┴─────────────────┴───────┴───────┴───────┴───────┴───────┘
 */
[_BASE] = LAYOUT_60_mickaelmarchal(
	FR_ESC,		M_1_EXCL,	M_2_AROB,	M_3_SHRP,	M_4_DOLL,	M_5_PCNT,	M_6_CIRC,	M_7_AND,	M_8_STAR,	M_9_LPAR,	M_0_RPAR,	FR_EQUA,	FR_EXCL,  	M_SLSH,    M_BSLSH,
	FR_TAB,		FR_B, 		FR_P, 		FR_O, 		FR_F, 		FR_W, 		FR_J, 		FR_Q, 		FR_L, 		FR_Y,		M_SCOL,	    M_LBR,   	M_RBR,      FR_BSPC,
	MO(1),	    FR_A, 		FR_U, 		FR_I, 		FR_E, 		FR_D, 		FR_G, 		FR_T, 		FR_S,		FR_R, 		FR_N, 		M_QUOT, 	KC_ENT,
	KC_LSFT,  	M_EACU,   	FR_Z,   	FR_X,   	FR_C,   	FR_V,   	FR_K,   	FR_H,   	FR_M,   	M_COMMA,	M_DOT, 	    KC_RSFT, 	KC_UP,		M_GRV,
	FR_LCTR, 	KC_LALT, 	KC_LGUI,	KC_SPC,		MO(1),		KC_SPC, 	KC_RGUI,	KC_RALT, 	KC_LEFT,	KC_DOWN,	KC_RGHT
),


/*
 * SYMBOLS LAYER (_SYM)
 * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
 * │RESET  │F1     │F2     │F3     │F4     │F5     │F6     │F7     │F8     │F9     │F10    │F11    │F12    │KVM1   │KVM2   │
 * ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
 * │LCTRL      │RGB    │RGB+   │RBG-   │       │       │       │       │UP     │       │       │       │       |DEL        │
 * ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
 * │_______      │LSHIFT │       │       │       │       │       │LEFT   │DOWN   │RIGHT  │       │       │                 │
 * ├──────────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴───────┴─┬───────┬───────┤
 * │LSHIFT    │       │       │       │       │       │VOL-   │VOL-   │REWIND │FFWD   │       │L CLICK     │MOUSE U│R CLICK│
 * ├──────────┼───────┴──┬────┴─────┬─┴───────┴───────┼───────┴──┬────┴───────┴────┬──┴────┬──┴────┬───────┼───────┼───────┤
 * │LCTRL     │LALT      │LCMD      │VOL MUTE         │FN        │PLAY/PAUSE       │       │       │MOUSE L│MOUSE D│MOUSE R│
 * └──────────┴──────────┴──────────┴─────────────────┴──────────┴─────────────────┴───────┴───────┴───────┴───────┴───────┘
 */

[_SYM] = LAYOUT_60_mickaelmarchal(
	RESET, 		KC_F1, 		KC_F2, 		KC_F3, 		KC_F4, 		KC_F5, 		KC_F6, 		KC_F7, 		KC_F8, 		KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	M_KVM1, 	M_KVM2,
	FR_LCTR,    RGB_TOG, 	RGB_MOD, 	RGB_RMOD, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_UP, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_DEL,
	KC_TRNS, 	KC_LSFT, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_LEFT, 	KC_DOWN, 	KC_RGHT, 	KC_NO, 		KC_NO, 		KC_NO,
	KC_LSFT, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_VOLD, 	KC_VOLU,	KC_MRWD, 	KC_MFFD, 	KC_NO,      KC_MS_BTN1, KC_MS_U,    KC_MS_BTN2,
	FR_LCTR, 	KC_LALT, 	KC_LGUI, 	KC_MUTE, 	KC_TRNS, 	KC_MPLY, 	KC_NO, 		KC_NO, 		KC_MS_L, 	KC_MS_D, 	KC_MS_R
)
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        // ! 1
        case M_1_EXCL: {
            norm_shift(FR_UNDS, FR_AMP, record);
            break;
        }
        // @ 2
        case M_2_AROB: {
            alt_shift(FR_AST, FR_EACU, record);
            break;
        }
        // # 3
        case M_3_SHRP: {
            shiftalt_shift(FR_AST, FR_QUOT, record);
            break;
        }
        // $ 4
        case M_4_DOLL: {
            norm_shift(FR_DLR, FR_APOS, record);
            break;
        }
        // % 5
        case M_5_PCNT: {
            shift_shift(FR_UGRV, FR_LPAR, record);
            break;
        }
        // ^ 6
        case M_6_CIRC: {
            norm_shift(FR_HAT, FR_MINS, record);
            break;
        }
        // & 7
        case M_7_AND: {
            norm_shift(FR_AMP, FR_EGRV, record);
            break;
        }
        // * 8
        case M_8_STAR: {
            shift_shift(FR_DLR, FR_UNDS, record);
            break;
        }
        // ( 9
        case M_9_LPAR: {
            norm_shift(FR_LPAR, FR_CCED, record);
            break;
        }
        // ) 0
        case M_0_RPAR: {
            norm_shift(FR_RPAR, FR_AGRV, record);
            break;
        }
        // / ?
        case M_SLSH: {
            shift_shift(FR_COLN, FR_COMM, record);
            break;
        }
        // \ |
        case M_BSLSH: {
            shiftalt_shiftalt(FR_COLN, FR_L, record);
            break;
        }
        // ; :
        case M_SCOL: {
            norm_norm(FR_SCLN, FR_COLN, record);
            break;
        }
        // [ {
        case M_LBR: {
            shiftalt_alt(FR_LPAR, FR_LPAR, record);
            break;
        }
        // ] }
        case M_RBR: {
            shiftalt_alt(FR_RPAR, FR_RPAR, record);
            break;
        }
        // ' "
        case M_QUOT: {
            norm_norm(FR_APOS, FR_QUOT, record);
            break;
        }
        // , <
        case M_COMMA: {
            norm_norm(FR_COMM, KC_GRV, record);
            break;
        }
        // . >
        case M_DOT: {
            shift_shift(FR_SCLN, KC_GRV, record);
            break;
        }

        // é è
        case M_EACU: {
            norm_norm(FR_EACU, FR_EGRV, record);
            break;
        }

        // `à
        case M_GRV: {
            norm_shift(FR_AST, FR_HAT, record);
            break;
        }

        // Switch KVM to Port 1
        case M_KVM1: {
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LOCKING_SCROLL) SS_DELAY(30) SS_TAP(X_LOCKING_SCROLL) SS_DELAY(30) SS_LSFT("1"));
            }
            break;
        }

        // Switch KVM to Port 2
        case M_KVM2: {
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LOCKING_SCROLL) SS_DELAY(30) SS_TAP(X_LOCKING_SCROLL) SS_DELAY(30) SS_LSFT("2"));
            }
            break;
        }
	}
  	return true;
};
