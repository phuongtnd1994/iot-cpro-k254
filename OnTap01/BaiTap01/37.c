#include <stdio.h>

union Data
{
    int i;
    char c[4];
};

struct Test
{
    char flag;
    union Data data;
};

int main()
{
    printf("Size of struct Test: %ld\n", sizeof(struct Test));
}