#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *result = S21_NULL;
  int flag = 0;
  while (*str && !flag) {
    if (*str == c) {
      result = (char *)str;
      flag = 1;
    }
    str++;
  }

  if (c == '\0') {
    result = (char *)str;
  }

  return result;
}
