#include<stdio.h>
#include<stdlib.h>


int main(void){
    int n = 5;
    //int *ptr = (int *) malloc(n*sizeof(int));
    int *ptr = (int *) calloc(n, sizeof(int));
    for(int i=0; i<n; i++){
        ptr[i] = i;
    }
    for(int i=0; i<n; i++){
        printf("%d \t",ptr[i]);
    }
    ptr = realloc(ptr, 10);
    for(int i=5; i<10; i++){
        ptr[i] = i;
    }
    for(int i=0; i<10; i++){
        printf("\n %d \t",ptr[i]);
    }

    free(ptr);
    return 0;
}