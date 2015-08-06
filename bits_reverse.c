
#include "../inc/bit_reverse.h"

// 位反转，MSB->LSB
// 实现一个字节的位反转
unsigned char BitsReverse8(unsigned char x)
{
    x = (((x & 0xaa) >> 1) | ((x & 0x55) << 1));
    x = (((x & 0xcc) >> 2) | ((x & 0x33) << 2));
    //x = (((x & 0xf0) >> 4) | ((x & 0x0f) << 4));
    //x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
    return((x >> 4) | (x << 4));
 
}

// 位反转，MSB->LSB
// 实现一个字节的位反转
unsigned int BitsReverse32(unsigned int x)
{
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
    x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
    return((x >> 16) | (x << 16));
}

