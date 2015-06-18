//
// Created by Paul Sonnenschein on 17.06.15.
//

#include <stdlib.h>
#include <stdio.h>
#include "list_sort.h"

SortList* SortList_create() {
    SortList *list = malloc(sizeof(SortList));
    list->size = 0;
    list->start = NULL;
    list->end = NULL;
    return list;
}

void SortList_append(SortList* list, int value)
{
    SortNode *tmp = malloc(sizeof(SortNode));
    tmp->value = value;
    tmp->next = NULL;
    if (list->start == NULL && list->end == NULL) {
        list->start = list->end = tmp;
    } else {
        list->end->next = tmp;
        list->end = tmp;
    }
    list->size++;
}

void SortList_print(SortList* list)
{
    SortNode *tmp = list->start;
    printf("Size: %i Content: ", list->size);
    while (tmp != NULL) {
        printf("%i ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

void SortList_sort(SortList* list)
{
    SortNode *arrayList[list->size];
    SortNode *tmp = list->start;
    int i = 0;
    while (tmp != NULL) {
        arrayList[i++] = tmp;
        tmp = tmp->next;
    }
};