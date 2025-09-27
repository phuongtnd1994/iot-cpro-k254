#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include "spws_common.h"
#include "config.h"
#include "utils.h"
#include "logger.h"
#include "actuators.h"
#include "sensors.h"
#include "buttons.h"
#include "watering_logic.h"

static volatile sig_atomic_t g_stop = 0; // lấy từ thư viện signal.h; dùng làm cờ đảm bảo tính atomic
static void on_sigint(int sig)
{
    (void)sig;
    g_stop = 1;
} // hàm xử lý tín hiệu ngắt

int main(void)
{
    signal(SIGINT, on_sigint);

    SystemConfig cfg;
    SystemState st;
    SensorData sd;

    sensors_init();
    actuators_init(&st);
    logic_init(&cfg, &st, &sd);
    buttons_init();

    const unsigned LOOP_PERIOD_MS = 100; // main loop tick 100ms

    log_event("HELP", "Controls: [m]=toggle AUTO/MANUAL, [w]=manual water, [s]=status, [q]=quit");

    while (!g_stop)
    {
        st.now_ms = monotonic_ms();

        ButtonEvents ev;
        buttons_poll(&ev);
        if (ev.quit)
            break;
        if (ev.print_status)
            log_status(&st, &cfg, &sd);
        handle_buttons(&cfg, &st, &sd, ev.toggle_auto_manual, ev.manual_water);

        logic_tick(&cfg, &st, &sd);

        sleep_ms(LOOP_PERIOD_MS);
    }

    buttons_shutdown();
    turn_pump_off(&st);
    set_led(&st, LED_NORMAL);
    log_event("EXIT", "Goodbye.");
    return 0;
}
