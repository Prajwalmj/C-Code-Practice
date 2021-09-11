#include<stdio.h>

void function(int *temp1){
    int temp2;
    if(temp1<&temp2){
        printf("Stack grows upwards");
    }
    else{
        printf("Stack grows downwards");
    }

}

int main(void){

    int local = 0;
    function(&local);
    
    return 0;
}