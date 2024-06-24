#include "s21_string.h"

void s21_set_flag(Flags *spec, const char *format) {
  switch (*format) {
    case '-':
      spec->flag_minus = 1;
      break;
    case '+':
      spec->flag_plus = 1;
      break;
    case ' ':
      spec->flag_space = 1;
      break;
  }
}