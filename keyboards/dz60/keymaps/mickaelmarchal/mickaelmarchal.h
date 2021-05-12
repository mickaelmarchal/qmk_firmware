
#include QMK_KEYBOARD_H

#ifndef mickaelmarchal
#define mickaelmarchal

#include "quantum.h"
#include "layout.h"
#include "keymap_french.h"

enum keyboard_layers {
  _BASE_WIN,
  _BASE_MAC,
  _FN_WIN,
  _FN_MAC,
};


// for the creation of Qwerty keys on an Azerty keyboard at the OS layer.

// so we can create an array of reasonable size
// for our translation keys. We have to create a
// good range of numbers
#define GR(x) (x-SAFE_RANGE)

uint8_t gr(uint8_t);
void send_keycode(uint8_t);

#define MOD_NONE 0x00

// indexs for the keycode translation table.
#define UNSHIFTED_KEY(key)  key_translations[gr(key)][0][0]
#define UNSHIFTED_MODS(key) key_translations[gr(key)][0][1]
#define SHIFTED_KEY(key)    key_translations[gr(key)][1][0]
#define SHIFTED_MODS(key)   key_translations[gr(key)][1][1]

enum userspace_custom_keycodes {
    // Win      // Mac os
    MW_1 = SAFE_RANGE, MM_1,
    MW_2,       MM_2,
    MW_3,       MM_3,
    MW_4,       MM_4,
    MW_5,       MM_5,
    MW_6,       MM_6,
    MW_7,       MM_7,
    MW_8,       MM_8,
    MW_9,       MM_9,
    MW_0,       MM_0,
    MW_MINS,    MM_MINS,
    MW_EQL,     MM_EQL,
    MW_SLSH,    MM_SLSH,
    MW_BSLS,    MM_BSLS,
    MW_SCLN,    MM_SCLN,
    MW_LCBR,    MM_LCBR,
    MW_RCBR,    MM_RCBR,
    MW_QUOT,    MM_QUOT,
    MW_EACU,    MM_EACU,
    MW_COMM,    MM_COMM,
    MW_DOT,     MM_DOT,
    MW_GRV,     MM_GRV,

    MW_ALTAB,   MM_ALTAB,

    M_KVM1,
    M_KVM2,
};

#endif
