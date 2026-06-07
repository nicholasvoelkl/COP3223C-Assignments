//Compilation Command: gcc -Wall -Wextra -std=c17 -o toolkit toolkit.c mathlib.c -lm
#include <stdio.h>
#include "mathlib.h"

//Main
int main(void) {
    int choice = 0;
    int answer_int;
    int answer_lf;
    do {
        choice = display_menu();
        switch(choice){
            case 1:
                int value; int lo; int hi;
                printf("Enter value, lo, hi: "); fscanf(stdin, "%d %d %d", &value, &lo, &hi);
                answer_int = clamp(value, lo, hi);
                printf("clamp(%d, %d, %d) = %d\n", value, lo, hi, answer_int);
                break;
            case 2:
                double base; int exp;
                printf("Enter base and exponent: "); fscanf(stdin,"%lf %d", &base, &exp);
                answer_lf = power(base, exp);
                printf("power(%lf, %d) = %lf", base, exp, answer_lf);
                break;
            case 3:
                is_prime(int n); break;
            case 4:
                gcd(int a, int b);
            case 5:
                average(int arr[], int len);
            case 6:
                count_digits(long long n);
            case 7:
                printf("Goodbye!\n");
        }
    } while (choice != 7);
}