#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node *next;
};

//using arrays

int compare_array(int a[], int b[], int n){
    for(int i=0; i<n; i++){
        if(a[i]!=b[i]){
            return 0;
        }    
    }
    return 1;
}

int main(void){
    int a[180]; 
    int b[180];
    int no_of_cards = 180;

    int *temp = (int *)malloc(no_of_cards*sizeof(int));

    for(int i=0; i<no_of_cards; i++){
        a[i] = i+1;
        b[i] = i+1;
    }

    int start = 3;
    int end = 5;

    int k = start;    //no of piles
    int j = 0;

    int ele_per_pile = no_of_cards/k;
    int count  = 0;
    while (!compare_array(temp, b, 60))
    {
        if(k==3){
            j = ele_per_pile-1;
            for(int i=0; i<no_of_cards; i++){
                //if(a[i]==22){printf("Here");}
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
            for(int i=0; i<no_of_cards; i++){
                printf("%d \t", temp[i]);
            }
        k++;
        ele_per_pile = no_of_cards/k;
        }
        else if(k==4){
            j = ele_per_pile-1;
            for(int i=0; i<no_of_cards; i++){
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
            for(int i=0; i<no_of_cards; i++){
                printf("%d \t", temp[i]);
            }
        k++;
        ele_per_pile = no_of_cards/k;
        }
        else if(k==5){
            j = ele_per_pile-1;
            for(int i=0; i<no_of_cards; i++){
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
                else if(((i+1)%k==0)){
                    temp[j+(4*ele_per_pile)] = a[i];
                }
                if((i+1)%k==0){
                    j--;
                }
            }
            printf("\n Piles: %d \n", k);
            for(int i=0; i<no_of_cards; i++){
                printf("%d \t", temp[i]);
            }
        k = start;
        ele_per_pile = no_of_cards/k;
        }
        //updating the array after shuffle
        for(int i=0; i<no_of_cards; i++){
            a[i] = temp[i];
        }
        count++;
        //if(count==1){break;}
    }

    printf("\n No of rounds = %d", count);
    return 0;
}