#include<stdio.h>

int main(void){
    int no, flag = 0, i;
    no = 21;
    if(no==1 || no==2){
        printf("%d is not prime", no);
        flag = 1;
    }
    else if(!flag){
        for(i=2; i<(no/2); i++){
            if((no%i)==0){
                flag = 1;
            }
        }
    }
    if(flag)
        printf("%d is not prime", no);
    else
        printf("%d is prime", no);
    return 0;
}