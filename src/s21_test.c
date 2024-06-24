#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_memchr) {
  ck_assert_ptr_eq(s21_memchr("Hello,world!", 'e', 5),
                   memchr("Hello,world!", 'e', 5));
  ck_assert_ptr_eq(s21_memchr("Hello,world!", 'z', 12),
                   memchr("Hello, world!", 'z', 12));
  ck_assert_ptr_eq(s21_memchr("Hello,world!", 'd', 5),
                   memchr("Hello, world!", 'd', 5));
  ck_assert_ptr_eq(s21_memchr("Hello", '\0', 5), memchr("Hello", '\0', 5));
  ck_assert_ptr_eq(s21_memchr("", 'w', 0), memchr("", 'w', 0));
}
END_TEST

START_TEST(test_s21_memcmp) {
  ck_assert_int_eq(s21_memcmp("", "", 0), memcmp("", "", 0));
  ck_assert_int_eq(s21_memcmp("Hello", "Hello", 5),
                   memcmp("Hello", "Hello", 5));
  ck_assert_int_eq(s21_memcmp("Hello", "", 0), memcmp("Hello", "", 0));
  ck_assert_int_eq(s21_memcmp("Hello", "Hello, world", 5),
                   memcmp("Hello", "Hello, world", 0));
  ck_assert_int_eq(s21_memcmp("a", "b", 5), memcmp("a", "b", 1));
}
END_TEST

START_TEST(test_s21_memcpy_full_string) {
  char src[] = "Hello, world!";
  char dest1[14], dest2[14];
  s21_memcpy(dest1, src, 14);
  memcpy(dest2, src, 14);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_s21_memcpy_single_char) {
  char src[] = "H";
  char dest1[5], dest2[5];
  s21_memcpy(dest1, src, 1);
  memcpy(dest2, src, 1);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_s21_memcpy_partial_string) {
  char src[] = "Hello, world!";
  char dest1[6], dest2[6];
  s21_memcpy(dest1, src, 5);
  memcpy(dest2, src, 5);
  dest1[5] = '\0';
  dest2[5] = '\0';
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_s21_memcpy_empty_string) {
  char src[] = "";
  char dest1[1], dest2[1];
  s21_memcpy(dest1, src, 1);
  memcpy(dest2, src, 1);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_s21_memcpy_array) {
  int src[] = {1, 2, 3, 4, 5};
  int dest1[5], dest2[5];
  s21_memcpy(dest1, src, 5 * sizeof(int));
  memcpy(dest2, src, 5 * sizeof(int));
  ck_assert_mem_eq(dest1, dest2, 5 * sizeof(int));
}
END_TEST

START_TEST(test_s21_memset_full_string) {
  char str1[14] = "Hello, world!";
  char str2[14] = "Hello, world!";
  s21_memset(str1, 'x', 13);
  memset(str2, 'x', 13);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_memset_partial_string) {
  char str1[14] = "Hello, world!";
  char str2[14] = "Hello, world!";
  s21_memset(str1, 'x', 5);
  memset(str2, 'x', 5);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_memset_single_char) {
  char str1[2] = "H";
  char str2[2] = "H";
  s21_memset(str1, 'x', 1);
  memset(str2, 'x', 1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_memset_empty_string) {
  char str1[2] = "";
  char str2[2] = "";
  s21_memset(str1, 'b', 1);
  memset(str2, 'b', 1);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_memset_array) {
  int array1[5] = {1, 2, 3, 4, 5};
  int array2[5] = {1, 2, 3, 4, 5};
  s21_memset(array1, 0, 5 * sizeof(int));
  memset(array2, 0, 5 * sizeof(int));
  ck_assert_mem_eq(array1, array2, 5 * sizeof(int));
}
END_TEST

START_TEST(test_s21_strncat_normal_concatenation) {
  char dest[20] = "Hello, ";
  const char *src = "world!";
  s21_strncat(dest, src, 5);
  ck_assert_str_eq(dest, strncat(dest, src, 5));
}
END_TEST

START_TEST(test_s21_strncat_empty_src) {
  char dest[20] = "Hello, ";
  const char *src = "";
  s21_strncat(dest, src, 5);
  ck_assert_str_eq(dest, strncat(dest, src, 5));
}
END_TEST

START_TEST(test_s21_strncat_n_zero) {
  char dest[20] = "Hello, ";
  const char *src = "world!";
  s21_strncat(dest, src, 0);
  ck_assert_str_eq(dest, strncat(dest, src, 0));
}
END_TEST

START_TEST(test_s21_strncat_empty_dest) {
  char dest[20] = "";
  const char *src = "world!";
  s21_strncat(dest, src, 7);
  ck_assert_str_eq(dest, strncat(dest, src, 7));
}
END_TEST

START_TEST(test_s21_strchr_first_occurrence) {
  const char *str = "Hello, world!";
  char *result = s21_strchr(str, 'o');
  ck_assert_ptr_eq(result, strchr(str, 'o'));
}
END_TEST

START_TEST(test_s21_strchr_not_found) {
  const char *str = "Hello, world!";
  char *result = s21_strchr(str, 'x');
  ck_assert_ptr_eq(result, strchr(str, 'x'));
}
END_TEST

START_TEST(test_s21_strchr_empty_string) {
  const char *str = "";
  char *result = s21_strchr(str, 'x');
  ck_assert_ptr_eq(result, strchr(str, 'x'));
}
END_TEST

START_TEST(test_s21_strchr_null_terminator) {
  const char *str = "Hello";
  char *result = s21_strchr(str, '\0');
  ck_assert_ptr_eq(result, strchr(str, '\0'));
}
END_TEST

START_TEST(test_s21_strncmp_equal_strings) {
  const char *str1 = "Hello";
  const char *str2 = "Hello";
  int result = s21_strncmp(str1, str2, 5);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_s21_strncmp_different_strings) {
  const char *str1 = "Hello";
  const char *str2 = "World";
  int result = s21_strncmp(str1, str2, 5);
  ck_assert_int_eq(result, strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_s21_strncmp_same_prefix) {
  const char *str1 = "Hello, world!";
  const char *str2 = "Hello, people!";
  int result = s21_strncmp(str1, str2, 6);
  ck_assert_int_eq(result, strncmp(str1, str2, 6));
}
END_TEST

START_TEST(test_s21_strncmp_null_terminator) {
  const char *str1 = "Hello";
  const char *str2 = "Hello";
  int result = s21_strncmp(str1, str2, 6);
  ck_assert_int_eq(result, strncmp(str1, str2, 6));
}
END_TEST

START_TEST(test_s21_strncmp_different_lengths) {
  const char *str1 = "Hello";
  const char *str2 = "Hello, world!";
  int result = s21_strncmp(str1, str2, 5);
  ck_assert_int_eq(result, strncmp(str1, str2, 5));
}
END_TEST

START_TEST(test_s21_strncpy_normal_copy) {
  char dest[20] = "Hello";
  const char *src = "world!";
  s21_strncpy(dest, src, 5);
  ck_assert_str_eq(dest, strncpy(dest, src, 5));
}
END_TEST

START_TEST(test_s21_strncpy_partial_copy) {
  char dest[20] = "Hello";
  const char *src = "world!";
  s21_strncpy(dest, src, 3);
  ck_assert_str_eq(dest, strncpy(dest, src, 3));
}
END_TEST

START_TEST(test_s21_strncpy_full_copy) {
  char dest[20] = "Hello";
  const char *src = "world!";
  s21_strncpy(dest, src, 7);
  ck_assert_str_eq(dest, strncpy(dest, src, 7));
}
END_TEST

START_TEST(test_s21_strncpy_empty_src) {
  char dest[20] = "Hello";
  const char *src = "";
  s21_strncpy(dest, src, 5);
  ck_assert_str_eq(dest, strncpy(dest, src, 5));
}
END_TEST

START_TEST(test_s21_strncpy_n_zero) {
  char dest[20] = "Hello";
  const char *src = "world!";
  s21_strncpy(dest, src, 0);
  ck_assert_str_eq(dest, "Hello");
}

START_TEST(test_s21_strtok) {
  char str1[] = "Hello, world! This is a test.";
  const char *delim1 = " ,.!";

  char str2[] = "Hello, world! This is a test.";
  const char *delim2 = " ,.!";

  char *token1 = s21_strtok(str1, delim1);
  char *token2 = strtok(str2, delim2);

  while (token1 != S21_NULL && token2 != S21_NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = s21_strtok(S21_NULL, delim1);
    token2 = strtok(S21_NULL, delim2);
  }

  char str[] = "token";
  char *token = s21_strtok(str, " ");
  ck_assert_str_eq(token, "token");

  token = s21_strtok(S21_NULL, " ");
  ck_assert_ptr_eq(token, S21_NULL);

  ck_assert_ptr_eq(token1, token2);
}
END_TEST

START_TEST(test_s21_strstr) {
  ck_assert_ptr_eq(s21_strstr("Hello, world!", "world"),
                   strstr("Hello, world!", "world"));
  ck_assert_ptr_eq(s21_strstr("Hello, world!", "o, w"),
                   strstr("Hello, world!", "o, w"));
  ck_assert_ptr_eq(s21_strstr("Hello, world!", ""),
                   strstr("Hello, world!", ""));
  ck_assert_ptr_eq(s21_strstr("Hello, world!", "notfound"),
                   strstr("Hello, world!", "notfound"));
  ck_assert_ptr_eq(s21_strstr("", ""), strstr("", ""));
  ck_assert_ptr_eq(s21_strstr("", "needle"), strstr("", "needle"));
  ck_assert_ptr_eq(s21_strstr("Hello, world!", "\0"),
                   strstr("Hello, world!", "\0"));
}
END_TEST

START_TEST(test_s21_strrchr) {
  ck_assert_ptr_eq(s21_strrchr("Hello, world!", 'o'),
                   strrchr("Hello, world!", 'o'));
  ck_assert_ptr_eq(s21_strrchr("Hello, world!", 'z'),
                   strrchr("Hello, world!", 'z'));
  ck_assert_ptr_eq(s21_strrchr("Hello, world!", '\0'),
                   strrchr("Hello, world!", '\0'));
  ck_assert_ptr_eq(s21_strrchr("", 'a'), strrchr("", 'a'));
  ck_assert_ptr_eq(s21_strrchr("aabbcc", 'a'), strrchr("aabbcc", 'a'));
}
END_TEST

START_TEST(test_s21_strpbrk) {
  ck_assert_ptr_eq(s21_strpbrk("Hello", "o"), strpbrk("Hello", "o"));
  ck_assert_ptr_eq(s21_strpbrk("JSAcbsshauebc", "1"),
                   strpbrk("JSAcbsshauebc", "1"));
  ck_assert_ptr_eq(s21_strpbrk("dscsdcd1_dslkc", "_"),
                   strpbrk("dscsdcd1_dslkc", "_"));
  ck_assert_ptr_eq(s21_strpbrk("", ""), strpbrk("", ""));
  ck_assert_ptr_eq(s21_strpbrk(" ", " "), strpbrk(" ", " "));
}
END_TEST

START_TEST(test_s21_strcspn) {
  ck_assert_int_eq(s21_strcspn("Hello", "o"), strcspn("Hello", "o"));
  ck_assert_int_eq(s21_strcspn("JSAcbsshauebc", "1"),
                   strcspn("JSAcbsshauebc", "1"));
  ck_assert_int_eq(s21_strcspn("dscsdcd1_dslkc", "_"),
                   strcspn("dscsdcd1_dslkc", "_"));
  ck_assert_int_eq(s21_strcspn("", ""), strcspn("", ""));
  ck_assert_int_eq(s21_strcspn(" ", " "), strcspn(" ", " "));
}
END_TEST

START_TEST(test_s21_strlen) {
  ck_assert_int_eq(s21_strlen(""), strlen(""));
  ck_assert_int_eq(s21_strlen("Hello"), strlen("Hello"));
  ck_assert_int_eq(s21_strlen("This is a test string."),
                   strlen("This is a test string."));
  ck_assert_int_eq(s21_strlen("1234567890"), strlen("1234567890"));
}
END_TEST

START_TEST(test_s21_strerror) {
  for (int i = MIN_ERRLIST - 1; i <= MAX_ERRLIST + 1; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

START_TEST(test_insert_1) {
  char str_src[30] = "hello, world!";
  char str_ins[] = "hELLO, WORLD!";
  char str_res[] = "hello, hELLO, WORLD!world!";
  s21_size_t num = 7;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_2) {
  char str_src[30] = "";
  char str_ins[] = "";
  char *str_res = S21_NULL;
  s21_size_t num = 7;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_3) {
  char *str_src = S21_NULL;
  char str_ins[] = "";
  char *str_res = S21_NULL;
  s21_size_t num = 0;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_4) {
  char str_src[30] = "abcdefghij";
  char str_ins[] = "\'I WAS HERE\'";
  char str_res[] = "abc\'I WAS HERE\'defghij";
  s21_size_t num = 3;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_5) {
  char str_src[30] = "abc";
  char str_ins[] = "333";
  char *str_res = S21_NULL;
  s21_size_t num = 10;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_6) {
  char str_src[30] = "hello, world!";
  char str_ins[] = "hELLO, WORLD!";
  char *str_res = S21_NULL;
  s21_size_t num = -1;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_7) {
  char *str_src = S21_NULL;
  char *str_ins = S21_NULL;
  char *str_res = S21_NULL;
  s21_size_t num = 0;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_8) {
  char str_src[30] = "";
  char str_ins[] = "";
  char str_res[] = "";
  s21_size_t num = 0;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_9) {
  char str_src[] = "wtf";
  char *str_ins = S21_NULL;
  char *str_res = S21_NULL;
  s21_size_t num = 0;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_insert_10) {
  char str_src[] = "";
  char *str_ins = S21_NULL;
  char *str_res = S21_NULL;
  s21_size_t num = 0;
  char *res = s21_insert(str_src, str_ins, num);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_lower_1) {
  char str_src[30] = "hELLO, WORLD!";
  char str_res[] = "hello, world!";
  char *res = s21_to_lower(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_lower_2) {
  char str_src[30] = "\nH\t\\G123123";
  char str_res[30] = "\nh\t\\g123123";
  char *res = s21_to_lower(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_lower_3) {
  char str_src[30] = "already lower";
  char str_res[30] = "already lower";
  char *res = s21_to_lower(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_lower_4) {
  char str_src[30] = "";
  char str_res[30] = "";
  char *res = s21_to_lower(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_lower_5) {
  char str_src[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char str_res[30] = "abcdefghijklmnopqrstuvwxyz";
  char *res = s21_to_lower(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_lower_6) {
  char str_src[30] = "_?};!234";
  char str_res[30] = "_?};!234";
  char *res = s21_to_lower(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_lower_7) {
  char *str_src = S21_NULL;
  char *str_res = S21_NULL;
  char *res = s21_to_lower(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_upper_1) {
  char str_src[30] = "Hello, world!";
  char str_res[30] = "HELLO, WORLD!";
  char *res = s21_to_upper(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_upper_2) {
  char str_src[30] = "\nh\t\\g123123";
  char str_res[30] = "\nH\t\\G123123";
  char *res = s21_to_upper(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_upper_3) {
  char str_src[30] = "ALREADY UPPER";
  char str_res[30] = "ALREADY UPPER";
  char *res = s21_to_upper(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_upper_4) {
  char str_src[30] = "";
  char str_res[30] = "";
  char *res = s21_to_upper(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_upper_5) {
  char str_src[50] = "abcdefghijklmnopqrstuvwxyz";
  char str_res[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *res = s21_to_upper(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_upper_6) {
  char str_src[30] = "_?};!234";
  char str_res[30] = "_?};!234";
  char *res = s21_to_upper(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_to_upper_7) {
  char *str_src = S21_NULL;
  char *str_res = S21_NULL;
  char *res = s21_to_upper(str_src);
  ck_assert_pstr_eq(res, str_res);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_1) {
  char str_src[30] = "-?hello, world!";
  char str_strim[] = "!?-";
  char str_res[] = "hello, world";
  char *res = s21_trim(str_src, str_strim);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_2) {
  char str_src[30] = "MAF MAF";
  char str_strim[] = "MAF MAF";
  char *str_res = "";
  char *res = s21_trim(str_src, str_strim);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_3) {
  char *str_src = S21_NULL;
  char str_strim[] = "";
  char *str_res = S21_NULL;
  char *res = s21_trim(str_src, str_strim);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_4) {
  char str_src[30] = "!!!abcdefghij!?!";
  char str_strim[] = "!?";
  char str_res[] = "abcdefghij";
  char *res = s21_trim(str_src, str_strim);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_5) {
  char str_src[30] = "abc";
  char str_strim[] = "";
  char *str_res = "abc";
  char *res = s21_trim(str_src, str_strim);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_6) {
  char str_src[30] = "hello, world!";
  char str_strim[] = "?!";
  char *str_res = "hello, world";
  char *res = s21_trim(str_src, str_strim);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_7) {
  char *str_src = S21_NULL;
  char *str_strim = S21_NULL;
  char *str_res = S21_NULL;
  char *res = s21_trim(str_src, str_strim);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_8) {
  char str_src[30] = "";
  char str_strim[] = "";
  char str_res[] = "";
  char *res = s21_trim(str_src, str_strim);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST

START_TEST(test_trim_9) {
  char str_src[] = " wtf ";
  char *str_strim = "";
  char *str_res = " wtf ";
  char *res = s21_trim(str_src, str_strim);
  ck_assert_pstr_eq(str_res, res);
  if (res) free(res);
}
END_TEST
START_TEST(test_s21_sprintf_combinations) {
  char s21_buffer[256];
  char std_buffer[256];

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%c", 'A'),
                   sprintf(std_buffer, "%c", 'A'));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%d", 123),
                   sprintf(std_buffer, "%d", 123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%+d", 123),
                   sprintf(std_buffer, "%+d", 123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "% d", 123),
                   sprintf(std_buffer, "% d", 123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%5d", 123),
                   sprintf(std_buffer, "%5d", 123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%-5d", 123),
                   sprintf(std_buffer, "%-5d", 123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%.5d", 123),
                   sprintf(std_buffer, "%.5d", 123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%+5d", -123),
                   sprintf(std_buffer, "%+5d", -123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%-+5d", -123),
                   sprintf(std_buffer, "%-+5d", -123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%-20f", 123.456),
                   sprintf(std_buffer, "%-20f", 123.456));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%f", 123.456),
                   sprintf(std_buffer, "%f", 123.456));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%20f", 123.456),
                   sprintf(std_buffer, "%20f", 123.456));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%.2f", 123.456),
                   sprintf(std_buffer, "%.2f", 123.456));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%+f", 123.456),
                   sprintf(std_buffer, "%+f", 123.456));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "% f", 123.456),
                   sprintf(std_buffer, "% f", 123.456));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%.3f", 123.456),
                   sprintf(std_buffer, "%.3f", 123.456));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%.8f", 4567.89),
                   sprintf(std_buffer, "%.8f", 4567.89));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%.2f", 0.0),
                   sprintf(std_buffer, "%.2f", 0.0));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%.5f", 9876.54321),
                   sprintf(std_buffer, "%.5f", 9876.54321));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%.4f", -456.789),
                   sprintf(std_buffer, "%.4f", -456.789));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%.6f", -0.123456789),
                   sprintf(std_buffer, "%.6f", -0.123456789));
  ck_assert_str_eq(s21_buffer, std_buffer);

  s21_sprintf(s21_buffer, "%.0f", 789.123),
      sprintf(std_buffer, "%.0f", 789.123);
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%s", "Hello"),
                   sprintf(std_buffer, "%s", "Hello"));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%10s", "Hello"),
                   sprintf(std_buffer, "%10s", "Hello"));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%-10s", "Hello"),
                   sprintf(std_buffer, "%-10s", "Hello"));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%.3s", "Hello"),
                   sprintf(std_buffer, "%.3s", "Hello"));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%u", 123),
                   sprintf(std_buffer, "%u", 123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%5u", 123),
                   sprintf(std_buffer, "%5u", 123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%-5u", 123),
                   sprintf(std_buffer, "%-5u", 123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%.5u", 123),
                   sprintf(std_buffer, "%.5u", 123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%%"), sprintf(std_buffer, "%%"));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(
      s21_sprintf(s21_buffer, "%d %f %s %u %%", 123, 123.456, "Hello", 123),
      sprintf(std_buffer, "%d %f %s %u %%", 123, 123.456, "Hello", 123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%d", -123),
                   sprintf(std_buffer, "%d", -123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%+d", -123),
                   sprintf(std_buffer, "%+d", -123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "% d", -123),
                   sprintf(std_buffer, "% d", -123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%.5d", -123),
                   sprintf(std_buffer, "%.5d", -123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%f", -123.456),
                   sprintf(std_buffer, "%f", -123.456));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%.2f", -123.456),
                   sprintf(std_buffer, "%.2f", -123.456));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%+f", -123.456),
                   sprintf(std_buffer, "%+f", -123.456));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "% f", -123.456),
                   sprintf(std_buffer, "% f", -123.456));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%u", -123),
                   sprintf(std_buffer, "%u", -123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%5u", -123),
                   sprintf(std_buffer, "%5u", -123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%-5u", -123),
                   sprintf(std_buffer, "%-5u", -123));
  ck_assert_str_eq(s21_buffer, std_buffer);

  ck_assert_int_eq(s21_sprintf(s21_buffer, "%.5u", -123),
                   sprintf(std_buffer, "%.5u", -123));
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *s = suite_create("s21_string");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_memchr);
  tcase_add_test(tc_core, test_s21_memcmp);

  tcase_add_test(tc_core, test_s21_memcpy_full_string);
  tcase_add_test(tc_core, test_s21_memcpy_single_char);
  tcase_add_test(tc_core, test_s21_memcpy_partial_string);
  tcase_add_test(tc_core, test_s21_memcpy_empty_string);
  tcase_add_test(tc_core, test_s21_memcpy_array);

  tcase_add_test(tc_core, test_s21_memset_full_string);
  tcase_add_test(tc_core, test_s21_memset_partial_string);
  tcase_add_test(tc_core, test_s21_memset_single_char);
  tcase_add_test(tc_core, test_s21_memset_empty_string);
  tcase_add_test(tc_core, test_s21_memset_array);

  tcase_add_test(tc_core, test_s21_strncat_normal_concatenation);
  tcase_add_test(tc_core, test_s21_strncat_empty_src);
  tcase_add_test(tc_core, test_s21_strncat_n_zero);
  tcase_add_test(tc_core, test_s21_strncat_empty_dest);

  tcase_add_test(tc_core, test_s21_strchr_first_occurrence);
  tcase_add_test(tc_core, test_s21_strchr_not_found);
  tcase_add_test(tc_core, test_s21_strchr_empty_string);
  tcase_add_test(tc_core, test_s21_strchr_null_terminator);

  tcase_add_test(tc_core, test_s21_strncmp_equal_strings);
  tcase_add_test(tc_core, test_s21_strncmp_different_strings);
  tcase_add_test(tc_core, test_s21_strncmp_same_prefix);
  tcase_add_test(tc_core, test_s21_strncmp_null_terminator);
  tcase_add_test(tc_core, test_s21_strncmp_different_lengths);

  tcase_add_test(tc_core, test_s21_strncpy_normal_copy);
  tcase_add_test(tc_core, test_s21_strncpy_partial_copy);
  tcase_add_test(tc_core, test_s21_strncpy_full_copy);
  tcase_add_test(tc_core, test_s21_strncpy_empty_src);
  tcase_add_test(tc_core, test_s21_strncpy_n_zero);

  tcase_add_test(tc_core, test_s21_strtok);
  tcase_add_test(tc_core, test_s21_strstr);
  tcase_add_test(tc_core, test_s21_strpbrk);
  tcase_add_test(tc_core, test_s21_strrchr);
  tcase_add_test(tc_core, test_s21_strcspn);
  tcase_add_test(tc_core, test_s21_strlen);
  tcase_add_test(tc_core, test_s21_strerror);

  tcase_add_test(tc_core, test_insert_1);
  tcase_add_test(tc_core, test_insert_2);
  tcase_add_test(tc_core, test_insert_3);
  tcase_add_test(tc_core, test_insert_4);
  tcase_add_test(tc_core, test_insert_5);
  tcase_add_test(tc_core, test_insert_6);
  tcase_add_test(tc_core, test_insert_7);
  tcase_add_test(tc_core, test_insert_8);
  tcase_add_test(tc_core, test_insert_9);
  tcase_add_test(tc_core, test_insert_10);

  tcase_add_test(tc_core, test_to_lower_1);
  tcase_add_test(tc_core, test_to_lower_2);
  tcase_add_test(tc_core, test_to_lower_3);
  tcase_add_test(tc_core, test_to_lower_4);
  tcase_add_test(tc_core, test_to_lower_5);
  tcase_add_test(tc_core, test_to_lower_6);
  tcase_add_test(tc_core, test_to_lower_7);

  tcase_add_test(tc_core, test_to_upper_1);
  tcase_add_test(tc_core, test_to_upper_2);
  tcase_add_test(tc_core, test_to_upper_3);
  tcase_add_test(tc_core, test_to_upper_4);
  tcase_add_test(tc_core, test_to_upper_5);
  tcase_add_test(tc_core, test_to_upper_6);
  tcase_add_test(tc_core, test_to_upper_7);

  tcase_add_test(tc_core, test_trim_1);
  tcase_add_test(tc_core, test_trim_2);
  tcase_add_test(tc_core, test_trim_3);
  tcase_add_test(tc_core, test_trim_4);
  tcase_add_test(tc_core, test_trim_5);
  tcase_add_test(tc_core, test_trim_6);
  tcase_add_test(tc_core, test_trim_7);
  tcase_add_test(tc_core, test_trim_8);
  tcase_add_test(tc_core, test_trim_9);
  tcase_add_test(tc_core, test_s21_sprintf_combinations);
  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int no_failed = 0;
  Suite *s = s21_string_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? 0 : 1;
}
