# iot-cpro-k254

Lesson01:
valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --errors-for-leak-kinds=all ./test


gcc -E main.c -o main.i

cc -Wall -Wextra -O0 -g test_sensors.c sensors.c -o test_sensors
./test_sensors
