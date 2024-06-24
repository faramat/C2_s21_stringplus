#include "s21_string.h"

s21_size_t s21_strspn(const char *str, const char *str2) {
  const char *tmp = str;
  const char *tmp2;
  int found = 0;
  while (*tmp && !found) {
    found = 1;
    for (tmp2 = str2; *tmp2; tmp2++) {
      if (*tmp == *tmp2) {
        found = 0;
      }
    }
    if (!found) {
      tmp++;
    }
  }
  return tmp - str;
}

char *s21_strtok(char *str, const char *delim) {
  static char *last = S21_NULL;
  char *result = S21_NULL;

  if (str == S21_NULL) {
    str = last;
  }
  if (str != S21_NULL) {
    str += s21_strspn(str, delim);
    if (*str != '\0') {
      char *end = str + s21_strcspn(str, delim);
      if (*end == '\0') {
        last = S21_NULL;
      } else {
        *end = '\0';
        last = end + 1;
      }
      result = str;
    }
  }
  return result;
}