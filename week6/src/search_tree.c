/* file: search tree.c                                            */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)        */
/* date: 21-10-2018                                               */
/* version: 1.0                                                   */
/* Description: Recursively traverses and prints a given BTS      */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>



/* A Binary Tree node */
struct TNode
{
    int data;
    struct TNode* left;
    struct TNode* right;
};
struct TNode* newNode(int data);

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct TNode* newNode(int data)
{
    struct TNode* node = (struct TNode*)
            malloc(sizeof(struct TNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}
/* A function that constructs Balanced Binary Search Tree from a sorted array */
struct TNode* sortedArrayToBST(int arr[], int prevNode, int start, int end)
{
    /* Base Case */
    if (start > end) {
        printf("(Leaf %d)", prevNode);
        return NULL;
    }
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    struct TNode *root = newNode(arr[mid]);

    printf("Tree ");
    /* Recursively construct the left subtree and make it
       left child of root */
    root->left =  sortedArrayToBST(arr, root->data, start, mid-1);
    printf(" %d ", root->data);
    /* Recursively construct the right subtree and make it
       right child of root */
    root->right = sortedArrayToBST(arr, root->data, mid+1, end);

    return root;
}

struct TNode* getLeft(int arr[], struct TNode* node, int start, int end) {

}
/* A utility function to print preorder traversal of BST */
void preOrder(struct TNode* node);

void preOrderR(struct TNode* node)
{
    if (node == NULL)
        return;


    if(node->right == NULL){
        printf("(Leaf %d)", node->data);
        return;
    }
    printf("(");
    preOrder(node->right);
    printf(")");
}
void preOrderL(struct TNode* node)
{
    if (node == NULL)
        return;

    if(node->left == NULL){
        printf("(Leaf %d)", node->data);
        return;
    }
    printf("(");
    preOrder(node->left);
    printf(")");
}

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

void printTree(int arr[], int length, int min, int rootNode, int nodeIndex) {
    int leftSubTreeStart = min + ((nodeIndex-min) / 2);
    int leftSubTreeEnd = nodeIndex;
    int rightSubTreeStart = nodeIndex + ((length-nodeIndex) / 2);
    int rightSubTreeEnd = length;
    /* Base Case */
    if (min > length) {
        return;
    }
    /* Get the middle element and make it root */
    int mid = (min + length)/2;
    int node = arr[mid];
    printf("Tree ");

    traverseLeft(arr, leftSubTreeStart, min, leftSubTreeEnd);
    printf(" %d ", node);
    traverseRight(arr, rightSubTreeStart, length);
}

void preOrder(struct TNode *node) {
    if (node == NULL)
        return;

    printf("Tree ");
    preOrderL(node->left);
    printf(" %d ", node->data);
    preOrderR(node->right);
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
//        printTree(arr, length-1, 0, rootNode, rootNodeIndex);

        preOrder(sortedArrayToBST(arr, rootNode, 0, length-1));
    }

    return 0;
}
