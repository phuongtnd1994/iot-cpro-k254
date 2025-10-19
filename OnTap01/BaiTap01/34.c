#include <stdio.h>

#pragma pack(push, 1)
struct B
{
    char a;
    int b;
    short c;
};
#pragma pack(pop)

int main()
{
    struct B var;
    printf("Size of struct B: %ld\n", sizeof(var));
    return 0;
}