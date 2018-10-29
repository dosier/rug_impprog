/* file: decimal_fraction.c                                         */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)          */
/* date: 25-10-2018                                                 */
/* version: 1.0                                                     */
/* Description: Prints the series of repeating digits in a fraction */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1

void swap(int i, int j, int arr[]){
    int h = arr[i];
    arr[i] = arr[j];
    arr[j] = h;
}

void selectionSort(int length, int arr[]){
    int i, j, min;
    for (i = 0; i < length; i++) {
        min = i;
        for (j = i + 1; j < length; ++j) {
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        swap(i, min, arr);
    }
}

int *dynamicIntArray(int size){
    int *ptr = malloc(size * sizeof(int));
    if(ptr == NULL){
        /* memory allocation failed */
        printf("Error: memory allocation failed (out of memory?) \n");
        exit(-1);
    }
    return ptr;
}

int *resizeDynamicIntArray(int *arr, int newSize) {
    int *ptr = realloc(arr, newSize * sizeof(int));
    if(ptr == NULL){
        /* memory allocation failed */
        printf("Error: memory allocation failed (out of memory?) \n");
        exit(-1);
    }
    return ptr;
}
int findIndexY(char lines[100][2], int length, int value){
    for (int i = 0; i < length; ++i)
        if(lines[i][1] == value)
            return i;
    return -1;
}
int findIndexX(char lines[100][2], int length, int value){
    for (int i = 0; i < length; ++i)
        if(lines[i][0] == value)
            return i;
    return -1;
}
int findSmallestY(char lines[100][2], int length, int x) {
    int nextIndex = findIndexX(lines, length, x);
    if(nextIndex == -1)
        return x;
    int nextY = lines[nextIndex][1];
    return findSmallestY(lines, nextY, 0);
}
int isSmallerThanX(char lines[100][2], int length, int x,  int y){
    int xLine = findIndexX(lines, length, x);
    int yxLine = findIndexX(lines, length, lines[xLine][1]);
    int yLine = findIndexY(lines, length, y);
    if(yxLine == -1 || (yxLine > xLine && yxLine > yLine))
        return xLine == yLine;

    return yLine >= yxLine;
}
int main() {

    char lines[100][2];
    char X, Y;

    int alphabetX[26];
    int alphabetY[26];
    for (int j = 0; j < 26; ++j) {
        alphabetX[j] = 1;
        alphabetY[j] = 1;
    }
    int *x_values = dynamicIntArray(1);
    int *y_values = dynamicIntArray(1);
    int length = 0;
    int xLength = 0;
    int yLength = 0;

    while (TRUE) {
        int inputLength = scanf("%c<%c\n", &X, &Y);

        if(inputLength == EOF)
            break;

        lines[length][0] = X;
        lines[length][1] = Y;
        length++;

        int alphabetIndexX = X - 97;
        int alphabetIndexY = Y - 97;

        if(alphabetX[alphabetIndexX])
        {
            alphabetX[alphabetIndexX] = 0;
            x_values[xLength] = X;
            xLength++;
            x_values = resizeDynamicIntArray(x_values, xLength+1);
        }
        if(alphabetY[alphabetIndexY])
        {
            alphabetY[alphabetIndexY] = 0;
            y_values[yLength] = Y;
            yLength++;
            y_values = resizeDynamicIntArray(y_values, yLength+1);
        }
    }

    selectionSort(xLength, x_values);
    selectionSort(yLength, y_values);

    int copyYValues[yLength];
    for (int l = 0; l < yLength; ++l)
        copyYValues[l] = y_values[l];

    for (int k = 0; k < xLength; ++k) {
        int x = x_values[k];
        int indexX = findIndexX(lines, length, x);

        if(indexX != -1) {
            int found = 0;
            for (int i = 0; i < yLength; ++i) {
                int y = y_values[i];
                if(!found) {
                    if(isSmallerThanX(lines, length, x, y)){
                        copyYValues[i] = -1;
                        printf("%c<%c", x, y);
                        found = 1;
                    }
                }

                if(x == y)
                    copyYValues[i] = -1;
                if (copyYValues[i] == -1)
                    continue;
                if(found)
                    printf(",%c", y_values[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
