#ifndef SPWS_COMMON_H
#define SPWS_COMMON_H

#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    MODE_AUTO = 0,
    MODE_MANUAL = 1
} SystemMode;

typedef enum
{
    PUMP_OFF = 0,
    PUMP_ON = 1
} PumpState;

typedef enum
{
    LED_NORMAL = 0,
    LED_WATERING,
    LED_LOW_MOISTURE_ALERT,
    LED_ERROR
} LedState;

typedef struct
{
    float moisture;
    float temperature_c;
    bool sensor_status;
} SensorData;

typedef struct
{
    int moitsture_min;
    int moisture_max;
    uint32_t sensor_period_ms;
    uint32_t status_period_ms;
    uint32_t pump_max_ms;
    uint32_t pump_cooldown_ms;
    uint32_t manual_pump_ms;
} SystemConfig;

typedef struct
{
    SystemMode mode;
    PumpState pump;
    LedState led;

    // Luu tru thoi gian
    uint64_t now_ms;
    uint64_t last_sensor_ms;
    uint64_t last_status_ms;
    uint64_t pump_on_since_ms;
    uint64_t last_watering_end_ms;

    // Manual watering latch
    bool manual_watering_active;
    uint64_t manual_watering_start_ms;
} SystemState;

#endif