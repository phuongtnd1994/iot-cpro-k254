#include <assert.h>
#include "sensors.h"

int main(void)
{
    SystemState st; // giả lập input
    SensorData out;

    sensors_init();
    sensors_read(&out, &st);

    assert(out.temperature_c >= -40 && out.temperature_c <= 125);
    assert(out.moisture >= 0 && out.moisture <= 100);

    return 0;
}