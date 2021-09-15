#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

struct ArrayStack{
    int top;
    int capacity;
    int *array;
};

struct ArrayStack *CreateStack(){
    struct ArrayStack *S = (struct ArrayStack *) malloc(sizeof(struct ArrayStack));
    if(!S){
        return NULL;
    }

    S->top = -1;
    S->capacity = MAXSIZE;

    S->array = malloc(S->capacity*sizeof(int));

    if(!S->array){
        return NULL;
    }
    return S;
}

int IsStackFull(struct ArrayStack *S){
    return(S->top==S->capacity-1);
}

int ISStackEmpty(struct ArrayStack *S){
    return(S->top==-1);
}

void Push(struct ArrayStack *S, int data){
    if(IsStackFull(S)){
        printf("Stack Overflow! Can't Push");
    }
    else{
        S->array[++S->top] = data;
    }
}

int Pop(struct ArrayStack *S){
    if(ISStackEmpty(S)){
        printf("Stack Underflow! Can't Pop");
        return -1;
    }
    else{
        return(S->array[S->top--]);
    }
}

int main(void){
    struct ArrayStack *Stack = NULL;
    int stackData[MAXSIZE];

    Stack = CreateStack();

    Push(Stack, 4);
    Push(Stack, 3);
    Push(Stack, 2);
    Push(Stack, 1);
    printf("The Stack data are: \n");
    for(int i = 0; i<=3; i++){
        stackData[i] = Pop(Stack);
        printf(" \t %d:", stackData[i]);
    }

    return 0;
}