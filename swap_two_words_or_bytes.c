#include<stdio.h>
#include<stddef.h>

typedef unsigned short int uint_16t;

int main(void){
    uint_16t n = 0x1234;
    size_t ans = (char *)(&n+1) - (char *)(&n);
    //printf("%d", ans);
    uint_16t exch_n;
    uint_16t no_of_bits_half = (8*ans)/2;
    
    uint_16t mask = 0;
    mask = ~mask;

    uint_16t mask_1 = mask >> no_of_bits_half;
    uint_16t mask_2 = mask << no_of_bits_half;

    exch_n = ((n>>no_of_bits_half) & mask_1) | ((n<<no_of_bits_half) & mask_2);
    printf("Exchanged no is:%04X", exch_n);
    return 0;
}