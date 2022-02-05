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

# Modular Bongocat
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



# Conway's Game of Life

# Compile for master?
MASTER_HALF ?= yes

# Enable Conway?
CONWAY_ENABLE ?= yes
# Run conway on master?
CONWAY_MASTER ?= no

# Fix kyria / split keyboard matrix. Spawn points of right half to the right
# For other split kbs, other than the SplitKB Kyria™ you may want to adjust the corresponding code. 
KYRIA_MATRIX_FIX ?= yes
# Edge behaviour, kill points on edges?
EGDE_KILL ?= yes
# spawn in more random points, the longer a key is pressed. Look in conway.h to adjust interval times. 
HELD_SPAWN ?= yes

ifeq ($(strip $(MASTER_HALF)), yes)
    OPT_DEFS += -DMASTER_HALF
endif
ifeq ($(strip $(CONWAY_ENABLE)), yes)
    SRC += $(USER_PATH)/conway.c
    OPT_DEFS += -DCONWAY_ENABLE
    OLED_ENABLE = yes
    OLED_DRIVER_ENABLE = yes
endif

ifeq ($(strip $(CONWAY_MASTER)), yes)
    ifeq ($(strip $(MASTER_HALF)), yes)
        CONWAY_RENDER = yes
        OPT_DEFS += -DCONWAY_RENDER
    endif
else ifeq ($(strip $(CONWAY_MASTER)), no)
    ifeq ($(strip $(MASTER_HALF)), no)
        CONWAY_RENDER = yes
        OPT_DEFS += -DCONWAY_RENDER
    endif
endif
ifeq ($(strip $(KYRIA_MATRIX_FIX)), yes)
    OPT_DEFS += -DKYRIA_MATRIX_FIX
endif
ifeq ($(strip $(EGDE_KILL)), yes)
    OPT_DEFS += -DEGDE_KILL
endif
ifeq ($(strip $(HELD_SPAWN)), yes)
    OPT_DEFS += -DHELD_SPAWN
endif
# Conway's Game of Life end



# Trackball
PIMORONI_TRACKBALL_ENABLE ?= no
ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
    SRC += pimoroni_trackball.c
    OPT_DEFS += -DPIMORONI_TRACKBALL_ENABLE
    POINTING_DEVICE_ENABLE := yes
endif

TRACKBALL_LEFT ?= no
TRACKBALL_ANGLE_OFFSET = 0
ifeq ($(strip $(TRACKBALL_LEFT)), yes)
    TRACKBALL_ANGLE_OFFSET = 0
endif


# Swap slave & master oled render 
SLAVE_DEBUG ?= no
ifeq ($(strip $(SLAVE_DEBUG)), yes)
    OPT_DEFS += -DSLAVE_DEBUG
endif
