//
// Created by Paul Sonnenschein on 17.06.15.
//

#include <stdlib.h>
#include <stdio.h>
#include "list_sort.h"

SortList *SortList_create()
{
    SortList *list = malloc(sizeof(SortList));
    list->size = 0;
    list->start = NULL;
    list->end = NULL;
    return list;
}

void SortList_append(SortList *list, int value)
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

void SortList_print(SortList *list)
{
    SortNode *tmp = list->start;
    printf("Size: %i Content: ", list->size);
    while (tmp != NULL) {
        printf("%i ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}


void swapList(SortNode **first, SortNode **second) {
    SortNode *tmp = *first;
    *first = *second;
    *second = tmp;
}

int SortList_partition(SortNode *array[], int start, int end)
{
    SortNode *pivot = array[end];
    int pIndex = start;

    for (int i = start; i < end; ++i) {
        if (array[i]->value <= pivot->value) {
            swapList(array + i, array + pIndex);
            pIndex++;
        }
    }

    swapList(array + pIndex, array + end);
    return pIndex;
}


void SortList_sort_actual(SortNode *array[], int start, int end)
{
    if (start < end) {
        int pIndex = SortList_partition(array, start, end);
        SortList_sort_actual(array, start, pIndex - 1);
        SortList_sort_actual(array, pIndex + 1, end);
    }
}

void SortList_sort(SortList *list)
{
    SortNode *arrayList[list->size];
    SortNode *tmp = list->start;
    int i = 0;
    while (tmp != NULL) {
        arrayList[i++] = tmp;
        tmp = tmp->next;
    }
    SortList_sort_actual(arrayList, 0, i - 1);


    tmp = list->start = arrayList[0];
    list->end = arrayList[i - 1];

    for (int j = 1; j < i; ++j) {
        arrayList[j]->next = NULL;
        tmp->next = arrayList[j];
        tmp = arrayList[j];
    }
};