
// Read modify write
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long uint32_t;

// This function will replace num of bits starting from LSB (least significant bit) position with data in the regData.
// For example: if the regData is 100, lsbPosition is 4, numOfBits is 4, data is 15 then your program should return 244.
uint32_t readModifyWrite(uint32_t regData, uint32_t lsbPosition, uint32_t numOfBits, uint32_t data)
{
    uint32_t mask = 0;
    data = data << lsbPosition;
    mask = ~mask;
    mask = mask << (lsbPosition + numOfBits);
    mask = ~mask;
    data &= mask; 
    return(regData|data);
}


/* Driver program to test above functions*/
int main()
{
    printf("Modified data is: %lu", readModifyWrite(100, 28, 16, 0xFF00));
    return 0;
}