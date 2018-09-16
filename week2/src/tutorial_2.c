
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {

    int b, e;

    b = 2;
    e = 5;

    int value = b;

    for (int i = 1; i < e; ++i) {
        value *= b;
    }

    printf("%d", value);

    return 0;
}