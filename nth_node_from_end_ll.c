#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void push(struct node **head_ref, int data){
    struct node *newNode = (struct node *) malloc(sizeof(struct node));

    if(!newNode){
        printf("Memory not allocated");
    }

    newNode->data = data;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

int nthNodeFromEnd(struct node *head_ref, int nthNode){
    struct node *temp1, *temp2 = NULL;

    while(nthNode){
        
        if(!temp2){
            temp2 = head_ref;
        }
        else{
            temp2 = temp2->next;
        }

        nthNode--;

        if(!temp2){
            printf("\n Wrong query, please enter correct number");
            return 0;
        }
    }    

    temp1 = head_ref;

    while (temp2->next!=NULL)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return temp1->data;
    
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

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);
    push(&head, 9);
    push(&head, 10);
    push(&head, 11);

    printf("The linked list elements are : \n ");
    print(head);

    int nodeNo = 12;

    int ans = nthNodeFromEnd(head, nodeNo);

    if(!ans){
        return 0;
    }
    else{
        printf("\n The %d th node from end of list is : %d ", nodeNo, ans);
    }


    return 0;
}