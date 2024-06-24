#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  int len = 0;
  while (*dest) {
    dest++;
    len++;
  }
  while (*src) {
    *dest = *src;
    dest++;
    src++;
    len++;
  }
  *dest = '\0';
  dest -= len;
  return dest;
}