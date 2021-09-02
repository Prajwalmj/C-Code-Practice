#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node{
    int data;
    struct node *next;
};

//assuming position is always valid, assuming index starts from 1
//Function to push elements into Linked List
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

//Function to print linked list elements
void print(struct node *temp){
    while (temp!=NULL)
    {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    
}

//Function to compare if two linked lists are equal/same
bool compare_lists(struct node *temp1, struct node *temp2){
    while (temp1!=NULL && temp2!=NULL){
        if(temp1->data!=temp2->data){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return(temp1==NULL && temp2==NULL);  
    
}

//Function to copy one linked list to another
struct node* copyList(struct node* head)
{
    struct node* current = head;    // head of the original list
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

//Function to access nth element in the list, assuming index starting from 1
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

//replace or update nth element of linked list
void update(struct node **head_ref, int pos, int new_data){
    struct node *temp = *head_ref;
    int count = 1;
    while(temp!=NULL && count < pos){
        temp = temp->next;
        count++;
    }
    temp->data = new_data;
}

int main(int argc, char *argv[]){
    int num_of_cards = atoi(argv[1]);    //number of cards
    struct node* head = NULL;

    int start = 3, end = 5;
    int k = start;                       //number of piles
    int no_of_rounds = 0;
    struct node* temp_1 = NULL;
    struct node* temp_2 = NULL;

    //Simulating card numbers
    //printf("Cards are: \n");
    for(int i=0; i<num_of_cards; i++){
        push(&head, num_of_cards-i);
        push(&temp_1, num_of_cards-i);  //copy of original cards
        push(&temp_2, 0);
    }
    //print(head);  

    int cards_per_pile = num_of_cards/k; 
    int i = 1, j = 0;

    while (!(compare_lists(head, temp_2)))
    {
        if(k==start){                   //Number of piles = 3
            j = cards_per_pile;
            i = 1;
            while (i<=num_of_cards)
            {   
                int temp_data = get_nth(temp_1, i);
                if(i%k==1){
                    update(&temp_2, j, temp_data);
                }
                else if(i%k==2){
                    update(&temp_2, j+cards_per_pile, temp_data);
                }
                else if(i%k==0){
                    update(&temp_2, j+(2*cards_per_pile), temp_data);
                    j--;
                }
                i++;
            }
            //printf("\n Piles: %d \n", k);
            //print(temp_2);

            k++;
            cards_per_pile = num_of_cards/k;            
        }
        else if(k==start+1){            //Number of piles = 4
            j = cards_per_pile;
            i=1;
            while (i<=num_of_cards)
            {   
                int temp_data = get_nth(temp_1, i);
                if(i%k==1){
                    update(&temp_2, j, temp_data);
                }
                else if(i%k==2){
                    update(&temp_2, j+cards_per_pile, temp_data);
                }
                else if(i%k==3){
                    update(&temp_2, j+(2*cards_per_pile), temp_data);
                }                
                else if(i%k==0){
                    update(&temp_2, j+(3*cards_per_pile), temp_data);
                    j--;
                }
                i++;
            }
            //printf("\n Piles: %d \n", k);
            //print(temp_2);

            k++;
            cards_per_pile = num_of_cards/k;
        }
        else if(k==end){            //Number of piles = 5
            j = cards_per_pile;
            i=1;
            while (i<=num_of_cards)
            {   
                int temp_data = get_nth(temp_1, i);
                if(i%k==1){
                    update(&temp_2, j, temp_data);
                }
                else if(i%k==2){
                    update(&temp_2, j+cards_per_pile, temp_data);
                }
                else if(i%k==3){
                    update(&temp_2, j+(2*cards_per_pile), temp_data);
                }
                else if(i%k==4){
                    update(&temp_2, j+(3*cards_per_pile), temp_data);
                }                
                else if(i%k==0){
                    update(&temp_2, j+(4*cards_per_pile), temp_data);
                    j--;
                }
                i++;
            }
            //printf("\n Piles: %d \n", k);
            //print(temp_2);

            k = start;
            cards_per_pile = num_of_cards/k;
        }

    
       //Copy the updated list deck order
       temp_1 = copyList(temp_2);
       no_of_rounds++;
    }

    printf("No of rounds = %d", no_of_rounds);
    return 0;
}
//Please uncomment lines 145, 146, 172, 173, 202, 203 to see the deck order 
//in every rounds for different number of piles