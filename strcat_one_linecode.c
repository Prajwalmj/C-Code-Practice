#include<stdio.h>

void my_strcat(char *dest, char *src){
    (*dest)? my_strcat(++dest, src): (*dest++=*src++)?my_strcat(dest, src): 0;
}

int main(){
    char dest[20] = "Prajwal";
    char source[] = " M J";
    my_strcat(dest, source);
    printf("%s", dest);
    return 0;

}