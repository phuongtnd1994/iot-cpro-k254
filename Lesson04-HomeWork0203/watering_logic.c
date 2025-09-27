#include "watering_logic.h"
#include "config.h"
#include "logger.h"
#include "utils.h"

static uint64_t elapsed_ms(uint64_t now, uint64_t then)
{
    return now >= then ? now - then : 0;
}

void logic_init(SystemConfig *cfg, SystemState *st, SensorData *sd)
{

    cfg->moisture_min = DEFAULT_MOISTURE_MIN;
    cfg->moisture_max = DEFAULT_MOISTURE_MAX;
    cfg->sensor_period_ms = SENSOR_POLL_PERIOD_MS;
    cfg->status_period_ms = STATUS_REPORT_PERIOD_MS;
    cfg->pump_max_ms = WATER_PUMP_MAX_MS;
    cfg->pump_cooldown_ms = WATER_COOLDONW_MS;
    cfg->manual_pump_ms = MANUAL_WATER_MS;

    st->mode = MODE_AUTO;
    st->pump = PUMP_OFF;
    st->led = LED_NORMAL;
    st->now_ms = 0;
    st->last_sensor_ms = 0;
    st->last_status_ms = 0;
    st->pump_on_since_ms = 0;
    st->last_watering_end_ms = 0;
    st->manual_watering_active = false;
    st->manual_watering_start_ms = 0;

    sd->moisture = 45; // start mid
    sd->temperature_c = 28.0f;
    sd->sensor_status = true;

    log_event("INIT", "System initialized (default AUTO).");
    log_mode(st->mode);
    log_led(st->led);
}

static void update_led(const SystemConfig *cfg, SystemState *st, const SensorData *sd)
{
    (void)cfg;
    if (!sd->sensor_status)
    {
        set_led(st, LED_ERROR);
    }
    else if (st->pump == PUMP_ON)
    {
        set_led(st, LED_WATERING);
    }
    else if (sd->moisture < cfg->moisture_min)
    {
        set_led(st, LED_LOW_MOISTURE_ALERT);
    }
    else
    {
        set_led(st, LED_NORMAL);
    }
}

void handle_buttons(const SystemConfig *cfg, SystemState *st, SensorData *sd, bool toggle_mode, bool manual_water)
{
    if (toggle_mode)
    {
        st->mode = (st->mode == MODE_AUTO) ? MODE_MANUAL : MODE_AUTO;
        log_mode(st->mode);
        if (st->mode == MODE_MANUAL)
        {
            // safety: ensure pump off when entering manual
            turn_pump_off(st);
        }
    }
    if (manual_water)
    {
        if (st->mode == MODE_MANUAL)
        {
            // start manual watering cycle
            st->manual_watering_active = true;
            st->manual_watering_start_ms = st->now_ms;
            turn_pump_on(st);
            log_event("MANUAL", "Manual watering started.");
        }
        else
        {
            log_event("MANUAL", "Ignored: not in MANUAL mode.");
        }
    }
    (void)cfg;
    (void)sd;
}

void logic_tick(SystemConfig *cfg, SystemState *st, SensorData *sd)
{
    // Cập nhật sensor theo chu kỳ
    if (elapsed_ms(st->now_ms, st->last_sensor_ms) >= cfg->sensor_period_ms)
    {
        st->last_sensor_ms = st->now_ms;

        extern void sensors_simulation_tick(SensorData *, const SystemState *);
        sensors_simulation_tick(sd, st);
    }

    // Xử lý tưới tự động
    if (st->mode == MODE_AUTO)
    {
        if (!sd->sensor_status)
        {
            // sensor hỏng thì tắt máy bơm
            turn_pump_off(st);
        }
        else
        {
            bool cooldown_ok = elapsed_ms(st->now_ms, st->last_watering_end_ms) >= cfg->pump_cooldown_ms;
            // Kiem tra thoi gian cooldown

            if (st->pump == PUMP_OFF)
            {
                // Nếu bơm đang tắt mà độ ẩm thấp hơn ngưỡng min và đã hết thời gian cooldown thì bật bơm
                if (sd->moisture < cfg->moisture_min && cooldown_ok)
                {
                    turn_pump_on(st);
                    log_event("AUTO", "Soil low. Start watering.");
                }
            }
            else
            { // pump on
                // Nếu bơm đang bật thì kiểm tra có đạt thời gian tưới tối đa hoặc độ ẩm đã cao hơn ngưỡng max thì tắt bơm

                bool reached_max_time = elapsed_ms(st->now_ms, st->pump_on_since_ms) >= cfg->pump_max_ms;

                bool reached_moisture = sd->moisture >= cfg->moisture_max;

                if (reached_max_time || reached_moisture || !sd->sensor_status)
                {
                    turn_pump_off(st);
                    if (reached_moisture)
                        log_event("AUTO", "Target moisture reached. Stop.");
                    else if (reached_max_time)
                        log_event("AUTO", "Max watering time reached. Stop.");
                }
            }
        }
    }

    // Xử lý tưới thủ công
    if (st->mode == MODE_MANUAL)
    {
        if (st->manual_watering_active)
        {
            if (elapsed_ms(st->now_ms, st->manual_watering_start_ms) >= cfg->manual_pump_ms)
            {
                st->manual_watering_active = false;
                turn_pump_off(st);
                log_event("MANUAL", "Manual watering finished.");
            }
        }
        else
        {
            // đảm bảo bơm tắt nếu không ở phiên tưới tay
            if (st->pump == PUMP_ON)
            {
                turn_pump_off(st);
            }
        }
    }

    // Cập nhật led
    update_led(cfg, st, sd);

    // Log
    if (elapsed_ms(st->now_ms, st->last_status_ms) >= cfg->status_period_ms)
    {
        st->last_status_ms = st->now_ms;
        log_status(st, cfg, sd);
    }
}
