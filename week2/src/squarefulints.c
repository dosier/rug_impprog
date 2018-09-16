/* file: squarefullints.c                                    */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)   */
/* date: 5-9-2018                                            */
/* version: 1.0                                              */
/* Description: this program determines whether the input 'n'*/
/*              is a squareful number.                       */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int n;

    scanf("%d", &n);

    int original_n = n;
    int input = n;

    // iterate over each number starting from two till 44725 (roughly the square root of 2billion, our max input)
    for (int factor = 2; factor <= 44725; factor++) {

        // square the current iterated number
        int square = factor * factor;

        // if our square is over the input, then no point in continuing the loop (performance)
        if(square > input)
            break;

        // check if the squared number equals the input
        if (input == square) {

            // how many times does the current iterated number fit into the input?
            int fit = input / factor;

            // if more than one time, continue
            if(fit > 1){

                // declare boolean holding whether the current iterated number is square free.
                int isSquareFree = 1;

                // iterate over all numbers leading up to factor
                for (int i = 0; i < factor; ++i) {

                    // determine whether the factor is a square of i.
                    if((i*i) == factor){
                        isSquareFree = 0;
                        break;
                    }

                }

                // printf("found division of %d by %d, fit %d times. free = %d \n", n, square, fit, isSquareFree);

                if(isSquareFree){
                    printf("%d is a squareful number.", original_n);
                    return 0;
                }
            }
        }
    }
    printf("%d is not a squareful number.", original_n);
    return 0;
}