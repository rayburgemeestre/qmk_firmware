#include "jj40.h"
#include "action_layer.h"
#include "quantum.h"

#define CTL_T_CUSTOM 0x7101 // to work around LT() issue , see https://github.com/qmk/qmk_firmware/issues/303

#define _QWERTY 0
#define _LOWER  1
#define _LOWERSHIFT  2
#define _RAISE  3
#define _EXTRA  4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  LOWER_SHIFT,
  RAISE,
  EXTRA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | BS   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter | maybe make it shift when combined
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Alt  |Alt   |Lower | space|Raise | Shift| Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT) , \
  KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, MO(_LOWER),  MO(_EXTRA), KC_SPC,  CTL_T_CUSTOM,   KC_RSFT, KC_DOWN, KC_UP,   KC_RGHT \
	//KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, KC_LALT,  MO(_LOWER), KC_SPC,  LT(_RAISE, KC_SPACE),   KC_RSFT, KC_DOWN, KC_UP,   KC_RGHT // MT(_RAISE, KC_SPACE)., QQWER
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Backs|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |LCNTRL|LCTRL |      |LOWERS|      | left | down | up   | right|   \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |SHIFT |      |      |      |      |      |      |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LCONTR| BL ON|BL OFF|      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_DEL,  KC_LCTL,   KC_LCTL,   _______,   MO(_LOWERSHIFT), _______,  KC_LEFT,   KC_DOWN, KC_UP, KC_RIGHT, KC_RCBR, KC_PIPE, \
  KC_LSFT, _______,   _______,   _______,   _______,  _______,  _______,S(KC_NUHS),S(KC_NUBS),_______, _______, _______, \
  KC_LCTL, BL_ON, BL_OFF, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

[_LOWERSHIFT] = KEYMAP( \
 _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, \
 _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDOWN, KC_PGUP, KC_END,  _______, _______, \
 KC_LSFT, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, \
 KC_LCTL, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* EXTRA
 * ,-----------------------------------------------------------------------------------.
 * |RGB_TO| BLTOG| RGB? | RGB? |      |      |      |   7  |   8  |   9  |      | MUTE |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |RGBcycl BLSTP| RGB? | RGB? |   .  |      |      |   4  |   5  |   6  |      | VOL+ |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | RGB? | RGB? |      |      |      |   1  |   2  |   3  |      | VOL- | maybe make it shift when combined
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RGBB |      | RGB? | RGB? |LOWER |EXTRA | space|INSERT|   0  |  .   |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_EXTRA] = KEYMAP( \
  RGB_TOG,        BL_TOGG   , RGB_HUD, RGB_TOG, _______,  _______, _______,       KC_7,      KC_8,    KC_9,  _______, KC_MUTE, \
  RGB_MODE_FORWARD, BL_STEP , RGB_HUI, RGB_MOD,    KC_DOT, _______, _______,      KC_4,      KC_5,    KC_6,  _______, KC_VOLU, \
  _______,           _______, RGB_SAD, RGB_VAD, _______, _______, _______,        KC_1,      KC_2,    KC_3,  _______, KC_VOLD, \
  RGB_MODE_BREATHE,  _______, RGB_SAI, RGB_VAI, MO(_LOWER),  MO(_EXTRA), KC_SPC,  KC_INSERT, KC_0,  KC_DOT,  _______, KC_CALCULATOR \
),

};


bool layer_interrupted = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
      case CTL_T_CUSTOM: {
      if (record->event.pressed) {
        layer_interrupted = false;
        layer_on(_RAISE);
      } else {
        if (!layer_interrupted) {
          register_code(KC_SPACE);
          unregister_code(KC_SPACE);
        }
        layer_off(_RAISE);
      }
      return false;
      break;
    }
    default: {
      layer_interrupted = true;
      break;
    }
	}
	return true;
}

