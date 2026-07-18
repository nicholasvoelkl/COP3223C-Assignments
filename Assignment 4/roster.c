#include <stdio.h>
#include <string.h>
#include "roster.h"

Student  create_student(const char *first, const char *last,int id, double gpa){
    Student temp = {0};
    strncpy(temp.first_name, first, sizeof(temp.first_name) - 1);
    temp.first_name[sizeof(temp.first_name) - 1] = '\0';

    strncpy(temp.last_name, last, sizeof(temp.last_name) - 1);
    temp.last_name[sizeof(temp.last_name) - 1] = '\0';

    temp.student_id = id;
    temp.gpa = gpa;

    if (gpa < 0 || gpa > 4.0){
        temp.standing = GRADE_INVALID;
    } else if (gpa >= 3.5) {
        temp.standing = GRADE_A;
    } else if (gpa >= 3.0) {
        temp.standing = GRADE_B;
    } else if (gpa >= 2.0) {
        temp.standing = GRADE_C;
    } else if (gpa >= 1.0) {
        temp.standing = GRADE_D;
    } else {
        temp.standing = GRADE_F;}
    return temp;
}

int roster_add(Roster *r, Student s){
    if (r->count == MAX_STUDENTS){return 0;}
    for (int num = 0; num < r->count; num++){ 
        if (r->students[num].student_id == s.student_id) {
            return -1;}}
    r->students[r->count] = s;
    r->count++; return 1;
}

int roster_remove(Roster *r, int student_id){
    for (int num = 0; num < r->count; num++){
        if (r->students[num].student_id == student_id) {
            for (int shift = num; shift < r->count - 1; shift++){
                r->students[shift] = r->students[shift + 1];}
            r->count--;
            return 1;
        }    
    }
    return 0;
}

Student *roster_find_by_id(Roster *r, int student_id){
    for (int num = 0; num < r->count; num++){
        if (r->students[num].student_id == student_id){
            return &r->students[num];}
    }
    return NULL;
}

Student *roster_find_by_name(Roster *r, const char *last_name){
        for (int num = 0; num < r->count; num++){
            if (strcmp(r->students[num].last_name, last_name) == 0){ 
                return &r->students[num];}}
        return NULL;
}

void roster_sort_by_name(Roster *r){
    Student temp;
    for (int sorted = 0; sorted < r->count - 1; sorted++){
    for (int num = 0; num < r->count - 1 - sorted; num++){
        if (strcmp(r->students[num].last_name, r->students[num + 1].last_name) == 0){
            if (strcmp(r->students[num].first_name, r->students[num + 1].first_name) > 0){
                temp = r->students[num];
                r->students[num] = r->students[num + 1];
                r->students[num + 1] = temp;}
            } else if (strcmp(r->students[num].last_name, r->students[num + 1].last_name) > 0){
                temp = r->students[num];
                    r->students[num] = r->students[num + 1];
                    r->students[num + 1] = temp;}
        }}
    }

void roster_sort_by_gpa(Roster *r){
    Student temp;
    for (int sorted = 0; sorted < r->count - 1; sorted++){
    for (int num = 0; num < r->count - 1 - sorted; num++){
        if (r->students[num].gpa < r->students[num + 1].gpa){
            temp = r->students[num];
            r->students[num] = r->students[num + 1];
            r->students[num + 1] = temp;
        }
    }}
}

void print_student(const Student *s){
    if (s == NULL) { printf("No Student to Print\n"); return; }
    const char *grade = grade_to_string(s->standing);
    char full_name[65] = {0};
    strncat(full_name, s->last_name,  sizeof(full_name) - strlen(full_name) - 1);
    strncat(full_name, ", ",          sizeof(full_name) - strlen(full_name) - 1);
    strncat(full_name, s->first_name, sizeof(full_name) - strlen(full_name) - 1);
    printf("[%d] %-20s GPA: %.2f  Standing: %s\n", s->student_id, full_name, s->gpa, grade);
}

void print_roster(const Roster *r){
    printf("╔══════════════════════════════════════════════════╗\n");
    printf("║  Student Roster (%d students)%-21s║\n", r->count, "");
    printf("╠══════════════════════════════════════════════════╣\n");
    for (int num = 0; num < r->count; num++){
        printf("  ");
        print_student(&r->students[num]);
    }
    printf("╠══════════════════════════════════════════════════╣\n");
    printf("║  Class average GPA: %-29.2f║\n", roster_average_gpa(r));
    printf("╚══════════════════════════════════════════════════╝\n");
}

const char *grade_to_string(Grade g){
    switch(g){
        case GRADE_A: return "A";
        case GRADE_B: return "B";
        case GRADE_C: return "C";
        case GRADE_D: return "D";
        case GRADE_F: return "F";
        default: return "Incomplete";
    }
}

double roster_average_gpa(const Roster *r){
    double total = 0.0;
    if (r->count == 0){return 0.0;}
    for (int num = 0; num < r->count; num++){
        total += r->students[num].gpa;
    }
    return total/r->count;
}