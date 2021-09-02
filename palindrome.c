#include<stdio.h>

//idea - calculate revesrse of no, compare it with original
int main(){
    int n;
    int rev = 0, temp, rem;
    printf("Enter the no: \n");
    scanf("%d", &n);
    temp = n;
    while(temp){
        rem = temp % 10;
        rev = rev * 10 + rem;
        temp = temp/10;
    }
    if(rev==n){
        printf("\n%d is a palidrome",n);
    }
    else{
        printf("%d is not a palidrome",n);
    }
    return 0;
}