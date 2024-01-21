#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_m0116_ansi(
                                                 TG(1), \
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_NUM, KC_EQL,  KC_PSLS, KC_PAST,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,             KC_P7,  KC_P8,   KC_P9,   KC_PPLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,     KC_P4,  KC_P5,   KC_P6,   KC_PMNS,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TG(1),                        KC_P1,  KC_P2,   KC_P3,           
        KC_LCAP, KC_LGUI, KC_LALT, KC_GRV,                             KC_SPC,           KC_BSLS, KC_LEFT, KC_RGHT, KC_DOWN, KC_UP,      KC_P0,           KC_PDOT, KC_PENT 
    ),

    [1] = LAYOUT_m0116_ansi(
                                                TG(1), \
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC,    KC_DEL,  KC_INS,  KC_SLEP,          KC_WAKE,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,             KC_PGUP, KC_HOME, KC_AUDIO_VOL_UP,  KC_MEDIA_NEXT_TRACK,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,     KC_PAUSE,KC_PSCR, KC_AUDIO_MUTE,       KC_MEDIA_PLAY_PAUSE,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TG(0),                        KC_PGDN, KC_END,  KC_AUDIO_VOL_DOWN,           
        KC_LCAP, KC_LGUI, KC_LALT, KC_GRV,                             KC_SPC,           KC_BSLS, KC_LEFT, KC_RGHT, KC_DOWN, KC_UP,      KC_WHOM,          KC_PDOT,           KC_MEDIA_PREV_TRACK 
    ),
};


#ifdef OLED_ENABLE

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("DEFAULT\n"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("FUNCTION\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}

#endif