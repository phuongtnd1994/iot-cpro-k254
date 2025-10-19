# iot-cpro-k254

## Bài tập Module 01
Xem tại
[![Bài tập 01]](https://github.com/phuongtnd1994/iot-cpro-k254/tree/OnTap01/OnTap01/BaiTap01/)




Lesson01:
valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --errors-for-leak-kinds=all ./test


gcc -E main.c -o main.i

cc -Wall -Wextra -O0 -g test_sensors.c sensors.c -o test_sensors
./test_sensors