#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  int flag = 0;
  if (*needle == '\0') {
    flag = 1;
    result = (char *)haystack;
  }
  for (const char *h = haystack; *h != '\0' && !flag; h++) {
    const char *h_tmp = h;
    const char *n_tmp = needle;
    while (*n_tmp != '\0' && *h_tmp == *n_tmp && !flag) {
      h_tmp++;
      n_tmp++;
    }
    if (*n_tmp == '\0') {
      result = (char *)h;
      flag = 1;
    }
  }
  return result;
}