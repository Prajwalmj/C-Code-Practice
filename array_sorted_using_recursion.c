#include<stdio.h>
//This code is not working, look into it
int isArraySorted(int a[], int n);

int main(void){
    int test[4] = {5,2,3,4};
    int ans = 1000;
    ans = isArraySorted(test, 4);
    printf("%d", ans);
    return 0;
}

int isArraySorted(int a[], int n){
    if(n==1||n==0){
        return 1;
    if(a[n-1]<a[n-2]){
        return 0;
    }
    return isArraySorted(a, n-1);
    }
}