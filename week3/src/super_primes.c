/* file: sum_div_pal.c                                       */
/* author: Stan van der Bend (email: stanvdbend@gmail.com)   */
/* date: 17-9-2018                                           */
/* version: 1.0                                              */
/* Description: this program determines whether the input n  */
/* is a sum div pal number.                                  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int num) {

    if(num == 1)
        return 0;

    int i;
    for (i = 2; i < num; i++) {
        if (num % i == 0 && i != num)
            return 0;
    }
    return 1;
}

int dropDigit(int primeNum, int length, int index){

    int digit = primeNum;

    int divisor = 1;
    int split[length];

    for (int i = 0; i < length; ++i) {

        int value = digit / divisor % 10;

        split[i] = value;
        divisor *= 10;

    }
    digit = 0;
    divisor /= 10;

    int arr[length-1];
    int count = 0;

    for (int k = 0; k < length; ++k) {

        int i = length - k - 1;

//        printf("checking [%d]=%d \n", k, split[i]);
        if(k != index){
            divisor /= 10;
            arr[count] = split[i] * divisor;
            digit += arr[count];
//            printf("new num = %d (from %d)", digit, arr[count]);
            count++;
        }

    }

//    printf("%d -> %d", primeNum, digit);

    return digit;
}


int isSuperPrime(int primeNum){

    return 0;
}
int main(int argc, char *argv[]) {

    int n;
    int p;

    scanf("%d", &n);



    int superPrime = 0;
    int superPrimeCount = 0;

    /* Go from 3 to 49 and print prime numbers without checking even numbers */
    for (p = 3; p < 400000; p+=2) {
        if (isPrime(p)){

            int length = 0;
            int primeNum = p;

            while(primeNum != 0) {
                primeNum /= 10;
                ++length;
            }
//            printf("m = %d, l = %d \n",p,  length);
            int isSuperPrime = 1;

            if(length < 2){
                continue;
            }

            for (int i = 0; i < length; ++i) {
                int number = dropDigit(p, length, i);

//                printf("n = %d\n", number);

                if(!isPrime(number)){
//                    printf("%d is not a prime number", number);
                    isSuperPrime = 0;
                    break;
                }
            }
            if(isSuperPrime){
                superPrime = p;
                superPrimeCount++;

                if(superPrimeCount == n){
                    printf("%d", superPrime);
                    return 0;
                }
            }
        }
    }



    return 0;
}