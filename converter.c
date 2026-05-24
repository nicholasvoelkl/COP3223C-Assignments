//Compilation Command: gcc -Wall -Wextra -std=c17 -o converter converter.c
#include <stdio.h>

int display_menu(void);

int main(void) {

    int choice = 0;

    do {
        
        choice = display_menu();



        


        if (choice == 5){
            printf("Goodbye!")
        }

    } while (choice != 5);
}

int display_menu(void) {
    int userinput;
    printf("= Unit Conversion Station =\n");
    printf("1. Temperature  (Celsius <-> Fahrenheit)\n");
    printf("2. Distance     (Miles <-> Kilometers)\n");
    printf("3. Weight       (Pounds <-> Kilograms)\n");
    printf("4. Speed        (MPH <-> KPH)\n");
    printf("5. Quit\n");
    printf("Enter choice (1-5): "); fscanf(stdin, "%d", &userinput);
    return userinput;
}