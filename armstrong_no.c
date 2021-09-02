#include<stdio.h>

int main(void){

    int n, temp, sum = 0, rem;
    printf("Enter the number: \n");
    scanf("%d", &n);

    temp = n;
    while(temp){
        rem = temp%10;
        sum = sum + (rem*rem*rem);
        temp=temp/10;
    }
    if(sum==n){
        printf("%d is an Armstrong number", n);
    }
    else
        printf("%d is not an Armstrong number", n);
    return 0;
}