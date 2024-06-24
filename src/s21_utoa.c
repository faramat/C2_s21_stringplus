#include "s21_string.h"

void s21_utoa(unsigned int value, char *buffer) {
  char temp[50];
  char *ptr = temp + sizeof(temp) - 1;

  *ptr = '\0';

  do {
    *--ptr = '0' + (value % 10);
    value /= 10;
  } while (value > 0);

  s21_strcpy(buffer, ptr);
}