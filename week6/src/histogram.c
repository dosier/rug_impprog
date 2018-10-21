/* file: histogram.c                                              */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)        */
/* date: 19-10-2018                                               */
/* version: 1.0                                                   */
/* Description: determines a majority in a given number set       */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

typedef struct {
    int *array;
    size_t used;
    size_t size;
} DynamicArray;

void createDynamicArray(DynamicArray *a, size_t initialSize) {
    a->array = (int *)malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
}
void insertInDynamicArray(DynamicArray *a, int element) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (int *)realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
}
/**
 * Swap values in the argued array
 *
 * @param i     index being swapped by
 * @param j     index being swapped in
 * @param arr   array containing the indices
 */
void swap(int i, int j, int arr[]) {
    int h = arr[i];
    arr[i] = arr[j];
    arr[j] = h;
}

int partition(int length, int arr[]) {
    int left = 0;
    int right = length;
    int pivot = arr[0];
    while (left < right) {

        while ((left < right) && (arr[left] <= pivot))
            left++;
        while ((left < right) && (pivot < arr[right-1]))
            right--;

        if (left < right)
            swap(left, right-1, arr);
    }
    /* put pivot in right location: swap(0,left-1,arr) */
    left--;
    arr[0] = arr[left];
    arr[left] = pivot;
    return left;
}
/**
 * Sorting algorithm of complexity  O(n log n)
 *
 * @param length    the length of the array
 * @param arr       the array containing the numbers (initially unsorted)
 */
void quickSort(int length, int *arr) {

    if (length <= 1)
        return; // nothing to sort

    int boundary = partition(length, arr);
    quickSort(boundary, arr);
    quickSort(length - boundary - 1, &arr[boundary+1]);
}

int main() {

    DynamicArray a;

    // initialize the array with an initial size
    createDynamicArray(&a, 10000);

    // create a while loop that will loops indefinitely
    while(TRUE)
    {
        int input;
        scanf("%d", &input);

        // if the input is zero, end the loop.
        if(input == 0)
            break;

        insertInDynamicArray(&a, input);
    }

    // sort array by number
    quickSort((int) a.used, a.array);
    int previous = a.array[0];
    int currentCount = 1;

    // iterate over all values starting at index 1
    for (int i = 1; i < a.used; ++i) {
        int current = a.array[i];

        // if the previous value equals the current value
        if(previous == current)
            currentCount++;// increase the current duplicates count
        else {
            printf("%d: %d\n", previous, currentCount);
            currentCount = 1;
        }
        // cache current value to use for comparison in next iteration
        previous = current;
    }

    // print last value that is not incorporated into the loop
    printf("%d: %d\n", previous, currentCount);
    return 0;
}
