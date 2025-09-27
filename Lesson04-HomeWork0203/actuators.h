#ifndef ACTUATORS_H
#define ACTUATORS_H

#include "spws_common.h"

void actuators_init(SystemState *st);
void turn_pump_on(SystemState *st);
void turn_pump_off(SystemState *st);
void set_led(SystemState *st, LedState led);

#endif