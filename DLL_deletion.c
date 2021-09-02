#include<stdio.h>
#include<stdlib.h>

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
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}

void delete(struct dllnode **head_ref, int position){
    struct dllnode *temp2, *temp1;
    temp1 = *head_ref;
    int k=1;
    
    if(*head_ref==NULL){
        printf("List is empty");
        return;
    }
    
    if(position==1){
        *head_ref = (*head_ref)->next;

        if(*head_ref!=NULL){
            (*head_ref)->prev = NULL;
            free(temp1); 
            return;
        }
    }
    //printf("It's here");
    while ((k<(position)) && (temp1->next!=NULL))
    {
        temp1 = temp1->next;
        k++;
    }
    temp2 = temp1->prev;
        
    temp2->next = temp1->next;
    //if not a last node
    if(temp1->next){
        temp1->next->prev = temp2;
    }
    free(temp1);
    return;
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

    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Before deletion: \n");
    print(head);

    //delete(&head, 3);

    printf("After deletion: \n");
    print(head);

    return 0;
}