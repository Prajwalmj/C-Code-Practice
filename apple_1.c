#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node *next;
};

int compare_array(int a[], int b[], int n){
    for(int i=0; i<n; i++){
        if(a[i]!=b[i]){
            return 0;
        }    
    }
    return 1;
}

int main(void){
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int b[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int *temp = (int *)malloc(12*sizeof(int));

    int n = 12;
    int k = 3;
    int j = 0;

    int ele_per_pile = n/k;
    int count  = 0;
    while (!compare_array(temp, b, 12))
    {
        if(k==3){
            j = ele_per_pile-1;
            for(int i=0; i<n; i++){
                if((i+1)%k==1){
                    temp[j] = a[i];
                }
                else if((i+1)%k==2){
                    temp[j+(ele_per_pile)] = a[i];
                 }
                else if(((i+1)%k==0)){
                    temp[j+(2*ele_per_pile)] = a[i];
                }
                if((i+1)%k==0){
                    j--;
                }
            }
            printf("\n Piles: %d \n", k);
            for(int i=0; i<12; i++){
                printf("%d \t", temp[i]);
            }
        k = 4;
        ele_per_pile = n/k;
        }
        else if(k==4){
            j = ele_per_pile-1;
            for(int i=0; i<n; i++){
                if((i+1)%k==1){
                    temp[j] = a[i];
                }
                else if((i+1)%k==2){
                    temp[j+(ele_per_pile)] = a[i];
                }
                else if((i+1)%k==3){
                    temp[j+(2*ele_per_pile)] = a[i];
                }
                else if(((i+1)%k==0)){
                    temp[j+(3*ele_per_pile)] = a[i];
                }
                if((i+1)%k==0){
                    j--;
                }
            }
            printf("\n Piles: %d \n", k);
            for(int i=0; i<12; i++){
                printf("%d \t", temp[i]);
            }
        k = 6;
        ele_per_pile = n/k;
        }
        else if(k==6){
            j = ele_per_pile-1;
            for(int i=0; i<n; i++){
                if((i+1)%k==1){
                    temp[j] = a[i];
                }
                else if((i+1)%k==2){
                    temp[j+(ele_per_pile)] = a[i];
                }
                else if((i+1)%k==3){
                    temp[j+(2*ele_per_pile)] = a[i];
                }
                else if((i+1)%k==4){
                    temp[j+(3*ele_per_pile)] = a[i];
                }
                else if((i+1)%k==5){
                    temp[j+(4*ele_per_pile)] = a[i];
                }
                else if(((i+1)%k==0)){
                    temp[j+(5*ele_per_pile)] = a[i];
                }
                if((i+1)%k==0){
                    j--;
                }
            }
            printf("\n Piles: %d \n", k);
            for(int i=0; i<12; i++){
                printf("%d \t", temp[i]);
            }
        k = 3;
        ele_per_pile = n/k;
        }
        //updating the array after shuffle
        for(int i=0; i<12; i++){
            a[i] = temp[i];
        }
        count++;
    }

    printf("No of rounds = %d", count);
    return 0;
}