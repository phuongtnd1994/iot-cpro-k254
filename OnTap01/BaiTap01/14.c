#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

void print_bits(unsigned int x)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (x >> i) & 1);
    }
}

bool check_is_mutiple_of_8(unsigned int x)
{
    return (x & 0b111) == 0;
}

int main()
{
    unsigned int tests[] = {8, 16, 24, 26, 31};

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        unsigned int x = tests[i];
        print_bits(x);
        if (check_is_mutiple_of_8(x))
        {
            printf(" (%u) la so chia het cho 8\n", x);
        }
        else
        {
            printf(" (%u) khong phai la so chia het cho 8\n", x);
        }
    }
}