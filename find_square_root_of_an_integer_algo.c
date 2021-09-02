#include<stdio.h>

//Binary search to make it efficient, but only for integers and will return floor value for non-perfect square
int main(){
    int n, ans;
    printf("Enter the no: \n");
    scanf("%d", &n);
    int beg = 1, end = n/2;

    while (beg<=end)
    {
        int mid = (beg+end)/2;
        if(mid*mid == n){
            ans = mid;
            break;          
        } 
        if(mid <= n/mid){
            beg = mid+1;
            ans = mid;
        }
        else
            end = mid - 1;
    }

    printf("The square root of %d is %d", n, ans);    
    return 0;
}
    