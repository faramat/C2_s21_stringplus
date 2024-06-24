#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *dest_bytes = (unsigned char *)dest;
  const unsigned char *src_bytes = (const unsigned char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    dest_bytes[i] = src_bytes[i];
  }
  return dest;
}
