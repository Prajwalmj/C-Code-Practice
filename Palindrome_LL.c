#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node *next;
};

void push(struct node **head_ref, char data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if(!newNode){
        printf("Memory is not allocated");
        return;
    }

    newNode->data = data;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

char pop(struct node **head_ref){
    //stack underflow exception
    if(!*head_ref){
        printf("Stack is empty! Don't do pop operation");
        return '!';
    }

    struct node *temp = *head_ref;

    char test = temp->data;
    *head_ref = temp->next;
    free(temp);

    return test;
}

void print(struct node *temp){
    while (temp!=NULL)
    {
        printf("%c \t", temp->data);
        temp = temp->next;
    }
    
}



int main(void){
    struct node *head1 = NULL;
    int result = 1;

    char *a = "reviver";
    int len = 0, i = 0;
    for( i=0; a[i]!='\0'; i++){
        push(&head1, a[i]);
        len++;
    }
    

    printf("The LL elements are : \n");
    print(head1);
    i = 0;
    while(i<=(len-1)){
        char ans = pop(&head1);
        //printf("\n %c",ans);
        if(ans==a[i]){
            i++;
            continue;
        }
        else{
            result = 0;
            break;
        }
    }

    if(!result){
        printf("\n Given LL is not a palindrome");
    }
    else{
        printf("\n Given LL is a palindrome");
    }

    return 0;    
}