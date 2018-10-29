/* file: decimal_fraction.c                                         */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)          */
/* date: 25-10-2018                                                 */
/* version: 1.0                                                     */
/* Description: Prints the series of repeating digits in a fraction */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1

// template for a dynamic array
typedef struct { int *array; size_t used; size_t size; } DynamicArray;

// initialise a DynamicArray, allocate resources.
void initDA(DynamicArray *a, size_t initialSize) {
    a->array = (int *)malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
}

// insert an integer element into the argued DA
void insertInDynamicArray(DynamicArray *a, int element) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (int *)realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
}

int main() {

    int denominator;

    scanf("%d", &denominator);

    // create 2 dynamic arrays, one to store remainders and one to store division results
    DynamicArray remainders, results;
    initDA(&remainders, 0);
    initDA(&results, 0);

    int nominator = 1;
    int rem, res;
    printf("0.");
    // Loop indefinitely till broken
    while (TRUE){
        // calculate the remainder of the next division
        rem = nominator % denominator;
        // calculate the result of the next division
        res = nominator / denominator;

        /*
         * insert the remainder and result in their respective arrays.
         */
        insertInDynamicArray(&remainders, rem);
        insertInDynamicArray(&results, res);

        // if our remainder is 0, it is not recurring
        if(rem == 0) {

            for (int j = 1; j < results.used; ++j) {
                printf("%d", results.array[j]);
            }
            printf("[0]");
            return 0;
        }

        // loop over all previous remainder values
        for (int i = 0; i < remainders.used-1; ++i) {
            // if the currently iterated remainder equals the calculated remainder
            if(remainders.array[i] == rem){

                // we can start the period at one step later because we manually print '0.'
                int periodStart = i + 1;

                // as the nominator is 1 and the denominator is bigger than 1, the first digit must always be 0
                printf("0.");

                // print the digits before the period starts
                for (int j = 1; j < periodStart; ++j) printf("%d", results.array[j]);

                printf("[");

                // print the periodic digits
                for (int k = periodStart; k < results.used; ++k) printf("%d", results.array[k]);

                printf("]");
                return 0;
            }
        }
        // prepare for next iteration by setting the numerator to the current remainder multiplied by base 10
        nominator = rem * 10;
    }
    return 0;
}
