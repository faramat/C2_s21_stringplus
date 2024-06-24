#ifndef S21_STRING_H_
#define S21_STRING_H_

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#if defined(__APPLE__)
#define MAX_ERRLIST 107
#define MIN_ERRLIST -1
#define ERROR "Unknown error: "
#elif defined(__linux__)
#define MAX_ERRLIST 134
#define MIN_ERRLIST -1
#define ERROR "Unknown error "
#endif

#define S21_NULL ((void *)0)
typedef unsigned long s21_size_t;

typedef struct {
  int flag_minus;
  int flag_plus;
  int flag_space;
  int width;
  int tolerance;
  char len;
  char spec;
  int flag_error;
  int flag_zero;
} Flags;

typedef enum { FLAG, DIGIT, SPEC, LEN } CheckType;

//Функции string.h
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
char *s21_strcpy(char *dest, const char *src);
char *s21_strcat(char *dest, const char *src);
// sprintf
int s21_sprintf(char *str, const char *format, ...);
void s21_set_flag(Flags *spec, const char *format);
char *s21_str_to_int(const char *format, int *number);
void s21_format_param_to_str(char **point_str, Flags *spec, va_list *args);
void s21_str_from_c(char **point_str, va_list *args);
void s21_str_from_d(char **point_str, va_list *args, Flags *spec);
void s21_str_from_f(char **point_str, va_list *args, Flags *spec);
void s21_str_from_s(char **point_str, va_list *args, Flags *spec);
void s21_str_from_u(char **point_str, va_list *args, Flags *spec);
void s21_str_from_perc(char **point_str);
int s21_check(CheckType type, char c);
void s21_utoa(unsigned int value, char *buffer);
void s21_ftoa(double value, char *buffer, int precision);
void s21_itoa(int value, char *buffer);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_str_i);
void *s21_trim(const char *src, const char *trim_chars);
#endif