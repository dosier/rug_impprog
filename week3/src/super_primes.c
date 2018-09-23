/* file: super_primes.c                                      */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)   */
/* date: 23-9-2018                                           */
/* version: 1.0                                              */
/* Description: this program determines whether the input n  */
/* can be represented as the nth super prime, that is a prime*/
/* if it remains prime by dropping any digit                 */
/* (leading zeros are allowed)                               */

#include <stdio.h>

/**
 * @param i         :   the index at which our targeted digit is located in the digits array.
 * @param digits    :   the array of chars containing all digits.
 *
 * @return {@code 1} when true and {@code 0} when false.
 */
int dropDigit(int i, char *digits) {

    int next_digit_index;
    int t = 1;

    while (t < i) {

        next_digit_index = i / 10 / t * t + i % t;

        if (digits[next_digit_index] == 0)
            return 0;

        t *= 10;
    }
    return 1;
}

int main(int argc, char *argv[]) {

    int max_length = 480000L;
    char digits[max_length];

    int n;
    int index = 0;

    // wait for input and store in 'n'
    scanf("%d", &n);

    // set default value of digits to 1
    for (int i = 2; i < max_length; i++)
        digits[i] = 1;

    // iterate over possible values
    for (int i = 2; i < max_length; i++) {

        // if the digit at index 'i' equals 0, disregard and continue loop
        if (digits[i] == 0)
            continue;

        for (int j = i+i; j < max_length; j += i){
//            printf("[%d] nulling [%d] -> %d \n", i, j, digits[j]);
            digits[j] = 0;
        }

        //no need to drop digits when we have only 10.
        if (i > 10) {

            // see if we can drop the digit at the specified index
            if (dropDigit(i, digits)){

                index++; // increment and compare with 'n'
                if(index == n){
                    printf("%d", i);
                    return 0;
                }
            }
        }
    }
}

