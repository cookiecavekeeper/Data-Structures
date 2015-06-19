#include <stdio.h>
#include "queue.h"
#include "sort.h"
#include "list_sort.h"
#include "hash_table.h"

int main()
{
    printf("===== Queue =====\n");
    Queue *queue = Queue_create();
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
    int array[] = {3, 5, 2, 7, 5, 1, 8, 0, 9, 4, 6};
    int lenght = sizeof(array) / sizeof(array[0]);
    Quicksort_sort(array, 0, lenght - 1);
    printf("Values: ");
    int i;
    for (i = 0; i < lenght; ++i) {
        printf("%i ", array[i]);
    }
    printf("\n");


    printf("===== Sorting Lists =====\n");

    SortList *list = SortList_create();
    SortList_append(list, 3);
    SortList_append(list, 5);
    SortList_append(list, 2);
    SortList_append(list, 7);
    SortList_append(list, 5);
    SortList_append(list, 1);
    SortList_append(list, 8);
    SortList_append(list, 0);
    SortList_append(list, 9);
    SortList_append(list, 4);
    SortList_append(list, 6);

    SortList_print(list);
    SortList_sort(list);
    SortList_print(list);

    printf("===== HashTable =====\n");

    HashTable *table = HashTable_create(100);
    HashTable_set(table, "test", "Paul der Gaul!");
    HashTable_set(table, "tset", "Paul der Gaul 2!");
    char *result = HashTable_get(table, "test");
    char *result2 = HashTable_get(table, "tset");
    HashTable_set(table, "tset", "Paul der Gaul 3!");
    HashTable_set(table, "bullshit", "Paul der Gaul bull!");
    char *result3 = HashTable_get(table, "tset");
    char *result4 = HashTable_get(table, "bullshit");
    printf("Result: %s %s\n", result, result2);
    printf("Result: %s %s\n", result3, result4);
    return 0;
}