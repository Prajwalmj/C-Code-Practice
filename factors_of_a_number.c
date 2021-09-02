#include <stdio.h>
#include <math.h>
 
// function to print the divisors
void printDivisors(int n)
{
    for (int i = 1; i*i < n; i++) {
        if (n % i == 0)
            printf("%d ", i);
    }
    for (int i = sqrt(n); i >= 1; i--) {
        if (n % i == 0)
            printf("%d ", n / i);
    }
}
 
/* Driver program to test above function */
int main()
{
    printf("The divisors of 100 are: \n");
    printDivisors(20);
    return 0;
}