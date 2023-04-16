#include "py/mphal.h"

void F411CE_board_early_init(void) {
    // set SPI flash CS pin high
    mp_hal_pin_output(pin_A4);
    mp_hal_pin_write(pin_A4, 1);
    mp_hal_pin_output(pin_A8);
    mp_hal_pin_write(pin_A8, 1);
}