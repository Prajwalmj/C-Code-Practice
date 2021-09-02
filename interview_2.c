// A complete working C program to delete a node in a linked list
// at a given position
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
    int data;
    struct Node *next;
};

/* Given a reference (pointer to pointer) to the head of a list
and an int inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Given a reference (pointer to pointer) to the head of a list
and a position, deletes the node at the given position */
void deleteNode(struct Node **head_ref, int position)
{   
    int count = 0, length = 0;
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp = *head_ref;
    while (temp!=NULL)
    {
        temp=temp->next;
        length++;   
    }
    if(position>length){
        printf("Entered position not valid");
        return;
    }
    temp = *head_ref;
    if(position==0){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(count!=(position-1) && temp!=NULL){
        temp = temp->next;
        count++;
    }
    if(count == (position-1)){
        temp->next = temp->next->next;
    }
    //free(temp);

}

// This function prints contents of linked list starting from
// the given node
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

/* Driver program to test above functions*/
int main()
{
/* Start with the empty list */
struct Node* head = NULL;

push(&head, 7);
push(&head, 1);
push(&head, 3);
push(&head, 2);
push(&head, 8);

printf ("Created Linked List: ");
printList(head);
deleteNode(&head, 4);
printf ("\nLinked List after Deletion at position 4: ");
printList(head);
push(&head, 1);
printf ("\nLinked List after Deletion at position 4: ");
printList(head);
return 0;
}