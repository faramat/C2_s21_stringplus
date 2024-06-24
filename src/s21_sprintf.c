#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  s21_size_t flag = 0, error = 0;
  char *str_start = str;
  char *point_str = str;

  while (*format && error == 0 && !flag) {
    Flags spec = {0};
    spec.width = spec.tolerance = -1;
    if (*format == '%') {
      format++;
      if (s21_check(FLAG, *format))
        while (s21_check(FLAG, *format)) s21_set_flag(&spec, format++);

      if ((s21_check(DIGIT, *format) || *format == '*'))
        format = s21_str_to_int(format, &spec.width);

      if (*format == '.') {
        spec.tolerance = 0;
        format = s21_str_to_int(++format, &spec.tolerance);
      }

      if (s21_check(LEN, *format)) spec.len = *(format++);
      if (s21_check(SPEC, *format)) spec.spec = *(format++);

      s21_format_param_to_str(&point_str, &spec, &args);
      error = spec.flag_error;
      flag = 0;
    } else {
      *point_str = *format;
      point_str++;
      *point_str = '\0';
      format++;
    }
  }
  va_end(args);
  if (error != 0)
    *str_start = '\0';
  else
    *point_str = '\0';
  return error == 0 ? (int)(point_str - str) : -1;
}
