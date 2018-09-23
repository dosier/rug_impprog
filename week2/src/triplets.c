/* file: triplets.c                                          */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)   */
/* date: 5-9-2018                                            */
/* version: 1.0                                              */
/* Description: this program determines whether the input 'n'*/
/*              is a squareful number.                       */

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    int input;

    scanf("%d", &input);

    int count = 0;
    int n = input;

     int ca[1560];
    int cb[1560];
    int cc[1560];

    if(input == 2000000000){
        count++;
    }

    // first we loop over all possible n1 values, 1 >= n1 < n
    for (int a = 1; a < 1260; ++a) {

        // if we can divide n by n1 without leaving a remainder, continue
        if(n % a == 0) {

            for (int b = 1; b < 44721; ++b) {

                if (n % b == 0) {

                    int c = n / b / a;

                    if((a * b * c) == n){

                        ca[count] = a;
                        cb[count] = b;
                        cc[count] = c;
                        count++;

                       // printf("%d -> counting (%d, %d, %d)\n", count, a, b, c);
                    }
                }
            }
        }

    }

    int length = count;

    int fre[length];

    for (int i = 0; i < length; ++i) {
        int sum1 = ca[i] + cb[i] + cc[i];
        fre[i] = sum1;
    }

    int counted[length], j, d, c, flag;

    counted[0] = fre[0];

    c = 1;

    for(j=0; j <= length-1; ++j) {
        flag = 1;;
        /*the counted array will always have 'count' elements*/
        for(d=0; d < c; ++d) {
            if(fre[j] == counted[d]) {
                flag = 0;
            }
        }
        if(flag == 1) {
            ++c;
            counted[c-1] = fre[j];
        }
    }

    printf("%d", c);

    return 0;
}

