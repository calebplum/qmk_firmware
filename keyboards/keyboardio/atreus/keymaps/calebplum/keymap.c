// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

int os = 0; // 0 for mac, 1 for linux

enum layer_names {
    _QW,
    _RS,
    _LW,
    _WC,
};


enum custom_keycodes {
  // Window control
  WCMONLEFT = SAFE_RANGE,
  WCMONRIGHT,
  WCSNAPLEFT,
  WCSNAPRIGHT,
  WCSNAPUP,
  WCSNAPDOWN,
  WCSNAPTL,   // Top left
  WCSNAPTR,   // Top right
  WCSNAPBL,   // Bottom left
  WCSNAPBR,   // Bottom right
  WCSNAPOFF,  // Snap restore
  WCMAX,      // Maximise
  WCSM,       // Select Mac
  WCSL,       // Select Linux
};


// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case WCMONLEFT:
    if (record->event.pressed) {
      switch (os) {

        case 0: // Mac
        tap_code16(LCTL(LGUI(KC_DELETE)));
        break;

        case 1: // Linux
        tap_code16(LCTL(LALT(KC_DELETE)));
        break;
      }
    }
    break;

    case WCMONRIGHT:
    if (record->event.pressed) {
      switch (os) {

        case 0: // Mac
        tap_code16(LCTL(LGUI(KC_PGDN)));
        break;

        case 1: // Linux
        tap_code16(LCTL(LALT(KC_PGDN)));
        break;
      }
    }
    break;
    
    case WCSNAPLEFT:
    if (record->event.pressed) {
      switch (os) {

        case 0: // Mac
        tap_code16(RCTL(LALT(KC_LEFT)));
        break;

        case 1: // Linux
        tap_code16(LCTL(LGUI(KC_INSERT)));
        break;
      }
    }
    break;
        
    case WCSNAPRIGHT:
    if (record->event.pressed) {
      switch (os) {

        case 0: // Mac
        tap_code16(RCTL(LALT(KC_RIGHT)));
        break;

        case 1: // Linux
        tap_code16(LCTL(LGUI(KC_PGUP)));
        break;
      }
    }
    break;
            
    case WCSNAPUP:
    if (record->event.pressed) {
      switch (os) {

        case 0: // Mac
        tap_code16(RCTL(LALT(KC_SCROLLLOCK)));
        break;

        case 1: // Linux
        tap_code16(LCTL(LGUI(KC_SCROLLLOCK)));
        break;
      }
    }
    break;
                         
    case WCSNAPDOWN:
    if (record->event.pressed) {
      switch (os) {

        case 0: // Mac
        tap_code16(RCTL(LALT(KC_END)));
        break;

        case 1: // Linux
        tap_code16(LCTL(LGUI(KC_END)));
        break;
      }
    }
    break;
                         
    case WCSNAPTL:
    if (record->event.pressed) {
      switch (os) {

        case 0: // Mac
        tap_code16(RCTL(LALT(KC_PSCREEN)));
        break;

        case 1: // Linux
        tap_code16(LCTL(LGUI(KC_PSCREEN)));
        break;
      }
    }
    break;
                         
    case WCSNAPTR:
    if (record->event.pressed) {
      switch (os) {

        case 0: // Mac
        tap_code16(RCTL(LALT(KC_PAUSE)));
        break;

        case 1: // Linux
        tap_code16(LCTL(LGUI(KC_PAUSE)));
        break;
      }
    }
    break;
                         
    case WCSNAPBL:
    if (record->event.pressed) {
      switch (os) {

        case 0: // Mac
        tap_code16(RCTL(LALT(KC_DELETE)));
        break;

        case 1: // Linux
        tap_code16(LCTL(LGUI(KC_DELETE)));
        break;
      }
    }
    break;
                         
    case WCSNAPBR:
    if (record->event.pressed) {
      switch (os) {

        case 0: // Mac
        tap_code16(RCTL(LALT(KC_PGDN)));
        break;

        case 1: // Linux
        tap_code16(LCTL(LGUI(KC_PGDN)));
        break;
      }
    }
    break;
                         
    case WCSNAPOFF:
    if (record->event.pressed) {
      switch (os) {

        case 0: // Mac
        tap_code16(RCTL(LALT(KC_DOWN)));
        break;

        case 1: // Linux
        tap_code16(LCTL(LGUI(KC_DOWN)));
        break;
      }
    }
    break;
                         
    case WCMAX:
    if (record->event.pressed) {
      switch (os) {

        case 0: // Mac
        tap_code16(RCTL(LALT(KC_UP)));
        break;

        case 1: // Linux
        tap_code16(LCTL(LGUI(KC_UP)));
        break;
      }
    }
    break;

    case WCSM:
    if (record->event.pressed) {
      os = 0;
    }
    break;

    case WCSL:
    if (record->event.pressed) {
      os = 1;
    }
    break;

  }
  return true;
}


// Tap Dance declarations
enum {
  TD_LSEL
};


// Tap dance functions
// Layer select
void dance_layer_select(qk_tap_dance_state_t *state, void *user_data) {

  if (state->count == 1) {
    layer_on(_LW);  // Lower layer
  }

  else if (state->count == 2) {
    layer_on(_WC);  // Window control layer
  }
};


// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {

  // Layer Select - Tap once for RAISE, twice for WINCTRL
  [TD_LSEL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_layer_select, NULL),
};


// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,               KC_QUOT,              KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_ESC, KC_TAB, KC_LGUI,  KC_LSFT, KC_BSPC,  MT(MOD_LCTL, KC_DEL), MT(MOD_LALT, KC_TAB), KC_SPC,  TT(_RS), KC_MINS, KC_BSLS, KC_ENT ),

  /*
   *  !       @     up     $    %            ||            home    7     8     9    pgup
   *  (     left   down  right  )            ||            end     4     5     6    pgdn
   *  [       ]      #     {    }       ^    ||     &       *      1     2     3    +
   * lower  insert super shift del  ctrl/del ||  alt/tab  space    fn    0     .    =
   */
  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM,     KC_AT,    KC_UP,   KC_DLR,  KC_PERC,                                             KC_HOME, KC_7,    KC_8,   KC_9, KC_PLUS,
    KC_LPRN,     KC_LEFT,  KC_DOWN, KC_RGHT, KC_RPRN,                                             KC_END,  KC_4,    KC_5,   KC_6, KC_EQL,
    KC_LBRC,     KC_RBRC,  KC_HASH, KC_LCBR, KC_RCBR, KC_CIRC,              KC_AMPR,              KC_ASTR, KC_1,    KC_2,   KC_3, KC_PGUP,
    TD(TD_LSEL), TT(_WC),  KC_LGUI, KC_LSFT, KC_DEL,  MT(MOD_LCTL, KC_DEL), MT(MOD_LALT, KC_TAB), KC_SPC,  KC_TRNS, KC_0, KC_DOT, KC_PGDN ),

  /*
   *  insert    home      up       end   pgup           ||           up     F7    F8    F9      F10
   *   del      left     down     right  pgdn           ||          down    F4    F5    F6      F11
   * prevtrack  volup  nexttrack         reset          ||                  F1    F2    F3      F12
   *   L0       voldn    super    shift  bksp  ctrl/del || alt/tab  space   L0  prtsc scroll playpause
   */
  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                                             KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                                             KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_MPRV, KC_VOLU, KC_MNXT, KC_NO,   RESET,   _______,              _______,              KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    TO(_QW), KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, MT(MOD_LCTL, KC_DEL), MT(MOD_LALT, KC_TAB), KC_SPC,  TO(_QW), KC_PSCR, KC_SLCK, KC_MPLY ),

  /*
   *  _   _  _  _  _     ||     _   _  _  _  _
   *  _   _  _  _  _     ||     _   _  _  _  _
   *  _   _  _  _  _  _  ||  _  _  _   _  _  _
   *  L0  _  _  _  _  _  ||  _  _  L0  _  _  _
   */
  [_WC] = LAYOUT( /* [> WINCTRL <] */
    WCSM,    WCSL,       KC_NO,   KC_NO,      KC_NO,                                               WCMAX,  WCSNAPTL,   WCSNAPUP,   WCSNAPTR,    KC_NO,
    KC_NO,   WCMONLEFT,  KC_NO,   WCMONRIGHT, KC_NO,                                               KC_NO,  WCSNAPLEFT, WCSNAPOFF,  WCSNAPRIGHT, KC_NO,
    KC_NO,   KC_NO,      KC_NO,   KC_NO,      KC_NO,  KC_GRV,               _______,               KC_NO,  WCSNAPBL,   WCSNAPDOWN, WCSNAPBR,    KC_NO,
    TO(_QW), KC_TAB,     KC_LGUI, KC_LSFT,    KC_DEL, MT(MOD_LCTL, KC_DEL), MT(MOD_LALT, KC_TAB),  KC_SPC, TO(_QW),    KC_0,       KC_DOT,      KC_EQL )
};
