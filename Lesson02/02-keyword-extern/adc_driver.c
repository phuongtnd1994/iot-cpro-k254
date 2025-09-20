#include <stdio.h>
#include "shared_state.h"
#include <stdint.h>

uint16_t g_current_temperature_celsius = 0;

void ADC_update_temperature()
{
    static uint16_t simulated_temp = 25;
    simulated_temp = (simulated_temp + 1) % 50;

    g_current_temperature_celsius = simulated_temp;
}