#include "s21_string.h"

void s21_str_from_u(char **point_str, va_list *args, Flags *spec) {
  char buffer[1000] = {0};
  unsigned int value = va_arg(*args, unsigned int);

  s21_utoa(value, buffer);

  int str_len = s21_strlen(buffer);
  int num_len = s21_strlen(buffer);
  int total_len = num_len;

  if (spec->tolerance > num_len) {
    total_len = spec->tolerance;
  }

  int field_width = spec->width - total_len;

  if (field_width > 0 && !spec->flag_minus && !spec->flag_zero) {
    while (field_width-- > 0) {
      *(*point_str)++ = ' ';
    }
  }

  if (spec->tolerance > num_len) {
    int zero_fill = spec->tolerance - num_len;
    while (zero_fill-- > 0) {
      *(*point_str)++ = '0';
    }
  }

  s21_strcpy(*point_str, buffer);
  *point_str += str_len;

  if (field_width > 0 && spec->flag_minus) {
    while (field_width-- > 0) {
      *(*point_str)++ = ' ';
    }
  }
}