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

    int n;

    // store input into digit
    scanf("%d", &n);

    if(n % 2 == 0){     // if there is no remainder, then the digit is even
        printf("%d is an even digit number.", n);
    } else {            // if there is a remainder then the digit is not even
        printf("%d is not an even digit number.", n);
    }

    return 0;
}
