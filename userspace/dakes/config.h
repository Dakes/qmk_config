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


#define WIDTH 128
#define HEIGHT 64

#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 28

#define RGB_DISABLE_WHEN_USB_SUSPENDED true


# ifdef CONWAY_ENABLE
#define SPLIT_TRANSACTION_IDS_USER CONWAY_SYNC
# endif
