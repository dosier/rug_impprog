/* file: overlap.c                                                 */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)         */
/* date: 9-9-2018                                                  */
/* version: 1.0                                                    */
/* Description: This program takes as input the corner coordinates */
/*              of two squares and calculates the overlapping area */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){

    int sw1_x;
    int sw1_y;

    int ne1_x;
    int ne1_y;

    scanf("%d %d %d %d", &sw1_x, &sw1_y, &ne1_x, &ne1_y);

    if(sw1_x > ne1_x){
        int prevX = ne1_x;
        ne1_x = sw1_x;
        sw1_x = prevX;
    }
    if(sw1_y > ne1_y){
        int prevY = ne1_y;
        ne1_y = sw1_y;
        sw1_y = prevY;
    }

    int se2_x;
    int se2_y;

    int nw2_x;
    int nw2_y;

    scanf("%d %d %d %d", &se2_x, &se2_y, &nw2_x, &nw2_y);

    if(se2_x > nw2_x){
        int prevX = nw2_x;
        nw2_x = se2_x;
        se2_x = prevX;
    }
    if(se2_y > nw2_y){
        int prevY = nw2_y;
        nw2_y = se2_y;
        se2_y = prevY;
    }

    int count = 0;

    for (int sq_1_x = sw1_x; sq_1_x != ne1_x; ++sq_1_x) {
        for (int sq_1_y = sw1_y; sq_1_y != ne1_y; ++sq_1_y) {
            for (int sq_2_x = se2_x; sq_2_x != nw2_x; ++sq_2_x) {
                for (int sq_2_y = se2_y; sq_2_y != nw2_y; ++sq_2_y) {
                    if(sq_1_x == sq_2_x && sq_1_y == sq_2_y ){
                        count++;
                    }
                }
            }
        }
    }

    printf("%d", count);

    return 0;
}