#ifndef WATERING_LOGIC_H
#define WATERING_LOGIC_H

#include "spws_common.h"

void logic_init(SystemConfig *cfg, SystemState *st, SensorData *sd);
void logic_tick(SystemConfig *cfg, SystemState *st, SensorData *sd);
void handle_buttons(const SystemConfig *cfg, SystemState *st, SensorData *sd, bool toggle_mode, bool manual_water);

#endif