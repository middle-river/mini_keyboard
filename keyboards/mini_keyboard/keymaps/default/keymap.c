/* Copyright 2020 %YOUR_NAME%
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _BASE,
  _NUM,
  _FNC
};

#define JKC_CARET KC_EQL
#define JKC_ATMARK KC_LBRC
#define JKC_LBRC KC_RBRC
#define JKC_CLN KC_QUOT
#define JKC_RBRC KC_BSLS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_ESC , KC_F1   , KC_F2  , KC_F3  , KC_F4  , KC_F5 , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11    , KC_F12   , TG(_NUM), KC_PAUS, KC_INS, KC_DEL,
    KC_ZKHK, KC_1    , KC_2   , KC_3   , KC_4   , KC_5  , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS   , JKC_CARET, KC_JYEN , KC_BSPC,
    KC_TAB , KC_Q    , KC_W   , KC_E   , KC_R   , KC_T  , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , JKC_ATMARK, JKC_LBRC , KC_ENT  ,
    KC_CAPS, KC_A    , KC_S   , KC_D   , KC_F   , KC_G  , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, JKC_CLN   , JKC_RBRC ,
    KC_LSFT, KC_Z    , KC_X   , KC_C   , KC_V   , KC_B  , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RO     , KC_UP    , KC_RSFT ,
    KC_LCTL, MO(_FNC), KC_LWIN, KC_LALT, KC_MHEN, KC_SPC, KC_HENK, KC_KANA, KC_APP , KC_RCTL, KC_LEFT, KC_DOWN   , KC_RGHT
  ),
  [_NUM] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_P7  , KC_P8  , KC_P9  , _______, KC_PMNS, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_P4  , KC_P5  , KC_P6  , _______, KC_PENT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_P1  , KC_P2  , KC_P3  , KC_PPLS, KC_PAST, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_P0  , _______, KC_PDOT, KC_PSLS, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_FNC] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_CALC, KC_MYCM, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_WAKE, KC_SLEP, XXXXXXX, KC_SLCK, XXXXXXX, KC_PSCR, KC_SYSREQ,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_END
  )
};

#define LED_CAPS B0
#define LED_NUM D5

void matrix_init_user(void) {
  setPinOutput(LED_CAPS);
  writePin(LED_CAPS, true);
  setPinOutput(LED_NUM);
  writePin(LED_NUM, true);
}

bool led_update_user(led_t led_state) {
  writePin(LED_CAPS, !led_state.caps_lock);
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  writePin(LED_NUM, !(get_highest_layer(state) == _NUM));
  return state;
}
