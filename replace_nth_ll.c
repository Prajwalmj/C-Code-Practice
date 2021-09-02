#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;    
};

void push(struct node **head_ref, int data){
    struct node *newNode = (struct node *) malloc(sizeof(struct node));

    if(!newNode){
        printf("No memory");
        return;
    }

    newNode->data = data;
    newNode->next = *head_ref;
    (*head_ref) = newNode;

}

void update(struct node **head_ref, int pos, int new_data){
    struct node *temp = *head_ref;
    int count = 1;
    while(temp!=NULL && count < pos){
        temp = temp->next;
        count++;
    }
    temp->data = new_data;
}



void print(struct node *temp){
    while (temp!=NULL)
    {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    
}



int main(void){
    struct node* head = NULL;

    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);

    printf("Before replacing: \n");
    print(head);

    update(&head, 3, 6);

    printf("\n After replacing: \n");
    

    print(head);
    return 0;
}