#include <stdio.h>

struct
{
    int a;
    char b;
} ab;

#pragma pack(push, 1)
struct
{
    char a;
    int b;
} ba;
#pragma pack(pop)

int main(void)
{
    printf("Size of struct ab: %ld\n", sizeof(ab));
    printf("Size of struct ba: %ld\n", sizeof(ba));
}