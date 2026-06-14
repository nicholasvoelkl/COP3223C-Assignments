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

void array_stats(const int arr[], int len, int *out_min, int *out_max, double *out_avg){
    if (len <= 0){*out_min = *out_max = 0; *out_avg = 0.0; return;}
    *out_min = 2147483647;
    *out_max = -2147483647;
    int total = 0;
    for (int count = 0; count < len; count++){
        if (arr[count] < *out_min){*out_min = arr[count];}
        if (arr[count] > *out_max){*out_max = arr[count];}
        total += arr[count];}
    *out_avg = (double)total/len;}

int array_find(const int arr[], int len, int target){
    int position = 0;
    for (int count = 0; count < len; count++){
        if (target != arr[count]){
            position++;}
        if (target == arr[count]){
            return position;}}
    return -1;
}