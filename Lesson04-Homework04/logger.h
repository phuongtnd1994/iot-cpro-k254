#ifndef LOGGER_H
#define LOGGER_H

#include <stdint.h>
#include <stdarg.h>

typedef enum
{
    LOG_EMERGENCY = 0,
    LOG_ALERT = 1,
    LOG_CRITICAL = 2,
    LOG_ERROR = 3,
    LOG_WARNING = 4,
    LOG_NOTICE = 5,
    LOG_INFO = 6,
    LOG_DEBUG = 7
} log_level_t;

// xác định mức min và filepath
void logger_init(log_level_t min_level, const char *file_path);

// geter và seter
void logger_set_level(log_level_t min_level);
log_level_t logger_get_level(void);

void logger_close(void);

void logger_log_impl(log_level_t level,
                     const char *src_file,
                     int src_line,
                     const char *fmt, ...);

#define log_message(level, fmt, ...) \
    logger_log_impl((level), __FILE__, __LINE__, (fmt)__VA_OPT__(, ) __VA_ARGS__)

#endif // LOGGER_H