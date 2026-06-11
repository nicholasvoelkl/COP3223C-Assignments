//Compilation Command: gcc -Wall -Wextra -std=c17 -o toolkit toolkit.c mathlib.c -lm
#include <stdio.h>
#include "mathlib.h"

//Main
int main(void) {
    int choice = 0;
    int answer_int;
    double answer_lf;
    do {
        choice = display_menu();
        switch(choice){
            case 1:{
                int value; int lo; int hi;
                printf("Enter value, lo, hi: "); fscanf(stdin, "%d %d %d", &value, &lo, &hi);
                answer_int = clamp(value, lo, hi);
                printf("clamp(%d, %d, %d) = %d\n", value, lo, hi, answer_int);
                break;}
            case 2:{
                double base; int exp;
                printf("Enter base and exponent: "); fscanf(stdin,"%lf %d", &base, &exp);
                answer_lf = power(base, exp);
                printf("power(%.2f, %d) = %.2f\n", base, exp, answer_lf);
                break;}
            case 3:{
                int number;
                printf("Enter n: "); fscanf(stdin,"%d", &number);
                answer_int = is_prime(number);
                if (answer_int == 1){
                    printf("%d is prime.\n", number);}
                else {
                    printf("%d is not prime.\n", number);}
                break;}
            case 4:{
                int a; int b;
                printf("Enter a and b: "); fscanf(stdin,"%d %d", &a, &b);
                answer_int = gcd( a, b);
                printf("gcd(%d, %d) = %d\n", a, b, answer_int);
                break;}
            case 5:{
                int len;
                printf("Enter count then values: "); fscanf(stdin,"%d", &len);
                int number_list[len];
                for (int x = 0; x < len; x++){
                    fscanf(stdin,"%d",&number_list[x]);
                }
                answer_lf = average(number_list, len);
                printf("average = %.2f\n", answer_lf);
                break;}
            case 6:{
                long long long_number;
                printf("Enter integer: "); fscanf(stdin,"%lld", &long_number);
                answer_int = count_digits(long_number);
                printf("%lld has %d digits.\n", long_number, answer_int);
                break;}
            case 7:{
                printf("Goodbye!\n");}
        }
    } while (choice != 7);
}