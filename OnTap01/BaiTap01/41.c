#include <stdio.h>

struct Packet
{
    unsigned char header;
    union
    {
        struct
        {
            unsigned int id : 4;
            unsigned int type : 3;
            unsigned int err : 1;
        } bits;
        unsigned char raw;
    } data;
};
int main(void)
{
    struct Packet pkt;
    printf("Size of struct Packet: %ld\n", sizeof(pkt));

    pkt.data.raw = 0xAB; // Example raw data

    printf("id = %u, type = %u, err = %u\n", pkt.data.bits.id, pkt.data.bits.type, pkt.data.bits.err);

    return 0;
}