/* file: descend.c                                               */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)       */
/* date: 5-9-2018                                                */
/* version: 1.0                                                  */
/* Description: TODO: add description                            */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){

    int n;

    scanf("%d", &n);

    int digits[4];
    int sortedDigits[4];
    int i = 0;

    while (n > 0) {
        digits[i++] = n % 10;
        sortedDigits[i] = digits[i];
        n /= 10;
    }

    for (int j = 0; j < i; ++j) {
        for (int k = 0; k < i; ++k) {
            if(digits[k] > sortedDigits[j]){
                sortedDigits[j] = digits[k];
            }
        }
    }

    for (int l = 0; l < i; ++l) {
        printf("%d", sortedDigits[l]);
    }

    return 0;
}
