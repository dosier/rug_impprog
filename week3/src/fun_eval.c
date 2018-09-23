/* file: fun_eval.c                                            */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)     */
/* date: 18-9-2018                                             */
/* version: 1.0                                                */
/* Description: this program can perform numerous operations  '*/
/*              to a given input.                              */

#include <stdio.h>
#include <stdlib.h>

int f(int x){
    return x + 1;
}
int g(int x){
    return (3 * x) + 1;
}
int h(int x){
    return (x * x) - x + 42;
}

int main(int argc, char *argv[]) {

    int x;
    char word[256];

    scanf("%d %s", &x, word);

    int output = x;

    // loop through all characters
    for (int i = 0; i < sizeof(word); ++i) {

        // if we reached the termination symbol, break out of the loop.
        if(word[i] == '='){
            break;
        }

        // check if there is any function indicator, if so apply to the output.
        switch (word[i]){
            case 'h':
                output = h(output);
                break;
            case 'f':
                output = f(output);
                break;
            case 'g':
                output = g(output);
                break;
            default:break;
        }
    }

    printf("%d", output);
    return 0;
}