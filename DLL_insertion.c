#include<stdio.h>
#include<stdlib.h>

//Doubly linked list node creation
struct dllnode{
    int data;
    struct dllnode *next;
    struct dllnode *prev;
};

void push(struct dllnode **head_ref, int data){
    struct dllnode *newNode = (struct dllnode *) malloc(sizeof(struct dllnode *));
    if(!newNode){
        printf("Memory not allocated!!");
        return;
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head_ref;
    (*head_ref) = newNode;
    
}

void insert(struct dllnode **head_ref, int data, int position){
    int k = 1;
    struct dllnode *newNode = (struct dllnode *) malloc(sizeof(struct dllnode));

    newNode->data = data;
    newNode->prev = NULL;

    if(position==1){
        newNode->next = *head_ref;

        //if list is not empty
        if(*head_ref){
            (*head_ref)->prev = newNode;
        }
        (*head_ref) = newNode;
        return;
    }

    struct dllnode *temp = *head_ref;

    while ((k<position-1) && temp->next!=NULL)
    {
        temp = temp->next;
        k++;
    }
    newNode->next = temp->next;
    newNode->prev = temp;

    //if this is not a last node
    if(temp->next){
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void print(struct dllnode *temp){
    while (temp!=NULL)
    {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    
}

int main(void){
    struct dllnode *head = NULL;

    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    print(head);

    insert(&head, 5, 5);

    printf("\n");

     print(head);

    return 0;
}