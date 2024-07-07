#include <stdio.h>

#include QMK_KEYBOARD_H

enum sofle_layers {
    _DEFAULTS = 0,
    _ENGRAM = 0,
    _QWERTY,
    _COLEMAK,
    _COLEMAKDH,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMPAD,
    _SWITCH
};

enum custom_keycodes {
    KC_ENGRAM = SAFE_RANGE,
    KC_QWERTY,
    KC_COLEMAK,
	KC_COLEMAKDH,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,

    KC_FIND_,
    KC_NFIND,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY]   = { ENCODER_CCW_CW(KC_RGHT, KC_LEFT),    ENCODER_CCW_CW(KC_DOWN, KC_UP) },
    [_ENGRAM]   = { ENCODER_CCW_CW(KC_RGHT, KC_LEFT),    ENCODER_CCW_CW(KC_DOWN, KC_UP) },
    [_COLEMAK]  = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),    ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [_COLEMAKDH]= { ENCODER_CCW_CW(_______, _______),    ENCODER_CCW_CW(_______, _______)},
    [_LOWER]    = { ENCODER_CCW_CW(KC_NXTWD, KC_PRVWD),  ENCODER_CCW_CW(KC_PGDN, KC_PGUP)},
    [_RAISE]    = { ENCODER_CCW_CW(KC_WH_L, KC_WH_R),    ENCODER_CCW_CW(KC_WH_U, KC_WH_D)},
    [_ADJUST]   = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD),    ENCODER_CCW_CW(KC_BRIU, KC_BRID)},
    [_NUMPAD]   = { ENCODER_CCW_CW(KC_MS_R, KC_MS_L),    ENCODER_CCW_CW(KC_MS_D, KC_MS_U)},
    [_SWITCH]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),    ENCODER_CCW_CW(RGB_RMOD, RGB_MOD)},
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  `~  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  ;:  |  '"  |
 * |------+------+------+------+------+------|  Home |    |  End  |------+------+------+------+------+------|
 * |  `~  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ,<  |  .>  |  /?  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,           LT(_SWITCH,KC_6),     KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC,
LT(_NUMPAD,KC_TAB),KC_Q,KC_W,  KC_E,    KC_R,    KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_GRV,
    KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_GRV,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LSTRT,    KC_LEND ,KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LCTL,KC_LGUI,KC_LALT, MO(_LOWER), KC_SPC,      KC_ENT,  MO(_RAISE), KC_RALT, KC_RGUI, KC_RCTL
),

/*
 * ENGRAM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Tab |   B  |   Y  |   O  |   U  |  '"  |                    |  ;:  |   L  |   D  |   W  |   V  |  Z   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   C  |   I  |   E  |   A  |  ,<  |-------.    ,-------|  .>  |   H  |   T  |   S  |   N  |  Q   |
 * |------+------+------+------+------+------|  Home |    |  End  |------+------+------+------+------+------|
 * |  `~  |   G  |   X  |   J  |   K  |  -_  |-------|    |-------|  /?  |   R  |   M  |   F  |   P  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ENGRAM] = LAYOUT(
        KC_ESC,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,            LT(_SWITCH,KC_6),   KC_7,    KC_8,    KC_9,   KC_0,    KC_BSPC,
LT(_NUMPAD,KC_TAB),KC_B,    KC_Y,    KC_O,    KC_U,    KC_QUOT,                    KC_SCLN, KC_L,    KC_D,    KC_W,   KC_V,    KC_Z,
        KC_LSFT,  KC_C,     KC_I,    KC_E,    KC_A,    KC_COMM,                    KC_DOT,  KC_H,    KC_T,    KC_S,   KC_N,    KC_Q,
        KC_GRV,   KC_G,     KC_X,    KC_J,    KC_K,    KC_MINS, KC_LSTRT, KC_LEND, KC_SLSH, KC_R,    KC_M,    KC_F,   KC_P,    KC_RSFT,
                            KC_LCTL,KC_LGUI,KC_LALT, MO(_LOWER), KC_SPC,      KC_ENT,  MO(_RAISE), KC_RALT, KC_RGUI, KC_RCTL
),

/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_COLEMAK] = LAYOUT(
  KC_TRNS,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,          LT(_SWITCH,KC_6),    KC_7,   KC_8,    KC_9,    KC_0,    KC_TRNS,
  KC_TRNS,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_TRNS,
  KC_TRNS,  KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,   KC_E,    KC_I,    KC_O,    KC_TRNS,
  KC_TRNS,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_TRNS,    KC_TRNS,KC_K,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
),

/*
 * COLEMAK-DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_COLEMAKDH] = LAYOUT(
  KC_TRNS,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,          LT(_SWITCH,KC_6),    KC_7,   KC_8,    KC_9,    KC_0,    KC_TRNS,
  KC_TRNS,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_TRNS,
  KC_TRNS,  KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,   KC_E,    KC_I,    KC_O,    KC_TRNS,
  KC_TRNS,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,  KC_TRNS,    KC_TRNS,KC_K,    KC_H,   KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Quit | Close|      |      |      |                    | Ins  | Pscr | Menu |      |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps |Select| Save | Stop | Again| Find |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|  Home |    |  End  |------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste| nFind|-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,             LT(_SWITCH,KC_F6),  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
LCTL(KC_TAB),LCTL(KC_Q),LCTL(KC_W),XXXXXXX,XXXXXXX, XXXXXXX,                        KC_INS, KC_PSCR,  KC_APP, _______, _______, KC_F12,
  CW_TOGG,KC_SELECT,LCTL(KC_S), KC_STOP, KC_AGAIN, KC_FIND_,                       _______, _______,  _______,  _______,   _______,  _______,
LCTL(KC_GRV),KC_UNDO,  KC_CUT,  KC_COPY, KC_PASTE, KC_NFIND, KC_LSTRT,    KC_LEND, _______, _______,  _______,  _______,   _______,  _______,
                      _______,  _______,  _______,  _______,  _______,    _______, _______, _______,  _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | PgUP | pWrd |  Up  | nWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| PgDN | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  BTN1 |    |  BTN2 |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | Home |      |  End |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                    _______,  _______,  _______,  _______,  _______,   KC_DEL,
  _______, _______, _______, _______, _______, _______,                    KC_PGUP, KC_PRVWD,    KC_UP, KC_NXTWD, KC_DLINE,  KC_BSPC,
  _______, _______, _______, _______, _______, _______,                    KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_DEL,  KC_BSPC,
  _______, _______, _______, _______, _______, _______,KC_BTN1,    KC_BTN2,XXXXXXX, KC_LSTRT,  XXXXXXX,  KC_LEND,  XXXXXXX,  _______,
                 _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | MEH^ |      |      | HYPR^|      |                    |      | CG(^)|      |      |CAG(^)|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | MEH< | MEH⌄ | MEH> | HYPR<| HYPR⌄| HYPR>|-------.    ,-------| CG(<)| CG(⌄)| CG(>)|CAG(<)|CAG(⌄)|CAG(>)|
 * |------+------+------+------+------+------|  Mute |    |  Play |------+------+------+------+------+------|
 * |      |      |      |      |ENGRAM|QWERTY|-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,MEH(KC_UP), XXXXXXX,  XXXXXXX,HYPR(KC_UP),XXXXXXX,                  XXXXXXX,C(G(KC_UP)),XXXXXXX,  XXXXXXX,LCAG(KC_UP),XXXXXXX,
MEH(KC_LEFT),MEH(KC_DOWN),MEH(KC_RGHT),HYPR(KC_LEFT),HYPR(KC_DOWN),HYPR(KC_RGHT),   C(G(KC_LEFT)),C(G(KC_DOWN)),C(G(KC_RGHT)),LCAG(KC_LEFT),LCAG(KC_DOWN),LCAG(KC_RGHT),
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, KC_ENGRAM,KC_QWERTY,KC_MUTE, KC_MPLY,XXXXXXX,  KC_MPRV,  KC_MPLY,  KC_MNXT,  XXXXXXX,  XXXXXXX,
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),
/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  (   |  )   |  \   |  <   |  >   |                    |      |NumLck|   /  |   *  |   -  | Calc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  [   |  ]   |  |   |      |      |                    |   ^  |   7  |   8  |   9  |   +  |   (  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  {   |  }   |  /   |      |      |-------.    ,-------|   %  |   4  |   5  |   6  |   ,  |   )  |
 * |------+------+------+------+------+------|  BTN1 |    |  BTN2 |------+------+------+------+------+------|
 * |      |  =   |  -   |  +   |  *   |      |-------|    |-------|      |   1  |   2  |   3  |   =  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |OSMMEH|      |      | /       /       \      \  |      | 0    |  .   | Enter|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NUMPAD] = LAYOUT(
  XXXXXXX, KC_LPRN, KC_RPRN, KC_BSLS,   KC_LT,   KC_GT,                   _______, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, KC_CALC,
  XXXXXXX, KC_LBRC, KC_RBRC, KC_PIPE, XXXXXXX, XXXXXXX,                   KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_PLUS, KC_LPRN,
  XXXXXXX, KC_LCBR, KC_RCBR, KC_SLSH, XXXXXXX, XXXXXXX,                   KC_PERC, KC_P4,  KC_P5,   KC_P6,  KC_COMMA, KC_RPRN,
  XXXXXXX,  KC_EQL, KC_MINS, KC_PLUS, KC_PAST, XXXXXXX,KC_BTN1,   KC_BTN2,_______, KC_P1,  KC_P2,   KC_P3,   KC_PEQL, _______,
              _______, OSM(MOD_MEH), _______, _______, _______,   _______, _______,  KC_P0,   KC_PDOT, KC_PENT
),

/* SWITCH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | engr | qwer | cole |col_dh| low  | raise|                    |MACWIN|      |      |      |      |QK_BOOT|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  adj |numpad|      |      |      |      |-------.    ,-------|      |      |      |      |      |EE_CLR|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |  PWR | SLEEP| WAKE |      | BRIU | BRID |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  // layer switcher
[_SWITCH] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  DF(0),   DF(1),   DF(2),   DF(3),   TO(4),   TO(5),                      CG_TOGG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
  TO(6),   TO(7),   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   EE_CLR,
  KC_PWR,KC_SYSTEM_SLEEP,KC_WAKE,KC_NO, KC_BRIU, KC_BRID,  KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO

	),
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _ENGRAM:
            oled_write_ln_P(PSTR("Engr"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        case _COLEMAKDH:
            oled_write_ln_P(PSTR("CmkDH"), false);
            break;

        default:
            oled_write_ln_P(PSTR("\n"), false);
    }
    oled_write_P(PSTR("\n"), false);

    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _ENGRAM:
        case _QWERTY:
        case _COLEMAKDH:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Nump\n"), false);
            break;
        case _SWITCH:
            oled_write_P(PSTR("Swit\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    oled_write_P(PSTR("\n\n"), false);
    led_t led_state = host_keyboard_led_state();

    if (led_state.num_lock) {
        oled_write_ln_P(PSTR("NUMLK"), true);
    }
    if (led_state.caps_lock) {
        oled_write_ln_P(PSTR("CAPSL"), true);
    }
    if (led_state.scroll_lock) {
        oled_write_ln_P(PSTR("SCRLK"), true);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Helper function to handle custom key press and release
static void handle_custom_key(uint16_t key, uint16_t mod, keyrecord_t *record) {
    if (record->event.pressed) {
        register_mods(mod_config(mod));
        register_code(key);
    } else {
        unregister_mods(mod_config(mod));
        unregister_code(key);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // LAYERS
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_ENGRAM:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_ENGRAM);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_COLEMAKDH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAKDH);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;

        // custom KEYS
        case KC_FIND_:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_F);
                } else {
                    register_code(KC_FIND);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_F);
                } else {
                    unregister_code(KC_FIND);
                }
            }
            break;
        case KC_NFIND:
            handle_custom_key(KC_G, MOD_LCTL, record);
            break;
        case KC_PRVWD:
            handle_custom_key(KC_LEFT, keymap_config.swap_lctl_lgui ? MOD_LALT : MOD_LCTL, record);
            break;
        case KC_NXTWD:
            handle_custom_key(KC_RIGHT, keymap_config.swap_lctl_lgui ? MOD_LALT : MOD_LCTL, record);
            break;
        case KC_LSTRT:
            if (keymap_config.swap_lctl_lgui) {
                handle_custom_key(KC_LEFT, MOD_LCTL, record);
            } else {
                handle_custom_key(KC_HOME, 0, record);
            }
            break;
        case KC_LEND:
            if (keymap_config.swap_lctl_lgui) {
                handle_custom_key(KC_RIGHT, MOD_LCTL, record);
            } else {
                handle_custom_key(KC_END, 0, record);
            }
            break;
        case KC_DLINE:
            handle_custom_key(KC_BSPC, MOD_LCTL, record);
            break;
        case KC_COPY:
            handle_custom_key(KC_C, MOD_LCTL, record);
            return false;
        case KC_PASTE:
            handle_custom_key(KC_V, MOD_LCTL, record);
            return false;
        case KC_CUT:
            handle_custom_key(KC_X, MOD_LCTL, record);
            return false;
        case KC_UNDO:
            handle_custom_key(KC_Z, MOD_LCTL, record);
            return false;
        default:
            return true;
    }
    return true;
}

// #ifdef ENCODER_ENABLE
//
// bool encoder_update_user(uint8_t index, bool clockwise) {
//     if (index == 0) {
//         if (clockwise) {
//             tap_code(KC_VOLU);
//         } else {
//             tap_code(KC_VOLD);
//         }
// 		} else if (index == 1) {
// 			switch (get_highest_layer(layer_state)) {
// 				case _COLEMAK:
// 				case _ENGRAM:
// 				case _QWERTY:
// 				case _COLEMAKDH:
// 					if (clockwise) {
// 						tap_code(KC_PGDN);
// 					} else {
// 						tap_code(KC_PGUP);
// 					}
// 				break;
// 			case _RAISE:
// 			case _LOWER:
// 					if (clockwise) {
// 						tap_code(KC_DOWN);
// 					} else {
// 						tap_code(KC_UP);
// 					}
// 				break;
// 			default:
// 					if (clockwise) {
// 						tap_code(KC_WH_D);
// 					} else {
// 						tap_code(KC_WH_U);
// 					}
// 				break;
// 		}
//     }
//     return true;
// }

// #endif
