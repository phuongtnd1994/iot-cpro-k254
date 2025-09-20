#include <stdio.h>
#include "shared_state.h"

#include <stdint.h>

void LCD_display_temperature()
{
    uint16_t temp_to_display = g_current_temperature_celsius;
    printf("LCD Display: Current temperature is %c C\n", temp_to_display);
}