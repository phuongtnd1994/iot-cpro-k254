#include <stdio.h>

union Frame
{
    struct
    {
        unsigned short len : 10;
        unsigned short type : 3;
        unsigned short crc : 3;
    } info;

    struct
    {
        unsigned char low;
        unsigned char high;
    } bytes;
};

int main(void)
{
    // printf("Size of  unsigned short : %ld\n", sizeof(unsigned short));

    printf("Size of union Frame: %ld\n", sizeof(union Frame));

    union Frame frm = {.bytes = {0xAA, 0xBB}}; // 0xA35A

    printf("len = %u, type = %u, crc = %u\n", frm.info.len, frm.info.type, frm.info.crc);

    return 0;
}