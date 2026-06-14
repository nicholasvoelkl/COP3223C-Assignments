//Compilation command: gcc -Wall -Wextra -std=c17 -o strtool strtool.c strlib.c
#include <stdio.h>
#include "strlib.h"

int display_prompt(void);


int main(void){
    const int max_string_length = 200;
    int choice = 0;

    do {
        choice = display_prompt();
        switch(choice){
            case 1:{
                char string[max_string_length];
                printf("Enter string: "); fscanf(stdin,"%s", string);
                int length = str_length(string);
                printf("Length: %d\n", length);
                break;}
            case 2:{
                char dst[8]; char src[max_string_length];
                printf("Enter string: "); fscanf(stdin," %[^\n]", src);
                str_copy(dst, src, sizeof(dst));
                printf("Destination: %s\n", dst);
                break;}
            case 3:{
                char string1[max_string_length]; char string2[max_string_length];
                printf("Enter first string: "); fscanf(stdin,"%s", string1);
                printf("Enter second string: "); fscanf(stdin,"%s", string2);
                int result = str_compare(string1, string2);
                if (result < 0){printf("%s comes before %s\n", string1, string2);}
                if (result > 0){printf("%s comes after %s\n", string1, string2);}
                if (result == 0){printf("%s equals %s\n", string1, string2);}
                break;}
            case 4:{
                char string_frev[max_string_length];
                printf("Enter string: "); fscanf(stdin,"%s", string_frev);
                str_reverse(string_frev);
                printf("Reversed: %s\n", string_frev);
                break;}
            case 5:{  
                char string_fcount[max_string_length]; char character;
                printf("Enter string: "); fscanf(stdin," %[^\n]", string_fcount);
                printf("Enter character: "); fscanf(stdin," %c", &character);
                int appearances = str_count_char(string_fcount, character);
                printf("Count: %d\n", appearances);
                break;}
            case 6:{
                char string_forup[max_string_length];
                printf("Enter string: "); fscanf(stdin,"%s", string_forup);
                str_to_upper(string_forup);
                printf("Upper: %s\n", string_forup);
                break;}
            case 7:{

                break;}
            case 8:{

                break;}
            case 9:{printf("Goodbye!\n");}
        }
    } while (choice != 9);
}

int display_prompt(void){
    int choice;
    printf("\n= String & Array Toolkit =\n");
    printf("1. String length\n");
    printf("2. String copy (with truncation demo)\n");
    printf("3. String compare\n");
    printf("4. Reverse a string\n");
    printf("5. Count a character\n");
    printf("6. Convert to uppercase\n");
    printf("7. Array stats (min/max/avg)\n");
    printf("8. Find value in array\n");
    printf("9. Quit\n");
    do{
        printf("Enter choice (1-9): "); fscanf(stdin,"%d",&choice);
        if (choice >= 1 && choice <= 9){
            return choice;
        } else {
            printf("Invalid choice. Try again.\n");}
    } while (choice > 9 || choice < 1);
    return 0;
}