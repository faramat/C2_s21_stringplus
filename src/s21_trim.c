#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *str_res = S21_NULL;
  if (src != S21_NULL) {
    s21_size_t curr_index = 0;

    str_res = malloc(sizeof(char) * (s21_strlen(src) + 1));

    if (trim_chars == S21_NULL) {
      for (curr_index = 0; src[curr_index] != '\0'; curr_index++) {
        str_res[curr_index] = src[curr_index];
      }
      curr_index++;
      str_res[curr_index] = '\0';
    } else {
      int flag_trim = 1;
      s21_size_t index_src = 0;
      s21_size_t index_trim = 0;

      while (flag_trim) {
        flag_trim = 0;
        for (index_trim = 0; trim_chars[index_trim] != '\0'; index_trim++) {
          if (src[index_src] == trim_chars[index_trim]) {
            flag_trim = 1;
            index_src++;
          }
        }
      }

      while (src[index_src] != '\0') {
        str_res[curr_index] = src[index_src];
        index_src++;
        curr_index++;
      }

      flag_trim = 1;
      curr_index -= 1;
      while (flag_trim) {
        flag_trim = 0;
        for (index_trim = 0; trim_chars[index_trim] != '\0'; index_trim++) {
          if (str_res[curr_index] == trim_chars[index_trim]) {
            flag_trim = 1;
            curr_index--;
          }
        }
      }
      curr_index += 1;
      str_res[curr_index] = '\0';
    }
  } else
    str_res = S21_NULL;
  return str_res;
}
