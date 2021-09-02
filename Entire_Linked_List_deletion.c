#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;    
};

void push(struct node **head_ref, int data){
    struct node* newNode = (struct node*) malloc (sizeof(struct node *));

    if(!newNode){
        printf("No memory");
        return;
    }

    newNode->data = data;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

void print(struct node * temp){

    if(temp==NULL){
        printf("\nLinked List is empty \n");
        return;
    }
    while (temp!=NULL)
    {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    
}

void DeleteList(struct node **headref){
    struct node *p, *q;

    p = *headref; 
    while (p!=NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    *headref = NULL;
}

int main(void){
    struct node *head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);

    printf("Entire Linked List b4 deletion: \n");
    print(head);

    DeleteList(&head);

    printf("\nEntire Linked List after deletion: \n");
    print(head);

}