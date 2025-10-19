#include <stdio.h>

union data
{
    int a;
    char b;
} ab;

int main(void)
{
    ab.a = 64;
    ab.a = 2500; // 0x09C4

    printf("%d", ab.b);
}