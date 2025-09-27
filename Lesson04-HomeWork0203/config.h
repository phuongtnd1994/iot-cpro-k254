#ifndef CONFIG_H
#define CONFIG_H

#define SENSOR_POLL_PERIOD_MS 2000   // 2s: đọc cảm biến
#define STATUS_REPORT_PERIOD_MS 5000 // 5s: in trạng thái
#define WATER_PUMP_MAX_MS 30000      // 30s: tưới nước tối đa
#define WATER_COOLDONW_MS 60000      // 60s: thời gian nghỉ giữa 2 lần tưới tự động
#define MANUAL_WATER_MS 10000        // 10s: tưới nước thủ công
#define EVAPORATION_RATE 1           // % giảm mỗi tick nếu không tưới
#define WATERING_RATE 3              // % tăng mỗi tick khi tưới
#define MOISTURE_NOIST 1             //

#define DEFAULT_MOISTURE_MIN 35 // dưới 35% thì tưới, trên 55% thì dừng
#define DEFAULT_MOISTURE_MAX 55 //

#endif