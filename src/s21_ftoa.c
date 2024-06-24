#include "s21_string.h"

void s21_ftoa(double value, char *buffer, int precision) {
  char int_part[50];
  char frac_part[50];
  char *ptr = buffer;
  int is_negative = value < 0;

  if (is_negative) {
    value = -value;
  }

  unsigned long long int int_value = (unsigned long long int)value;
  s21_utoa(int_value, int_part);
  s21_strcpy(ptr, int_part);
  ptr += s21_strlen(int_part);

  if (precision > 0) *ptr++ = '.';

  double frac_value = value - int_value;
  for (int i = 0; i < precision; i++) {
    frac_value *= 10;
    int digit = (int)frac_value;
    frac_part[i] = '0' + digit;
    frac_value -= digit;
  }
  if (frac_value * 10 >= 5) {
    int idx = precision - 1;

    while (idx >= 0 && frac_part[idx] == '9') {
      frac_part[idx] = '0';
      idx--;
    }
    if (idx >= 0) {
      frac_part[idx]++;
    } else {
      int_part[s21_strlen(int_part) - 1]++;
    }
  }
  frac_part[precision] = '\0';
  s21_strcpy(ptr, frac_part);
}