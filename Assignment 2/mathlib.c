#include <stdio.h>
#include "mathlib.h"

int clamp(int value, int lo, int hi){
    if (value < lo){
        return lo;
    } else if (value > hi){
        return hi;
    } else {
        return value;
    }
}

double power(double base, int exp){
    double answer = 1.0;
    int count = exp;
    if (exp > 0){
        do{
            answer *= base;
            count -= 1;
        } while (count != 0);
        return answer;
    } else if (exp < 0){
        do{
            answer *= base;
            count += 1;
        } while (count != 0);
        return 1.0/answer;
    } else {
    return 1.0;
    }
}

int is_prime(int n){
    int count = 0;
    if (n <= 1) {
        return 0;
    }
    for (int countup = 1; countup < n + 1; countup++){
        if (n%countup == 0){ count += 1;}
    }
    return (count > 2) ? 0: 1;
}

int gcd(int a, int b){
    int c; int r;
    if (a < b){c = a; a = b; b = c;}
    do {
        c = a/b;
        r = a%b;
        a = b;
        b = r;
    } while (r != 0);
    return a;
}

double average(int arr[], int len){
    if (len <= 0){
        return 0;
    }
    double total = 0;
    for (int x = 0; x < len; x++){
        total += arr[x];
    }
    return total/len;
}

int count_digits(long long n){
    int count = 0;
    long long number = n;
    if (n == 0){
        return 1;
    } else {
        do  {
            number = number/10;
            count += 1;
        } while (number <= -1 || number >= 1);
    }
    return count;
}