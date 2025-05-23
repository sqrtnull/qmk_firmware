/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// const uint16_t PROGMEM com_sd[]    = {KC_S, KC_D, COMBO_END};
// const uint16_t PROGMEM com_sdf[]   = {KC_S, KC_D, KC_F, COMBO_END};
// const uint16_t PROGMEM com_df[]    = {KC_F, KC_D, COMBO_END};
// const uint16_t PROGMEM com_xc[]    = {KC_X, KC_C, COMBO_END};
// const uint16_t PROGMEM com_kl[]    = {KC_K, KC_L, COMBO_END};
// const uint16_t PROGMEM com_jk[]    = {KC_K, KC_J, COMBO_END};
// const uint16_t PROGMEM com_zxc[]   = {KC_Z, KC_X, KC_C, COMBO_END};
// const uint16_t PROGMEM com_cmdt[]  = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    // COMBO(com_sd, MO(1)),           // numbers
    // COMBO(com_sdf, MO(4)),           // function
    // COMBO(com_kl, KC_ENT),           // enter
    // COMBO(com_jk, KC_ESC),           // esc
    // COMBO(com_xc, KC_TAB),           // tab
    // COMBO(com_df, QK_LEAD),          // leader
    // COMBO(com_cmdt, KC_BSPC),        // backspace
    // COMBO(com_zxc, KC_CAPS),         // caps lock
};

#define NAV_SCN LT(3,KC_SCLN)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)

enum Layer {
    DEF, NUM, NAV, SYM, FUN, XXX
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_split_3x5_3(
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
                                 MO(NUM), MO(SYM), OS_LSFT,    OS_LCTL,  KC_SPC, KC_LGUI
  ),

    [NUM] = LAYOUT_split_3x5_3(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, MO(FUN), XXXXXXX,                      XXXXXXX,    KC_4,    KC_5,    KC_6,    KC_0,
      XXXXXXX, XXXXXXX, TG(NAV), XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX,
                                 XXXXXXX, KC_LGUI, _______,    _______,    KC_0, KC_LALT
  ),

    [NAV] = LAYOUT_split_3x5_3(
      KC_LGUI, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,                      KC_HOME, KC_PGUP, TG(NAV), TG(NAV), TG(NAV),
      TG(NAV), KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, TG(NAV),
      KC_WH_L, KC_BTN4, KC_BTN3, KC_BTN5, KC_WH_R,                       KC_END, KC_PGDN, KC_BSPC,  KC_TAB,  KC_ENT,
                                 MO(XXX), MO(SYM), _______,    _______,  KC_SPC, KC_LALT
  ),

    [SYM] = LAYOUT_split_3x5_3(
       KC_GRV,   KC_AT, KC_LPRN, KC_RPRN, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR,  KC_ENT,  KC_ESC,
      KC_EXLM, KC_HASH, KC_LCBR, KC_RCBR, KC_DQUO,                      KC_PIPE, KC_MINS,  KC_EQL, KC_PLUS, KC_COLN,
      KC_TILD,  KC_DLR, KC_LBRC, KC_RBRC, KC_QUOT,                      KC_CAPS, KC_UNDS, KC_BSPC,  KC_TAB, KC_BSLS,
                                 KC_LGUI, XXXXXXX, _______,    _______,  KC_SPC, KC_LALT
  ),

    [FUN] = LAYOUT_split_3x5_3(
      QK_MAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F12,
                                 XXXXXXX, KC_LGUI, _______,    _______,  KC_SPC, KC_LALT
  ),

    [XXX] = LAYOUT_split_3x5_3(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
  )
};
