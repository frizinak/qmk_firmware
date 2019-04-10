#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2
#define _ARROWS 3
#define _ADJUST 4

#define SFT OSM(MOD_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,        KC_T,   KC_Y,   KC_U,        KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,        KC_G,   KC_H,   KC_J,        KC_K,    KC_L,    KC_SCLN, KC_QUOT,  \
  SFT,     KC_Z,    KC_X,    KC_C,    KC_V,        KC_B,   KC_N,   KC_M,        KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, \
  KC_LCTL, _______, KC_LALT, KC_LGUI, OSL(_LOWER), KC_SPC, KC_SPC, OSL(_RAISE), KC_RGUI, _______, MO(_ARROWS), KC_RCTL  \
),

[_LOWER] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  _______, \
  _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, _______, _______, KC_LCBR, KC_RCBR, KC_PIPE, KC_BSLS, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Raise
 * ,-------------------------------------------------------------------------------------.
 * |      |       |   7  |   8  |   9  |       |      |      |      |      |      |      |
 * |------+-------+------+------+------+--------------+------+------+------+------+------|
 * |      |       |   4  |   5  |   6  |       | Left | Down |  Up  | Right|      |      |
 * |------+-------+------+------+------+-------|------+------+------+------+------+------|
 * |      |       |   1  |   2  |   3  |       |      |      |      |      |      |      |
 * |------+-------+------+------+------+-------+------+------+------+------+------+------|
 * |      |       |      |      |   0  |       |      |      |      |      |      |      |
 * `-------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  _______, XXXXXXX, KC_7,    KC_8,    KC_9, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,  _______, \
  _______, XXXXXXX, KC_4,    KC_5,    KC_6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12, _______, \
  _______, XXXXXXX, KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, \
  _______, _______, _______, _______, KC_0, _______, _______, _______, _______, _______, _______, _______  \
),

[_ARROWS] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______  \
),

[_ADJUST] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, KC_DEL, \
  _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______  \
),

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_P:
            if (record->event.pressed && get_mods() == MOD_BIT(KC_LGUI)) {
                SEND_STRING(SS_UP(X_LGUI) SS_LCTRL("v") SS_DOWN(X_LGUI));
                return false;
            }

            break;
    }

    return true;
}
