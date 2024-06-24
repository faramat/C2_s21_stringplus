#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *bytes1 = (const unsigned char *)str1;
  const unsigned char *bytes2 = (const unsigned char *)str2;
  int result = 0;
  int flag = 0;

  for (s21_size_t i = 0; i < n && !flag; i++) {
    if (bytes1[i] != bytes2[i]) {
      result = bytes1[i] - bytes2[i];
      flag = 1;
    }
  }
  return result;
}
