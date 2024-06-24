#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *bytes = str;
  void *result = S21_NULL;
  int flag = 0;
  for (s21_size_t i = 0; i < n && !flag; i++) {
    if (bytes[i] == (unsigned char)c) {
      result = (void *)&bytes[i];
      flag = 1;
    }
  }
  return result;
}
