#include QMK_KEYBOARD_H
#include "dakes.h"


//check numlock and turn off if on
void numlock_off(void)
{
    //Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    if (led_state.num_lock)
    {
        tap_code16(KC_NLCK);
    }
}
