// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum planck_layers {
_QWERTY,
_NUMPAD,
_DIGITS,
_ARROWS,
_FUNCTIONS,
_SYMBOLS,
_SETTINGS,
_BRACKETS
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  NUMEPAD,
  DIGITS,
  ARROWS,
  FUNCTIONS,
  SYMBOLS,
  SETTINGS,
  BRACKETS,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  | E/L6 | R/L7 |   T  |   Y  |   U  |   I  |   O  |   P  |   "  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Ctrl/Esc|A/L3| S/L5 | D/L1 | F/L4 |   G  |   H  |   J  |   K  |   L  |   ;  |Ctrl/Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift |   Z  |   X  | C/L2 |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Hyper| Del  |    Space    | Bksp | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
  KC_TAB,  KC_Q,    KC_W, LT(6, KC_E), LT(7, KC_R),    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
  MT(MOD_LCTL, KC_ESC), LT(3, KC_A), LT(5, KC_S), LT(1, KC_D),  LT(4, KC_F),  KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MT(MOD_RCTL, KC_ENT),
  KC_LSFT, KC_Z,    KC_X,    LT(2, KC_C),    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT, ALL_T(KC_NO), KC_DEL,   KC_SPC,  KC_SPC,  KC_BSPC,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Numpad (chord and pick)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | Numl |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |   +  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   -  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   ,  |   0  |   .  |   /  |  =   |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, KC_NLCK,   KC_P7,   KC_P8,   KC_P9, KC_PAST, XXXXXXX,
  _______, _______, _______, _______, _______, _______, XXXXXXX,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, KC_PENT,
  _______, _______, _______, _______, _______, _______, XXXXXXX,   KC_P1,   KC_P2,   KC_P3, KC_PMNS, KC_PENT,
  _______, _______, _______, _______, _______, _______, _______, KC_PCMM,   KC_P0, KC_PDOT, KC_PSLS, KC_PEQL
),

/* Digits (chord and pick)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |   +  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   -  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   ,  |   0  |   .  |   /  |   =  |
 * `-----------------------------------------------------------------------------------'
 */
[_DIGITS] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, XXXXXXX,    KC_7,    KC_8,    KC_9, KC_ASTR, XXXXXXX,
  _______, _______, _______, _______, _______, _______, XXXXXXX,    KC_4,    KC_5,    KC_6, KC_PLUS,  KC_ENT,
  _______, _______, _______, _______, _______, _______, XXXXXXX,    KC_1,    KC_2,    KC_3, KC_MINS,  KC_ENT,
  _______, _______, _______, _______, _______, _______, _______, KC_COMM,    KC_0,  KC_DOT, KC_SLSH,  KC_EQL
),

/* Arrows (chord and pick)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      | HOME |  UP  |  END | PgUp |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | LEFT | DOWN |RIGHT | PgDn |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |SHOME |      | SEND |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ARROWS] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, XXXXXXX, KC_HOME,   KC_UP,  KC_END, KC_PGUP, XXXXXXX,
  _______, _______, _______, _______, _______, _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
  _______, _______, _______, _______, _______, _______, XXXXXXX,S(KC_HOME),XXXXXXX,S(KC_END),XXXXXXX,XXXXXXX,
  _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Functions (chord and pick)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  F7  |  F8  |  F9  | F12  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  F4  |  F5  |  F6  | F11  | PSCR |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  F1  |  F2  |  F3  | F10  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |Brite |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTIONS] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F12, XXXXXXX,
  _______, _______, _______, _______, _______, _______, XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11,KC_PSCREEN,
  _______, _______, _______, _______, _______, _______, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F10, XXXXXXX,
  _______, _______, _______, _______, _______, _______, _______, XXXXXXX, BACKLIT, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Symbols (chord and pick)
Symbols layer based on pocketkk's Chord left Pick right design. No need for lower and raise layers anymore.
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  &   |  *   |  =   |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  $   |  %   |  ^   |  ~   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  !   |  @   |  #   |  _   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOLS] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, XXXXXXX, KC_AMPR, KC_ASTR, KC_EQL,  XXXXXXX, XXXXXXX,
  _______, _______, _______, _______, _______, _______, XXXXXXX, KC_DLR,  KC_PERC, KC_CIRC, KC_TILD, XXXXXXX,
  _______, _______, _______, _______, _______, _______, XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_UNDS, XXXXXXX,
  _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Settings
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SETTINGS] = LAYOUT_planck_grid(
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Brackets (chord and pick)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  <   |  [   |  ]   |  >   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  {   |  (   |  )   |  }   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  \   |  |   |  .   |  /   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_BRACKETS] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, XXXXXXX, KC_LABK, KC_LBRC, KC_RBRC, KC_RABK, XXXXXXX,
  _______, _______, _______, _______, _______, _______, XXXXXXX, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, XXXXXXX,
  _______, _______, _______, _______, _______, _______, XXXXXXX, KC_BSLS, KC_PIPE, KC_DOT,  KC_SLSH, XXXXXXX,
  _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(tone_qwerty);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    PLAY_SONG(tone_startup);
}

void shutdown_user()
{
    PLAY_SONG(tone_goodbye);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif
