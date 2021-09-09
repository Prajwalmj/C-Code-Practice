#include<stdio.h>
#include<stdlib.h>

struct CLLnode{
    int data;
    struct CLLnode *next;
};

//Deletion there is some issue, look into it when free 
void InsertBegin(struct CLLnode **head_ref, int data){
    struct CLLnode *newNode = (struct CLLnode *)malloc(sizeof(struct CLLnode));

    newNode->data = data;
    newNode->next = newNode;

    if(!*head_ref){
        *head_ref = newNode;
        return;
    }

    struct CLLnode *p = *head_ref;

    while (p->next!=*head_ref)
    {
        p = p->next;
    }

    newNode->next = *head_ref;
    p->next = newNode;
    *head_ref = newNode;
}

void DeleteBegin(struct CLLnode **head_ref){
    if(*head_ref == NULL){
        printf("List is empty");
        return;
    }

    struct CLLnode *p = *head_ref;
    struct CLLnode *q = *head_ref;

    while (q->next!=*head_ref)
    {
        q = q->next;
    }

    q->next = (*head_ref)->next;
    *head_ref = (*head_ref)->next;
    free(p);    
}

void print(struct CLLnode *head_ref){
    struct CLLnode *temp = head_ref;
    do{
        printf("%d \t", temp->data);
        temp = temp->next;

    }while(temp!=head_ref);

}
int main(void){
    struct CLLnode *head = NULL;

    InsertBegin(&head, 5);
    InsertBegin(&head, 4);
    InsertBegin(&head, 3);
    InsertBegin(&head, 2);
    InsertBegin(&head, 1);

    print(head);  

    DeleteBegin(&head);
    printf("\n LL after deletion : \t ");
    print(head);

    DeleteBegin(&head);
    printf("\n LL after deletion : \t ");
    print(head);

    DeleteBegin(&head);
    printf("\n LL after deletion : \t ");
    print(head);

    DeleteBegin(&head);
    printf("\n LL after deletion : \t ");
    print(head);

    DeleteBegin(&head);
    printf("\n LL after deletion : \t ");
    print(head);

    return 0;
}