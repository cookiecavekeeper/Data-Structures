//
// Created by Paul Sonnenschein on 17.06.15.
//

#ifndef DATASTRUCTURES_LIST_SORT_H
#define DATASTRUCTURES_LIST_SORT_H

typedef struct SortNode {
    int value;
    struct SortNode *next;
} SortNode;

typedef struct SortList {
    SortNode *start;
    SortNode *end;
    int size;
} SortList;

SortList* SortList_create();

void SortList_append(SortList* list, int value);

void SortList_print(SortList* list);

void SortList_sort(SortList* list);

#endif //DATASTRUCTURES_LIST_SORT_H
