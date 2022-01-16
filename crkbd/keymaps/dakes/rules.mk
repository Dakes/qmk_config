MCU = atmega32u4
# Pro Micro
BOOTLOADER = caterina
# Elite-C
# BOOTLOADER = atmel-dfu

OLED_ENABLE = no
OLED_DRIVER = SSD1306

MODULAR_BONGOCAT_ENABLE = no
QMK_LOGO_ENABLE = no
KYRIA_LOGO_ENABLE = no

LTO_ENABLE = yes

BOOTMAGIC_ENABLE = lite     # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = WS2812




RGBLIGHT_SUPPORTED = no
RGB_MATRIX_SUPPORTED = no
RGB_MATRIX_FRAMEBUFFER_EFFECTS = no
RGB_MATRIX_KEYPRESSES = no

WPM_ENABLE = no
SPACE_CADET_ENABLE = no
KEY_LOCK_ENABLE = no
AUDIO_ENABLE = no
VELOCIKEY_ENABLE = no
MIDI_ENABLE = no
UNICODE_ENABLE = no
FAUXCLICKY_ENABLE = no
HD44780_ENABLE = no
