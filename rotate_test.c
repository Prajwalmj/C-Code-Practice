#include<stdio.h>

int main(void){
    int n = 16, temp, ans_left, ans_right;
    int no_of_bits = sizeof(int) * 8;
    int shift_left = 2;
    int shift_right = 2;
    //temp = n << shift_left;
    ans_left = (n << shift_left) | (n>>(no_of_bits-shift_left));
    ans_right = (n >> shift_right) | (n<<(no_of_bits-shift_right));
    printf("values after shifting are: %d \t %d", ans_left, ans_right);
    return 0;
}