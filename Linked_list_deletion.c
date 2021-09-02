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

void delete_node(struct node **head_ref, int position){
    struct node *p, *q;
    int k = 1;

    p = *head_ref;
    //head node deletion case
    if(position==1){
        *head_ref = p->next;
        free(p);               //deleting dynamically created node
    }

    else{
        while ((p!=NULL) && (k<position))
        {
            q = p;
            p = p->next;
            k++;
        }

        if(p==NULL){
            printf("\n Wrong position entered: \n");
        }
        else{
        q->next = p->next;
        free(p);
        }
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
    push(&head,5);

    printf("Nodes before deletion: \n");
    print(head);

    delete_node(&head, 6);
    printf("\n Nodes after deletion: \n");
    print(head);

}