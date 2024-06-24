#include "s21_string.h"

void s21_str_from_s(char **point_str, va_list *args, Flags *spec) {
  char *value = va_arg(*args, char *);
  char buffer[1000] = {0};

  if (spec->tolerance >= 0) {
    s21_strncpy(buffer, value, spec->tolerance);
    buffer[spec->tolerance] = '\0';
  } else {
    s21_strcpy(buffer, value);
  }

  int str_len = s21_strlen(buffer);
  int field_width = spec->width - str_len;

  if (field_width > 0 && !spec->flag_minus) {
    while (field_width--) {
      *(*point_str)++ = ' ';
    }
  }

  s21_strcpy(*point_str, buffer);
  *point_str += str_len;

  if (field_width > 0 && spec->flag_minus) {
    while (field_width--) {
      *(*point_str)++ = ' ';
    }
  }
}