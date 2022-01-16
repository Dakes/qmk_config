#ifndef KB_H
#define KB_H

#include "quantum.h"

#define KEYMAP( \
	K00, K01, K02,      \
	K10, K11, K12, K13, \
	K20, K21, K22, K23, \
	K30, K31, K32, K33, \
	K40, K41, K42, K43, \
	K50, K51, K52, K53, \
	     K61, K62, K63  \
) { \
	{ K00,   K01,   K02,   KC_NO }, \
	{ K10,   K11,   K12,   K13 }, \
	{ K20,   K21,   K22,   K23 }, \
	{ K30,   K31,   K32,   K33 }, \
	{ K40,   K41,   K42,   K43 }, \
	{ K50,   K51,   K52,   K53 }, \
	{ KC_NO, K61,   K62,   K63 }  \
}

#endif