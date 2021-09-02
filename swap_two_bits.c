#include<stdio.h>

int main(void){
    int n = 0xA;
    int x = 1, y = 2;

    //bit extraction
    int bit_x = n & (1<<x);
    int bit_y = n & (1<<y);
    
    printf("Bits to be exchanged are: %d, %d \n", bit_x, bit_y);
    //clearing the bit positions
    n &= ~(1<<x);
    n &= ~(1<<y);
    
    bit_x <<= (y-x);
    bit_y >>= (y-x);

    n |= bit_x;
    n |= bit_y;

    printf("%d", n);

    return 0;
}