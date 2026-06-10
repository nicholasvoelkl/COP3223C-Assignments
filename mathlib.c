#include "mathlib.h"

int confirm_valid(int min, int max){
    int userinput = 0;
    //Uses do-while loop to verify input
    do {
        printf("Enter choice (%d-%d): ",min,max); fscanf(stdin, "%d", &userinput);
        if (userinput >= min && userinput <= max){
            return userinput;
        } else if (userinput < min || userinput > max) {
            printf("Invalid choice. Try again.\n");
        }
    } while (userinput < min || userinput > max);
    return 0;
}

int display_menu(void) {
    int userinput = 0;
    printf("\n= Math Toolkit =\n");
    printf("1. Clamp a value\n");
    printf("2. Compute a power\n");
    printf("3. Prime check\n");
    printf("4. GCD\n");
    printf("5. Array average\n");
    printf("6. Count digits\n");
    printf("7. Quit\n");
    
    userinput = confirm_valid(1, 7);
    return userinput;
}

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
    return (count > 2) ? 0: 1
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
    return c;
}

double average(int arr[], int len){

}

int count_digits(long long n){

}