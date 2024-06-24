#include "s21_string.h"

void s21_format_param_to_str(char **point_str, Flags *spec, va_list *args) {
  switch (spec->spec) {
    case 'c':
      s21_str_from_c(point_str, args);
      break;
    case 'd':
      s21_str_from_d(point_str, args, spec);
      break;
    case 'f':
      s21_str_from_f(point_str, args, spec);
      break;
    case 's':
      s21_str_from_s(point_str, args, spec);
      break;
    case 'u':
      s21_str_from_u(point_str, args, spec);
      break;
    case '%':
      s21_str_from_perc(point_str);
      break;
  }
}