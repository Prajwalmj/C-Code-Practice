#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int data;
    struct node *next;    
};


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

    int n = 12;
    //int i = 0;
    int pos = 1;
    for (int i = 1; i*i < n; i++) {
        if (n % i == 0)
            //printf("%d ", i);
            insertnode(&head, pos, i);
            pos++;
    }
    for (int i = sqrt(n); i >= 1; i--) {
        if (n % i == 0)
            //printf("%d ", n / i);
            insertnode(&head, pos, n/i);
            pos++;
    }

    printf("After insertion: \n");
    // insertnode(&head, 1, 5);
    // insertnode(&head, 2, 6);
    // insertnode(&head, 3, 7);

    print(head);
    return 0;
}