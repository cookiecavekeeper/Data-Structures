#include <stdio.h>
#include "queue.h"
#include "sort.h"

int main()
{
    printf("===== Queue =====\n");
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

    printf("===== Sorting =====\n");
    int array[] = {3,5,2,7,5,1,8,0,9,4,6};
    int lenght = sizeof(array)/sizeof(array[0]);
    Quicksort_sort(array, 0, lenght -1);
    printf("Values: ");
    for (int i = 0; i < lenght; ++i) {
        printf("%i ", array[i]);
    }
    printf("\n");
    return 0;
}