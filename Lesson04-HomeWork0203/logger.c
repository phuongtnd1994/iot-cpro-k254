#include "logger.h"
#include <stdio.h>

static const char *mode_str(SystemMode m)
{
    return m == MODE_AUTO ? "AUTO" : "MANUAL";
}

static const char *pump_str(PumpState p)
{
    return p == PUMP_ON ? "ON" : "OFF";
}

static const char *led_str(LedState l)
{
    switch (l)
    {
    case LED_NORMAL:
        return "NORMAL";
    case LED_WATERING:
        return "WATERING";
    case LED_LOW_MOISTURE_ALERT:
        return "LOW_MOISTURE_ALERT";
    case LED_ERROR:
        return "ERROR";
    default:
        return "?";
    }
}

void log_event(const char *tag, const char *msg)
{
    printf("[%s] %s\n", tag, msg);
}

void log_led(LedState led)
{
    printf("[LED] -> %s\n", led_str(led));
}

void log_mode(SystemMode mode)
{
    printf("[MODE] -> %s\n", mode_str(mode));
}

void log_pump(PumpState ps)
{
    printf("[PUMP] -> %s\n", pump_str(ps));
}

void log_status(const SystemState *st, const SystemConfig *cfg, const SensorData *sd)
{
    (void)cfg;
    printf("[STATUS] t=%llums | Mode=%s | Pump=%s | LED=%s | Moisture=%d%% | Temp=%.1fC | SensorOK=%d\n",
           (unsigned long long)st->now_ms,
           st->mode == MODE_AUTO ? "AUTO" : "MANUAL",
           st->pump == PUMP_ON ? "ON" : "OFF",
           (st->led == LED_NORMAL ? "NORMAL" : st->led == LED_WATERING         ? "WATERING"
                                           : st->led == LED_LOW_MOISTURE_ALERT ? "LOW_ALERT"
                                                                               : "ERROR"),
           sd->moisture, sd->temperature_c, sd->sensor_status ? 1 : 0);
}
