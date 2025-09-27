
#include "logger.h"
#include <stdio.h>
#include <unistd.h> // chỉ để demo getpid(), có thể bỏ

int main(void)
{
    // Khởi tạo: tối thiểu LOG_INFO, ghi thêm ra file "app.log"
    logger_init(LOG_INFO, "app.log");

    log_message(LOG_INFO, "App start. pid=%d", (int)getpid());
    log_message(LOG_DEBUG, "This DEBUG is filtered at LOG_INFO threshold"); // sẽ bị bỏ qua

    // Nâng mức lọc: cho phép DEBUG
    logger_set_level(LOG_DEBUG);
    log_message(LOG_DEBUG, "Now DEBUG is visible. threshold=%d", logger_get_level());

    // Ví dụ lỗi
    int rc = -1;
    if (rc < 0)
    {
        log_message(LOG_ERROR, "Failed to connect to database. rc=%d", rc);
    }

    // Một vài mức khác
    log_message(LOG_WARNING, "Low disk space: %d%% remaining", 7);
    log_message(LOG_NOTICE, "Config reloaded");
    log_message(LOG_CRITICAL, "Unrecoverable state encountered");

    logger_close();
    return 0;
}