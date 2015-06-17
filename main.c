#include <stdio.h>
#include "queue.h"

int main() {
    Queue* queue = Queue_create();
    Queue_enqueue(queue, 12);
    Queue_enqueue(queue, 34);
    Queue_enqueue(queue, 1);
    Queue_enqueue(queue, 22);
    Queue_print(queue);
    printf("Current Front: %i \n", Queue_front(queue));
    Queue_dequeue(queue);
    Queue_dequeue(queue);
    printf("Current Front: %i \n", Queue_front(queue));
    Queue_print(queue);
    Queue_destroy(queue);
    return 0;
}