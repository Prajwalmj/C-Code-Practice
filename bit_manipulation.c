#include<stdio.h>

int main(void){
    int n = 12, pos = 2;
    int mask = ~((1<<pos+1)-1);
    n &= mask;
    printf("%d\n", mask);
    printf("%d", n);
    return 0;
}