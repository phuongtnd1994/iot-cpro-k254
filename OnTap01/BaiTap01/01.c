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
    unsigned int x = 0b00000101;
    int n = 3;

    printf("Truoc khi bat bit %d: 0b", n);
    print_bits(x);

    x |= (1u << n);

    printf("Sau khi bat bit %d: 0b", n);
    print_bits(x);
    printf(" (%u)\n", x);

    return 0;
}