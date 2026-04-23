#include "queue.h"
#include <stdlib.h>

Queue *queue_create(){
    
    Queue *p = malloc(sizeof(Queue));

    if (p == NULL){
        return NULL;
    }

    p -> head = NULL;
    p -> tail = NULL;
    p -> size = 0;

    return p;
}

int queue_size(Queue *queue){

    if (queue==NULL){
        return 0;
    }
    
    int value = queue -> size;
    return value;
}

void queue_enqueue(Queue *queue, void *data){

    QueueNode *newNode = malloc(sizeof(QueueNode));
    
    if (newNode == NULL){
        return;
    }

    newNode -> data = data;
    newNode -> next = NULL;

    if (queue ->size == 0){

        queue -> head = newNode;
        queue -> tail = newNode;
    }
    
    else{

        queue -> tail -> next = newNode;
        queue -> tail = newNode;
    }

    queue -> size++;
}

void *queue_dequeue(Queue *queue){

    if (queue == NULL || queue -> size == 0){
        return NULL;
    }

    QueueNode *NodeToRemove = queue -> head;
    void *data = NodeToRemove->data;
    QueueNode *NextNode = NodeToRemove -> next;
    free(queue->head);
    queue -> head = NextNode;
    queue -> size--;

    if (queue -> head == NULL){

        queue -> tail = NULL;
    }

    return data;
}

void queue_destroy(Queue *queue){

    if (queue == NULL || queue -> size == 0){
        return;
    }

    while (queue -> size != 0){

        queue_dequeue(queue);
    }
}