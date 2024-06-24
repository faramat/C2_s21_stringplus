#include "s21_string.h"

void s21_itoa(int value, char *buffer) {
  char temp[50];
  char *ptr = temp + sizeof(temp) - 1;
  int is_negative = value < 0;

  *ptr = '\0';
  if (is_negative) value = -value;

  do {
    *--ptr = '0' + (value % 10);
    value /= 10;
  } while (value > 0);

  s21_strcpy(buffer, ptr);
}