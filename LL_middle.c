#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void push(struct node **head_ref, int data){
    struct node *newNode = (struct node *) malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

int FindMiddleLL(struct node *head_ref){
    struct node *slowptr, *fastptr;
    slowptr = fastptr = head_ref;
    int i = 0;

    while (fastptr->next!=NULL)
    {
        if(i==0){
            fastptr = fastptr->next;
            i = 1;
        }
        else if(i==1){
            fastptr = fastptr->next;
            slowptr = slowptr->next;
            i = 0;
        }
    }
    return slowptr->data;
}

void print(struct node *temp){
    while (temp!=NULL)
    {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    
}

int main(void){
    struct node *head = NULL;

    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("The LL elements are: \n");
    print(head);

    printf("\n The middle element is: \t %d ", FindMiddleLL(head));
    return 0;
}