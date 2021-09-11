#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void push(struct node **head_ref, int data){
    struct node *newNode = (struct node *) malloc(sizeof(struct node));

    if(!newNode){
        printf("No memory!");
        return;
    }

    newNode->data = data;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

struct node *ReverseLL(struct node *head_ref){
    struct node *nextNode, *prevNode;
    nextNode = prevNode = NULL;

    while(head_ref){
        nextNode = head_ref->next;
        head_ref->next = prevNode;
        prevNode = head_ref;
        head_ref = nextNode;
    }
    return prevNode;
}

void print(struct node *temp){
    while(temp!=NULL){
        printf("%d \t", temp->data);
        temp = temp->next;
    }
}

int main(void){
    struct node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    printf("The LL elements are: \n");
    print(head);

    struct node *head_reverse = NULL;

    head_reverse = ReverseLL(head);

    printf("\n The reversed LL elements are: \n");
    print(head_reverse);
    return 0;
}