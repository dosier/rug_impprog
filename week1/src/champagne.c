/* file: champagne.c                                         */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)   */
/* date: 5-9-2018                                            */
/* version: 1.0                                              */
/* Description: This program prints ’Hello world’            */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){

    int peopleCount;

    // read number of invited friends from the input (keyboard)
    scanf("%d", &peopleCount);

    // count user
    peopleCount++;

    // calculate total amount of champagne drank
    int totalChampagneInML = peopleCount * 150;
    // calculate the amount of bottles that need to be bought
    int requiredChampagneBottles = totalChampagneInML / 1500;

    // is there any leftover champagne?
    if(totalChampagneInML % 1500 > 0){
        requiredChampagneBottles++;
    }

    // print minimal amount of required champagne bottles
    printf("%d", requiredChampagneBottles);

    return 0;
}
