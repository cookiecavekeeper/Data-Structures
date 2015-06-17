//
// Created by Paul Sonnenschein on 17.06.15.
//

#include "sort.h"

int Quicksort_partition(int array[], int start, int end);

void swap(int *first, int *second);

void Quicksort_sort(int array[], int start, int end)
{
    if (start < end) {
        int pIndex = Quicksort_partition(array, start, end);
        Quicksort_sort(array, start, pIndex - 1);
        Quicksort_sort(array, pIndex + 1, end);
    }
}

int Quicksort_partition(int array[], int start, int end)
{
    int pivot = array[end];
    int pIndex = start;

    for (int i = start; i < end; ++i) {
        if (array[i] > pivot) {
            swap(array + i, array + pIndex);
            pIndex++;
        }
    }

    swap(array + pIndex, array + end);
    return pIndex;
}


void swap(int *first, int *second) {
    int tmp = *first;
    *first = *second;
    *second = tmp;
}
