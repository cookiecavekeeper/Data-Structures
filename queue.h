//
// Created by Paul Sonnenschein on 15.06.15.
//

#ifndef DATASTRUCTURES_QUEUE_H
#define DATASTRUCTURES_QUEUE_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* tail;
} Queue;

Queue* Queue_create();

void Queue_destroy(Queue* queue);

void Queue_enqueue(Queue* queue, int value);

void Queue_dequeue(Queue* queue);

int Queue_front(Queue* queue);

void Queue_print(Queue* queue);

#endif //DATASTRUCTURES_QUEUE_H
