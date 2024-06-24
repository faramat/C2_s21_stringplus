#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *tmp1, *tmp2;
  char *result = S21_NULL;
  int flag = 0;

  for (tmp1 = str1; *tmp1 != '\0' && !flag; tmp1++) {
    for (tmp2 = str2; *tmp2 != '\0' && !flag; tmp2++) {
      if (*tmp1 == *tmp2) {
        flag = 1;
      }
    }
    if (flag) {
      result = (char *)tmp1;
    }
  }
  return result;
}