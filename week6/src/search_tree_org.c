/* file: search tree.c                                            */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)        */
/* date: 21-10-2018                                               */
/* version: 1.0                                                   */
/* Description: Recursively traverses and prints a given BTS      */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * Template for the print tree method.
 *
 * @param arr       the number inputs
 * @param length    the length of the array
 * @param min       the minimum (left most) value of the tree
 * @param rootNode  the root node of the tree
 * @param nodeIndex the index of the root node in the number inputs
 */
void printTree(int arr[], int length, int min, int rootNode, int nodeIndex);

/**
 * Traverses the left sub-tree / leaf.
 *
 * @param arr       the number inputs
 * @param index     the index of the next node in the number inputs
 * @param min       the minimum (left most) value of the tree
 * @param length    the length of the array
 */
void traverseLeft(int *arr, int index, int min, int length){
    int node = arr[index];

    if(index == min){
        printf("(Leaf %d)", node);
        return;
    }
    printf("(");
    printTree(arr, length, min, node, index);
    printf(")");
}
/**
 * Traverses the right sub-tree / leaf.
 *
 * @param arr       the number inputs
 * @param index     the index of the next node in the number inputs
 * @param length    the length of the array
 */
void traverseRight(int *arr, int index, int length) {
    int node = arr[index];

    if(index == length-1){
        printf("(Leaf %d)", node);
        return;
    }
    printf("(");
    printTree(arr, length, (length/2)+1, node, index);
    printf(")");
}

int *copySubArray(int left, int right, int arr[]){
    int i;
    int *copy = dynamicIntArray((right-left) * sizeof(int));
}

void printTree(int arr[], int length, int min, int rootNode, int nodeIndex) {
    int leftSubTreeStart = min + ((nodeIndex-min) / 2);
    int leftSubTreeEnd = nodeIndex;
    int rightSubTreeStart = nodeIndex + ((length-nodeIndex) / 2);
    int rightSubTreeEnd = length;

    printf("Tree ");
    traverseLeft(arr, leftSubTreeStart, min, leftSubTreeEnd);
    printf(" %d ", rootNode);
    traverseRight(arr, rightSubTreeStart, rightSubTreeEnd);
}

int main() {

    int n; // 1 <= n < 20

    scanf("%d", &n);

    int length = (int) pow(2.0, (double) n) - 1;//length is (2^n)−1

    int arr[length];

    // store input values
    for (int i = 0; i < length; ++i) {
        scanf("%d", &arr[i]);
    }
    mergeSort(length, arr);
    // Special case if our input is just 1 number
    if(length == 1){
        printf("Leaf %d", arr[0]);
    } else {
        // middle index
        int rootNodeIndex = length / 2;
        // middle root
        int rootNode = arr[rootNodeIndex];
        /* display the tree */
        printTree(arr, length, 0, rootNode, rootNodeIndex);
    }
    
    return 0;
}
