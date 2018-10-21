/*************************************************************************************
* file:        reduction_to_one.c
* author:      Stan van der Bend
* date:        15/10/2018
* version:     1.0
* Description: This program counts the minimal amount of computational steps to get from n to 1
*************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int countComputationalSteps(int n, int count){

    if(n == 1)
        return count;

    if(n % 2 == 0)
        return countComputationalSteps(n/2, count + 1);

    else if(n % 4 == 1 || n == 3)
        return countComputationalSteps(n-1, count + 1);

    return countComputationalSteps(n+1, count + 1);
}

int main(int argc, char *argv[]) {

    int n;
    scanf("%d", &n);

    int steps = countComputationalSteps(n, 0);

    printf("%d", steps);

}
