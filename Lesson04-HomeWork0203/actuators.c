#include "actuators.h"

void actuators_init(SystemState *st)
{
    st->pump = PUMP_OFF;
    st->led = LED_NORMAL;
}

void turn_pump_on(SystemState *st)
{
    if (st->pump != PUMP_ON)
    {
        st->pump = PUMP_ON;
        st->pump_on_since_ms = st->now_ms;
        log_pump(st->pump);
    }
}

void turn_pump_off(SystemState *st)
{
    if (st->pump != PUMP_OFF)
    {
        st->pump = PUMP_OFF;
        st->last_watering_end_ms = st->now_ms;
        log_pump(st->pump);
    }
}

void set_led(SystemState *st, LedState led)
{
    if (st->led != led)
    {
        st->led = led;
        log_led(led);
    }
}
