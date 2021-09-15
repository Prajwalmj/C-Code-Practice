#include <stdio.h>

int CountZeros(int n){
    int count
    while (n)
    {
        count++;
        n = n & (n-1);
    }

    return(32-n);
    

}

int main(void){
    
    return 0;
}