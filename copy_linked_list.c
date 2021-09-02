  #include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void push(struct node **headref, int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if(!newNode){
        printf("No memory");
        return;
    }

    newNode->data = data;
    newNode->next = *headref;
    (*headref) = newNode;
}

struct node* copyList(struct node* head)
{
    struct node* current = head;    // used to iterate over the original list
    struct node* newList = NULL;    // head of the new list
    struct node* tail = NULL;       // point to the last node in a new list
 
    while (current != NULL)
    {
        // special case for the first new node
        if (newList == NULL)
        {
            push(&newList, current->data);
            tail = newList;
        }
        else {
            push(&(tail->next), current->data);        // add each node at the tail
            tail = tail->next;        // advance the tail to the new last node
        }
        current = current->next;
    }
 
    return newList;
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
    struct node *head_2 = NULL;

    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    print(head);

    struct node *copy = copyList(head);

    printf("\n Copy is: ");
    print(copy);


    return 0;
}