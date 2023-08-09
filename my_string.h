#ifndef __STRING_H__
#define __STRING_H__

#include <stdlib.h>

// Utilities
void print_string(char *str);

// Core functions
size_t my_strlen(const char *str);
void *my_memcpy(void *dest, void *src, size_t byte_count);
void *my_memmove(void *dest, void *src, size_t byte_count);
char *my_strcpy(char *dest, char *src);
char *my_strncpy(char *dest, char *src, size_t n);
char *my_strcat(char *dest, char *src);
char *my_strncat(char *dest, char *src, size_t n);
int my_strcmp(char *lhs, char *rhs);
int my_strncmp(char *lhs, char *rhs, size_t n);
char *my_strchr(char *str, char chr);
char *my_strrchr(char *str, char chr);
size_t my_strcspn(char *str1, char *str2);
size_t my_strspn(char *string, char *chars);
char *my_strpbrk(char *string, char *chars);
void *my_memset(void *ptr, int x, size_t n);
int my_memcmp(void *ptr1, void *ptr2, size_t n);
void *memchr(void *src, char c, size_t n);
#endif