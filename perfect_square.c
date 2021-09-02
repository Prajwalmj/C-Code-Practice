#include<stdio.h>
#include<math.h>

int main(void){
    float n, fvar;
    int ivar;
    printf("Enter the number: \n");
    scanf("%f", &n);

    fvar = sqrt(n);
    ivar = fvar;
    printf("%d \n", ivar);
    if(ivar==fvar){
        printf("%f is perfect square", n);
    }
    else{
        printf("%f is not a perfect square", n);
    }
    return 0;
}