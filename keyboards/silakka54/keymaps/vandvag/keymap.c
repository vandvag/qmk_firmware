// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// QWERTY Home Row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

// COLEMAK Home Row mods
#define ALT_R LALT_T(KC_R)
#define SFT_S LSFT_T(KC_S)
// rename necessary, since CTL_H is already defined
#define CTL_TH LCTL_T(KC_T)

// Right-hand home row mods
#define CTL_N RCTL_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define ALT_I RALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)

#define NUM_ALT LT(_NUM, KC_LALT)
#define FN_ALT  LT(_FN, KC_LALT)
#define SFT_ENT LSFT_T(KC_ENT)

enum layers {
    _QWERTY,
    _COLEMAK,
    _SYM,
    _NAV,
    _FN,
    _NUM,
    _ADJUST,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
       XXXXXXX,    KC_1,     KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_GRV,
        KC_TAB,    KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
        KC_LCTL,  GUI_A,    ALT_S,   SFT_D,   CTL_F,    KC_G,                               KC_H,   CTL_J,   SFT_K,   ALT_L,GUI_SCLN,  KC_QUOT,
        KC_LSFT,   KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_ESC,
                                           NUM_ALT, MO(_SYM), SFT_ENT,           KC_SPC,  MO(_NAV), FN_ALT
    ),
    [_COLEMAK] = LAYOUT(
       XXXXXXX,    KC_1,     KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_GRV,
        KC_TAB,    KC_Q,     KC_W,    KC_F,    KC_P,    KC_G,                               KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,
        KC_LCTL,  GUI_A,    ALT_R,   SFT_S,  CTL_TH,    KC_D,                               KC_H,   CTL_N,   SFT_E,   ALT_I,   GUI_O,  KC_QUOT,
        KC_LSFT,   KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,                               KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_ESC,
                                           NUM_ALT, MO(_SYM), SFT_ENT,           KC_SPC,  MO(_NAV), FN_ALT
    ),
    [_SYM] = LAYOUT(
         KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
        _______,  KC_GRV, KC_TILD, KC_HASH, KC_AMPR, KC_PIPE,                            KC_CIRC, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_BSPC,
        _______, KC_EXLM, KC_UNDS, KC_COLN,  KC_EQL,  KC_DLR,                            KC_PERC, KC_LPRN, KC_RPRN, KC_UNDS, _______, KC_PIPE,
        _______,   KC_AT, KC_SLSH, KC_ASTR, KC_PLUS, KC_BSLS,                             KC_DLR, KC_MINS,   KC_LT,   KC_GT, KC_SLSH, _______,
                                           _______, _______, _______,           _______, MO(_ADJUST),_______
    ),
    [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______, _______, _______, MS_UP, _______, _______,                            KC_HOME, _______,   KC_UP, _______, KC_PGUP,  KC_DEL,
        _______, MS_WHLU, MS_LEFT, MS_DOWN, MS_RGHT, KC_CAPS,                             KC_END, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
        _______, MS_WHLD, MS_BTN1, MS_BTN3, MS_BTN2, KC_PSCR,                            _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______,
                                            _______, _______, _______,      _______, MO(_ADJUST),_______
    ),
    [_FN] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______, _______,   KC_F7,   KC_F8,   KC_F9,  KC_F12,                            _______, _______, _______, _______, _______, _______,
        _______, _______,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                            _______, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, _______,
        _______, _______,   KC_F1,   KC_F2,   KC_F3,  KC_F10,                            _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,          _______, _______,_______
    ),
    [_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______,    KC_7,    KC_8,    KC_9,    KC_0, _______,
        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                            _______,    KC_4,    KC_5,    KC_6, _______, _______,
        _______, _______, _______, _______, _______, _______,                               KC_0,    KC_1,    KC_2,    KC_3, _______, _______,
                                            _______, _______, _______,          _______, _______,_______
    ),
    [_ADJUST] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______, _______, DF(_QWERTY), DF(_COLEMAK), _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,          _______, _______,_______
    )
};
