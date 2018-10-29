/* file: winner_runner_up.c                                       */
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

/**
 * Sort algorithm
 */
void bubbleSort(int length, int arr[]) {
    for (int i=0; i < length-1; i++) {
        for (int j=0; j+1 < length - i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(j, j+1, arr);
            }
        }
    }
}

int main() {

    DynamicArray a;

    // initialize the array with an initial size
    createDynamicArray(&a, 10000);
    int length = 0;

//    for (int j = 0; j < 1000000; ++j) {
//        insertInDynamicArray(&a, j);
//        length++;
//    }

    // create a while loop that will loops indefinitely
    while(TRUE)
    {
        int input;
        scanf("%d", &input);

        // if the input is zero, end the loop.
        if(input == 0)
            break;
        insertInDynamicArray(&a, input);
        length++;
    }

    // sort array by number
    bubbleSort(length, a.array);

    int currentCount = 1;
    int runnerUpInput = -1, runnerUpInputCount = 0;

    int majorityInput = a.array[0], majorityInputCount = 1;
    // iterate over all values starting at index 1
    for (int i = 1; i < length; ++i) {

        int previous = a.array[i-1];
        int current = a.array[i];

        if(previous == current)
            currentCount++;
        else currentCount = 1;

        if(currentCount > majorityInputCount){
            majorityInputCount = currentCount;
            majorityInput = current;
        }
    }

    // iterate over all values starting at index 1
    for (int i = 1; i < length; ++i) {

        int previous = a.array[i-1];
        int current = a.array[i];

        if(previous == current)
            currentCount++;
        else currentCount = 1;

        if(current != majorityInput && currentCount > runnerUpInputCount){
            runnerUpInputCount = currentCount;
            runnerUpInput = current;
        }
    }

    double percentageMajorityWhole = 100.0 - (100.0 * (((double) length  - (double) majorityInputCount)/ (double) length));

    // if the current majority occurs more than 50% of the cases
    if(percentageMajorityWhole > 50.0){

        double  percentageRunnerUpWhole = 100.0 - (100.0 * (((double) length  - (double) runnerUpInputCount)/ (double) length));
        // else print the majority count
        printf("majority: %d\n", majorityInput);

        // if runner up duplicate count is more than 25% but less than 50%
        if(runnerUpInputCount > 0 && percentageRunnerUpWhole > 25.0 && percentageRunnerUpWhole < 50.0)
            printf("runner-up: %d", runnerUpInput);
        else
            printf("runner-up: NONE");
    } else  printf("majority: NONE");
    return 0;
}
