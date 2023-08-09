#include "my_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_string(char *str) {
  while (*str != '\0') {
    printf("%c", *str);
    str++;
  }
  printf("\n");
}

size_t my_strlen(const char *str) {
  size_t counter = 0;
  while (str[counter] != '\0') {
    counter++;
  }
  return counter;
}

void *my_memcpy(void *dest, void *src, size_t byte_count) {
  char *s = src;
  char *d = dest;
  while (byte_count--) {
    *d++ = *s++;
  }
  return dest;
}

char *my_strcpy(char *dest, char *src) {
  if (dest == NULL) {
    return NULL;
  }

  return my_memcpy(dest, src, my_strlen(src) + 1);
}

char *my_strncpy(char *dest, char *src, size_t n) {
  if (dest == NULL) {
    return NULL;
  }
  *(dest + n) = '\0';
  return my_memcpy(dest, src, n);
}

char *my_strcat(char *dest, char *src) {
  if (dest == NULL) {
    return NULL;
  }

  size_t dest_length = my_strlen(dest);
  size_t counter = 0;
  while (src[counter] != '\0') {
    dest[dest_length] = src[counter];
    counter++;
    dest_length++;
  }
  dest[dest_length] = '\0';
  return dest;
}

char *my_strncat(char *dest, char *src, size_t n) {
  if (dest == NULL) {
    return NULL;
  }

  size_t dest_length = my_strlen(dest);
  size_t counter = 0;
  while (src[counter] != '\0' && counter < n) {
    dest[dest_length] = src[counter];
    counter++;
    dest_length++;
  }
  dest[dest_length] = '\0';
  return dest;
}

int my_strcmp(char *lhs, char *rhs) {
  unsigned char c1, c2;
  do {
    c1 = *lhs++;
    c2 = *rhs++;
    if (c1 == '\0') {
      return c1 - c2;
    }
  } while (c1 == c2);
  return c1 - c2;
}

int my_strncmp(char *lhs, char *rhs, size_t n) {
  unsigned char c1, c2;
  do {
    c1 = *lhs++;
    c2 = *rhs++;
    if (c1 == '\0') {
      return c1 - c2;
    }
  } while (c1 == c2 && n-- > 1);
  return c1 - c2;
}

char *my_strchr(char *str, char chr) {
  while (*str++ != '\0') {
    if (*str == '\0')
      return NULL;
    if (*str == chr)
      return str;
  }
  return NULL;
}

char *my_strrchr(char *str, char chr) {
  char *result = NULL;
  while (*str++ != '\0') {
    if (*str == '\0')
      return result;
    if (*str == chr)
      result = str;
  }
  return result;
}

char *my_strstr(char *str1, char *str2) {
  size_t str1_length = my_strlen(str1);
  for (size_t i = 0; i < str1_length; i++) {
    char *str1_ptr = str1 + i;
    char *str2_ptr = str2;
    while ((char)*str1_ptr == (char)*str2_ptr) {
      str1_ptr++;
      str2_ptr++;
      if ((char)*str2_ptr == '\0') {
        return str1 + i;
      }
    }
  }
  return NULL;
}

size_t my_strcspn(char *str1, char *str2) {
  size_t str1_length = my_strlen(str1);
  size_t str2_length = my_strlen(str2);
  for (size_t i = 0; i < str1_length; i++) {
    for (size_t j = 0; j < str2_length; j++) {
      if (str1[i] == str2[j])
        return i;
      j++;
    }
  }
  return str1_length;
}

size_t my_strspn(char *string, char *chars) {
  char *s, *p, c;
  for (s = string, c = *s; c != '\0'; s++, c = *s) {
    for (p = chars; *p != '\0'; p++) {
      if (c == *p) {
        goto next;
      }
    }
    break;
  next:;
  }
  return s - string;
}

char *my_strpbrk(char *string, char *chars) {
  char *s, *p, c;
  for (s = string, c = *s; c != '\0'; s++, c = *s) {
    for (p = chars; *p != '\0'; p++) {
      if (c == *p) {
        return s;
      }
    }
  }
  return NULL;
}

void *my_memset(void *ptr, int x, size_t n) {
  char *p = (char *)ptr;
  while (n--) {
    *p++ = (unsigned char)x;
  }
  return ptr;
}

int my_memcmp(void *ptr1, void *ptr2, size_t n) {
  char *p1 = ptr1, *p2 = ptr2;
  for (; *p1 == *p2 && n; n--, p1++, p2++)
    ;
  return n ? *p1 - *p2 : 0;
}

void *my_memmove(void *dest, void *src, size_t n) {
  char temp[n];
  char *d = (char *)dest, *s = src;
  for (int i = 0; i < n; i++) {
    temp[i] = s[i];
  }

  for (int i = 0; i < n; i++) {
    d[i] = temp[i];
  }
  return dest;
}

void *memchr(void *src, char c, size_t n) {
  char *s = src;

  for (; n && *s != c; s++, n--)
    ;
  return n ? (void *)s : NULL;
}