#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *last_occurrence = S21_NULL;
  while (*str != '\0') {
    if (*str == (char)c) {
      last_occurrence = str;
    }
    str++;
  }

  if (c == '\0') {
    last_occurrence = (char *)str;
  }

  return (char *)last_occurrence;
}