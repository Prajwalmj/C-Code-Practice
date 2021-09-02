#include<stdio.h>
#include<stddef.h>

int main(){
    int a;
    //char *ptr = &a;
    int b;
    size_t size = (char*)(&a+1)-(char*)(&a);
    printf("the size of data type is: %d", size);
    return 0;
}