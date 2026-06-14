#ifndef STRLIB_H
#define STRLIB_H

int str_length(const char *s);

void str_copy(char *dst, const char *src, int dst_size);

int str_compare(const char *a, const char *b);

void str_reverse(char *s);

int str_count_char(const char *s, char c);

void str_to_upper(char *s);

#endif