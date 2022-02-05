OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
UNICODEMAP_ENABLE = no
TAP_DANCE_ENABLE = no
WPM_ENABLE = no
NO_USB_STARTUP_CHECK = yes


# EXTRAFLAGS += -flto

# debugging output
CONSOLE_ENABLE = no

# MOUSEKEY_ENABLE = no
STENO_ENABLE = no
BOOTMAGIC_ENABLE = no
TERMINAL_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
KEY_LOCK_ENABLE = no
AUDIO_ENABLE = no
VELOCIKEY_ENABLE = no

MIDI_ENABLE = no
UNICODE_ENABLE = no
BLUETOOTH_ENABLE = no
FAUXCLICKY_ENABLE = no
HD44780_ENABLE = no
NKRO_ENABLE = no


RGB_MATRIX_FRAMEBUFFER_EFFECTS = no
RGB_MATRIX_KEYPRESSES = no

# which side to build
MASTER_HALF = yes
ifeq ($(strip $(MASTER_HALF)), yes)

endif
MOUSEKEY_ENABLE = yes
# enable (yes) only on the side with the trackball
PIMORONI_TRACKBALL_ENABLE = yes
TRACKBALL_MASTER = yes
# disable on other half
ifeq ($(strip $(MASTER_HALF)), no)
    ifeq ($(strip $(TRACKBALL_MASTER)), yes)
        PIMORONI_TRACKBALL_ENABLE = no
    endif
else ifeq ($(strip $(MASTER_HALF)), yes)
    ifeq ($(strip $(TRACKBALL_MASTER)), no)
        PIMORONI_TRACKBALL_ENABLE = no
    endif
endif


WPM_ENABLE = no
OLED_DRIVER_ENABLE = yes
OLED_ENABLE = yes
SLAVE_DEBUG = no

CONWAY_ENABLE = yes
CONWAY_MASTER = no
# if pimoroni is disabled (right half?), enough space is available for animations
ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), no)
    # MODULAR_BONGOCAT_ENABLE = yes
    # QMK_LOGO_ENABLE = yes
    # KYRIA_LOGO_ENABLE = yes
    # CONWAY_MASTER = yes
    # CONWAY_SLAVE = no  # needed for keypress sync for spawn in
else
    # CONWAY_MASTER = no
endif

CONWAY_MASTER = no

MODULAR_BONGOCAT_ENABLE ?= no
QMK_LOGO_ENABLE ?= no
KYRIA_LOGO_ENABLE ?= no

# completely en/disable Conway
CONWAY_ENABLE ?= no
# Put on master (yes) or Slave
CONWAY_MASTER ?= yes

