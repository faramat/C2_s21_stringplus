#include "s21_string.h"

char *s21_str_to_int(const char *format, int *number) {
  *number = 0;
  while (s21_check(DIGIT, *format)) {
    *number = *format - '0' + *number * 10;
    format++;
  }
  return (char *)format;
}