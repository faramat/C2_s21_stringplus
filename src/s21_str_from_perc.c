#include "s21_string.h"

void s21_str_from_perc(char **point_str) {
  **point_str = '%';
  (*point_str)++;
  **point_str = '\0';
}