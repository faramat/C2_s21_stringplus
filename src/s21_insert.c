#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_str_i) {
  char *str_res = S21_NULL;

  if (src != S21_NULL && str != S21_NULL) {
    int strlen_src = s21_strlen(src);
    int strlen_str = s21_strlen(str);
    int diff_strlen = strlen_src + strlen_str - start_str_i;

    if (diff_strlen >= 0 && diff_strlen <= (strlen_src + strlen_str)) {
      str_res = malloc(sizeof(char) * (strlen_src + strlen_str + 1));

      if (src[0] == '\0' && str[0] == '\0') {
        str_res[0] = '\0';
      } else {
        s21_size_t curr_index = 0;
        s21_size_t index_src = 0;
        s21_size_t index_str = 0;

        while (curr_index < start_str_i) {
          str_res[curr_index] = src[index_src];
          index_src++;
          curr_index++;
        }

        for (s21_size_t i = start_str_i; str[index_str] != '\0'; i++) {
          str_res[i] = str[index_str];
          index_str++;
          curr_index++;
        }

        while (src[index_src] != '\0') {
          str_res[curr_index] = src[index_src];
          index_src++;
          curr_index++;
        }
        str_res[curr_index] = '\0';
      }
    } else
      str_res = S21_NULL;

  } else {
    str_res = S21_NULL;
  }
  return str_res;
}
