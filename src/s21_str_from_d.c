#include "s21_string.h"

void s21_str_from_d(char **point_str, va_list *args, Flags *spec) {
  char buffer[100] = {0};
  int value = va_arg(*args, int);
  int is_negative = value < 0;

  s21_itoa(value, buffer + (is_negative ? 1 : 0));

  int num_len = s21_strlen(buffer + (is_negative ? 1 : 0));
  int total_len = num_len;

  if (spec->tolerance > num_len) {
    total_len = spec->tolerance;
  }

  if (is_negative || spec->flag_plus || spec->flag_space) {
    total_len++;
  }

  int field_width = spec->width - total_len;

  if (field_width > 0 && !spec->flag_minus && !spec->flag_zero) {
    while (field_width-- > 0) {
      *(*point_str)++ = ' ';
    }
  }

  if (is_negative) {
    *(*point_str)++ = '-';
    buffer[0] = '\0';
  } else if (spec->flag_plus) {
    *(*point_str)++ = '+';
  } else if (spec->flag_space) {
    *(*point_str)++ = ' ';
  }

  if (spec->tolerance > num_len) {
    int zero_fill = spec->tolerance - num_len;
    while (zero_fill-- > 0) {
      *(*point_str)++ = '0';
    }
  }

  s21_strcpy(*point_str, buffer + (is_negative ? 1 : 0));
  *point_str += s21_strlen(buffer + (is_negative ? 1 : 0));

  if (field_width > 0 && spec->flag_minus) {
    while (field_width-- > 0) {
      *(*point_str)++ = ' ';
    }
  }
}