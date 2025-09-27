#ifndef LOGGER_H
#define LOGGER_H

#include "spws_common.h"

void log_status(const SystemState *st, const SystemConfig *cfg, const SensorData *sd);
void log_event(const char *tag, const char *msg);
void log_led(LedState led);
void log_mode(SystemMode mode);
void log_pump(PumpState ps);

#endif