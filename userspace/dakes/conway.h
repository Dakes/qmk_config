/* Copyright 2022 Daniel Ostertag (Dakes) <dakes@vivaldi.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// OLED size
#ifndef WIDTH
#define WIDTH 128
#endif

#ifndef HEIGHT
#define HEIGHT 64
#endif

// for syncing to keypresses
#define SPLIT_TRANSACTION_IDS_USER CONWAY_SYNC

// how much to scale down the playing field (2: 128->64) (other scalings currently not supported)
#define SCALING 2

// Size of playing field
#define WC (WIDTH/SCALING + 1)
#define HC (HEIGHT/SCALING)

// cell spawning behaivior
// Matrix position / where to spawn the points (Default middle bottom)
#define MATRIX_POS_X 24
#define MATRIX_POS_Y 22

// determines, how long a key needs to be pressed to trigger the next spawning ring
#define SPAWN_INTERVAL_1 250
#define SPAWN_INTERVAL_2 2000
#define SPAWN_INTERVAL_3 4000

// Whether to spawn in that structure after keyb turn on. coordinates, where to spawn. (For mutliple modify code)
#define GOSPER_GLIDER_GUN 3, 1
#define BEACON 55, 10


typedef struct conway_spawn_coordinates
{
    uint8_t x;
    uint8_t y;
    uint8_t level;
} conway_spawn_coordinates;

#ifdef CONWAY_RENDER
void render_cell(uint8_t x, uint8_t y, bool on);
void render_field(uint32_t field[WC]);
void render_column(uint32_t field[WC], uint8_t x);
// shifts 3-wide column one to right
void advance_tmp_state(bool field[WC][HC], bool tmp_state[3][HC]);

// adds a glider gun at position x, y (top left of glider)
void gosper_glider_gun(uint32_t field[WC], uint8_t x, uint8_t y);
void beacon(uint32_t field[WC], uint8_t x, uint8_t y);

void advance_prev_state(uint32_t field[WC], uint32_t prev_state[2], uint8_t idx_x);

// advances the game
void step(uint32_t field[WC]);

// spawn in new live cells, depending, which key was pressed
void conway_spawn_in(const conway_spawn_coordinates* csc);

// to be called from keymap matrix_scan_user
void conway(void);

#endif  // CONWAY_RENDER

void conway_keyboard_post_init_user(void);
void conway_process_record_user(uint16_t keycode, keyrecord_t *record);

conway_spawn_coordinates conway_calc_spawn_pos(uint16_t keycode, keyrecord_t *record);

void user_sync_a_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data);
