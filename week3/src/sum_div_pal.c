/* file: sum_div_pal.c                                       */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)   */
/* date: 17-9-2018                                           */
/* version: 1.0                                              */
/* Description: this program determines whether the input n  */
/* is a sum div pal number.                                  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getReverse(int x) {

    int r, reverseN, temp;
    temp = x;
    reverseN = 0;

    // algorithmically find reverse n
    while (temp) {
        r = temp % 10;
        temp = temp / 10;
        reverseN = reverseN * 10 + r;
    }

    return reverseN;
}

int main(int argc, char *argv[]) {

    int n;

    scanf("%d", &n);

    int sum = 0;

    // all natural numbers are a divisor of 0 and the sum of all cannot be 0 when read in reverse.
    if(n == 0){
        printf("NO");
        return 0;
    }

    for (int i = 1; i < n; ++i) {

        // is i proper divisor?
        if(n % i == 0){
            sum += i;
        }
    }

    if(sum == getReverse(n)){
        printf("YES");
    } else {
        printf("NO");
    }


    return 0;
}