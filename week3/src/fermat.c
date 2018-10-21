/* file: fermat.c                                              */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)     */
/* date: 18-9-2018                                             */
/* version: 1.0                                                */
/* Description: this program can perform numerous operations  '*/
/*              to a given input.                              */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int isPrimeNumber(int num){}

/**
 * For any integer 'n' > 1 which is not a prime,
 * we call a number 'a' (where 2 <= 'a' < n) a witness for 'n' if 'a'^n mod 'n' != 'a'.
 */
int isWitnessingNumber(int n, int a){

    // n can be fairly big thus we can do this more smartly.

    double powResult = pow((double) a, (double) n);
    double modResult = fmod(powResult, (double) n);

    printf("%fd, %fd \n", powResult, modResult);

    if(modResult != a) {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {

    int x;

    scanf("%d", &x);

    for (int a = 2; a < x; ++a) {
        if(isWitnessingNumber(x, a)){
            printf("%d is a witness for %d.", a, x);
            return 0;
        }
    }

    printf("%d is a Carmichael number.", x);
    return 0;
}