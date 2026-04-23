#include "stack.h"
#include <stdlib.h>

Stack stack_create(){

}

int stack_size(Stack *stack){

    Stack *p = malloc(sizeof(Stack));

    if (p==NULL){
        return NULL;
    }

    p -> head = NULL;
    p -> tail = NULL;
    p -> size = NULL;

    return p;
}

void stack_push(Stack *stack, void *data){

}

void *stack_pop(stack *stack){

}

void stack_destroy(Stack *stack){

}