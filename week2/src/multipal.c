/* file: multipal.c                                          */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)   */
/* date: 5-9-2018                                            */
/* version: 1.0                                              */
/* Description: this program counts the amount of mulpals   '*/
/*              with a <= n <= b                             */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // declare variables used for calculating the reverse n
    int n,r,reverseN,temp;
    int min,max;
    int count = 0;
    scanf("%d %d", &min, &max);

    for(n = min; n <= max; n++) {

        // assign variables used for calculating the reverse n
        temp = n;
        reverseN = 0;

        // algorithmically find reverse n
        while (temp) {
            r = temp % 10;
            temp = temp / 10;
            reverseN = reverseN * 10 + r;
        }

        // if there is no remainder, then the number n is a multipal
        if(reverseN % n == 0){
            //int d = reverseN / n;
            //printf("%d * %d = %d\n", n, d, reverseN);
            count++;
        }

    }

    printf("%d",count);
    return 0;
}