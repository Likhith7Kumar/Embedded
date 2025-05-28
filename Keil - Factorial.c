#include <reg51.h>

void main() 
{
    unsigned int i;
    unsigned char num = 12;
    unsigned long factorial = 1;  // factorial initialized properly

    for (i = 1; i <= num; i++) 
    {
        factorial *= i;
    }

    // Send factorial result to Ports P0–P3
    P0 = factorial & 0xFF;                      // LSB
    P1 = (factorial & 0xFF00) >> 8;
    P2 = (factorial & 0xFF0000) >> 16;
    P3 = (factorial & 0xFF000000) >> 24;        // MSB
}


output : 12! = 479001600 → In hex: 0x1C8CFC00

So:

Port	Value in Hex	Value in Decimal	Description
P3	0x1C	28	Most Significant Byte
P2	0x8C	140	
P1	0xFC	252	
P0	0x00	0	Least Significant Byte
