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

//assuming position is always valid, assuming index starts from 1
void insertnode(struct node **head_ref, int pos, int data){
    struct node *p,*q;
    struct node *newNode = (struct node *) malloc(sizeof(struct node));

    int k = 0;

    newNode->data = data;

    p = *head_ref;

    if(pos==1){
        newNode->next = p;
        (*head_ref) = newNode;
    }
    else{
        while ((p!=NULL) && (k<(pos-1)))
        {
            k++;
            q = p;
            p = p->next;
        }
        newNode->next = p;
        q->next = newNode; 
    }
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

    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);

    printf("Before insertion: \n");
    print(head);

    printf("After insertion: \n");
    insertnode(&head, 3, 5);

    print(head);
    return 0;
}