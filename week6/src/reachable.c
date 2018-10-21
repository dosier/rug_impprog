/*************************************************************************************
* file:        reachable.c
* author:      Stan van der Bend
* date:        15/10/2018
* version:     1.0
* Description: This program counts the minimal amount of computational steps to get from n to 1
*************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isJumpableArray(const int *contents, int length){

    if(length <= 1)
        return 1;

    int max = contents[0];

    for (int i = 0; i < length; ++i) {

        if(max <= i && contents[i] == 0)
            return 0;

        if(i + contents[i] > max)
            max = i + contents[i];

        if(max >= length-1)
            return 1;
    }
    return 0;
}
int main(int argc, char *argv[]) {

    int length;
    scanf("%d", &length);
    int contents[length];

    int j = 1;
    for (int i = 0; i < length; ++i){
//        contents[i] = j;
//        j+=2;
        scanf("%d", &contents[i]);
    }
//

    //if(countJumps(contents, 0, length - 1) != INT_MAX){
    if(isJumpableArray(contents, length)){
        printf("YES");
    } else {
        printf("NO");
    }
}
