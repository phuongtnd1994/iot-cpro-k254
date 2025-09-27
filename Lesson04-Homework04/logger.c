#include "logger.h"

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct
{
    log_level_t min_level;
    FILE *fp; // file log (có thể NULL)
    bool file_enabled;
} logger_state_t;

static logger_state_t g_logger = {
    .min_level = LOG_INFO,
    .fp = NULL,
    .file_enabled = false};

static const char *level_name(log_level_t lv)
{
    static const char *names[] = {
        "EMERGENCY", "ALERT", "CRITICAL", "ERROR",
        "WARNING", "NOTICE", "INFO", "DEBUG"};
    if (lv < 0 || lv > 7)
        return "UNKNOWN";
    return names[lv];
}

// Lấy tên file ngắn (bỏ path)
static const char *base_name(const char *path)
{
    if (!path)
        return "";
    const char *slash = strrchr(path, '/');

    return slash ? slash + 1 : path;
}

static FILE *console_stream_for(log_level_t lv)
{
    return (lv <= LOG_ERROR) ? stderr : stdout;
}

void logger_init(log_level_t min_level, const char *file_path)
{
    g_logger.min_level = min_level;

    if (g_logger.fp)
    {
        fclose(g_logger.fp);
        g_logger.fp = NULL;
    }
    g_logger.file_enabled = false;

    if (file_path && file_path[0] != '\0')
    {
        g_logger.fp = fopen(file_path, "a");
        if (g_logger.fp)
        {
            // Line-buffer để flush theo dòng
            setvbuf(g_logger.fp, NULL, _IOLBF, 0);
            g_logger.file_enabled = true;
        }
        else
        {
            // Nếu mở file thất bại, ta vẫn tiếp tục ghi console
            fprintf(stderr, "[LOGGER] Failed to open log file: %s\n", file_path);
        }
    }
}

void logger_set_level(log_level_t min_level) { g_logger.min_level = min_level; }
log_level_t logger_get_level(void) { return g_logger.min_level; }

void logger_close(void)
{
    if (g_logger.fp)
    {
        fclose(g_logger.fp);
        g_logger.fp = NULL;
    }
    g_logger.file_enabled = false;
}

// Tạo timestamp "YYYY-MM-DD HH:MM:SS"
static void make_timestamp(char out[20])
{
    time_t t = time(NULL);

    struct tm tmv;
    localtime_r(&t, &tmv);
    strftime(out, 20, "%Y-%m-%d %H:%M:%S", &tmv);
}

void logger_log_impl(log_level_t level,
                     const char *src_file,
                     int src_line,
                     const char *fmt, ...)
{
    // Lọc theo mức: chỉ ghi nếu level <= min_level
    if (level > g_logger.min_level)
        return;

    // Format message thân (vsnprintf để an toàn)
    char msg[1024];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(msg, sizeof msg, fmt, ap);
    va_end(ap);

    // Loại bỏ newline cuối (nếu có) để mình tự thêm 1 newline chuẩn
    size_t len = strlen(msg);
    while (len > 0 && (msg[len - 1] == '\n' || msg[len - 1] == '\r'))
    {
        msg[--len] = '\0';
    }

    // Làm header: [timestamp] [LEVEL] [file:line] - ...
    char ts[20]; // "YYYY-MM-DD HH:MM:SS"
    make_timestamp(ts);

    char linebuf[1400];
    snprintf(linebuf, sizeof linebuf,
             "[%s] [%s] [%s:%d] - %s\n",
             ts, level_name(level), base_name(src_file), src_line, msg);

    // Ghi console
    FILE *cstream = console_stream_for(level);
    fputs(linebuf, cstream);
    fflush(cstream);

    // Ghi file (nếu bật)
    if (g_logger.file_enabled && g_logger.fp)
    {
        fputs(linebuf, g_logger.fp);
        fflush(g_logger.fp);
    }
}