/*************************************************************************************
* file:        pangram_primes.c
* author:      Stan van der Bend
* date:        15/10/2018
* version:     1.0
* Description: TODO:
*************************************************************************************/

#include <stdio.h>
#define MAX 10

int total_count = 0;

void swap_digits(int *first_digit, int *second_digit) {
    int copy_first_digit = *first_digit;
    *first_digit = *second_digit;
    *second_digit = copy_first_digit;
}

int is_prime(int num){
    if (num % 2 == 0)
        return 0;

    for(int i = 3;i * i <= num + 2; i = i + 2)
        if(num % i == 0)
            return 0;

    return 1;
}

void count_if_pp(const int *arr, int size, int l, int h) {
    int k = 0;


    for (int i = 0 ; i < size ; i++) {
        k = 10 * k + arr[i];
      //  printf("checking %d %d %d \n", size, k, arr[i]);
    }

    if(is_prime(k) && k >= l && k<= h && k != 1)
        total_count++;
}

void swap_and_count(int *digits, int next, int final, int min, int max) {

    if(next == final) {
//        int n = digits[next];
//        if(is_prime(n) && next >= min && next<= max && next != 1) {
//            total_count++;
//        }
//    total_count++;
        count_if_pp(digits, final + 1, min, max);
        return;
    }

    for(int i = next; i <= final; i++)
    {

        swap_digits((digits + i), (digits + next));
//        if(is_prime(digits[next]))
        swap_and_count(digits, next + 1, final, min, max);
        swap_digits((digits + i), (digits + next));
     //   printf("1-iterating %d %d  \n", next, digits[i]);
    }
}

int main() {

    int l_d_length = 0, u_d_length = 0;
    int upper_bound, lower_bound;

    scanf("%d %d", &lower_bound, &upper_bound);

    int org_lower_bound = lower_bound;
    int org_upper_bound = upper_bound;

    while(lower_bound != 0){
        lower_bound = lower_bound/10;
        l_d_length++;
    }

    while(upper_bound != 0){
        upper_bound = upper_bound/10;
        u_d_length++;
    }

    if(u_d_length == MAX){
        u_d_length--;
    }

    int digits[MAX];
    int prev_digit;
    int d_i;

    for (int dig_i = l_d_length ; dig_i <= u_d_length; dig_i++){

        prev_digit = dig_i;
        d_i = 0;
        while(prev_digit != 0){
            digits[d_i] = prev_digit;
            d_i++;
            prev_digit--;
        }

//        if(highestDigit >0){
//            if(is_prime(highestDigit)){
//                total_count++;
                swap_and_count(digits, 0, dig_i - 1, org_lower_bound, org_upper_bound);
//            }
//        }
//        printf("2-iterating %d %d \n", prev_digit, dig_i);

    }

    // 1 1000000000
    printf("%d", total_count);
    return 0;
}