# MOUSEKEY_ENABLE      = yes     # Mouse keys
# AUTO_SHIFT_ENABLE    = yes
# DYNAMIC_MACRO_ENABLE = yes
# EXTRAKEY_ENABLE      = yes

# OLED_DRIVER_ENABLE  = yes
# RGBLIGHT_ENABLE     = no       # Enable WS2812 RGB underlight.
# RGB_MATRIX_ENABLE   = no
# VIA_ENABLE          = no        # Enable VIA
# LTO_ENABLE          = yes

LTO_ENABLE = yes
SRC += dakes.c

WPM_ENABLE ?= no
# MODULAR_BONGOCAT_ENABLE = yes
# QMK_LOGO_ENABLE ?= no
# KYRIA_LOGO_ENABLE ?= no

MODULAR_BONGOCAT_ENABLE ?= no
ifeq ($(strip $(MODULAR_BONGOCAT_ENABLE)), yes)
    SRC += modular_bongocat.c
    OPT_DEFS += -DMODULAR_BONGOCAT_ENABLE

    QMK_LOGO_ENABLE ?= yes
    KYRIA_LOGO_ENABLE ?= yes
    ifeq ($(strip $(QMK_LOGO_ENABLE)), yes)
         OPT_DEFS += -DQMK_LOGO_ENABLE
    endif
    ifeq ($(strip $(KYRIA_LOGO_ENABLE)), yes)
         OPT_DEFS += -DKYRIA_LOGO_ENABLE
    endif

    OLED_ENABLE = yes
    OLED_DRIVER_ENABLE = yes
endif

PIMORONI_TRACKBALL_ENABLE ?= no
ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
    SRC += pimoroni_trackball.c
    OPT_DEFS += -DPIMORONI_TRACKBALL_ENABLE
    POINTING_DEVICE_ENABLE := yes
endif

TRACKBALL_LEFT ?= no
TRACKBALL_ANGLE_OFFSET = 45
ifeq ($(strip $(TRACKBALL_LEFT)), yes)
    TRACKBALL_ANGLE_OFFSET = -45
endif
