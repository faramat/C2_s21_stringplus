#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *str_res = S21_NULL;
  if (str != S21_NULL) {
    str_res = malloc(sizeof(char) * (s21_strlen(str) + 1));
    s21_size_t curr_index = 0;

    for (curr_index = 0; str[curr_index] != '\0'; curr_index++) {
      if (str[curr_index] >= 'a' && str[curr_index] <= 'z')
        str_res[curr_index] = str[curr_index] - 32;
      else
        str_res[curr_index] = str[curr_index];
    }

    str_res[curr_index] = '\0';
  } else
    str_res = S21_NULL;
  return str_res;
}
