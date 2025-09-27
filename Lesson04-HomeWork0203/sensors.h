#ifndef SENSORS_H
#define SENSORS_H

#include "spws_common.h"

void sensors_init(void);
void sensors_read(SensorData *out, const SystemState *st);
void sensors_simulation_tick(SensorData *io_sd, const SystemState *st);

#endif