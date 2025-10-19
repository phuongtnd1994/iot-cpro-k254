#include <stdio.h>
union Config
{
    struct
    {
        unsigned int enable : 1;
        unsigned int speed : 2;
        unsigned int mode : 3;
    } normal;

    struct
    {
        unsigned int secure : 1;
        unsigned int key : 7;
    } security;
};

int main(void)
{
    union Config cfg;

    printf("Size of union Config: %ld\n", sizeof(cfg));

    return 0;
}