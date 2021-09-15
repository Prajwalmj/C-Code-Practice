#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void push(struct node **head_ref, int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if(!newNode){
        printf("No memory");
        return;
    }

    newNode->data = data;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

void print(struct node *head){
    struct node *temp = head;

    while(temp){
        printf("\t %d", temp->data);
        temp = temp->next;
    }
}

int main(void){
    struct node *head = NULL;

    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("The LL elements are: ");
    print(head);

    return 0;
}