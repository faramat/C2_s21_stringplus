#include "s21_string.h"

int s21_check(CheckType type, char c) {
  int result = 0;
  switch (type) {
    case FLAG:
      result = c == '-' || c == '+' || c == ' ';
      break;
    case DIGIT:
      result = c >= '0' && c <= '9';
      break;
    case SPEC:
      result =
          c == 'c' || c == 'd' || c == 'f' || c == 's' || c == 'u' || c == '%';
      break;
    case LEN:
      result = c == 'h' || c == 'l';
      break;
  }
  return result;
}