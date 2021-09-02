#include<stdio.h>

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

}
int main(void){
    int a = 10, b= 25;
    printf("Values before swapping = %d \n %d \n", a, b);
    swap(&a, &b);
    printf("Values after swapping = %d \n %d", a, b);
    return 0;
}