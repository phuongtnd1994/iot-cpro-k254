#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t x = 0b11010101;

    int count = __builtin_popcount(x);

    printf("So %u co %d bit 1 trong bieu dien nhi phan.\n", x, count);
}