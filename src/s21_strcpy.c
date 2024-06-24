#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *dest_start = dest;
  while ((*dest++ = *src++) != '\0') {
    //
  }
  return dest_start;
}