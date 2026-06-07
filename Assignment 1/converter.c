//Compilation Command: gcc -Wall -Wextra -std=c17 -o converter converter.c
#include <stdio.h>

//Constants
const double C_TO_F_SCALE  = 9.0 / 5.0;
const double F_TO_C_SCALE = 5.0 / 9.0;
const double CF_OFFSET = 32.0;
const double MI_TO_KM      = 1.60934;
const double LB_TO_KG      = 0.453592;

//Declared Functions
int display_menu(void);
int confirm_valid(int min, int max);
int confirm_subvalid(int min, int max);
void temp_convert(void);
void distance_convert(void);
void weight_convert(void);
void speed_convert(void);

//Main
int main(void) {
    int choice = 0;
    do {
        choice = display_menu();
        switch(choice){
            case 1:
                temp_convert(); break;
            case 2:
                distance_convert(); break;
            case 3:
                weight_convert(); break;
            case 4:
                speed_convert(); break;
            case 5:
                printf("Goodbye!\n");
        }
    } while (choice != 5);
}

//Functions
//Confirm valid for main
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

//Confirms valid for sub-menu
int confirm_subvalid(int min, int max){
    int userinput = 0;
    //Uses do-while loop to verify input
    do {
        printf("Enter choice (%d-%d): ",min,max); fscanf(stdin, "%d", &userinput);
        if (userinput >= min && userinput <= max){
            return userinput;
        } else if (userinput < min || userinput > max) {
            printf("Invalid direction. Try again.\n");
        }
    } while (userinput < min || userinput > max);
    return 0;
}

//Display Menu
int display_menu(void) {
    int userinput = 0;
    printf("\n= Unit Conversion Station =\n");
    printf("1. Temperature  (Celsius <-> Fahrenheit)\n");
    printf("2. Distance     (Miles <-> Kilometers)\n");
    printf("3. Weight       (Pounds <-> Kilograms)\n");
    printf("4. Speed        (MPH <-> KPH)\n");
    printf("5. Quit\n");
    
    userinput = confirm_valid(1, 5);
    return userinput;
}

//Temperature Conversion
void temp_convert(void){
    int userinput = 0;
    double temp = 0;
    double finaltemp = 0;
    printf("--- Temperature ---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    //Uses do-while loop to verify input
    userinput = confirm_subvalid(1, 2);
    if (userinput == 1) {
        printf("Enter temperature in Celsius: "); fscanf(stdin, "%lf", &temp);
        finaltemp = temp*C_TO_F_SCALE+CF_OFFSET;
        printf("%.2lf°C = %.2lf°F\n", temp, finaltemp);
    } else if (userinput == 2){
        printf("Enter temperature in Fahrenheit: "); fscanf(stdin, "%lf", &temp);
        finaltemp = (temp-CF_OFFSET)*F_TO_C_SCALE;
        printf("%.2lf°F = %.2lf°C\n", temp, finaltemp);
    }
}

//Distance Conversion
void distance_convert(void){
    int userinput = 0;
    double distance = 0;
    double finaldistance = 0;
    printf("--- Distance ---\n");
    printf("1. Miles to Kilometers\n");
    printf("2. Kilometers to Miles\n");
    userinput = confirm_subvalid(1, 2);
    if (userinput == 1) {
        printf("Enter distance in miles: "); fscanf(stdin, "%lf", &distance);
        finaldistance = distance*MI_TO_KM;
        printf("%.2lf miles = %.2lf km\n", distance, finaldistance);
    } else if (userinput == 2){
        printf("Enter distance in kilometers: "); fscanf(stdin, "%lf", &distance);
        finaldistance = distance/MI_TO_KM;
        printf("%.2lf km = %.2lf miles\n", distance, finaldistance);
    }
}

//Weight Conversion
void weight_convert(void){
    int userinput = 0;
    double weight = 0;
    double finalweight = 0;
    printf("--- Weight ---\n");
    printf("1. Pounds to Kilograms\n");
    printf("2. Kilograms to Pounds\n");
    userinput = confirm_subvalid(1, 2);
    if (userinput == 1) {
        printf("Enter weight in pounds: "); fscanf(stdin, "%lf", &weight);
        finalweight = weight*LB_TO_KG;
        printf("%.2lf lbs = %.2lf kg\n", weight, finalweight);
    } else if (userinput == 2){
        printf("Enter weight in kilograms: "); fscanf(stdin, "%lf", &weight);
        finalweight = weight/LB_TO_KG;
        printf("%.2lf kg = %.2lf lbs\n", weight, finalweight);
    }
}

//Speed
void speed_convert(void){
    int userinput = 0;
    double speed = 0;
    double finalspeed = 0;
    printf("--- Speed ---\n");
    printf("1. MPH to KPH\n");
    printf("2. KPH to MPH\n");
    userinput = confirm_subvalid(1, 2);
    if (userinput == 1) {
        printf("Enter speed in MPH: "); fscanf(stdin, "%lf", &speed);
        finalspeed = speed*MI_TO_KM;
        printf("%.2lf MPH = %.2lf KPH\n", speed, finalspeed);
    } else if (userinput == 2){
        printf("Enter speed in KPH: "); fscanf(stdin, "%lf", &speed);
        finalspeed = speed/MI_TO_KM;
        printf("%.2lf KPH = %.2lf MPH\n", speed, finalspeed);
    }
}