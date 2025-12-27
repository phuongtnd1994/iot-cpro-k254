#include <stdio.h>

void print_bits(unsigned int x)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (x >> i) & 1);
    }
}

int main()
{
    unsigned x = 120;
    unsigned y = 16;

    if (x != 0 && (x & (x - 1)) == 0)
    {
        printf("%d la so luy thua 2", x);
    }
    else
    {
        printf("%d khong la so luy thua 2 ", x);
    }

    if (y != 0 && (y & (y - 1)) == 0)
    {
        printf("%d la so luy thua 2", y);
    }
    else
    {
        printf("%d khong phai la la so luy thua 2", y);
    }
}