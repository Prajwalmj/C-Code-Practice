#include<stdio.h>

int main(void){
    int n;
    printf("Enter the number in decimal \n");
    scanf("%d", &n);

    int temp = n;
    int arr[32];
    
    int i = 0;

    while ((temp!=1) && (temp!=0))
    {
        arr[i] = temp%2;
        temp = temp/2;
        i++;
    }
    arr[i] = temp;
    int count = i;

    for (i = count; i >= 0; i--)
    {   
        printf("%d", arr[i]);
    }        
    return 0;
}