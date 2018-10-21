/************************************************************************************
* file:        balanced_splitter.c
* author:      Stan van der Bend
* date:        15/10/2018
* version:     1.0
* Description: This program outputs the smallest balanced splitter
*              in a series of real numbers or UNBALANCED in for none is found..
*************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1

int count = 0;

int is_prime(int x){
    if (x%2 == 0){
        return 0;
    }
    int a;
    for(a = 3;a * a <= x + 2; a = a + 2) {
        if(x % a == 0) {
            return 0;
        }
    }
    return 1;
}

void count_if_pp(int *arr, int size, int l, int h)
{
    int i;
    int k = 0;
    for (int i = 0 ; i < size ; i++){
        k = 10 * k + arr[i];
    }
    if(is_prime(k) && k >= l && k<= h && k != 1){
        count++;
    }
}


void swap_digits(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void swap_and_count(int *arr, int start, int end, int l, int h)
{
    if(start==end)
    {
        count_if_pp(arr, end + 1, l, h);
        return;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        swap_digits((arr + i), (arr + start));
        swap_and_count(arr, start + 1, end, l, h);
        swap_digits((arr + i), (arr + start));
    }
}

int main()
{
    int lowlength = 0;
    int highlength = 0;
    int upperBound;
    int lowerBound;

    scanf("%d %d", &lowerBound, &upperBound);

    int lo = lowerBound;
    int hi = upperBound;

    while(lowerBound != 0){
        lowerBound = lowerBound/10;
        lowlength++;
    }

    while(upperBound != 0){
        upperBound = upperBound/10;
        highlength++;
    }

    int i;
    int arr[10];
    int hold;
    int h;
    int foundP = 0;

    for (i = lowlength ; i <= highlength; i++){
        hold = i;
        h = 0;
        while(hold != 0){
            arr[h] = hold;
            h++;
            hold--;
        }
        swap_and_count(arr, 0, i - 1, lo, hi);
    }


    printf("%d", count);
    return 0;
}