#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  int flag = 0;
  for (s21_size_t i = 0; i < n && !flag; ++i) {
    if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0') {
      result = (unsigned char)str1[i] - (unsigned char)str2[i];
      flag = 1;
    }
  }
  return result;
}
