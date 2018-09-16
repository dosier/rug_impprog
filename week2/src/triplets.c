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

    // below is used to print max value of n1 iteration.
     int biggest_a = 0, biggest_b = 0, biggest_c = 0;

     int prevstep = 0;

    // first we loop over all possible n1 values, 1 >= n1 < n
    for (int n1 = 1260; n1 >= 1; --n1) {

//        if(n1 > n){
//            continue;
//        }

        // if we can divide n by n1 without leaving a remainder, continue
        if(n % n1 == 0) {



            int n2 = n / n1;

            printf("(%d, %d)\n ",n1, n2);

//            if(n2 < n1){
//                break;
//            }

            while (n2 >= n1){

                int c = n / n2 / n1;

                // if n is divisible by n2 without leaving a remainder, continue.
                if (n % n2 == 0) {
                   // printf("(%d, %d, %d) ",n1, n2, c);

                    // conditions to make sure we're not counting duplicates.
                    if(n1 > c || (n1 == n2 && c != n1)  ||  (n1 < c && n1 < n2 && n2 > c)){
//                        printf("-> skipping \n");
                        n2--;
                        continue;
                    }

                    if((n1 * n2 * c) == n){

//                        int diff_a = n1 - biggest_a;
//                        int diff_b = n2 - biggest_b;
//                        int diff_c = c  - biggest_c;

                        //printf("diff(%d, %d, %d)\n", diff_a, diff_b, diff_c);

//                        if(n1 > biggest_a && n1 != 2000000000){
//                            biggest_a = n1;
//                        }
//                        if(n2 > biggest_b && n2 != 2000000000){
//                            biggest_b = n2;
//                        }
//                        if(c > biggest_c && c != 2000000000){
//                            biggest_c = c;
//                        }
                        count++;

                        int steps = (n2 - n1);

                        printf("%d -> counting (steps = %d, delta = %d)\n", count, steps, prevstep - steps);

                        prevstep = steps;
                    }
                }
                n2--;
            }

        }
    }

    printf("biggest (%d, %d, %d)\n", biggest_a, biggest_b, biggest_c);
    printf("%d", count);

    return 0;
}