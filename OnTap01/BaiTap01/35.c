#include <stdio.h>

struct Inner
{
    char c;
    int d;
};

struct Outer
{
    int a;
    struct Inner in;
    char e[3];
};
int main(void)
{
    struct Outer var;
    printf("Size of struct Outer: %ld\n", sizeof(var));

    return 0;
}