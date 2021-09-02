#include<stdio.h>

//Simplest method to understand!!
int main(void){
    int arr[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    int i, k = 0, l = 0; //starting index for row, column
    int m =4, n=4;       //ending index for row, column
    
    while (k<=m && l<=n)
    {
        //move right
        for(i=l; i<n; i++){
            printf("%d \t", arr[k][i]);
        }
        k++;    //Increase current row (basically reducing visited row)

        //move down
        for(i=k; i<m; i++){
            printf("%d \t", arr[i][n-1]);
        }
        n--;    //Decrease max column (basically reducing visited column)

        //move left
        if(k<m){
            for(i=n-1; i>=l; i--){
                printf("%d \t", arr[m-1][i]);
            }
            m--; //decrease max row (basically reducing visited row at bottom)
        }
        //move up
        if(l<n){
            for(i=m-1; i>=k; i--){
                printf("%d \t", arr[i][l]);
            }
            l++; //increase current column (basically reducing visited column at left)
        }
    }    
    return 0;
}