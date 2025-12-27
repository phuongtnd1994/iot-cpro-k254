#include <stdio.h>
#include <stdint.h>

int main()
{
    uint8_t x = 0b00011101;
    uint8_t y = 0b00110100;

    printf("x - y: %u\n", x ^ y);
    printf("x - x: %u\n", x ^ x);
}
