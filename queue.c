//
// Created by Paul Sonnenschein on 15.06.15.
//

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

Queue *Queue_create()
{
    Queue *queue = malloc(sizeof(Queue));
    queue->front = NULL;
    queue->tail = NULL;
    return queue;
}

void Queue_destroy(Queue *queue)
{
    while (queue->front != NULL && queue->tail != NULL) {
        Queue_dequeue(queue);
    }
    free(queue);
}

void Queue_enqueue(Queue *queue, int value)
{
    Node *tmp = malloc(sizeof(Node));
    tmp->data = value;
    tmp->next = NULL;

    if (queue->front == NULL && queue->tail == NULL) {
        queue->front = queue->tail = tmp;
    } else {
        queue->tail->next = tmp;
        queue->tail = tmp;
    }
}

void Queue_dequeue(Queue *queue)
{
    if (queue->front == NULL && queue->tail == NULL) {
        printf("Queue allready emty!\n");
        return;
    }

    Node *tmp = queue->front;

    if (queue->front == queue->tail) {
        queue->front = queue->tail = NULL;
    } else {
        queue->front = queue->front->next;
    }
    free(tmp);
}

int Queue_front(Queue *queue)
{
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        return 0;
    }
    return queue->front->data;
}

void Queue_print(Queue *queue)
{
    Node *tmp = queue->front;
    printf("Values: ");
    while (tmp != NULL) {
        printf("%i ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

