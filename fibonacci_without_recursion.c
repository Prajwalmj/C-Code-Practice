#include<stdio.h>

int main(void){
    int n, first = 0, second = 1, ans;
    printf("Enter the limit \n");
    scanf("%d", &n);

    if(n==0){
        printf("%d", n);
        return 0;
    }
    else if(n==1){
        printf("%d, %d", first, second);
    }
    else{
        printf("%d, %d, ", first, second);
        while (second <n)
        {
            ans = first + second;
            printf("%d, ", ans);
            first = second;
            second = ans;
        }        
    }
    return 0;
}