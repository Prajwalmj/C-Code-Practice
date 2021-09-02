#include<stdio.h>
#include<stdlib.h>

int main(){
    int i;
    srand(1);
    for(i=0; i<4; i++)
        printf("%d \n", rand());
    return 0;
}