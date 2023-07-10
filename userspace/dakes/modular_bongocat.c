
#include QMK_KEYBOARD_H
#include "modular_bongocat.h"
#include <string.h>

// #ifdef OLED_DRIVER_ENABLE
#if defined(OLED_ENABLE) || defined(OLED_DRIVER_ENABLE)

// fake WPM
#if !defined WPM_ENABLE

static uint8_t current_wpm = 0;

void bongo_fake_wpm_increment(void)
{
    #define increment_amount 1
    if (current_wpm + increment_amount >= 255)
        current_wpm = 255;
    else
        current_wpm += increment_amount;
}

void bongo_fake_wpm_decay(void)
{
    #define decay_every_x 150
    static uint8_t decay_calls = 0;

    if (decay_calls == 0)
    {
        if (!current_wpm == 0)
            current_wpm --;
        else
            return;
    }

    if (decay_calls > decay_every_x)
        decay_calls = 0;
    else
        decay_calls ++;
}

uint8_t get_current_wpm(void)
{
    return current_wpm;
}
#endif

#ifdef WPM_ENABLE
char wpm_str[8];
#endif

void render_wpm(void)
{
    #ifdef WPM_ENABLE
    char wpm_number_str[3];
    itoa(get_current_wpm(), wpm_number_str, 10);
    oled_set_cursor(7,6);
    strcpy(wpm_str, "WPM: ");
    strcat(wpm_str, wpm_number_str);
    oled_write(wpm_str, false);
    #endif
}


// Add your own logos here

#ifdef KYRIA_LOGO_ENABLE
// TODO: use bitfield
const uint8_t kyria_logo_width = 31;
const uint16_t kyria_logo[] PROGMEM = {466, 32769, 32770, 32773, 32774, 32800, 32801, 32803, 32804, 32807, 32808, 32811, 32812, 32814, 32815, 32816, 32817, 32820, 32821, 32825, 32826, 32827, 32828, 32831, 32832, 32833, 32834, 32838, 32839, 32842, 32843, 32848, 32849, 32851, 32852, 32855, 32856, 32858, 32859, 32862, 32863, 32864, 32865, 32870, 32871, 32872, 32873, 32876, 32877, 32878, 32879, 32882, 32883, 32885, 32886, 32889, 32890, 32893, 32894, 32896, 32897, 32902, 32903, 32907, 32910, 32911, 32913, 32914, 32916, 32917, 32918, 32919, 32920, 32921, 32924, 32925, 32928, 32929, 32933, 32934, 32938, 32941, 32942, 32944, 32945, 32947, 32948, 32951, 32952, 32995, 32996, 32997, 32998, 32999, 33000, 33001, 33002, 33003, 33004, 33005, 33024, 33025, 33026, 33027, 33035, 33036, 33037, 33038, 33053, 33054, 33055, 33069, 33070, 33071, 33083, 33084, 33102, 33103, 33113, 33114, 33120, 33121, 33122, 33123, 33124, 33125, 33126, 33127, 33128, 33134, 33135, 33143, 33144, 33149, 33150, 33151, 33154, 33155, 33156, 33159, 33160, 33161, 33166, 33167, 33173, 33174, 33179, 33180, 33185, 33186, 33187, 33192, 33193, 33198, 33199, 33204, 33209, 33210, 33215, 33217, 33219, 33224, 33225, 33230, 33234, 33235, 33239, 33240, 33246, 33248, 33250, 33256, 33257, 33261, 33262, 33265, 33269, 33270, 33276, 33279, 33282, 33288, 33289, 33293, 33295, 33296, 33300, 33301, 33302, 33303, 33304, 33305, 33306, 33307, 33310, 33313, 33314, 33315, 33316, 33317, 33318, 33319, 33320, 33324, 33325, 33326, 33327, 33330, 33331, 33332, 33333, 33334, 33339, 33341, 33343, 33348, 33349, 33350, 33351, 33352, 33355, 33356, 33357, 33361, 33363, 33366, 33367, 33370, 33372, 33374, 33377, 33378, 33381, 33383, 33387, 33388, 33392, 33395, 33399, 33400, 33401, 33402, 33403, 33404, 33405, 33406, 33407, 33411, 33414, 33418, 33419, 33423, 33426, 33432, 33433, 33434, 33435, 33436, 33442, 33445, 33449, 33450, 33454, 33458, 33459, 33460, 33461, 33462, 33463, 33464, 33465, 33466, 33467, 33468, 33469, 33470, 33471, 33472, 33476, 33480, 33481, 33485, 33488, 33494, 33495, 33496, 33497, 33498, 33504, 33507, 33511, 33512, 33516, 33519, 33523, 33524, 33525, 33526, 33527, 33528, 33529, 33530, 33531, 33535, 33538, 33542, 33543, 33547, 33549, 33552, 33553, 33556, 33558, 33560, 33563, 33564, 33567, 33569, 33573, 33574, 33575, 33578, 33579, 33580, 33581, 33582, 33587, 33589, 33591, 33596, 33597, 33598, 33599, 33600, 33603, 33604, 33605, 33606, 33610, 33611, 33612, 33613, 33614, 33615, 33616, 33617, 33620, 33623, 33624, 33625, 33626, 33627, 33628, 33629, 33630, 865, 33634, 33635, 33637, 33641, 33642, 33648, 33651, 33654, 33660, 33661, 894, 895, 33665, 33668, 33669, 33673, 33674, 33680, 33682, 33684, 919, 920, 921, 33690, 33691, 924, 33695, 33696, 33700, 33705, 33706, 33711, 33713, 33715, 948, 949, 33720, 33721, 33726, 33731, 33732, 33737, 33738, 973, 974, 33743, 33744, 33745, 978, 33750, 33751, 33756, 33757, 33763, 33764, 1000, 33769, 33770, 33771, 33774, 33775, 33776, 33779, 33780, 33781, 33786, 33787, 33795, 33796, 1029, 1030, 33802, 33803, 33804, 33805, 33806, 33807, 33808, 33809, 33810, 33816, 33817, 33827, 33828, 33846, 33847, 33859, 33860, 33861, 33875, 33876, 33877, 33892, 33893, 33894, 33895, 33903, 33904, 33905, 33906, 33925, 33926, 33927, 33928, 33929, 33930, 33931, 33932, 33933, 33934, 33935};
#endif

#ifdef QMK_LOGO_ENABLE
// TODO: use bitfield
const uint8_t qmk_logo_width = 15;
const uint16_t qmk_logo[] PROGMEM = {176, 32771, 32773, 32775, 32777, 32779, 32786, 32788, 32790, 32792, 32794, 32800, 32801, 32802, 32803, 32804, 32805, 32806, 32807, 32808, 32809, 32810, 32813, 32814, 32815, 32816, 32817, 32818, 32819, 32820, 32821, 32822, 32823, 32824, 32825, 32830, 32831, 32833, 32834, 32836, 32837, 32839, 32840, 32841, 32842, 32843, 32844, 32845, 32846, 32848, 32849, 32851, 32852, 32854, 32855, 32860, 32861, 32863, 32864, 32866, 32867, 32869, 32870, 32871, 32872, 32873, 32874, 32875, 32876, 32877, 32879, 32881, 32883, 32884, 32885, 32890, 32891, 32892, 32893, 32897, 32898, 32899, 32900, 32901, 32902, 32903, 32904, 32905, 32906, 32907, 32908, 32909, 32911, 32912, 32913, 32914, 32915, 32920, 32921, 32922, 32923, 32924, 32926, 32927, 32928, 32929, 32930, 32931, 32932, 32933, 32934, 32935, 32936, 32937, 32938, 32939, 32940, 32941, 32942, 32943, 32944, 32945, 32950, 32951, 32952, 32953, 32954, 32955, 32956, 32957, 32958, 32959, 32960, 32966, 32968, 32970, 32972, 32974, 32981, 32983, 32985, 32987, 32989, 33024, 33025, 33028, 33032, 33034, 33037, 33038, 33041, 33043, 33044, 33046, 33047, 33049, 33051, 33053, 33056, 33058, 33060, 33062, 33064, 33065, 33068, 33071, 33073, 33077, 33079, 33081, 33084, 33085, 33088, 33092, 33094, 33097, 33101};
#endif


/**
 * renders a PROGMEM uint16_t array, smaller or equal in size than the OLED
 * x, y: top left position of the image
 * width: width of the image
 */
void render_short_array_pos(const uint16_t* frame, uint8_t x, uint8_t y, uint8_t width)
{
    uint16_t size = pgm_read_word(&(frame[0])) + 1;
    for(uint16_t i=1; i<size; i++)
    {
        uint16_t cur_px = pgm_read_word(&(frame[i]));

        // get pixel state bit
        bool on = (cur_px & (1<<15)) >> 15;
        // remove pixel state bit
        cur_px &= ~(1UL << 15);

        uint8_t x_cur = (cur_px % width) + x;
        uint8_t y_cur = (cur_px / width) + y;
        oled_write_pixel(x_cur, y_cur, on);
    }
}

/**
 * Shortcut to render images of the size of the OLED
 */
void render_short_array(const uint16_t* frame)
{
    render_short_array_pos(frame, 0, 0, WIDTH);
}

// originally by j-inc: https://github.com/qmk/qmk_firmware/blob/master/keyboards/kyria/keymaps/j-inc/keymap.c
// Adapted to modular system and diffs using uint16_t arrays by Dakes (Daniel Ostertag).

// WPM-responsive animation stuff here
#define IDLE_FRAMES 5 // 5
#define IDLE_SPEED 40 // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#define TAP_FRAMES 2
#define TAP_SPEED 60 // above this wpm value typing animation to triggere

#define PREP_FRAMES 1

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms 200
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
uint8_t current_tap_frame = 0;


// Images credit j-inc(/James Incandenza) and pixelbenny. Credit to obosob for initial animation approach.

void render_anim(void)
{
    // bongocat frames
    // saves the pixel index in bits 1-13 and pixel on, off in bit 16. 1: on 0: off (+2^15)
    // first element is the size of the array , without the size itself
    static const uint16_t base[] PROGMEM = {223, 32968, 32969, 32970, 33095, 33099, 33222, 33228, 33346, 33347, 33348, 33349, 33356, 33470, 33471, 33472, 33473, 33484, 33596, 33597, 33613, 33723, 33742, 33789, 33790, 33791, 33844, 33845, 33850, 33871, 33872, 33913, 33914, 33915, 33916, 33971, 33974, 33975, 33976, 33977, 34001, 34036, 34037, 34038, 34039, 34040, 34098, 34130, 34160, 34161, 34162, 34163, 34226, 34259, 34283, 34284, 34285, 34286, 34287, 34354, 34379, 34380, 34388, 34407, 34408, 34409, 34410, 34483, 34507, 34508, 34517, 34530, 34531, 34532, 34533, 34534, 34611, 34638, 34639, 34640, 34641, 34646, 34654, 34655, 34656, 34657, 34740, 34751, 34752, 34762, 34766, 34767, 34768, 34769, 34775, 34779, 34780, 34781, 34868, 34879, 34880, 34884, 34887, 34888, 34889, 34890, 34903, 34904, 34905, 34906, 34996, 35013, 35014, 35032, 35123, 35132, 35133, 35134, 35135, 35150, 35151, 35160, 35250, 35260, 35261, 35262, 35263, 35273, 35274, 35275, 35276, 35277, 35280, 35281, 35288, 35378, 35397, 35398, 35399, 35400, 35410, 35411, 35412, 35413, 35414, 35415, 35506, 35522, 35523, 35524, 35633, 35649, 35761, 35778, 35889, 35892, 35893, 35894, 35895, 35896, 35897, 35906, 36016, 36017, 36018, 36019, 36026, 36027, 36034, 36142, 36143, 36156, 36157, 36162, 36266, 36267, 36268, 36269, 36286, 36287, 36288, 36289, 36390, 36391, 36392, 36393, 36514, 36515, 36516, 36517, 36638, 36639, 36640, 36641, 36762, 36763, 36764, 36765, 36886, 36887, 36888, 36889, 37010, 37011, 37012, 37013, 37134, 37135, 37136, 37137, 37258, 37259, 37260, 37261, 37382, 37383, 37384, 37385, 37506, 37507, 37508, 37509, 37632, 37633};

    // diffs rendered after base frame, turns on/off certain pixels
    // unfortunately C Arrays can't have a variable second dimension
    static const uint16_t idle_diff_0[] PROGMEM = {0};
    static const uint16_t idle_diff_2[] PROGMEM = {22, 32841, 32842, 201, 202, 32971, 331, 33100, 588, 33357, 716, 33485, 33716, 33717, 33843, 1076, 1077, 33846, 33847, 33970, 1203, 1206, 1207};
    static const uint16_t idle_diff_3[] PROGMEM = {104, 200, 327, 33096, 454, 33223, 578, 579, 580, 581, 33350, 702, 703, 704, 705, 33474, 33475, 33476, 33477, 716, 33485, 828, 829, 33598, 33599, 33600, 33601, 955, 33724, 33725, 33741, 974, 1082, 33851, 33870, 1103, 1104, 1208, 1209, 33978, 33999, 34000, 1233, 34104, 34105, 34129, 1362, 34258, 1491, 1611, 1612, 34387, 1620, 34482, 1715, 34516, 1749, 34635, 34636, 1870, 1871, 1872, 1873, 34645, 1878, 34739, 1972, 1983, 1984, 1994, 34774, 2007, 2116, 2119, 2120, 2121, 34894, 34895, 34896, 34897, 35007, 35008, 35012, 2245, 2246, 35015, 35016, 35017, 35018, 2355, 35124, 2364, 2365, 2366, 2367, 35141, 35142, 2482, 35251, 35388, 35389, 35390, 35391, 2865, 35634};
    static const uint16_t idle_diff_4[] PROGMEM = {20, 200, 201, 202, 327, 33096, 33097, 33098, 331, 454, 33223, 33227, 460, 33350, 1076, 1077, 1203, 33972, 33973, 1330, 34099};
    static const uint16_t *idle_diff[IDLE_FRAMES] = {
            idle_diff_0,
            idle_diff_0, // first two frames are identical
            idle_diff_2,
            idle_diff_3,
            idle_diff_4
    };

    static const uint16_t prep_diff_0[] PROGMEM = {107, 32841, 32842, 201, 202, 32971, 331, 33100, 588, 33357, 716, 33485, 33716, 33717, 33843, 1076, 1077, 33846, 33847, 33875, 33876, 33877, 33878, 33970, 1203, 1206, 1207, 34002, 34007, 34133, 34136, 34257, 34263, 34264, 34385, 34389, 34392, 34512, 34516, 34520, 1870, 1871, 1873, 1878, 34648, 34746, 34747, 34748, 1998, 1999, 2001, 34873, 34875, 34877, 35000, 35005, 35027, 35028, 35029, 35030, 2264, 35128, 35129, 2365, 2367, 35152, 35153, 35154, 2392, 35255, 35258, 35259, 2492, 2493, 2495, 2512, 2513, 2520, 35383, 35386, 35387, 35390, 2642, 2643, 2644, 2645, 2646, 2647, 35518, 35646, 35647, 35648, 35770, 35771, 35772, 35773, 3010, 3138, 3258, 3259, 3266, 3388, 3389, 3394, 3518, 3519, 3520, 3521};
    static const uint16_t *prep_diff[PREP_FRAMES] = {
            prep_diff_0
    };

    static const uint16_t tap_diff_0[] PROGMEM = {187, 32841, 32842, 201, 202, 32971, 331, 33100, 33238, 33239, 33240, 33241, 588, 33357, 33366, 33367, 33368, 33369, 716, 33485, 33494, 33495, 33496, 33497, 33622, 33623, 33624, 33625, 33716, 33717, 33750, 33751, 33752, 33753, 33759, 33760, 33843, 1076, 1077, 33846, 33847, 33878, 33879, 33880, 33881, 33886, 33887, 33888, 33889, 33970, 1203, 1206, 1207, 34006, 34007, 34008, 34013, 34014, 34015, 34016, 34017, 34135, 34136, 34140, 34141, 34142, 34143, 34144, 34145, 34146, 34264, 34267, 34268, 34269, 34270, 34271, 34272, 34273, 34274, 34395, 34396, 34397, 34398, 34399, 34400, 34523, 34524, 1870, 1871, 1872, 1873, 34746, 34747, 34748, 1998, 1999, 2000, 2001, 34873, 34875, 34877, 2135, 35000, 35005, 35128, 35129, 2365, 2367, 35162, 35163, 35164, 35165, 35166, 35167, 35168, 35169, 35170, 35255, 35258, 35259, 2492, 2493, 2495, 35290, 35291, 35292, 35293, 35294, 35295, 35296, 35297, 35298, 35383, 35386, 35387, 35390, 35418, 35419, 35420, 35421, 35422, 35423, 35424, 35425, 35518, 35546, 35547, 35548, 35549, 35550, 35551, 35552, 35553, 35646, 35647, 35648, 35675, 35676, 35677, 35678, 35679, 35680, 35770, 35771, 35772, 35773, 3010, 35804, 35805, 35806, 35807, 35808, 3138, 35933, 35934, 35935, 3258, 3259, 3266, 36062, 36063, 3388, 3389, 3394, 3518, 3519, 3520, 3521};
    static const uint16_t tap_diff_1[] PROGMEM = {187, 32841, 32842, 201, 202, 32971, 331, 33100, 588, 33357, 716, 33485, 33716, 33717, 33843, 1076, 1077, 33846, 33847, 33875, 33876, 33877, 33878, 33970, 1203, 1206, 1207, 34002, 34007, 34133, 34136, 34257, 34263, 34264, 34385, 34389, 34392, 34512, 34516, 34520, 1870, 1871, 1873, 1878, 34648, 1998, 1999, 2001, 35027, 35028, 35029, 35030, 2264, 2364, 2365, 2366, 2367, 35152, 35153, 35154, 2392, 2492, 2493, 2494, 2495, 2512, 2513, 2520, 2642, 2643, 2644, 2645, 2646, 2647, 36274, 36275, 36276, 36277, 36278, 36279, 36280, 36402, 36403, 36404, 36405, 36406, 36407, 36408, 36409, 36530, 36531, 36532, 36533, 36534, 36535, 36536, 36537, 36658, 36659, 36660, 36661, 36662, 36663, 36800, 36801, 36802, 36803, 36922, 36923, 36924, 36928, 36929, 36930, 36931, 36932, 37049, 37050, 37051, 37052, 37056, 37057, 37058, 37059, 37060, 37061, 37176, 37177, 37178, 37179, 37180, 37184, 37185, 37186, 37187, 37188, 37189, 37190, 37303, 37304, 37305, 37306, 37307, 37312, 37313, 37314, 37315, 37316, 37317, 37318, 37319, 37430, 37431, 37432, 37433, 37434, 37435, 37440, 37441, 37442, 37443, 37444, 37445, 37446, 37447, 37558, 37559, 37560, 37561, 37562, 37563, 37568, 37569, 37570, 37571, 37572, 37573, 37687, 37688, 37689, 37690, 37696, 37697, 37698, 37699, 37817, 37818, 37824, 37825};
    static const uint16_t *tap_diff[TAP_FRAMES] = {
            tap_diff_0,
            tap_diff_1
    };

    //assumes 1 frame prep stage
    void animation_phase(void)
    {
        oled_clear();
        if (get_current_wpm() <= IDLE_SPEED)
        {
            current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
            // first render base frame
            render_short_array(base);
            // only add or remove changed pixels
            render_short_array(idle_diff[ current_idle_frame ]);
        }
        if (get_current_wpm() > IDLE_SPEED && get_current_wpm() < TAP_SPEED)
        {
            render_short_array(base);
            render_short_array(prep_diff[0]);
        }
        if (get_current_wpm() >= TAP_SPEED)
        {
            current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
            render_short_array(base);
            render_short_array(tap_diff[ current_tap_frame ]);
        }

        // Add your own logos here

        #ifdef QMK_LOGO_ENABLE
        render_short_array_pos(qmk_logo, 108, 14, qmk_logo_width);
        #endif

        #ifdef KYRIA_LOGO_ENABLE
        render_short_array_pos(kyria_logo, 6, 2, kyria_logo_width);
        #endif
    }

    if(get_current_wpm() != 0)
    {
        oled_on(); // not essential but turns on animation OLED with any alpha keypress
        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION)
        {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else
    {
        if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT)
        {
            oled_off();
        } else
        {
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION)
            {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}

__attribute__((weak)) void oled_task_user(void)
{
    static bool logos_rendered = false;
    #ifdef BONGO_DEBUG
    if (!is_keyboard_master())
    #endif
    #ifndef BONGO_DEBUG
    if (is_keyboard_master())
    #endif
    {
        if(!logos_rendered)
        {
            #ifdef QMK_LOGO_ENABLE
            render_short_array_pos(qmk_logo, 0, 0, qmk_logo_width);
            #endif
            #ifdef KYRIA_LOGO_ENABLE
            render_short_array_pos(kyria_logo, WIDTH-kyria_logo_width, -6, kyria_logo_width);
            #endif
            logos_rendered = true;
        }
        // oled_set_cursor(0,4);
        // render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else
    {
        render_anim();
        render_wpm();
    }
}


#endif
