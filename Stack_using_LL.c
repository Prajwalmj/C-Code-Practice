#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

//Push operation
void push(struct node **head_ref, int data){    
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = *head_ref;

    *head_ref = newNode;
}

void pop(struct node **head_ref){
    if(!*head_ref){
        printf("LL is empty! Please don't pop");
        return;
    }

    struct node *temp = *head_ref;

    (*head_ref) = temp->next;
    free(temp); 
}

//Printing LL elements
void print(struct  node *head)
{
    struct node *temp = head;

    while (temp!=NULL)
    {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
}


int main(void){
    struct node *head = NULL;

    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printf("Linked List elements after pushing: \n");

    print(head);
    
    pop(&head);
    printf("\n LL after pop : ");
    print(head);

    pop(&head);
    printf("\n LL after pop : ");
    print(head);

    pop(&head);
    printf("\n LL after pop : ");
    print(head);

    pop(&head);
    printf("\n LL after pop : ");
    print(head);

    pop(&head);
    printf("\n LL after pop : ");
    print(head);
    
    print(head);



    return 0;
}