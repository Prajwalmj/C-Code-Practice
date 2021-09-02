#include<stdio.h>
#include<stdlib.h>

struct node{
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

int get_nth(struct node* head, int index)
{
 
    struct node* current = head;
 
    int count = 0;
    while (current != NULL) {
        if (count == index-1)
            return (current->data);
        count++;
        current = current->next;
    }

    printf("Wrong position entered");
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

    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    print(head);
    printf("\n The nth element is : %d ", get_nth(head, 3));
    

    return 0;
}