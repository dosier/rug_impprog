/* file: search tree.c                                            */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)        */
/* date: 21-10-2018                                               */
/* version: 1.0                                                   */
/* Description: Recursively traverses and prints a given BTS      */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int *dynamicIntArray(int sz){
    int *ptr = malloc(sz* sizeof(int));
    if(ptr == NULL){
        printf("ERROR memory allocation failed (out of memory?).\n");
        exit(-1);
    }
    return ptr;
}

int *copySubArray(int left, int right, int arr[]){
    int i;
    int *copy = dynamicIntArray((right-left) * sizeof(int));
    for(i = left; i < right; i++){
        copy[i-left] = arr[i];
    }
    return copy;
}

void mergeSort(int length, int arr[]){
    int l, r, mid, idx, *left, *right;
    if( length <= 1 ){
        return;
    }
    mid = length/2;
    left = copySubArray(0, mid, arr);
    right = copySubArray(mid, length, arr);
    mergeSort(mid, left);
    mergeSort(length - mid, right);
    idx = 0;
    l = r = 0;
    while ((l < mid) && (r < length - mid)){
        if(left[l] < right[r]){
            arr[idx] = left[l];
            l++;
        } else {
            arr[idx] = right[r];
            r++;
        }
        idx++;
    }
    while(l < mid){
        arr[idx] = left[l];
        idx++;
        l++;
    }
    while(r < length - mid){
        arr[idx] = right[r];
        idx++;
        r++;
    }
    free(left);
    free(right);
}

int main() {

    int n; // 1 <= n < 20

    scanf("%d", &n);

    int length = (int) pow(2.0, (double) n) - 1;//length is (2^n)−1

    int xValues[length];

    // store input values
    for (int i = 0; i < length; ++i) {
        scanf("%d", &xValues[i]);
    }
    mergeSort(length, xValues);

    for (int d = 1; d < length; ++d) {

        for (int i = 0; i < length; ++i) {

        }

        printf("%d ", xValues[d]);
    }

    return 0;
}
