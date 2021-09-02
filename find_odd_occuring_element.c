#include<stdio.h>

int main(void){
    int i, res = 0;
    int arr[] = { 12, 12, 14, 90, 14, 14, 14 };
    for(i=0; i<7; i++){
        res = res ^ arr[i];
    }
    printf("The odd occuring element is: %d", res);
    return 0;
}