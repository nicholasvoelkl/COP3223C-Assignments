// Compilation Command: gcc -Wall -Wextra -std=c17 -o roster main.c roster.c

#include <stdio.h>
#include "roster.h"

int display_prompt(void);

int main (void){
int choice = 0;
Roster roster = {0};
    do {
        choice = display_prompt();
        switch(choice){
            case 1:{
                char first[32], last[32]; int id; double gpa;
                printf("First name: "); fscanf(stdin, " %31s", first);
                printf("Last name: ");  fscanf(stdin, " %31s", last);
                printf("Student ID: "); fscanf(stdin, "%d", &id);
                printf("GPA: ");        fscanf(stdin, "%lf", &gpa);
                int result = roster_add(&roster, create_student(first, last, id, gpa));
                if (result == 1){
                    printf("Student added.\n");
                } else if (result == 0){
                    printf("Roster Full, Student Not Added\n");
                } else { printf("ID Already Exists, Student Not Added\n");}
                break;}
            case 2:{
                int id;
                printf("Enter student ID: "); fscanf(stdin, "%d", &id);
                if (roster_remove(&roster, id)){
                    printf("Student removed.\n");
                } else {printf("Student Not Found\n");}
                break;}
            case 3:{
                int id;
                printf("Enter student ID: "); fscanf(stdin, "%d", &id);
                Student *s = roster_find_by_id(&roster, id);
                if (s != NULL){
                    print_student(s);
                } else {printf("Student not found.\n");}
                break;}
            case 4:{
                char last[32];
                printf("Enter last name: "); fscanf(stdin, " %31s", last);
                Student *s = roster_find_by_name(&roster, last);
                if (s != NULL){
                    print_student(s);
                } else { printf("Student not found.\n");}
                break;}
            case 5:{
                roster_sort_by_name(&roster);
                printf("Roster sorted by name.\n");
                break;}
            case 6:{
                roster_sort_by_gpa(&roster);
                printf("Roster sorted by GPA.\n");
                break;}
            case 7:{
                print_roster(&roster);
                break;}
            case 8:{
               printf("Goodbye!\n");
                break;}
        }
    } while (choice != 8);
}

int display_prompt(void){
    int choice;
    printf("\n= Student Roster System =\n");
    printf("1. Add student\n");
    printf("2. Remove student (by ID)\n");
    printf("3. Find student (by ID)\n");
    printf("4. Find student (by last name)\n");
    printf("5. Sort by name\n");
    printf("6. Sort by GPA\n");
    printf("7. Print roster\n");
    printf("8. Quit\n");
    do{
        printf("Enter choice (1-8): "); fscanf(stdin,"%d",&choice);
        if (choice >= 1 && choice <= 8){
            return choice;
        } else {
            printf("Invalid choice. Try again.\n");}
    } while (choice > 8 || choice < 1);
    return 0;
}