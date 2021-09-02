#include<stdio.h>
#include<string.h>

int main(void){
    char str[3] = "MJ";
    //char str[] = {'M','J','\0'};
    for(int i=0; i<=strlen(str); i++)
        printf("%c \n", str[i]);
    return 0;
}