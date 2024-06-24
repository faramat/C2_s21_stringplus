#include "s21_string.h"

void s21_str_from_f(char **point_str, va_list *args, Flags *spec) {
  char buffer[100];
  double value = va_arg(*args, double);

  int precision = spec->tolerance >= 0 ? spec->tolerance : 6;

  s21_ftoa(value, buffer, precision);

  int str_len = s21_strlen(buffer);

  int field_width = spec->width - str_len;
  if (field_width > 0 && !spec->flag_minus) {
    while (field_width--) {
      *(*point_str)++ = spec->flag_zero ? '0' : ' ';
    }
  }

  if (value < 0) {
    *(*point_str)++ = '-';
  } else if (spec->flag_plus) {
    *(*point_str)++ = '+';
  } else if (spec->flag_space) {
    *(*point_str)++ = ' ';
  }

  s21_strcpy(*point_str, buffer);
  *point_str += str_len;

  if (field_width > 0 && spec->flag_minus) {
    while (field_width--) {
      *(*point_str)++ = ' ';
    }
  }
}