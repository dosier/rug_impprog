/* file: descend.c                                               */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)       */
/* date: 5-9-2018                                                */
/* version: 1.0                                                  */
/* Description:
 *              This program takes an input 'digit' and outputs  */
/*              whether a sorted digit                           */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){

    int digit;

    scanf("%d", &digit);

    int divisor = 1;
    int split[4];

    for (int i = 0; i < 4; ++i) {

        int value = digit / divisor % 10;

        split[i] = value;
        divisor *= 10;

    }

    int array_size = 4;
    int i, j, temp;
    for (i = 0; i < (array_size - 1); ++i)
    {
        for (j = 0; j < array_size - 1 - i; ++j )
        {
            if (split[j] < split[j+1])
            {
                temp = split[j+1];
                split[j+1] = split[j];
                split[j] = temp;
            }
        }
    }

    digit = 0;

    for (int k = 0; k < array_size; ++k) {
        divisor /= 10;
        digit += split[k] * divisor;
    }

    printf("%d", digit);

    return 0;
}