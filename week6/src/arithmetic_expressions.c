/* file: arithmetic_expressions.c                                   */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)          */
/* date: 28-10-2018                                                 */
/* version: 1.0                                                     */
/* Description: Prints the series of repeating digits in a fraction */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
int solutionCount = 0;

int subtract(int digit, int n){
    return n - digit;
}
int multi(int f, int s){
    int i;
    int res = 1;
    for (i = f; i < s+1; ++i) {
        res *= i;
    }
    return res;
}

int next(int n, int i, char ops[10]) {

    int res = multi(i, 9);

    if(n % res == 0)
        return 1;

    if(i == 10) {
       if(n == 0)
           return 1;
       return 0;
    }


    return next(n - i, i + 1, ops) + next(n + i, i + 1, ops);
}

int main() {

    int n = 362881;
    char ops[10];

    for (int i = 0; i < 10; ++i) {
        ops[i] = '*';
    }

    int foundSolutions = next(n, 1, ops);

    printf("solution = %d", foundSolutions);
    return 0;
}
