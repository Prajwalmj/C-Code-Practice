#include<stdio.h>

int main(void){
    int n = 0xA;
    int x = 1, y = 2;

    int bit_x = (n >> x) & 1;  //Extract bits
    int bit_y = (n >> y) & 1;

    int bit_xor = bit_x ^ bit_y;  //Perform xor

    int ans  = n ^ (bit_xor << x) | (bit_xor << y);
    printf("%d", ans);
}