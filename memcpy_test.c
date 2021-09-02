#include<stdio.h>
#include<string.h>

int main(void){
    char str1[] = "Testing now!";
    char str2[] = "Testing done!";

    //char *first = 

    printf("Before memcpy: %s \n", str1);

    memcpy(str1, str2+7, 5);

    printf("After memcpy: %s", str1);
    printf("\n %s", str2);
    return 0;
}