#include<stdio.h>

void print_array(int a[], int size){
    int i;
    for(i=0; i<size; i++)
        printf("%d \t", a[i]);
}

int main(){
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, n);
    return 0;
}