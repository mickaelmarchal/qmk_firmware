

#include "mickaelmarchal.h"
#include "quantum.h"

// For super alt+tab (cmd+tab on mac)
// @see https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_macros#super-alt-tab
bool is_alt_tab_active = false; // ADD this near the begining of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.


// These are the keys for my layout on top of an AZERTY OS.  column one is the keycode and mods for
// the unshifted key, the second column is the keycode and mods for the shifted key.
// GR is Good Range.  It subtracts SAFE_RANGE from the keycode so we can make a
// reasnably sized array without difficulties. The macro is for the constant declarations
// the function is for when we use it.
const uint8_t key_translations[][2][2] = {

  // 1 !
  [GR(MW_1)] =      {{FW_AMPR, MOD_LSFT},      {FW_EXLM, MOD_NONE}},
  [GR(MM_1)] =      {{FM_AMPR, MOD_LSFT},      {FM_EXLM, MOD_NONE}},

  // 2 @
  [GR(MW_2)] =      {{FW_EACU, MOD_LSFT},      {FW_AGRV, MOD_BIT(KC_RALT)}},
  [GR(MM_2)] =      {{FM_EACU, MOD_LSFT},      {FM_AT, MOD_NONE}},

   // 3 #
  [GR(MW_3)] =      {{FW_DQUO, MOD_LSFT},      {FW_DQUO, MOD_BIT(KC_RALT)}},
  [GR(MM_3)] =      {{FM_DQUO, MOD_LSFT},      {FM_AT, MOD_LSFT}},

  // 4 $
  [GR(MW_4)] =      {{FW_QUOT, MOD_LSFT},      {FW_DLR, MOD_NONE}},
  [GR(MM_4)] =      {{FM_QUOT, MOD_LSFT},      {FM_DLR, MOD_NONE}},

  // 5 %
  [GR(MW_5)] =      {{FW_LPRN, MOD_LSFT},      {FW_UGRV, MOD_LSFT}},
  [GR(MM_5)] =      {{FM_LPRN, MOD_LSFT},      {FM_UGRV, MOD_LSFT}},

  // 6 ^
  [GR(MW_6)] =      {{FW_MINS, MOD_LSFT},      {FW_CIRC, MOD_NONE}},
  [GR(MM_6)] =      {{FM_SECT, MOD_LSFT},      {FM_CIRC, MOD_NONE}},

  // 7 &
  [GR(MW_7)] =      {{FW_EGRV, MOD_LSFT},      {FW_AMPR, MOD_NONE}},
  [GR(MM_7)] =      {{FM_EGRV, MOD_LSFT},      {FM_AMPR, MOD_NONE}},

  // 8 *
  [GR(MW_8)] =      {{FW_UNDS, MOD_LSFT},      {FW_ASTR, MOD_NONE}},
  [GR(MM_8)] =      {{FM_EXLM, MOD_LSFT},      {FM_DLR, MOD_LSFT}},

  // 9 (
  [GR(MW_9)] =      {{FW_CCED, MOD_LSFT},      {FW_LPRN, MOD_NONE}},
  [GR(MM_9)] =      {{FM_CCED, MOD_LSFT},      {FM_LPRN, MOD_NONE}},

   // 0 )
  [GR(MW_0)] =      {{FW_AGRV, MOD_LSFT},      {FW_RPRN, MOD_NONE}},
  [GR(MM_0)] =      {{FM_AGRV, MOD_LSFT},      {FM_RPRN, MOD_NONE}},

  // - _
  [GR(MW_MINS)] =   {{FW_MINS, MOD_NONE},      {FW_UNDS, MOD_NONE}},
  [GR(MM_MINS)] =   {{FM_MINS, MOD_NONE},      {FM_MINS, MOD_LSFT}},

  // = +
  [GR(MW_EQL)] =    {{FW_EQL, MOD_NONE},       {FW_EQL, MOD_LSFT}},
  [GR(MM_EQL)] =    {{FM_EQL, MOD_NONE},       {FM_EQL, MOD_LSFT}},

  // / ?
  [GR(MW_SLSH)] =   {{FW_COLN, MOD_LSFT},      {FW_COMM, MOD_LSFT}},
  [GR(MM_SLSH)] =   {{FM_COLN, MOD_LSFT},      {FM_COMM, MOD_LSFT}},

  // \ |
  [GR(MW_BSLS)] =   {{FW_UNDS, MOD_BIT(KC_RALT)},                       {FW_MINS, MOD_BIT(KC_RALT)}},
  [GR(MM_BSLS)] =   {{FM_COLN, MOD_BIT(KC_RALT)|MOD_BIT(KC_LSFT)},      {FM_L, MOD_BIT(KC_RALT)|MOD_BIT(KC_LSFT)}},

  // ; :
  [GR(MW_SCLN)] =   {{FW_SCLN, MOD_NONE},      {FW_COLN, MOD_NONE}},
  [GR(MM_SCLN)] =   {{FM_SCLN, MOD_NONE},      {FM_COLN, MOD_NONE}},

  // [ {
  [GR(MW_LCBR)] =   {{FW_LPRN, MOD_BIT(KC_RALT)},                       {FW_QUOT, MOD_BIT(KC_RALT)}},
  [GR(MM_LCBR)] =   {{FM_LPRN, MOD_BIT(KC_RALT)|MOD_BIT(KC_LSFT)},      {FM_LPRN, MOD_BIT(KC_RALT)}},

  // ] }
  [GR(MW_RCBR)] =   {{FW_RPRN, MOD_BIT(KC_RALT)},                       {FW_EQL, MOD_BIT(KC_RALT)}},
  [GR(MM_RCBR)] =   {{FM_RPRN, MOD_BIT(KC_RALT)|MOD_BIT(KC_LSFT)},      {FM_RPRN, MOD_BIT(KC_RALT)}},

  // ' "
  [GR(MW_QUOT)] =   {{FW_QUOT, MOD_NONE},      {FW_DQUO, MOD_NONE}},
  [GR(MM_QUOT)] =   {{FM_QUOT, MOD_NONE},      {FM_DQUO, MOD_NONE}},

  // é è
  [GR(MW_EACU)] =   {{FW_EACU, MOD_NONE},      {FW_EGRV, MOD_NONE}},
  [GR(MM_EACU)] =   {{FM_EACU, MOD_NONE},      {FM_EGRV, MOD_NONE}},

  // , <
  [GR(MW_COMM)] =   {{FW_COMM, MOD_NONE},      {FW_LABK, MOD_NONE}},
  [GR(MM_COMM)] =   {{FM_COMM, MOD_NONE},      {FM_LABK, MOD_NONE}},

  // . >
  [GR(MW_DOT)] =   {{FW_SCLN, MOD_LSFT},       {FW_LABK, MOD_LSFT}},
  [GR(MM_DOT)] =   {{FM_SCLN, MOD_LSFT},       {FM_LABK, MOD_LSFT}},

  // ` ¨
  [GR(MW_GRV)] =   {{FW_EGRV, MOD_BIT(KC_RALT)},        {FW_CIRC, MOD_LSFT}},
  [GR(MM_GRV)] =   {{FM_GRV, MOD_NONE},                 {FM_CIRC, MOD_LSFT}},
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/**
 * BASE LAYERS (WINDOWS, MAC)
 * Provide the same mapping on both OS.
 *
 * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
 * │ESC    │1 !    │2 @    │3 #    │4 $    │5 %    │6 ^    │7 &    │8 *    │9 (    │0 )    │- _    │= +    │/ ?    │\ |    │
 * ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
 * │TAB        │b      │p      │o      │f      │w      │j      │q      │l      │y      │;      │[      │]      │BACKSP     │
 * ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
 * │→FN          │a      │u      │i      │e      │d      │g      │t      │s      │r      │n      │'      │ENTER            │
 * ├──────────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴───────┴─┬───────┬───────┤
 * │LSHIFT    │é è    │z      │x      │c      │v      │k      │h      │m      │,      │.      │RSHIFT      │UP     │` ¨    │
 * ├──────────┼───────┴──┬────┴─────┬─┴───────┴───────┼───────┴──┬────┴───────┴────┬──┴─────┬─┴────┬───────┼───────┼───────┤
 * │WIN/LCTRL │LALT      │LCTRL/LCMD│SPACE            │→FN/SPC   │SPACE            │RCMD/WIN│RALT  │LEFT   │DOWN   │RIGHT  │
 * └──────────┴──────────┴──────────┴─────────────────┴──────────┴─────────────────┴────────┴──────┴───────┴───────┴───────┘
 */
[_BASE_WIN] = LAYOUT_60_mickaelmarchal(
	KC_ESC,		MW_1,	    MW_2,	    MW_3,	    MW_4,	    MW_5,	    MW_6,	    MW_7,	    MW_8,	    MW_9,	    MW_0,	    MW_MINS,	MW_EQL,  	MW_SLSH,    MW_BSLS,
	KC_TAB,		FW_B, 		FW_P, 		FW_O, 		FW_F, 		FW_W, 		FW_J, 		FW_Q, 		FW_L, 		FW_Y,		MW_SCLN,	MW_LCBR,   	MW_RCBR,    KC_BSPC,
	MO(_FN_WIN),    FW_A, 		FW_U, 		FW_I, 		FW_E, 		FW_D, 		FW_G, 		FW_T, 		FW_S,		FW_R, 		FW_N, 		MW_QUOT, 	KC_ENT,
	KC_LSFT,  	MW_EACU,   	FW_Z,   	FW_X,   	FW_C,   	FW_V,   	FW_K,   	FW_H,   	FW_M,   	MW_COMM,	MW_DOT, 	KC_RSFT, 	KC_UP,		MW_GRV,
	KC_LGUI, 	KC_LALT, 	KC_LCTL,	KC_SPC,		LT(_FN_WIN, KC_SPC),    	KC_SPC, 	KC_RGUI,	KC_RALT, 	KC_LEFT,	KC_DOWN,	KC_RGHT
),
[_BASE_MAC] = LAYOUT_60_mickaelmarchal(
	KC_ESC,		MM_1,	    MM_2,	    MM_3,	    MM_4,	    MM_5,	    MM_6,	    MM_7,	    MM_8,	    MM_9,	    MM_0,	    MM_MINS,	MM_EQL,  	MM_SLSH,    MM_BSLS,
	KC_TAB,		FM_B, 		FM_P, 		FM_O, 		FM_F, 		FM_W, 		FM_J, 		FM_Q, 		FM_L, 		FM_Y,		MM_SCLN,	MM_LCBR,   	MM_RCBR,    KC_BSPC,
	MO(_FN_MAC),	FM_A, 		FM_U, 		FM_I, 		FM_E, 		FM_D, 		FM_G, 		FM_T, 		FM_S,		FM_R, 		FM_N, 		MM_QUOT, 	KC_ENT,
	KC_LSFT,  	MM_EACU,   	FM_Z,   	FM_X,   	FM_C,   	FM_V,   	FM_K,   	FM_H,   	FM_M,   	MM_COMM,	MM_DOT, 	KC_RSFT, 	KC_UP,		MM_GRV,
	KC_LCTL, 	KC_LALT, 	KC_LGUI,	KC_SPC,		LT(_FN_MAC, KC_SPC),	    KC_SPC, 	KC_RGUI,	KC_RALT, 	KC_LEFT,	KC_DOWN,	KC_RGHT
),

/**
 * FUNCTION LAYERS (WINDOWS, MAC)
 * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
 * │RESET  │F1     │F2     │F3     │F4     │F5     │F6     │F7     │F8     │F9     │F10    │F11    │F12    │KVM1   │KVM2   │
 * ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
 * │ALT_TAB    │RGB    │RGB+   │RGB-   │       │       │       │       │UP     │       │       │       │       |DEL        │
 * ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
 * │_______      │LSHIFT │       │       │       │       │       │LEFT   │DOWN   │RIGHT  │       │       │                 │
 * ├──────────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴────┬──┴───────┴─┬───────┬───────┤
 * │LSHIFT    │       │       │       │       │       │VOL-   │VOL-   │REWIND │FFWD   │       │L CLICK     │MOUSE U│R CLICK│
 * ├──────────┼───────┴──┬────┴─────┬─┴───────┴───────┼───────┴──┬────┴───────┴────┬──┴────┬──┴────┬───────┼───────┼───────┤
 * │LCTRL     │LALT      │LCMD      │VOL MUTE         │_______   │PLAY/PAUSE       │       │       │MOUSE L│MOUSE D│MOUSE R│
 * └──────────┴──────────┴──────────┴─────────────────┴──────────┴─────────────────┴───────┴───────┴───────┴───────┴───────┘
 */

[_FN_WIN] = LAYOUT_60_mickaelmarchal(
	RESET, 		KC_F1, 		KC_F2, 		KC_F3, 		KC_F4, 		KC_F5, 		KC_F6, 		KC_F7, 		KC_F8, 		KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	M_KVM1, 	M_KVM2,
	MW_ALTAB,    RGB_TOG, 	RGB_MOD, 	RGB_RMOD, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_UP, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_DEL,
	KC_TRNS, 	KC_LSFT, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_LEFT, 	KC_DOWN, 	KC_RGHT, 	KC_NO, 		KC_NO, 		KC_NO,
	KC_LSFT, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_VOLD, 	KC_VOLU,	KC_MRWD, 	KC_MFFD, 	KC_NO,      KC_MS_BTN1, KC_MS_U,    KC_MS_BTN2,
	KC_LCTL, 	KC_LALT, 	KC_LGUI, 	KC_MUTE, 	KC_TRNS, 	KC_MPLY, 	KC_NO, 		KC_NO, 		KC_MS_L, 	KC_MS_D, 	KC_MS_R
),
[_FN_MAC] = LAYOUT_60_mickaelmarchal(
	RESET, 		KC_F1, 		KC_F2, 		KC_F3, 		KC_F4, 		KC_F5, 		KC_F6, 		KC_F7, 		KC_F8, 		KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	M_KVM1, 	M_KVM2,
	MM_ALTAB,    RGB_TOG, 	RGB_MOD, 	RGB_RMOD, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_UP, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_DEL,
	KC_TRNS, 	KC_LSFT, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_LEFT, 	KC_DOWN, 	KC_RGHT, 	KC_NO, 		KC_NO, 		KC_NO,
	KC_LSFT, 	KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_NO, 		KC_VOLD, 	KC_VOLU,	KC_MRWD, 	KC_MFFD, 	KC_NO,      KC_MS_BTN1, KC_MS_U,    KC_MS_BTN2,
	KC_LCTL, 	KC_LALT, 	KC_LGUI, 	KC_MUTE, 	KC_TRNS, 	KC_MPLY, 	KC_NO, 		KC_NO, 		KC_MS_L, 	KC_MS_D, 	KC_MS_R
),

};

uint8_t gr(uint8_t kc){
  return (kc - SAFE_RANGE);
}

/**
 * send the right keycode for the right mod.
 * remove the mods we are taking care of,
 * send our keycodes then restore them.
 * all so we can make custom keys from azerty keycodes.
 */
void send_keycode(uint8_t kc){
  uint8_t tmp_mods = get_mods();
  bool is_shifted = ( tmp_mods & (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT)) );
  //uint8_t key[2][2] = key_translations[GR(kc)];
  // need to turn of the shift if it is on.
  unregister_mods((MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT)));
  if(is_shifted){
    register_mods(SHIFTED_MODS(kc));
    register_code(SHIFTED_KEY(kc));
    unregister_code(SHIFTED_KEY(kc));
    unregister_mods(SHIFTED_MODS(kc));
  } else{
    register_mods(UNSHIFTED_MODS(kc));
    register_code(UNSHIFTED_KEY(kc));
    unregister_code(UNSHIFTED_KEY(kc));
    unregister_mods(UNSHIFTED_MODS(kc));
  }
  clear_mods();
  register_mods(tmp_mods);
}




bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        // custom keys on azerty
        case MW_1 ... MM_GRV:
            if(record->event.pressed)
                send_keycode(keycode);
            unregister_code(keycode);
        break;

        // Switch KVM to Port 1 (Windows)
        case M_KVM1: {
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LOCKING_SCROLL) SS_DELAY(30) SS_TAP(X_LOCKING_SCROLL) SS_DELAY(30) SS_LSFT("1"));
                set_single_persistent_default_layer(_BASE_WIN);
            }
            break;
        }

        // Switch KVM to Port 2 (Mac)
        case M_KVM2: {
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_LOCKING_SCROLL) SS_DELAY(30) SS_TAP(X_LOCKING_SCROLL) SS_DELAY(30) SS_LSFT("2"));
                set_single_persistent_default_layer(_BASE_MAC);
            }
            break;
        }

        // Super alt+tab (win)
        case MW_ALTAB: {
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        }

        // Super cmd+tab (mac)
        case MM_ALTAB: {
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LGUI);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        }
    }
  	return true;
};

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      unregister_code(KC_LGUI);
      is_alt_tab_active = false;
    }
  }
}
