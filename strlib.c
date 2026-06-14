#include <stdio.h>
#include "strlib.h"

int str_length(const char *s){
    int count = 0;
    while (*s != '\0'){
        count++;
        s++;}
return count;
}

void str_copy(char *dst, const char *src, int dst_size){
    int counter = 0;
    while (*src != 0 && counter < dst_size - 1){
        *dst = *src;
        src++;
        dst++;
        counter++;}
    *dst = '\0';
}

int str_compare(const char *a, const char *b){
    while (*a != '\0' && *b != '\0'){
        if (*a != *b){
            return *a - *b;}
        a++;
        b++;}
    return *a - *b;
}

void str_reverse(char *s){
    char *start =  s;
    char *end = s + str_length(s) - 1;
    while (start < end){
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int str_count_char(const char *s, char c){
    int appearances = 0;
    while (*s != '\0'){
        if (*s == c){appearances++;}
        s++;}
    return appearances;
}

void str_to_upper(char *s){
    while (*s != '\0'){
        if  (*s >= 'a' && *s <= 'z'){
            *s -= 32;}
        s++;}
}