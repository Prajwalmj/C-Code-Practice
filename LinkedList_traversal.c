#include<stdio.h>
#include<stdlib.h>

//Linked List node 
struct Listnode{
    int data;
    struct Listnode *next;
};

//Head and tail pointer defintion
struct Listnode *head, *tail = NULL;

int FindLength(){
    struct Listnode *current = head;
    int count = 0;
    while (current->next!=NULL)
    {
        count++;
        current = current->next;
    }
    return count;
    
}

//Insert node function
void addnode(int data){
    struct Listnode *newNode = (struct Listnode*) malloc(sizeof(struct Listnode));
    newNode->data = data;
    newNode->next = NULL;

    if(head==NULL){
        //First node insertion case
        head = newNode;
        tail = newNode;
    }
    else{
        //insertion at the last
        tail->next = newNode;
        tail = newNode;
    }
}

void display(){
    struct Listnode *current = head;
    
    //Check if list is empty?!
    if(head==NULL){
        printf("List is empty");
        return;
    }
    //travrese till last node inclusive
    while(current!=NULL){
        printf("%d \t", current->data);
        current = current->next;
    }
}


int main(void){
    addnode(1);
    addnode(2);
    addnode(3);
    addnode(4);

    display();

    printf("\n The length of linked list is:%d", FindLength());

    return 0;

}