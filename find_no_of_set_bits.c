#include<stdio.h>

int main(void){
    int n = 12, temp = 0;
    int no_of_bits = 4*sizeof(n);
    //printf("%d", sizeof(n));
    int count = 0;
    for(int i=0; i<no_of_bits; i++){
        temp = n & (1<<i);
        if(temp){
            count++;
        }        
    }
    printf("%d", count);
    return 0;
}