#include "s21_string.h"

void s21_str_from_c(char **point_str, va_list *args) {
  char value = va_arg(*args, int);
  **point_str = value;
  (*point_str)++;
  **point_str = '\0';
}