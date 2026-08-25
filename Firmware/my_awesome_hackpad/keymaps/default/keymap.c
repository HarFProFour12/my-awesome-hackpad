// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/* keycodes for macros */
enum custom_keycodes {
    MACRO_COPY = SAFE_RANGE,
    MACRO_PASTE,
    MACRO_SAVE,
    MACRO_UNDO,
    MACRO_COPY_LINK,
    MACRO_REDO,
    MACRO_SELECT_ALL,
    MACRO_CUT
};

/* 2x4 hackpad */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        MACRO_COPY,       MACRO_PASTE,      MACRO_SAVE,       MACRO_UNDO,
        MACRO_COPY_LINK,       MACRO_REDO, MACRO_SELECT_ALL, MACRO_CUT
    )
};

/* encoder */
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MACRO_COPY:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCMD) "c" SS_UP(X_LCMD));
            }
            return false;

        case MACRO_PASTE:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCMD) "v" SS_UP(X_LCMD));
            }
            return false;

        case MACRO_CUT:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCMD) "x" SS_UP(X_LCMD));
            }
            return false;

        case MACRO_SAVE:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCMD) "s" SS_UP(X_LCMD));
            }
            return false;

        case MACRO_UNDO:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCMD) "z" SS_UP(X_LCMD));
            }
            return false;

        case MACRO_REDO:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCMD) "y" SS_UP(X_LCMD));
            }
            return false;

        case MACRO_SELECT_ALL:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCMD) "a" SS_UP(X_LCMD));
            }
            return false;            

        case MACRO_COPY_LINK:
            if (record->event.pressed) {
        	SEND_STRING(SS_LCMD(SS_LSFT("c")));
    	    }
            return false;       
    }
    return true;
}

/* oled */
#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_P(PSTR("Hackpad Active\n"), false);
    return false;
}
#endif
