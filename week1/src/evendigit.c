/* file: evendigit.c                                             */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)       */
/* date: 5-9-2018                                                */
/* version: 1.0                                                  */
/* Description: This program takes an input 'n' and outputs      */
/*              whether 'n' is an even number or not.            */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){

    int digit;

    scanf("%d", &digit);

    int n = digit;
    int iterations = 0;

    while (n > 0){
        n /= 10;
        iterations++;
    }

    int n2 = digit;
    int value;
    int count = 0;

    for (int i = 0; i < iterations; ++i) {
        value = n2 % 10;
        if(value % 2 == 0){
            count++;
        }
        n2 /= 10;
    }

    if(abs(digit) == digit && count == iterations){
        printf("%d is an even digit number.", digit);
    } else {
        printf("%d is not an even digit number.", digit);
    }

    return 0;
}
