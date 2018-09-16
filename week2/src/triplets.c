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

    for (int a = 1; a < n; ++a) {

        if(n % a == 0) {

            int b = n / a;

            printf("a = %d \n",a);

            while (b > a){

                int c = n / b / a;

                if (n % b == 0) {

                    if((a * b * c) == n){
                        count++;
                        printf("(%d, %d, %d) \n",a, b, c);
                    }
                }
                b--;
            }

        }
    }

    printf("%d", count);

    return 0;
}