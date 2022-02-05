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


#include <stdint.h>
#include QMK_KEYBOARD_H
#include <transactions.h>
#include "conway.h"

# ifdef CONWAY_RENDER  // only compiled into side, where conway is actually displayed

// Columns saved as Bit"fields" -> int size for field height. (32 -> uint32_t)
#define SET_CELL(BF, N) BF |=  ((uint32_t) 1 << N)
#define CLR_CELL(BF, N) BF &= ~((uint32_t) 1 << N)
#define CELL_LIVE(BF, N) ((BF >> N) & 1)

// The game field
static uint32_t field[WC] = {};

// draws an individuel cell (usually 4 pixel large)
void render_cell(uint8_t x, uint8_t y, bool on)
{
    // TODO: render cell dynamically, depending on scaling
    uint8_t xo = x*SCALING;
    uint8_t yo = y*SCALING;
    oled_write_pixel(xo,   yo,   on);
    oled_write_pixel(xo+1, yo,   on);
    oled_write_pixel(xo,   yo+1, on);
    oled_write_pixel(xo+1, yo+1, on);
}


void render_column(uint32_t field[WC], uint8_t x)
{
    for(uint8_t y=0; y<HC; y++)
        render_cell(x, y, CELL_LIVE(field[x], y));
}

# ifdef GOSPER_GLIDER_GUN
void gosper_glider_gun(uint32_t field[WC], uint8_t x, uint8_t y)
{
    SET_CELL(field[1+x],  (5+y));
    SET_CELL(field[1+x],  (6+y));
    SET_CELL(field[2+x],  (5+y));
    SET_CELL(field[2+x],  (6+y));

    SET_CELL(field[11+x], (5+y));
    SET_CELL(field[11+x], (6+y));
    SET_CELL(field[11+x], (7+y));
    SET_CELL(field[12+x], (4+y));
    SET_CELL(field[12+x], (8+y));
    SET_CELL(field[13+x], (3+y));
    SET_CELL(field[13+x], (9+y));
    SET_CELL(field[14+x], (3+y));
    SET_CELL(field[14+x], (9+y));
    SET_CELL(field[15+x], (6+y));
    SET_CELL(field[16+x], (4+y));
    SET_CELL(field[16+x], (8+y));
    SET_CELL(field[17+x], (5+y));
    SET_CELL(field[17+x], (6+y));
    SET_CELL(field[17+x], (7+y));
    SET_CELL(field[18+x], (6+y));

    SET_CELL(field[21+x], (3+y));
    SET_CELL(field[21+x], (4+y));
    SET_CELL(field[21+x], (5+y));
    SET_CELL(field[22+x], (3+y));
    SET_CELL(field[22+x], (4+y));
    SET_CELL(field[22+x], (5+y));
    SET_CELL(field[23+x], (2+y));
    SET_CELL(field[23+x], (6+y));
    SET_CELL(field[25+x], (1+y));
    SET_CELL(field[25+x], (2+y));
    SET_CELL(field[25+x], (6+y));
    SET_CELL(field[25+x], (7+y));
    SET_CELL(field[35+x], (3+y));
    SET_CELL(field[35+x], (4+y));
    SET_CELL(field[36+x], (3+y));
    SET_CELL(field[36+x], (4+y));
}
#endif  // GOSPER_GLIDER_GUN

# ifdef BEACON
void beacon(uint32_t field[WC], uint8_t x, uint8_t y)
{
    SET_CELL(field[1+x], (1+y));
    SET_CELL(field[1+x], (2+y));
    SET_CELL(field[2+x], (1+y));
    SET_CELL(field[3+x], (4+y));
    SET_CELL(field[4+x], (3+y));
    SET_CELL(field[4+x], (4+y));
}
#endif  // BEACON

void advance_prev_state(uint32_t field[WC], uint32_t prev_state[2], uint8_t idx_x)
{
    prev_state[0] = prev_state[1];
    prev_state[1] = field[idx_x+1];
}

/**
 * Each step advances scanning column only by one to right.
 * Called once per matrix scan
 * */
void step(uint32_t field[WC])
{
    static uint8_t x = 1;

    // render current column, before advancing game, to display just toggled single live cells
    render_column(field, x);
    if (x == 1)
        render_column(field, 0);
    else if (x >= WC-1)
        render_column(field, WC);

    // tmp array to compute the new game state
    // previous state for this slice will be copied into it
    static uint32_t prev_state[2] = {};
    if (x <= 1)
    {
        prev_state[0] = field[0];
        prev_state[1] = field[1];
    }

    for(uint8_t y=1; y<HC; y++)
    {
        // actual game algorithm
        // calculate new state for slice "prev_state"
        uint8_t alive_neighbors = 0;

        if (CELL_LIVE(prev_state[0], (y-1)))
            alive_neighbors ++;
        if (CELL_LIVE(prev_state[1], (y-1)))
            alive_neighbors ++;
        if (CELL_LIVE(field[x+1],    (y-1)))
            alive_neighbors ++;
        if (CELL_LIVE(field[x+1],    (y  )))
            alive_neighbors ++;
        if (CELL_LIVE(field[x+1],    (y+1)))
            alive_neighbors ++;
        if (CELL_LIVE(prev_state[1], (y+1)))
            alive_neighbors ++;
        if (CELL_LIVE(prev_state[0], (y+1)))
            alive_neighbors ++;
        if (CELL_LIVE(prev_state[0], (y  )))
            alive_neighbors ++;

        if (alive_neighbors == 3)
            SET_CELL(field[x], y);
        else if (CELL_LIVE(prev_state[1], y) && alive_neighbors == 2 ){}
        else
            CLR_CELL(field[x], y);
    }

    
    if (x<WC-1)
    {
        advance_prev_state(field, prev_state, x);
        x++;
    }
    else
    {
        // end of field. Reset to beginning and kill edges.
        x = 1;
#       ifdef EGDE_KILL
        for(uint8_t x=0; x<WC; x++)
            for(uint8_t y=0; y<HC; y++)
                if(y == 0 || y == HC-1 || x == 0 || x == WC-1)
                    CLR_CELL(field[x], y);
#       endif
    }
}

/**
 * Called from matrix_scan_user.
 * Maybe you have to add a timer, if it is running too fast.
 * */
void conway(void)
{
    static bool structures_set = false;

    // initial spawn in of structures on boot
    if (structures_set == false)
    {
#       ifdef GOSPER_GLIDER_GUN
        gosper_glider_gun(field, GOSPER_GLIDER_GUN);
#       endif
#       ifdef BEACON
        beacon(field, BEACON);
#       endif

        // create your own structures like this: SET_CELL(field[x], y);
        /*
        SET_CELL(field[3], 3);
        SET_CELL(field[3], 4);
        SET_CELL(field[3], 5);
        */
        structures_set = true;
    }
    
    step(field);
}

/**
 * on master called from  process_record_user->conway_calc_spawn_pos->conway_spawn_in
 * on slave called by user_sync_a_slave_handler->conway_spawn_in
 * Spawns in live cells, depending on keypress
 * */
void conway_spawn_in(const conway_spawn_coordinates* csc)
{
    SET_CELL(field[csc->x+MATRIX_POS_X], (csc->y+MATRIX_POS_Y));

#   ifdef HELD_SPAWN
    if (csc->level > 0)
    {
        uint8_t nbit = 0;
        uint8_t rand = random();
        // Toggle cells in radius 1, 2, 3 pseudo randomly
        if (csc->level == 1) // Ring +1
        {
            for(int8_t xo=-1; xo<=1; xo++)
                for(int8_t yo=-1; yo<=1; yo++)
                {
                    if ((rand >> nbit%16) & 1)
                        SET_CELL(field[csc->x+xo+MATRIX_POS_X], (csc->y+yo+MATRIX_POS_Y));
                    nbit++;
                }
        }
        else if (csc->level == 2) // Ring +2
        {
            for(int8_t xo=-2; xo<=2; xo++)
                for(int8_t yo=-2; yo<=2; yo++)
                {
                    if ((rand >> nbit%16) & 1)
                        SET_CELL(field[csc->x+xo+MATRIX_POS_X], (csc->y+yo+MATRIX_POS_Y));
                    nbit++;
                }
        }
        else if (csc->level >= 3) // Ring +3
        {
            for(int8_t xo=-3; xo<=3; xo++)
                for(int8_t yo=-3; yo<=3; yo++)
                {
                    if ((rand >> nbit%16) & 1)
                        SET_CELL(field[csc->x+xo+MATRIX_POS_X], (csc->y+yo+MATRIX_POS_Y));
                    nbit++;
                }
        }
    }
#   endif  // HELD_SPAWN
}

// dummy oled_task_user, to overwrite the keyboards default one
bool oled_task_user(void)
{
    return false;
}

__attribute__((weak)) void housekeeping_task_user(void)
{
    // Add this to your own keymap, if you are using this function. (with ifdef)
#   ifdef CONWAY_RENDER
    conway();
#   endif
}

#endif  // CONWAY_RENDER

/**
 * Will only run on master. Called by process_record_user->conway_process_record_user->conway_calc_spawn_pos
 * */
conway_spawn_coordinates conway_calc_spawn_pos(uint16_t keycode, keyrecord_t *record)
{
    uint8_t x = record->event.key.col;
    uint8_t y = record->event.key.row;

#   ifdef KYRIA_MATRIX_FIX
    if (y >= 4)
    {
        y = y-4;
        x = x+8;
    }
    else
        x = 7-x;
#   endif // KYRIA_MATRIX_FIX

    struct conway_spawn_coordinates csc = {x, y, 0};

#   ifdef HELD_SPAWN
    static uint16_t prev_keycode = 0;
    static uint16_t prev_time = 0;
    if (prev_keycode == 0 && record->event.pressed == 1 && keycode != 224)
    {
        prev_keycode = keycode;
        prev_time = record->event.time;
    }
    if (keycode == prev_keycode && record->event.pressed == 0)
    {
        uint16_t passed_time = record->event.time - prev_time;
        prev_keycode = 0;

        // Toggle cells in radius 1, 2, 3 pseudo randomly
        if (passed_time >= SPAWN_INTERVAL_1 && passed_time < SPAWN_INTERVAL_2) // Ring +1
            csc.level = 1;
        else if (passed_time >= SPAWN_INTERVAL_2 && passed_time < SPAWN_INTERVAL_3) // Ring +2
            csc.level = 2;
        else if (passed_time >= SPAWN_INTERVAL_3) // Ring +3
            csc.level = 3;
    }
#   endif  // HELD_SPAWN

    // same half, no sync needed. Spawn points directly.
#   ifdef MASTER_HALF
#   ifdef CONWAY_RENDER
    conway_spawn_in(&csc);
#   endif
#   endif
    return csc;
}

/**
 * Runs on slave to receive spawn in data
 * */
void user_sync_a_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data)
{
#   ifdef CONWAY_RENDER
    const conway_spawn_coordinates *csc = (const conway_spawn_coordinates*)in_data;
    conway_spawn_in(csc);
#   endif
}


void conway_keyboard_post_init_user(void)
{
    transaction_register_rpc(CONWAY_SYNC, user_sync_a_slave_handler);
}

__attribute__((weak)) void keyboard_post_init_user(void)
{
    // Add this to your own keymap, if you are using this function.
    conway_keyboard_post_init_user();
}

/**
 * Calculate position, where to spawn in points and sync them to the slave. 
 *  */
void conway_process_record_user(uint16_t keycode, keyrecord_t *record)
{
#   ifdef MASTER_HALF
    if (is_keyboard_master())
    {
        conway_spawn_coordinates csc = conway_calc_spawn_pos(keycode, record);
        // Interact with slave every 10ms
        /* static uint32_t last_sync = 0; */
        /* if (timer_elapsed32(last_sync) > 10) */
        /*     if(transaction_rpc_send(CONWAY_SYNC, sizeof(csc), &csc)) */
        /*         last_sync = timer_read32(); */
        transaction_rpc_send(CONWAY_SYNC, sizeof(csc), &csc);
    }
#   endif
}

__attribute__((weak)) bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    // Add this to your own keymap, if you are using this function.
    conway_process_record_user(keycode, record);

    return true;
}

