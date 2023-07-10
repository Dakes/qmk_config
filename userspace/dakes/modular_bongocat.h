
#pragma once
#include <string.h>

#ifndef WIDTH
#define WIDTH 128
#endif

void bongo_fake_wpm_increment(void);
void bongo_fake_wpm_decay(void);

void render_short_array_pos(const uint16_t* frame, uint8_t x, uint8_t y, uint8_t width);
void render_short_array(const uint16_t* frame);
void render_anim(void);
void render_wpm(void);

#ifdef KYRIA_LOGO_ENABLE
const uint8_t kyria_logo_width;
const uint16_t kyria_logo[467];
#endif

#ifdef QMK_LOGO_ENABLE
const uint8_t qmk_logo_width;
const uint16_t qmk_logo[177];
#endif

// swaps master and slave OLED
// #define BONGO_DEBUG
