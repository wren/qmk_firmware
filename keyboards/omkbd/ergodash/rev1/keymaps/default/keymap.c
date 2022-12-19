#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _SYMBOLS,
    _CONTROL,
    _NUMPAD,
};

#define QWERTY TO(_QWERTY)
#define CONTROL MO(_CONTROL)
#define SYMBOLS TT(_SYMBOLS)
#define NUMPAD TT(_NUMPAD)
#define FANCY_ESC LT(_CONTROL, KC_ESC)
#define LCMD_ENT LGUI_T(KC_ENT)
#define RCMD_ENT RGUI_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ` ~  |   1  |   2  |   3  |   4  |   5  |   6  ||||||||||||||||||||||   6  |   7  |   8  |   9  |   0  | - _  | = +  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  | PgDn |||||||||||||||||||||| PgUp |   Y  |   U  |   I  |   O  |   P  | \ |  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | F-Esc|   A  |   S  |   D  |   F  |   G  | MEH  |||||||||||||||||||||| MEH  |   H  |   J  |   K  |   L  | ; :  | ' "  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |      | Alt  ||||||||      |      |   N  |   M  | , <  | . >  | / ?  | Shift|
   * |-------------+------+------+------+------+ ENT  +------+------+------+ ENT  +------+------+------+------+-------------|
   * |      |      |      |SYMBOL|||||||| BSpc | Cmd  | Ctrl |||||||| Ctrl | Cmd  | SPACE||||||||SYMBOL|      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT(
    KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4, KC_5,    KC_6   ,                     KC_6   ,  KC_7,   KC_8, KC_9,    KC_0,    KC_MINS, KC_EQL,
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R, KC_T,    KC_PGDN,                     KC_PGUP,  KC_Y,   KC_U, KC_I,    KC_O,    KC_P,    KC_BSLS,
    FANCY_ESC, KC_A,    KC_S,    KC_D,    KC_F, KC_G,    KC_MEH ,                     KC_MEH ,  KC_H,   KC_J, KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V, KC_B,              KC_LALT,  KC_LALT,           KC_N,   KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    XXXXXXX,   XXXXXXX, XXXXXXX, SYMBOLS,       KC_BSPC, LCMD_ENT, KC_LCTL,  KC_RCTL, RCMD_ENT, KC_SPC,       SYMBOLS, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  /* Symbols
   * ,------------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      ||||||||||||||||||||||||      |      |      |   (  |   )  |   _  |   +  |
   * |------+------+------+------+------+------+------+----------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   ^  ||||||||||||||||||||||||   ^  |   &  |   *  |   {  |   }  |      |  |   |
   * |------+------+------+------+------+------+------+----------------------+------+------+------+------+------+------+------|
   * |NUMPAD|      |      |      |      |      |      ||||||||||||||||||||||||      |      |      |   [  |   ]  |   :  |  "   |
   * |------+------+------+------+------+------+-----------------------------+------+------+------+------+------+------+------|
   * | Shift|      |      |      |      |      |      | Alt   ||||||||       |      |      |      |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+Enter +-------||||||||------+Enter +-------+------+------+------+-------------|
   * |      |      |      |SYMBOL|||||||| BSpc | Cmd  | Ctrl |||||||| Ctrl | Cmd   | SPACE ||||||||SYMBOL|      |      |      |
   * ,------------------------------------------------------------------------------------------------------------------------.
   */
  [_SYMBOLS] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN,  KC_UNDS,  KC_PLUS,
    KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,                      KC_CIRC,  KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR,  XXXXXXX,  KC_PIPE,
    NUMPAD,   XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC,  KC_COLN,  KC_DQUO,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, _______,                      _______,  XXXXXXX, XXXXXXX, KC_LT,   KC_GT,    KC_QUES,  _______,
    _______,  _______,  _______,  _______,          KC_DEL ,  _______,  _______,  _______, _______,  _______,          _______, _______,  _______,  _______
  ),

  /* Control
   * ,----------------------------------------------------------------------------------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  ||||||||||||||||||||||||  F6  |  F7  |  F8  |  F9     |  F10  |  F11 |      |
   * |------+------+------+------+------+------+------+----------------------+------+------+------+---------+-------+------+------|
   * |      |      |      |      |      |      |      ||||||||||||||||||||||||      | Mute | Voldn|  VolUp  | Play  |      |      |
   * |------+------+------+------+------+------+------+----------------------+------+------+------+---------+-------+------+------|
   * |      |      |      |      |      |      |      ||||||||||||||||||||||||      | Left | Down |  Up     | Right |      |      |
   * |------+------+------+------+------+------+-----------------------------+------+------+------+---------+-------+------+------|
   * |Shift |      |      |      |      |      |      |       ||||||||       |      |      |     |  C+S+Tab | C+Tab |      |Shift |
   * |-------------+------+------+------+------+Enter +-------||||||||------+Enter +------+------+----------+-------+-------------|
   * |      |      |      |NUMPAD|||||||| BSpc | Cmd  | Ctrl |||||||| Ctrl | Cmd  | SPACE||||||||   SYMBOL  |       |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------------.
   */
  [_CONTROL] = LAYOUT(
    XXXXXXX,  KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F6,    KC_F7,   KC_F8,   KC_F9,       KC_F10,       KC_F11,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_MUTE, KC_VOLD, KC_VOLU,     KC_MPLY,      XXXXXXX, XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_LEFT, KC_DOWN, KC_UP,       KC_RGHT,      XXXXXXX, XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, _______,                      _______,  XXXXXXX, XXXXXXX, RCS(KC_TAB), LCTL(KC_TAB), XXXXXXX, _______,
    _______,  _______,  _______,  NUMPAD,           _______, _______,  _______,  _______,  _______,  _______,          _______,     _______,      _______, _______
  ),

  /* Numpad
   * ,------------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      ||||||||||||||||||||||||      |  =   |  ^   |  /   |  *   |  -   |  =   |
   * |------+------+------+------+------+------+------+----------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      ||||||||||||||||||||||||      |  -   |  7   |  8   |  -   |      |      |
   * |------+------+------+------+------+------+------+----------------------+------+------+------+------+------+------+------|
   * |QWERTY|      |      |      |      |      | Meh  |||||||||||||||||||||||| Meh  |  +   |  4   |  5   |  +   |      |      |
   * |------+------+------+------+------+------+-----------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |       ||||||||       |      |  *   |  1   |  2   |  *   |      |      |
   * |-------------+------+------+------+------+Enter +-------||||||||------+Enter +------+------+------+------+-------------|
   * |      |      |      |SYMBOL|||||||| BSpc | Cmd  | Ctrl |||||||| Ctrl | Cmd  |   0  ||||||||   0  |  .   |      |      |
   * ,------------------------------------------------------------------------------------------------------------------------.
   */
  [_NUMPAD] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_PEQL, KC_BSPC, KC_PSLS, KC_PAST, KC_CIRC, KC_PEQL,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_PMNS, KC_P7,   KC_P8,   KC_P9,   XXXXXXX, XXXXXXX,
    QWERTY , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                       _______, KC_PPLS, KC_P4,   KC_P5,   KC_P6,   XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                       _______, KC_PAST, KC_P1,   KC_P2,   KC_P3,   XXXXXXX, XXXXXXX,
    _______, _______, _______, _______,          KC_SPC , _______,  _______,   _______,  KC_SPC , KC_P0  ,          KC_P0  , KC_PDOT, XXXXXXX, XXXXXXX
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
