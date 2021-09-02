#include<stdio.h>

int main(void){
    int a = 100, b = 20;
    printf("Before swapping, values are: %d \t %d \n", a, b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("After swapping, values are: %d \t %d", a, b);
}