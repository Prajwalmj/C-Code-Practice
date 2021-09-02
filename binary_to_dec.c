#include<stdio.h>

int main(void){
    int n, temp, base=1, digit, ans = 0;
    printf("Enter the binary number \n");
    scanf("%d", &n);

    temp = n;
    while (temp)
    {
        digit = temp%10;
        temp = temp/10;
        
        ans+= digit*base;
        base = base*2;
    }
    printf("Decimal value is %d", ans);    
    return 0;
}