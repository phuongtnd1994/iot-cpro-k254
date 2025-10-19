#include <stdio.h>

struct Flags
{
    unsigned int a : 1;
    unsigned int b : 3;
    unsigned int c : 4;
};

int main(void)
{
    struct Flags flag;

    flag.a = 1;

    printf("sizeof unsigned int: %ld\n", sizeof(unsigned int));

    printf("Size of struct Flags: %ld\n", sizeof(flag));

    return 0;
}