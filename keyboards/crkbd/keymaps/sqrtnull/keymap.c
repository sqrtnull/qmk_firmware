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

// d series
const uint16_t PROGMEM com_sd[] = {KC_S, KC_D,COMBO_END}; // common, but nice position
const uint16_t PROGMEM com_df[] = {KC_F, KC_D,COMBO_END};
const uint16_t PROGMEM com_dv[] = {KC_V, KC_D,COMBO_END};
const uint16_t PROGMEM com_dg[] = {KC_G, KC_D,COMBO_END}; // godot?
const uint16_t PROGMEM com_db[] = {KC_B, KC_D,COMBO_END}; // db
// c series
// const uint16_t PROGMEM com_sc[] = {KC_S, KC_C,COMBO_END}; // too common?
const uint16_t PROGMEM com_cv[] = {KC_C, KC_C,COMBO_END};
const uint16_t PROGMEM com_xc[] = {KC_X, KC_C,COMBO_END};

// k series
const uint16_t PROGMEM com_kl[] = {KC_K, KC_L,COMBO_END};
const uint16_t PROGMEM com_jk[] = {KC_K, KC_J,COMBO_END}; // vim
const uint16_t PROGMEM com_mk[] = {KC_K, KC_M,COMBO_END};
const uint16_t PROGMEM com_hk[] = {KC_K, KC_H,COMBO_END};
// const uint16_t PROGMEM com_nk[] = {KC_K, KC_N,COMBO_END}; // too common?
// , series
const uint16_t PROGMEM com_coml[] = {KC_COMM, KC_L,COMBO_END};
const uint16_t PROGMEM com_comdot[] = {KC_COMM, KC_DOT,COMBO_END};
const uint16_t PROGMEM com_comdotm[] = {KC_M,KC_COMM, KC_DOT,COMBO_END};
const uint16_t PROGMEM com_comm[] = {KC_COMM, KC_M,COMBO_END};

combo_t key_combos[]={
    COMBO(com_sd,OSL(1)), // symbols
    COMBO(com_kl,KC_ENT), // enter
    COMBO(com_jk,KC_ESC), // enter
    COMBO(com_comdot,KC_BSPC), // backspace
    COMBO(com_comdotm,LALT(KC_BSPC)), // alt-backspace
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,LT(3,KC_SCLN), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       KC_LGUI,OSL(2),OSM(MOD_LSFT),     OSM(MOD_LCTL),KC_SPC, MT(MOD_LALT,KC_TAB)
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______,    KC_4,    KC_5,    KC_6, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                         KC_0,    KC_1,    KC_2,    KC_3, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_GRV,   KC_AT, KC_LCBR, KC_RCBR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, _______, KC_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM, KC_HASH, KC_LPRN, KC_RPRN, KC_DQUO,                      KC_PIPE, KC_MINS,  KC_EQL, KC_PLUS, KC_COLON, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_TILD, KC_DLR, KC_LBRC, KC_RBRC, KC_QUOT,                       KC_BSLS, KC_UNDS, KC_LABK, KC_RABK, KC_QUESTION, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};
