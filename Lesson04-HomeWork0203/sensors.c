#include "sensors.h"
#include "config.h"
#include <stdlib.h>
#include <time.h>

static int clampit(int v, int lo, int hi)
{
    if (v < lo)
        return lo;
    if (v > hi)
        return hi;
    return v;
} // Kep gia tri trong 01 khoang khi mo phong

void sensors_init(void)
{
    srand((unsigned int)time(NULL));
}

void sensors_simulation_tick(SensorData *sd, const SystemState *st)
{
    int noise = (rand() % (2 * MOISTURE_NOIST + 1)) - MOISTURE_NOIST;

    int delta = (st->pump == PUMP_ON ? WATERING_RATE : -EVAPORATION_RATE) + noise;
    sd->moisture = clampit(sd->moisture + delta, 0, 100);

    float temp_noise = ((rand() % 7) - 3);
    sd->temperature_c = 28.0f + temp_noise;

    if ((rand() % 200) == 0)
    {
        sd->sensor_status = false;
    }
    else
    {
        sd->sensor_status = true;
    }
}

void sensors_read(SensorData *out, const SystemState *st)
{
    (void)st;

    (void)out;
}