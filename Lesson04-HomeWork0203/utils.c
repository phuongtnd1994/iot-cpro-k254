#define _POSIX_C_SOURCE 200809L // Có cái này thì ra được CLOCK_MONOTONICΩ
#include "utils.h"
#include <time.h>
#include <unistd.h>

// CLOCK_MONOTONIC là đồng hộ đơn điệu của hệ thống
// Hàm này đo thời gian giữa 02 khoảng
uint64_t monotonic_ms(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

void sleep_ms(unsigned ms)
{
    struct timespec req = {ms / 1000, (ms % 1000) * 1000000L};
    nanosleep(&req, NULL);
}
