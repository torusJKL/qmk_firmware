// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _DIGITS 4
#define _ARROWS 5
#define _FUNCTIONS 6
#define _SYMBOLS 7
#define _SETTINGS 8

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  DIGITS,
  ARROWS,
  FUNCTIONS,
  SYMBOLS,
  SETTINGS,
  BACKLIT
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |E/FN5 |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |A/FN2 |S/FN4 |D/FN1 |F/FN3 |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Hyper| Del  |    Space    | Bksp | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    F(5),    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_ESC,  F(2),    F(4),    F(1),    F(3),    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT, KC_ENT) },
  {KC_LCTL, KC_LGUI, KC_LALT, ALL_T(KC_NO), KC_DEL,   KC_SPC,  KC_SPC,  KC_BSPC,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Digits (chord and pick)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | Numl |   7  |   8  |   9  |   *  | PgUp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | Left |   4  |   5  |   6  |   -  | PgDn |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   +  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   0  |   .  |Enter |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_DIGITS] = {
  {_______, _______, _______, _______, _______, _______, KC_NLCK,   KC_P7,   KC_P8,   KC_P9, KC_PAST, KC_PGUP},
  {_______, _______, _______, _______, _______, _______, _______,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, KC_PGDN},
  {_______, _______, _______, _______, _______, _______, _______,   KC_P1,   KC_P2,   KC_P3, KC_PMNS, KC_PENT},
  {_______, _______, _______, _______, _______, _______, _______, _______,   KC_P0, KC_PDOT, KC_SLSH, KC_PENT}
},

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
[_ARROWS] = {
  {_______, _______, _______, _______, _______, _______, _______, KC_HOME,   KC_UP,  KC_END, KC_PGUP, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______},
  {_______, _______, _______, _______, _______, _______, _______,S(KC_HOME),_______,S(KC_END),_______,_______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

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
[_FUNCTIONS] = {
  {_______, _______, _______, _______, _______, _______, _______,   KC_F7,   KC_F8,   KC_F9,  KC_F12, _______},
  {_______, _______, _______, _______, _______, _______, _______,   KC_F4,   KC_F5,   KC_F6,  KC_F11,KC_PSCREEN},
  {_______, _______, _______, _______, _______, _______, _______,   KC_F1,   KC_F2,   KC_F3,  KC_F10, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, BACKLIT, _______, _______, _______}
},

/* Symbols (chord and pick)
>>>>>>> Symbols layer based on pocketkk's Chord left Pick right design. No need for lower and raise layers anymore.
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |   \  |  &   |  *   |  (   |  )   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |   -  |  $   |  %   |  ^   |  |   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   +  |  !   |  @   |  #   |  [   |  ]   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |  _   |  =   |  {   |  }   |  ~   |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOLS] = {
  {_______, _______, _______, _______, _______, _______, KC_BSLS, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______},
  {_______, _______, _______, _______, _______, _______, KC_MINS,  KC_DLR, KC_PERC, KC_CIRC, KC_PIPE, _______},
  {_______, _______, _______, _______, _______, _______, KC_PLUS, KC_EXLM,   KC_AT, KC_HASH, KC_LBRC, KC_RBRC},
  {_______, _______, _______, _______, _______, _______, _______, KC_UNDS,  KC_EQL, KC_LCBR, KC_RCBR, KC_TILD}
},

/* Adjust (Lower + Raise)
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
[_SETTINGS] = {
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL},
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

};

const uint16_t PROGMEM fn_actions[] = {
 [1] = ACTION_LAYER_TAP_KEY(4, KC_D), // FN1 = momentary Digits layer on D key, to use with Numpad keys
 [2] = ACTION_LAYER_TAP_KEY(5, KC_A), // FN2 = momentary Arrows layer on A key, to use with Arrow keys
 [3] = ACTION_LAYER_TAP_KEY(6, KC_F), // FN3 = momentary Functions layer on F key, to use with Functions keys
 [4] = ACTION_LAYER_TAP_KEY(7, KC_S), // FN4 = momentary Symbol layer on S key, to use with Symbols keys
 [5] = ACTION_LAYER_TAP_KEY(8, KC_E), // FN5 = momentary Settings layer on E key, to use with Settings keys
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
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
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
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
