#include<stdio.h>

void print_array(int arr[], int n);
char a[4];

void print_array(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d \t", arr[i]);
    }    
}

void Binary(int n){
    if(n<1){
        //print_array(a, n);
        printf("%s \t", a);
    }
    else{
        a[n-1] = '0';
        Binary(n-1);

        a[n-1] = '1';
        Binary(n-1);
    }
}

int main(void){
    int n = 4;
    Binary(n);
    return 0;
}