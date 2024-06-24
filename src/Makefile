UNAME_S := $(shell uname -s)
FLAG = -Wall -Wextra -Werror
LIB = s21_memchr.o s21_memcmp.o s21_memcpy.o s21_memset.o s21_strchr.o \
      s21_strncat.o s21_strncmp.o s21_strncpy.o s21_strcspn.o s21_strerror.o \
      s21_strlen.o s21_strpbrk.o s21_strrchr.o s21_strstr.o s21_strtok.o \
      s21_check.o s21_set_flag.o s21_str_to_int.o s21_format_param_to_str.o \
      s21_str_from_c.o s21_str_from_d.o s21_str_from_f.o s21_str_from_s.o \
      s21_str_from_u.o s21_str_from_perc.o s21_strcpy.o s21_sprintf.o \
	  s21_strcat.o s21_ftoa.o s21_itoa.o s21_utoa.o s21_insert.o s21_to_lower.o \
	  s21_to_upper.o s21_trim.o

ifeq ($(UNAME_S), Linux)
	CHECK = -lcheck -lm -lpthread -lsubunit -lgcov --coverage
else ifeq ($(UNAME_S), Darwin)
	CHECK = -lcheck -lm -lpthread --coverage
endif

all: s21_string.a test gcov_report

s21_string.a: $(LIB)
	ar rcs s21_string.a $(LIB)
	ranlib s21_string.a

s21_memchr.o: s21_memchr.c s21_string.h
	gcc $(FLAG) -c s21_memchr.c -o s21_memchr.o 
s21_memcmp.o: s21_memcmp.c s21_string.h
	gcc $(FLAG) -c s21_memcmp.c -o s21_memcmp.o 
s21_memcpy.o: s21_memcpy.c s21_string.h
	gcc $(FLAG) -c s21_memcpy.c -o s21_memcpy.o 
s21_memset.o: s21_memset.c s21_string.h
	gcc $(FLAG) -c s21_memset.c -o s21_memset.o 
s21_strchr.o: s21_strchr.c s21_string.h
	gcc $(FLAG) -c s21_strchr.c -o s21_strchr.o 
s21_strncat.o: s21_strncat.c s21_string.h
	gcc $(FLAG) -c s21_strncat.c -o s21_strncat.o 
s21_strncmp.o: s21_strncmp.c s21_string.h
	gcc $(FLAG) -c s21_strncmp.c -o s21_strncmp.o
s21_strncpy.o: s21_strncpy.c s21_string.h
	gcc $(FLAG) -c s21_strncpy.c -o s21_strncpy.o
s21_strcspn.o: s21_strcspn.c s21_string.h
	gcc $(FLAG) -c s21_strcspn.c -o s21_strcspn.o
s21_strerror.o: s21_strerror.c s21_string.h
	gcc $(FLAG) -c s21_strerror.c -o s21_strerror.o
s21_strlen.o: s21_strlen.c s21_string.h
	gcc $(FLAG) -c s21_strlen.c -o s21_strlen.o
s21_strpbrk.o: s21_strpbrk.c s21_string.h
	gcc $(FLAG) -c s21_strpbrk.c -o s21_strpbrk.o
s21_strrchr.o: s21_strrchr.c s21_string.h
	gcc $(FLAG) -c s21_strrchr.c -o s21_strrchr.o
s21_strstr.o: s21_strstr.c s21_string.h
	gcc $(FLAG) -c s21_strstr.c -o s21_strstr.o
s21_strtok.o: s21_strtok.c s21_string.h
	gcc $(FLAG) -c s21_strtok.c -o s21_strtok.o
s21_strcpy.o: s21_strcpy.c s21_string.h
	gcc $(FLAG) -c s21_strcpy.c -o s21_strcpy.o
s21_strcat.o: s21_strcat.c s21_string.h
	gcc $(FLAG) -c s21_strcat.c -o s21_strcat.o

s21_set_flag.o: s21_set_flag.c s21_string.h
	gcc $(FLAG) -c s21_set_flag.c -o s21_set_flag.o
s21_str_to_int.o: s21_str_to_int.c s21_string.h
	gcc $(FLAG) -c s21_str_to_int.c -o s21_str_to_int.o
s21_format_param_to_str.o: s21_format_param_to_str.c s21_string.h
	gcc $(FLAG) -c s21_format_param_to_str.c -o s21_format_param_to_str.o
s21_str_from_c.o: s21_str_from_c.c s21_string.h
	gcc $(FLAG) -c s21_str_from_c.c -o s21_str_from_c.o
s21_str_from_d.o: s21_str_from_d.c s21_string.h
	gcc $(FLAG) -c s21_str_from_d.c -o s21_str_from_d.o
s21_str_from_f.o: s21_str_from_f.c s21_string.h
	gcc $(FLAG) -c s21_str_from_f.c -o s21_str_from_f.o
s21_str_from_s.o: s21_str_from_s.c s21_string.h
	gcc $(FLAG) -c s21_str_from_s.c -o s21_str_from_s.o
s21_str_from_u.o: s21_str_from_u.c s21_string.h
	gcc $(FLAG) -c s21_str_from_u.c -o s21_str_from_u.o
s21_str_from_perc.o: s21_str_from_perc.c s21_string.h
	gcc $(FLAG) -c s21_str_from_perc.c -o s21_str_from_perc.o
s21_check.o: s21_check.c s21_string.h
	gcc $(FLAG) -c s21_check.c -o s21_check.o
s21_sprintf.o: s21_sprintf.c s21_string.h
	gcc $(FLAG) -c s21_sprintf.c -o s21_sprintf.o
s21_utoa.o: s21_utoa.c s21_string.h
	gcc $(FLAG) -c s21_utoa.c -o s21_utoa.o
s21_ftoa.o: s21_ftoa.c s21_string.h
	gcc $(FLAG) -c s21_ftoa.c -o s21_ftoa.o
s21_itoa.o: s21_itoa.c s21_string.h
	gcc $(FLAG) -c s21_itoa.c -o s21_itoa.o
s21_insert.o: s21_insert.c s21_string.h
	gcc $(FLAG) -c s21_insert.c -o s21_insert.o
s21_to_lower.o: s21_to_lower.c s21_string.h
	gcc $(FLAG) -c s21_to_lower.c -o s21_to_lower.o
s21_to_upper.o: s21_to_upper.c s21_string.h
	gcc $(FLAG) -c s21_to_upper.c -o s21_to_upper.o
s21_trim.o: s21_trim.c s21_string.h
	gcc $(FLAG) -c s21_trim.c -o s21_trim.o



test: s21_string.a s21_test.c
	gcc $(FLAG) s21_test.c -o s21_test s21_string.a $(CHECK)

gcov_report: test
	./s21_test
	lcov --directory . --capture --output-file coverage.info 
	genhtml coverage.info --output-directory coverage_report

clean:
	rm -f *.o *.a s21_test coverage.info *.gcda *.gcno
	rm -rf coverage_report

rebuild: clean all
