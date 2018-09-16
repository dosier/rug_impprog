/* file: k_composites.c                                      */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)   */
/* date: 5-9-2018                                            */
/* version: 1.0                                              */
/* Description: this program determines the k-composite of   */
/*              input 'n                                     */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int k;

    scanf("%d", &k);

    int multiple = 1;

    int prevTimes;

    // iterate over necessary values
    for (int i = 2; i < k + 1; ++i) {

        // reset variable holding how many times j fits into i
        prevTimes = 1;

        // if our current value is already divisible by i without leaving a remainder, continue to next iteration.
        if(multiple % i == 0){
            continue;
        }

        // iterate over all possible values leading up to i
        for (int j = 2; j < i; ++j) {

            // if i divided by j leaves no remainder, continue
            if(i%j == 0){

                // how many times j fits into i
                int times = i / j;

                // if this is not our first iteration and the times is bigger than the previous biggest fit, break.
                if(prevTimes > 1 && times > prevTimes){
                    break;
                }

                // check whether times fits into prevTimes without leaving a remainder
                if(prevTimes % times == 0){
                    multiple *= times;
                   // printf("[%d] %d multiplying by %d gives %d\n", i, prevTimes, times, multiple);
                }

                // divide final answer by j
                multiple /= j;

                //printf("[%d] %d, %d -> dividing by %d gives %d\n", i, prevTimes, times, j, multiple);
                prevTimes = times;
            }
        }

        multiple *= i;
        //printf("multiply by %d results in (%d)\n", i, multiple);
    }

    printf("%d", multiple);
    return 0;
}