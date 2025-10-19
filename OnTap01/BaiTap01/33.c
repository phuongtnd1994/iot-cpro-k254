#include <stdio.h>

struct A
{
    char a;
    int b;
    short c;
};

int main(void)
{
    struct A var;
    printf("Size of short: %ld\n", sizeof(short));
    printf("Size of struct A: %ld\n", sizeof(var));
}