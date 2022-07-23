#include <check.h>
#include <string.h>
#include <wchar.h>

#include "../s21_string.h"
#include "test_data.h"

//  memchr test
START_TEST(s21_memchr_f) {
    ck_assert_ptr_eq(s21_memchr(test1, 'h', 12), memchr(test1, 'h', 12));
    ck_assert_str_eq(s21_memchr(test2, 'l', 12), memchr(test2, 'l', 12));
    ck_assert_str_eq(s21_memchr(test3, '\n', 4), memchr(test3, '\n', 4));
    ck_assert_str_eq(s21_memchr(test4, '\n', 3), memchr(test4, '\n', 3));
    ck_assert_str_eq(s21_memchr(test5, ' ', 3), memchr(test5, ' ', 3));
    ck_assert_str_eq(s21_memchr(test6, '\n', 2), memchr(test6, '\n', 2));
    ck_assert_ptr_eq(s21_memchr(test7, ' ', 2), memchr(test7, ' ', 2));
}
END_TEST

//  memcmp test
START_TEST(s21_memcmp_f) {
    char toCompare[] = "Hell0 man";

    ck_assert_int_eq(s21_memcmp(test1, toCompare, 8),
                     memcmp(test1, toCompare, 8));
    ck_assert_int_eq(s21_memcmp(test2, toCompare, 10),
                     memcmp(test2, toCompare, 10));
    ck_assert_int_eq(s21_memcmp(test3, toCompare, 8),
                     memcmp(test3, toCompare, 8));
    ck_assert_int_eq(s21_memcmp(test4, toCompare, 8),
                     memcmp(test4, toCompare, 8));
    ck_assert_int_eq(s21_memcmp(test5, toCompare, 8),
                     memcmp(test5, toCompare, 8));
    ck_assert_int_eq(s21_memcmp(test6, toCompare, 8),
                     memcmp(test6, toCompare, 8));
    ck_assert_int_eq(s21_memcmp(test7, toCompare, 8),
                     memcmp(test7, toCompare, 8));
}
END_TEST

//  memcpy test
START_TEST(s21_memcpy_f) {
    char destination1[] = "Here w0 are\0";
    char result[] = "Here w0 are\0";
    ck_assert_str_eq(s21_memcpy(destination1, test1, 8),
                     memcpy(result, test1, 8));

    char destination2[] = "Here w0 are\n\0";
    char result2[] = "Here w0 are\n\0";
    ck_assert_str_eq(s21_memcpy(destination2, test2, 8),
                     memcpy(result2, test2, 8));

    char destination3[] = "a\n\0";
    char result3[] = "a\n\0";
    ck_assert_str_eq(s21_memcpy(destination3, test3, 2),
                     memcpy(result3, test3, 2));

    char destination4[] = " \n\0";
    char result4[] = " \n\0";
    ck_assert_str_eq(s21_memcpy(destination4, test4, 2),
                     memcpy(result4, test4, 2));

    char destination5[] = " \0";
    char result5[] = " \0";
    ck_assert_str_eq(s21_memcpy(destination5, test5, 2),
                     memcpy(result5, test5, 2));

    char destination6[] = "\n\0";
    char result6[] = "\n\0";
    ck_assert_str_eq(s21_memcpy(destination6, test6, 2),
                     memcpy(result6, test6, 2));

    char destination7[] = "\0";
    char result7[] = "aaa\0";
    ck_assert_str_eq(s21_memcpy(destination7, test7, 2),
                     memcpy(result7, test7, 2));
}
END_TEST

//  memmove test
START_TEST(s21_memmove_f) {
    char str1[30] = "teststring";
    char str2[30] = "teststring";
    ck_assert_str_eq(s21_memmove(str1 + 2, str1, 10),
                     memmove(str2 + 2, str2, 10));

    char destination2[] = "Here w0 are\n\0";
    char result2[] = "Here w0 are\n\0";
    ck_assert_str_eq(s21_memmove(destination2, test2, 8),
                     memmove(result2, test2, 8));

    char destination3[] = "a\n\0";
    char result3[] = "a\n\0";
    ck_assert_str_eq(s21_memmove(destination3, test3, 2),
                     memmove(result3, test3, 2));

    char destination4[] = " \n\0";
    char result4[] = " \n\0";
    ck_assert_str_eq(s21_memmove(destination4, test4, 2),
                     memmove(result4, test4, 2));

    char destination5[] = " \0";
    char result5[] = " \0";
    ck_assert_str_eq(s21_memmove(destination5, test5, 2),
                     memmove(result5, test5, 2));

    char destination6[] = "\n\0";
    char result6[] = "\n\0";
    ck_assert_str_eq(s21_memmove(destination6, test6, 2),
                     memmove(result6, test6, 2));

    char destination7[] = "\0";
    char result7[] = "\0";
    ck_assert_str_eq(s21_memmove(destination7, test7, 2),
                     memmove(result7, test7, 2));
}
END_TEST

//  memset test
START_TEST(s21_memset_f) {
    char destination[] = "Here w0 are123\0";
    char origin[] = "Here w0 are123\0";
    ck_assert_str_eq(s21_memset(destination, '-', 4), memset(origin, '-', 4));

    char destination2[] = "Here w0 are\n\0";
    char origin2[] = "Here w0 are\n\0";
    ck_assert_str_eq(s21_memset(destination2, '-', 4), memset(origin2, '-', 4));

    char destination3[] = "a\n\0";
    char origin3[] = "a\n\0";
    ck_assert_str_eq(s21_memset(destination3, '-', 2), memset(origin3, '-', 2));

    char destination4[] = " \n\0";
    char origin4[] = " \n\0";
    ck_assert_str_eq(s21_memset(destination4, '-', 2), memset(origin4, '-', 2));

    char destination5[] = " \0";
    char origin5[] = " \0";
    ck_assert_str_eq(s21_memset(destination5, '-', 1), memset(origin5, '-', 1));

    char destination6[] = "\n\0";
    char origin6[] = "\n\0";
    ck_assert_str_eq(s21_memset(destination6, '-', 1), memset(origin6, '-', 1));

    char origin7[] = "\0";
    char destination7[] = "\0";
    ck_assert_str_eq(s21_memset(destination7, '-', 1), memset(origin7, '-', 1));
}
END_TEST

// strcat test
START_TEST(s21_strcat_f) {
    char destination[40] = "Here w0 are123\0";
    char origin[40] = "Here w0 are123\0";
    ck_assert_str_eq(s21_strcat(destination, test1), strcat(origin, test1));

    char destination2[40] = "Here w0 are\n\0";
    char origin2[40] = "Here w0 are\n\0";
    ck_assert_str_eq(s21_strcat(destination2, test2), strcat(origin2, test2));

    char destination3[40] = "a\n\0";
    char origin3[40] = "a\n\0";
    ck_assert_str_eq(s21_strcat(destination3, test3), strcat(origin3, test3));

    char destination4[40] = " \n\0";
    char origin4[40] = " \n\0";
    ck_assert_str_eq(s21_strcat(destination4, test4), strcat(origin4, test4));

    char destination5[40] = " \0";
    char origin5[40] = " \0";
    ck_assert_str_eq(s21_strcat(destination5, test5), strcat(origin5, test5));

    char destination6[40] = "\n\0";
    char origin6[40] = "\n\0";
    ck_assert_str_eq(s21_strcat(destination6, test6), strcat(origin6, test6));

    char origin7[40] = "\0";
    char destination7[40] = "\0";
    ck_assert_str_eq(s21_strcat(destination7, test7), strcat(origin7, test7));
}
END_TEST

//  strncat test
START_TEST(s21_strncat_f) {
    char destination[40] = "Here w0 are123\0";
    char origin[40] = "Here w0 are123\0";
    ck_assert_str_eq(s21_strncat(destination, test1, 4),
                     strncat(origin, test1, 4));

    char destination2[40] = "Here w0 are\n\0";
    char origin2[40] = "Here w0 are\n\0";
    ck_assert_str_eq(s21_strncat(destination2, test2, 4),
                     strncat(origin2, test2, 4));

    char destination3[40] = "a\n\0";
    char origin3[40] = "a\n\0";
    ck_assert_str_eq(s21_strncat(destination3, test3, 4),
                     strncat(origin3, test3, 4));

    char destination4[40] = " \n\0";
    char origin4[40] = " \n\0";
    ck_assert_str_eq(s21_strncat(destination4, test4, 4),
                     strncat(origin4, test4, 4));

    char destination5[40] = " \0";
    char origin5[40] = " \0";
    ck_assert_str_eq(s21_strncat(destination5, test5, 4),
                     strncat(origin5, test5, 4));

    char destination6[40] = "\n\0";
    char origin6[40] = "\n\0";
    ck_assert_str_eq(s21_strncat(destination6, test6, 4),
                     strncat(origin6, test6, 4));

    char origin7[40] = "\0";
    char destination7[40] = "\0";
    ck_assert_str_eq(s21_strncat(destination7, test7, 4),
                     strncat(origin7, test7, 4));
}
END_TEST

//  strchr test
START_TEST(s21_strchr_f) {
    ck_assert_str_eq(s21_strchr(test1, 'e'), strchr(test1, 'e'));
    ck_assert_str_eq(s21_strchr(test2, 'e'), strchr(test2, 'e'));
    ck_assert_ptr_eq(s21_strchr(test3, 'e'), strchr(test3, 'e'));
    ck_assert_ptr_eq(s21_strchr(test4, 'e'), strchr(test4, 'e'));
    ck_assert_ptr_eq(s21_strchr(test5, 'e'), strchr(test5, 'e'));
    ck_assert_ptr_eq(s21_strchr(test6, 'e'), strchr(test6, 'e'));
    ck_assert_ptr_eq(s21_strchr(test7, 'e'), strchr(test7, 'e'));
}
END_TEST

//  strcmp  test
START_TEST(s21_strcmp_f) {
    char toCompare[] = "Hell0 man";

    ck_assert_int_eq(s21_strcmp(test1, toCompare), strcmp(test1, toCompare));
    ck_assert_int_eq(s21_strcmp(test2, toCompare), strcmp(test2, toCompare));
    ck_assert_int_eq(s21_strcmp(test3, toCompare), strcmp(test3, toCompare));
    ck_assert_int_eq(s21_strcmp(test4, toCompare), strcmp(test4, toCompare));
    ck_assert_int_eq(s21_strcmp(test5, toCompare), strcmp(test5, toCompare));
    ck_assert_int_eq(s21_strcmp(test6, toCompare), strcmp(test6, toCompare));
    ck_assert_int_eq(s21_strcmp(test7, toCompare), strcmp(test7, toCompare));
}
END_TEST

//  strncmp test
START_TEST(s21_strncmp_f) {
    char toCompare[] = "Hell0 man";

    ck_assert_int_eq(s21_strncmp(test1, toCompare, 6),
                     strncmp(test1, toCompare, 6));
    ck_assert_int_eq(s21_strncmp(test2, toCompare, 6),
                     strncmp(test2, toCompare, 6));
    ck_assert_int_eq(s21_strncmp(test3, toCompare, 4),
                     strncmp(test3, toCompare, 4));
    ck_assert_int_eq(s21_strncmp(test4, toCompare, 4),
                     strncmp(test4, toCompare, 4));
    ck_assert_int_eq(s21_strncmp(test5, toCompare, 3),
                     strncmp(test5, toCompare, 3));
    ck_assert_int_eq(s21_strncmp(test6, toCompare, 3),
                     strncmp(test6, toCompare, 3));
    ck_assert_int_eq(s21_strncmp(test7, toCompare, 2),
                     strncmp(test7, toCompare, 2));
}
END_TEST

//  strcpy  test
START_TEST(s21_strcpy_f) {
    char destination[] = "Here w0 are\0";
    char result[] = "Here w0 are\0";
    ck_assert_str_eq(s21_strcpy(destination, test1), strcpy(result, test1));

    char destination2[] = "Here w0 are\n\0";
    char result2[] = "Here w0 are\n\0";
    ck_assert_str_eq(s21_strcpy(destination2, test2), strcpy(result2, test2));

    char destination3[] = "a\n\0";
    char result3[] = "a\n\0";
    ck_assert_str_eq(s21_strcpy(destination3, test3), strcpy(result3, test3));

    char destination4[] = " \n\0";
    char result4[] = " \n\0";
    ck_assert_str_eq(s21_strcpy(destination4, test4), strcpy(result4, test4));

    char destination5[] = " \0";
    char result5[] = " \0";
    ck_assert_str_eq(s21_strcpy(destination5, test5), strcpy(result5, test5));

    char destination6[] = "\n\0";
    char result6[] = "\n\0";
    ck_assert_str_eq(s21_strcpy(destination6, test6), strcpy(result6, test6));

    char destination7[] = "\0";
    char result7[] = "\0";
    ck_assert_str_eq(s21_strcpy(destination7, test7), strcpy(result7, test7));
}
END_TEST

//  strncpy test
START_TEST(s21_strncpy_f) {
    char destination[] = "Here w0 are\0";
    char result[] = "Here w0 are\0";
    ck_assert_str_eq(s21_strncpy(destination, test1, 4),
                     strncpy(result, test1, 4));

    char destination2[] = "Here w0 are\n\0";
    char result2[] = "Here w0 are\n\0";
    ck_assert_str_eq(s21_strncpy(destination2, test2, 8),
                     strncpy(result2, test2, 8));

    char destination3[] = "a\n\0";
    char result3[] = "a\n\0";
    ck_assert_str_eq(s21_strncpy(destination3, test3, 2),
                     strncpy(result3, test3, 2));

    char destination4[] = " \n\0";
    char result4[] = " \n\0";
    ck_assert_str_eq(s21_strncpy(destination4, test4, 2),
                     strncpy(result4, test4, 2));

    char destination5[] = " \0";
    char result5[] = " \0";
    ck_assert_str_eq(s21_strncpy(destination5, test5, 2),
                     strncpy(result5, test5, 2));

    char destination6[] = "\n\0";
    char result6[] = "\n\0";
    ck_assert_str_eq(s21_strncpy(destination6, test6, 2),
                     strncpy(result6, test6, 2));

    char destination7[] = "\0";
    char result7[] = "\0";
    ck_assert_str_eq(s21_strncpy(destination7, test7, 2),
                     strncpy(result7, test7, 2));
}
END_TEST

//  strcspn test
START_TEST(s21_strcspn_f) {
    char toCompare[] = "0a \n";

    ck_assert_uint_eq(s21_strcspn(test1, toCompare), strcspn(test1, toCompare));
    ck_assert_uint_eq(s21_strcspn(test2, toCompare), strcspn(test2, toCompare));
    ck_assert_uint_eq(s21_strcspn(test3, toCompare), strcspn(test3, toCompare));
    ck_assert_uint_eq(s21_strcspn(test4, toCompare), strcspn(test4, toCompare));
    ck_assert_uint_eq(s21_strcspn(test5, toCompare), strcspn(test5, toCompare));
    ck_assert_uint_eq(s21_strcspn(test6, toCompare), strcspn(test6, toCompare));
    ck_assert_uint_eq(s21_strcspn(test7, toCompare), strcspn(test7, toCompare));
}
END_TEST

//  strerror  test
START_TEST(s21_strerror_f) {
    int i = 0;
    while (i++ < 100) ck_assert_str_eq(s21_strerror(i), strerror(i));
}
END_TEST

//  strlen  test
START_TEST(s21_strlen_f) {
    ck_assert_uint_eq(s21_strlen(test1), strlen(test1));
    ck_assert_uint_eq(s21_strlen(test2), strlen(test2));
    ck_assert_uint_eq(s21_strlen(test3), strlen(test3));
    ck_assert_uint_eq(s21_strlen(test4), strlen(test4));
    ck_assert_uint_eq(s21_strlen(test5), strlen(test5));
    ck_assert_uint_eq(s21_strlen(test6), strlen(test6));
    ck_assert_uint_eq(s21_strlen(test7), strlen(test7));
}
END_TEST

//  strpbrk test
START_TEST(s21_strpbrk_f) {
    char toCompare[] = "aeou";

    ck_assert_str_eq(s21_strpbrk(test1, toCompare), strpbrk(test1, toCompare));
    ck_assert_str_eq(s21_strpbrk(test2, toCompare), strpbrk(test2, toCompare));
    ck_assert_str_eq(s21_strpbrk(test3, toCompare), strpbrk(test3, toCompare));
    ck_assert_ptr_eq(s21_strpbrk(test4, toCompare), strpbrk(test4, toCompare));
    ck_assert_ptr_eq(s21_strpbrk(test5, toCompare), strpbrk(test5, toCompare));
    ck_assert_ptr_eq(s21_strpbrk(test6, toCompare), strpbrk(test6, toCompare));
    ck_assert_ptr_eq(s21_strpbrk(test7, toCompare), strpbrk(test7, toCompare));
}
END_TEST

//  strrchr test
START_TEST(s21_strrchr_f) {
    ck_assert_str_eq(s21_strrchr(test1, 'o'), strrchr(test1, 'o'));
    ck_assert_str_eq(s21_strrchr(test2, 'l'), strrchr(test2, 'l'));
    ck_assert_str_eq(s21_strrchr(test3, '\n'), strrchr(test3, '\n'));
    ck_assert_str_eq(s21_strrchr(test4, ' '), strrchr(test4, ' '));
    ck_assert_str_eq(s21_strrchr(test5, ' '), strrchr(test5, ' '));
    ck_assert_str_eq(s21_strrchr(test6, '\0'), strrchr(test6, '\0'));
    ck_assert_ptr_eq(s21_strrchr(test7, ' '), strrchr(test7, ' '));
}
END_TEST

//  strspn
START_TEST(s21_strspn_f) {
    char sym[] = "el";

    ck_assert_uint_eq(s21_strspn(test1, sym), strspn(test1, sym));
    ck_assert_uint_eq(s21_strspn(test2, sym), strspn(test2, sym));
    ck_assert_uint_eq(s21_strspn(test3, sym), strspn(test3, sym));
    ck_assert_uint_eq(s21_strspn(test4, sym), strspn(test4, sym));
    ck_assert_uint_eq(s21_strspn(test5, sym), strspn(test5, sym));
    ck_assert_uint_eq(s21_strspn(test6, sym), strspn(test6, sym));
    ck_assert_uint_eq(s21_strspn(test7, sym), strspn(test7, sym));
}
END_TEST

//  strstr
START_TEST(s21_strstr_f) {
    char sym[] = "el\0";

    char test8[10] = "\0";
    char sym2[10] = "";

    char test9[10] = "ello";
    char sym3[10] = "elk";

    char test11[10] = "ello";
    char sym5[10] = "elloz";

    ck_assert_str_eq(s21_strstr(test1, sym), strstr(test1, sym));
    ck_assert_str_eq(s21_strstr(test2, sym), strstr(test2, sym));
    ck_assert_ptr_eq(s21_strstr(test3, sym), strstr(test3, sym));
    ck_assert_ptr_eq(s21_strstr(test4, sym), strstr(test4, sym));
    ck_assert_ptr_eq(s21_strstr(test5, sym), strstr(test5, sym));
    ck_assert_ptr_eq(s21_strstr(test6, sym), strstr(test6, sym));
    ck_assert_ptr_eq(s21_strstr(test7, sym), strstr(test7, sym));
    ck_assert_ptr_eq(s21_strstr(test8, sym2), strstr(test8, sym2));
    ck_assert_ptr_eq(s21_strstr(test9, sym3), strstr(test9, sym3));
    ck_assert_ptr_eq(s21_strstr(test11, sym5), strstr(test11, sym5));
}
END_TEST

// strtok
START_TEST(s21_strtok_f) {
    char dest[] = "Hell0 world\0";
    char orig[] = "Hell0 world\0";
    ck_assert_str_eq(s21_strtok(dest, " "), strtok(orig, " "));

    char dest2[] = "Hell0 world\n\0";
    char orig2[] = "Hell0 world\n\0";
    ck_assert_str_eq(s21_strtok(dest2, " "), strtok(orig2, " "));

    char dest3[] = "a\n\0";
    char orig3[] = "a\n\0";
    ck_assert_str_eq(s21_strtok(dest3, " "), strtok(orig3, " "));

    char dest4[] = " s\0";
    char orig4[] = " s\0";
    ck_assert_str_eq(s21_strtok(dest4, " "), strtok(orig4, " "));

    char dest5[] = " \0";
    char orig5[] = " \0";
    ck_assert_ptr_eq(s21_strtok(dest5, " "), strtok(orig5, " "));

    char dest6[] = "\n\0";
    char orig6[] = "\n\0";
    ck_assert_str_eq(s21_strtok(dest6, " "), strtok(orig6, " "));

    char dest7[] = "\0";
    char orig7[] = "\0";
    ck_assert_ptr_eq(s21_strtok(dest7, " "), strtok(orig7, " "));

    char dest8[] = "test1/test2/test3/test4";
    char orig8[] = "test1/test2/test3/test4";
    ck_assert_str_eq(s21_strtok(dest8, "/"), strtok(orig8, "/"));
    ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_ptr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));

    char dest9[] = "test1/test2/test3///";
    char orig9[] = "test1/test2/test3///";
    ck_assert_str_eq(s21_strtok(dest9, "/"), strtok(orig9, "/"));
    ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_ptr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));

    char dest10[] = "///test1///test2/test3/";
    char orig10[] = "///test1///test2/test3/";
    ck_assert_str_eq(s21_strtok(dest10, "/"), strtok(orig10, "/"));
    ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_str_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
    ck_assert_ptr_eq(s21_strtok(NULL, "/"), strtok(NULL, "/"));
}
END_TEST

//  to_upper test
START_TEST(s21_to_upper_f) {
    char destination[] = "Here w0 are123\0";
    char *test01 = s21_to_upper(destination);
    ck_assert_str_eq(test01, "HERE W0 ARE123");
    free(test01);

    char destination2[] = "Here w0 are\n\0";
    char *test02 = s21_to_upper(destination2);
    ck_assert_str_eq(test02, "HERE W0 ARE\n");
    free(test02);

    char destination3[] = "a\n\0";
    char *test03 = s21_to_upper(destination3);
    ck_assert_str_eq(test03, "A\n");
    free(test03);

    char destination4[] = " \n\0";
    char *test04 = s21_to_upper(destination4);
    ck_assert_str_eq(test04, " \n");
    free(test04);

    char destination5[] = " \0";
    char *test05 = s21_to_upper(destination5);
    ck_assert_str_eq(test05, " ");
    free(test05);

    char destination6[] = "\n\0";
    char *test06 = s21_to_upper(destination6);
    ck_assert_str_eq(test06, "\n");
    free(test06);

    char destination7[] = "\0";
    char *test07 = s21_to_upper(destination7);
    ck_assert_str_eq(test07, "");
    free(test07);
}
END_TEST

//  to_lower test
START_TEST(s21_to_lower_f) {
    char destination[] = "HERE W0 ARE123\0";
    char *test01 = s21_to_lower(destination);
    ck_assert_str_eq(test01, "here w0 are123");
    free(test01);

    char destination2[] = "HERE W0 ARE\n\0";
    char *test02 = s21_to_lower(destination2);
    ck_assert_str_eq(test02, "here w0 are\n");
    free(test02);

    char destination3[] = "A\n\0";
    char *test03 = s21_to_lower(destination3);
    ck_assert_str_eq(test03, "a\n");
    free(test03);

    char destination4[] = " \n\0";
    char *test04 = s21_to_lower(destination4);
    ck_assert_str_eq(test04, " \n");
    free(test04);

    char destination5[] = " \0";
    char *test05 = s21_to_lower(destination5);
    ck_assert_str_eq(test05, " ");
    free(test05);

    char destination6[] = "\n\0";
    char *test06 = s21_to_lower(destination6);
    ck_assert_str_eq(test06, "\n");
    free(test06);

    char destination7[] = "\0";
    char *test07 = s21_to_lower(destination7);
    ck_assert_str_eq(test07, "");
    free(test07);
}
END_TEST

//  insert test
START_TEST(s21_insert_f) {
    char dest[] = "Hello\0";
    char insert[] = "Man\0";
    char *test01 = s21_insert(dest, insert, 2);
    ck_assert_str_eq(test01, "HeManllo\0");
    free(test01);

    char dest2[] = "Hello\n\0";
    char insert2[] = "Man\n\0";
    char *test02 = s21_insert(dest2, insert2, 1);
    ck_assert_str_eq(test02, "HMan\nello\n\0");
    free(test02);

    char dest3[] = "a\0";
    char insert3[] = "man\0";
    char *test03 = s21_insert(dest3, insert3, 1);
    ck_assert_str_eq(test03, "aman");
    free(test03);

    char dest4[] = " s\0";
    char insert4[] = " s\0";
    char *test04 = s21_insert(dest4, insert4, 1);
    ck_assert_str_eq(test04, "  ss");
    free(test04);

    char dest5[100] = "\n\0";
    char insert5[100] = "\n\0";
    char *test05 = s21_insert(dest5, insert5, 1);
    ck_assert_str_eq(test05, "\n\n");
    free(test05);

    char dest6[] = " \0";
    char insert6[] = " \0";
    char *test06 = s21_insert(dest6, insert6, 1);
    ck_assert_str_eq(test06, "  ");
    free(test06);

    char dest7[] = "\0";
    char insert7[] = "\0";
    char *test07 = s21_insert(dest7, insert7, 1);
    ck_assert_ptr_eq(test07, s21_NULL);
}
END_TEST

//  trim test
START_TEST(s21_trim_f) {
    char dest[] = "-=Hello=-\0";
    char *test01 = s21_trim(dest, "-");
    ck_assert_str_eq(test01, "=Hello=\0");
    free(test01);

    char dest2[] = "-Hello\n\0";
    char *test02 = s21_trim(dest2, "-");
    ck_assert_str_eq(test02, "Hello\n\0");
    free(test02);

    char dest3[] = "a\0";
    char *test03 = s21_trim(dest3, "a");
    ck_assert_str_eq(test03, "");
    free(test03);

    char dest4[] = " \n\0";
    char *test04 = s21_trim(dest4, "\n");
    ck_assert_str_eq(test04, " ");
    free(test04);

    char dest5[] = "\n\0";
    char *test05 = s21_trim(dest5, "\0");
    ck_assert_str_eq(test05, "\n");
    free(test05);

    char dest6[] = " \0";
    char *test06 = s21_trim(dest6, " ");
    ck_assert_str_eq(test06, "");
    free(test06);

    char dest7[] = " \0";
    char *test07 = s21_trim(dest6, s21_NULL);
    ck_assert_str_eq(test07, "");
    free(test07);
}
END_TEST

START_TEST(s21_chars_f) {
    char s21_buffer[256] = {0};
    char buffer[256] = {0};
    s21_sprintf(s21_buffer, "%%%% %c %s %c%s %c %s %s %s %s %s", 'a', test1,
                '\n', test2, '-', test3, test4, test5, test6, test7);
    sprintf(buffer, "%%%% %c %s %c%s %c %s %s %s %s %s", 'a', test1, '\n',
            test2, '-', test3, test4, test5, test6, test7);
    ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_nums_f) {
    char s21_buffer[256] = {0};
    char buffer[256] = {0};
    s21_sprintf(s21_buffer,
                "%-2i %+5i % 4i %2i %4d %d %15d %-+15d %22u %5u %4u %3u", 101,
                -210, -0, '0', 101, -210, -0, '0', (unsigned int)101,
                (unsigned int)210, (unsigned int)-0, (unsigned int)'0');
    sprintf(buffer, "%-2i %+5i % 4i %2i %4d %d %15d %-+15d %22u %5u %4u %3u",
            101, -210, -0, '0', 101, -210, -0, '0', (unsigned int)101,
            (unsigned int)210, (unsigned int)-0, (unsigned int)'0');
    ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_nums2_f) {
    char s21_buffer[256] = {0};
    char buffer[256] = {0};

    s21_sprintf(s21_buffer, "%- 5li %-5hi %12hu %-4lu %hi %li %hi %li",
                (long int)125123123123, (short int)160, (unsigned short)101,
                (unsigned long)210, (short int)0, (long int)0, (short int)-25,
                (long int)-51);
    sprintf(buffer, "%- 5li %-5hi %12hu %-4lu %hi %li %hi %li",
            (long int)125123123123, (short int)160, (unsigned short)101,
            (unsigned long)210, (short int)0, (long int)0, (short int)-25,
            (long int)-51);
    ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_nums3_f) {
    char s21_buffer[256] = {0};
    char buffer[256] = {0};
    s21_sprintf(s21_buffer, "%-+6.4f %-2.2lf %5.5f %f %f", 100.0, 0.01, 0.10,
                -12.0, 0.00001);
    sprintf(buffer, "%-+6.4f %-2.2f %5.5f %f %f", 100.0, 0.01, 0.10, -12.0,
            0.00001);
    ck_assert_str_eq(s21_buffer, buffer);

    char s21_buffer2[256] = {0};
    char buffer2[256] = {0};
    s21_sprintf(s21_buffer2, "%lf %lf %lf %lf %lf %lf", 0.0/0.0,  1.0/0.0, 0.0/1.0,
                         -0.0/0.0, -1.0/0.0, -0.0/1.0);
    sprintf(buffer2, "%lf %lf %lf %lf %lf %lf", 0.0/0.0,  1.0/0.0, 0.0/1.0,
                     -0.0/0.0, -1.0/0.0, -0.0/1.0);
    ck_assert_str_eq(s21_buffer2, buffer2);

    char s21_buffer3[256] = {0};
    char buffer3[256] = {0};
    s21_sprintf(s21_buffer3, "%lg %lG %#lg le", 234243.234, 8427348.234, 123.0, 155.2);
    sprintf(buffer3, "%lg %lG %#lg le", 234243.234, 8427348.234, 123.0, 155.2);
    ck_assert_str_eq(s21_buffer3, buffer3);
}
END_TEST

START_TEST(sscanf_test_e) {
    float e1 = 0, e2 = 0;
    int r1 = 0, r2 = 0;

    r1 = sscanf("123e34", "%e", &e1);
    r2 = s21_sscanf("123e34", "%e", &e2);
    ck_assert_msg(e1 == e2, "float not equals");
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("12e34", "%e", &e1);
    r2 = s21_sscanf("12e34", "%e", &e2);
    ck_assert_msg(e1 == e2, "float not equals");
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("123.345e-34", "%9e", &e1);
    r2 = s21_sscanf("123.345e-34", "%9e", &e2);
    ck_assert_msg(e1 == e2, "float not equals");
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("123.345e34", "%8e", &e1);
    r2 = s21_sscanf("123.345e34", "%8e", &e2);
    ck_assert_msg(e1 == e2, "float not equals");
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_l) {
    int r1 = 0, r2 = 0;
    unsigned long lu1 = 0, lu2 = 0;
    long ld1 = 0, ld2 = 0;
    wchar_t lc1, lc2, ls1[100], ls2[100];

    r1 = sscanf("a", "%lc", &lc1);
    r2 = s21_sscanf("a", "%lc", &lc2);
    ck_assert_int_eq(lc1, lc2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("ab", "%*c%lc", &lc1);
    r2 = s21_sscanf("ab", "%*c%lc", &lc2);
    ck_assert_int_eq(lc1, lc2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("12345", "%lu", &lu1);
    r2 = s21_sscanf("12345", "%lu", &lu2);
    ck_assert_int_eq(lu1, lu2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("12345", "%ld", &ld1);
    r2 = s21_sscanf("12345", "%ld", &ld2);
    ck_assert_int_eq(ld1, ld2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("kraken", "%9ls", ls1);
    r2 = s21_sscanf("kraken", "%9ls", ls2);
    ck_assert_int_eq(wcscmp(ls1, ls2), 0);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("kraken", "%ls", ls1);
    r2 = s21_sscanf("kraken", "%ls", ls2);
    ck_assert_int_eq(wcscmp(ls1, ls2), 0);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("kraken", "%2ls", ls1);
    r2 = s21_sscanf("kraken", "%2ls", ls2);
    ck_assert_int_eq(wcscmp(ls1, ls2), 0);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_L) {
    int r1 = 0, r2 = 0;
    long double Lf1 = 0, Lf2 = 0;

    r1 = sscanf("123.45", "%Lf", &Lf1);
    r2 = s21_sscanf("123.45", "%Lf", &Lf2);
    ck_assert_msg((int)Lf1 == (int)Lf2, "floats not equals");
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_u) {
    int r1 = 0, r2 = 0;
    unsigned u1 = 0, u2 = 0;

    r1 = sscanf("", "%u", &u1);
    r2 = s21_sscanf("", "%u", &u2);
    ck_assert_int_eq(u1, u2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("-0x123", "%u", &u1);
    r2 = s21_sscanf("-0x123", "%u", &u2);
    ck_assert_int_eq(u1, u2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("+0x123", "%2u", &u1);
    r2 = s21_sscanf("+0x123", "%2u", &u2);
    ck_assert_int_eq(u1, u2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("+123", "%u", &u1);
    r2 = s21_sscanf("+123", "%u", &u2);
    ck_assert_int_eq(u1, u2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("+z123", "%u", &u1);
    r2 = s21_sscanf("+z123", "%u", &u2);
    ck_assert_int_eq(u1, u2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0x12345", "%2u", &u1);
    r2 = s21_sscanf("0x12345", "%2u", &u2);
    ck_assert_int_eq(u1, u2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("123.456", "%u", &u1);
    r2 = s21_sscanf("123.456", "%u", &u2);
    ck_assert_msg(u1 == u2, "floats not equals");
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_h) {
    int r1 = 0, r2 = 0;
    unsigned short hu1 = 0, hu2 = 0;

    r1 = sscanf("12345", "%hu", &hu1);
    r2 = s21_sscanf("12345", "%hu", &hu2);
    ck_assert_int_eq(hu1, hu2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_s) {
    int r1 = 0, r2 = 0;
    char s1[100], s2[100];

    r1 = sscanf("werty kraken", "%*s%2s", s1);
    r2 = s21_sscanf("werty kraken", "%*s%2s", s2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("\nwerty kraken", "%*s%10s", s1);
    r2 = s21_sscanf("\nwerty kraken", "%*s%10s", s2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("   werty kraken", "%*s%s", s1);
    r2 = s21_sscanf("   werty kraken", "%*s%s", s2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("", "%s", s1);
    r2 = s21_sscanf("", "%s", s2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("\0", "%s", s1);
    r2 = s21_sscanf("\0", "%s", s2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("   weartewrsthxffdtsrhdfghdfghdfghdfghdfghdfghfdgпывапывапывапы", "%s", s1);
    r2 = s21_sscanf("   weartewrsthxffdtsrhdfghdfghdfghdfghdfghdfghfdgпывапывапывапы", "%s", s2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_f) {
    int r1 = 0, r2 = 0;
    float f1 = 0, f2 = 0;

    r1 = sscanf("12e-3", "%f", &f1);
    r2 = s21_sscanf("12e-3", "%f", &f2);
    ck_assert_int_eq(f1, f2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("12e11", "%5f", &f1);
    r2 = s21_sscanf("12e11", "%5f", &f2);
    ck_assert_int_eq(f1, f2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("-12e-3", "%f", &f1);
    r2 = s21_sscanf("-12e-3", "%f", &f2);
    ck_assert_int_eq(f1, f2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("-12e-11", "%f", &f1);
    r2 = s21_sscanf("-12e-11", "%f", &f2);
    ck_assert_int_eq(f1, f2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("12e-111", "%5f", &f1);
    r2 = s21_sscanf("12e-111", "%5f", &f2);
    ck_assert_int_eq(f1, f2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("12e-111", "%6f", &f1);
    r2 = s21_sscanf("12e-111", "%6f", &f2);
    ck_assert_int_eq(f1, f2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("+12e-3", "%f", &f1);
    r2 = s21_sscanf("+12e-3", "%f", &f2);
    ck_assert_int_eq(f1, f2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("12e+3", "%f", &f1);
    r2 = s21_sscanf("12e+3", "%f", &f2);
    ck_assert_int_eq(f1, f2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("12e3", "%4f", &f1);
    r2 = s21_sscanf("12e3", "%f4", &f2);
    ck_assert_int_eq(f1, f2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("12e3", "%3f", &f1);
    r2 = s21_sscanf("12e3", "%3f", &f2);
    ck_assert_int_eq(f1, f2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("2 12e3", "1 %4f", &f1);
    r2 = s21_sscanf("2 12e3", "1 %4f", &f2);
    ck_assert_int_eq(f1, f2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("-123.45", "%f", &f1);
    r2 = s21_sscanf("-123.45", "%f", &f2);
    ck_assert_int_eq(f1, f2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("-12.345", "%5f", &f1);
    r2 = s21_sscanf("-12.345", "%5f", &f2);
    ck_assert_int_eq(f1, f2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("12.345", "%5f", &f1);
    r2 = s21_sscanf("12.345", "%5f", &f2);
    ck_assert_int_eq(f1, f2);
    ck_assert_int_eq(r1, r2);

    int i1 = -1, i2 = -1;
    char c1, c2;
    f1 = 0; f2 = 0;
    r1 = sscanf("z 21", "%f%c %i", &f1, &c1, &i1);
    r2 = s21_sscanf("z 21", "%f%c %i", &f2, &c2, &i2);
    ck_assert_int_eq(f1, f2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf(".z 21", "%f%c %i", &f1, &c1, &i1);
    r2 = s21_sscanf(".z 21", "%f%c %i", &f2, &c2, &i2);
    ck_assert_int_eq(f1, f2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf(".z 21", "%3f%c %i", &f1, &c1, &i1);
    r2 = s21_sscanf(".z 21", "%3f%c %i", &f2, &c2, &i2);
    ck_assert_int_eq(f1, f2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0.z 21", "%3f%c %i", &f1, &c1, &i1);
    r2 = s21_sscanf("0.z 21", "%3f%c %i", &f2, &c2, &i2);
    ck_assert_int_eq(f1, f2);
    ck_assert_int_eq(r1, r2);

    double d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0;
    r1 = sscanf("12.345 -12.345 12e3", "%5lf %5lf %3lf", &d1, &d3, &d5);
    r2 = s21_sscanf("12.345 -12.345 12e3", "%5lf %5lf %3lf", &d2, &d4, &d6);
    ck_assert_double_eq(d1, d2); ck_assert_double_eq(d3, d4); ck_assert_double_eq(d5, d6);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_o) {
    int r1 = 0, r2 = 0;
    unsigned o1 = 0, o2 = 0, o3 = 0, o4 = 0, o5 = 0, o6 = 0;
    long unsigned int o7 = 0, o8 = 0, o9 = 0, o10 = 0;
    short unsigned int o11 = 0, o12 = 0;

    r1 = sscanf("12345678", "%3o", &o1);
    r2 = s21_sscanf("12345678", "%3o", &o2);
    ck_assert_int_eq(o1, o2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("+12345678", "%3o", &o1);
    r2 = s21_sscanf("+12345678", "%3o", &o2);
    ck_assert_int_eq(o1, o2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("012345678", "%3o", &o1);
    r2 = s21_sscanf("012345678", "%3o", &o2);
    ck_assert_int_eq(o1, o2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("-12345678", "%3o", &o1);
    r2 = s21_sscanf("-12345678", "%3o", &o2);
    ck_assert_int_eq(o1, o2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("123.456", "%o", &o1);
    r2 = s21_sscanf("123.456", "%o", &o2);
    ck_assert_uint_eq(o1, o2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("45 011 000 041", "%o%*o %o%o", &o1, &o3, &o5);
    r2 = s21_sscanf("45 011 000 041", "%o%*o %o%o", &o2, &o4, &o6);
    ck_assert_uint_eq(o1, o2); ck_assert_uint_eq(o3, o4); ck_assert_uint_eq(o5, o6);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("+36 -0123 -59", "%o %o %o", &o1, &o3, &o5);
    r2 = s21_sscanf("+36 -0123 -59", "%o %o %o", &o2, &o4, &o6);
    ck_assert_uint_eq(o1, o2); ck_assert_uint_eq(o3, o4); ck_assert_uint_eq(o5, o6);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("34 -123456 055", "%2o -%3o 456%02o", &o1, &o3, &o5);
    r2 = s21_sscanf("34 -123456 055", "%2o -%3o 456%02o", &o2, &o4, &o6);
    ck_assert_uint_eq(o1, o2); ck_assert_uint_eq(o3, o4); ck_assert_uint_eq(o5, o6);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0x9 -0xa2 0xBa1", "%ho %lo %lo", &o11, &o7, &o9);
    r2 = s21_sscanf("0x9 -0xa2 0xBa1", "%ho %lo %lo", &o12, &o8, &o10);
    ck_assert_uint_eq(o11, o12); ck_assert_uint_eq(o7, o8); ck_assert_uint_eq(o9, o10);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("10 12345678", "%ho %lo", &o11, &o7);
    r2 = s21_sscanf("10 12345678", "%ho %lo", &o12, &o8);
    ck_assert_uint_eq(o11, o12); ck_assert_uint_eq(o7, o8); ck_assert_uint_eq(o9, o10);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_x) {
    int r1 = 0, r2 = 0;
    unsigned x1 = 0, x2 = 0;
    unsigned x3 = 0, x4 = 0;
    unsigned short x5 = 0, x6 = 0;
    unsigned long x7 = 0, x8 = 0;

    r1 = sscanf("0x12345", "%2x", &x1);
    r2 = s21_sscanf("0x12345", "%2x", &x2);
    ck_assert_uint_eq(x1, x2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("abcdef", "%x", &x1);
    r2 = s21_sscanf("abcdef", "%x", &x2);
    ck_assert_int_eq(x1, x2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("abcdef", "%hx", &x5);
    r2 = s21_sscanf("abcdef", "%hx", &x6);
    ck_assert_int_eq(x5, x6);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("abcdef", "%lx", &x7);
    r2 = s21_sscanf("abcdef", "%lx", &x8);
    ck_assert_int_eq(x7, x8);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0gabcdef", "%hx", &x5);
    r2 = s21_sscanf("0gabcdef", "%hx", &x6);
    ck_assert_int_eq(x5, x6);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0gabcdef", "%lx", &x7);
    r2 = s21_sscanf("0gabcdef", "%lx", &x8);
    ck_assert_int_eq(x7, x8);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("KRAKEN", "%X", &x1);
    r2 = s21_sscanf("KRAKEN", "%X", &x2);
    ck_assert_uint_eq(x1, x2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("kraken", "%x", &x1);
    r2 = s21_sscanf("kraken", "%x", &x2);
    ck_assert_uint_eq(x1, x2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0x1234567890123456", "%x", &x1);
    r2 = s21_sscanf("0x1234567890123456", "%x", &x2);
    ck_assert_uint_eq(x1, x2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0x123", "%x", &x1);
    r2 = s21_sscanf("0x123", "%x", &x2);
    ck_assert_uint_eq(x1, x2);
    ck_assert_int_eq(r1, r2);

    char t1 = '0', t2 = '0';
    r1 = sscanf("0y923", "%x%c", &x1, &t1);
    r2 = s21_sscanf("0y923", "%x%c", &x2, &t2);
    ck_assert_uint_eq(x1, x2);
    ck_assert_int_eq(t1, t2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("y123", "%x", &x1);
    r2 = s21_sscanf("y123", "%x", &x2);
    ck_assert_uint_eq(x1, x2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0xy123", "%x", &x1);
    r2 = s21_sscanf("0xy123", "%x", &x2);
    ck_assert_uint_eq(x1, x2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("+123456", "%x", &x1);
    r2 = s21_sscanf("+123456", "%x", &x2);
    ck_assert_uint_eq(x1, x2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("-123456 0x12345", "%X %x", &x1, &x3);
    r2 = s21_sscanf("-123456 0x12345", "%X %x", &x2, &x4);
    ck_assert_uint_eq(x1, x2); ck_assert_uint_eq(x3, x4);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("bcdef", "      %x", &x1);
    r2 = s21_sscanf("bcdef", "      %x", &x2);
    ck_assert_uint_eq(x1, x2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("-bcdef", "%x", &x1);
    r2 = s21_sscanf("-bcdef", "%x", &x2);
    ck_assert_uint_eq(x1, x2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("1 2 3 0123", "1 2 3 %x", &x1);
    r2 = s21_sscanf("1 2 3 0123", "1 2 3 %x", &x2);
    ck_assert_uint_eq(x1, x2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_i) {
    int r1 = 0, r2 = 0;
    int i1 = -1, i2 = -1, i3 = 0, i4 = 0, i5 = 0, i6 = 0;
    short int i7, i8, i9, i10, i11, i12;
    long int i20, i21, i22, i23, i24, i25;

    // short int
    r1 = sscanf("0x9 001  777", "%hi %hi %hi", &i7, &i9, &i11);
    r2 = s21_sscanf("0x9 001  777", "%hi %hi %hi", &i8, &i10, &i12);
    ck_assert_int_eq(i7, i8); ck_assert_int_eq(i9, i10); ck_assert_int_eq(i11, i12);
    ck_assert_int_eq(r1, r2);

    // long int
    r1 = sscanf("-0x80000001 017777777777 2234234234234", "%li %li %li", &i20, &i22, &i24);
    r2 = s21_sscanf("-0x80000001 017777777777 2234234234234", "%li %li %li", &i21, &i23, &i25);
    ck_assert_int_eq(i20, i21); ck_assert_int_eq(i22, i23); ck_assert_int_eq(i24, i25);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0z123", "%hi", &i7);
    r2 = s21_sscanf("0z123", "%hi", &i8);
    ck_assert_int_eq(i7, i8);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0z123", "%li", &i20);
    r2 = s21_sscanf("0z123", "%li", &i21);
    ck_assert_int_eq(i20, i21);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0123", "%i", &i1);
    r2 = s21_sscanf("0123", "%i", &i2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("09", "%i", &i1);
    r2 = s21_sscanf("09", "%i", &i2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("s0123", "%i", &i1);
    r2 = s21_sscanf("s0123", "%i", &i2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0s123", "%i", &i1);
    r2 = s21_sscanf("0s123", "%i", &i2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0xs123", "%i", &i1);
    r2 = s21_sscanf("0xs123", "%i", &i2);

    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("-0123", "%i", &i1);
    r2 = s21_sscanf("-0123", "%i", &i2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0x123", "%i", &i1);
    r2 = s21_sscanf("0x123", "%i", &i2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0x123", "%4i", &i1);
    r2 = s21_sscanf("0x123", "%4i", &i2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0x123", "%6i", &i1);
    r2 = s21_sscanf("0x123", "%6i", &i2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0x123", "%2i", &i1);
    r2 = s21_sscanf("0x123", "%2i", &i2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("-123 5.     -0", "%i%2i %i", &i1, &i3, &i5);
    r2 = s21_sscanf("-123 5.     -0", "%i%2i %i", &i2, &i4, &i6);
    ck_assert_int_eq(i1, i2); ck_assert_int_eq(i3, i4); ck_assert_int_eq(i5, i6);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("-12 -10+3.5", "%3i %*i %i", &i1, &i3);
    r2 = s21_sscanf("-12 -10+3.5", "%3i %*i %i", &i2, &i4);
    ck_assert_int_eq(i1, i2); ck_assert_int_eq(i3, i4);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("-21474836481 2147483648", "%i %i", &i1, &i3);
    r2 = s21_sscanf("-21474836481 2147483648", "%i %i", &i2, &i4);
    ck_assert_int_eq(i1, i2); ck_assert_int_eq(i3, i4);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("-2147483648 -000", "%i %i", &i1, &i3);
    r2 = s21_sscanf("-2147483648 -000", "%i %i", &i2, &i4);
    ck_assert_int_eq(i1, i2); ck_assert_int_eq(i3, i4);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("077 -034      089", "%i%i%i", &i1, &i3, &i5);
    r2 = s21_sscanf("077 -034      089", "%i%i%i", &i2, &i4, &i6);
    ck_assert_int_eq(i1, i2); ck_assert_int_eq(i3, i4); ck_assert_int_eq(i5, i6);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("077 -0234 01", "%2i 7 %i%*i", &i1, &i3);
    r2 = s21_sscanf("077 -0234 01", "%2i 7 %i%*i", &i2, &i4);
    ck_assert_int_eq(i1, i2); ck_assert_int_eq(i3, i4);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("017777777777 020000000000", "%i %i", &i1, &i3);
    r2 = s21_sscanf("017777777777 020000000000", "%i %i", &i2, &i4);
    ck_assert_int_eq(i1, i2); ck_assert_int_eq(i3, i4);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("-020000000000 -020000000001", "%i %i", &i1, &i3);
    r2 = s21_sscanf("-020000000000 -020000000001", "%i %i", &i2, &i4);
    ck_assert_int_eq(i1, i2); ck_assert_int_eq(i3, i4);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0x9 -0xa2      0xBa1", "%*i%5i%i", &i1, &i3);
    r2 = s21_sscanf("0x9 -0xa2      0xBa1", "%*i%5i%i", &i2, &i4);
    ck_assert_int_eq(i1, i2); ck_assert_int_eq(i3, i4);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0x0 -0x3K0x02", "%i %i K %i", &i1, &i3, &i5);
    r2 = s21_sscanf("0x0 -0x3K0x02", "%i %i K %i", &i2, &i4, &i6);
    ck_assert_int_eq(i1, i2); ck_assert_int_eq(i3, i4); ck_assert_int_eq(i5, i6);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0x7fffffff 0x80000000", "%i %i", &i1, &i3);
    r2 = s21_sscanf("0x7fffffff 0x80000000", "%i %i", &i2, &i4);
    ck_assert_int_eq(i1, i2); ck_assert_int_eq(i3, i4);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("-0x80000000 -0x80000001", "%i %i", &i1, &i3);
    r2 = s21_sscanf("-0x80000000 -0x80000001", "%i %i", &i2, &i4);
    ck_assert_int_eq(i1, i2); ck_assert_int_eq(i3, i4);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("056 y 67", "%i %i %i", &i1, &i3, &i5);
    r2 = s21_sscanf("056 y 67", "%i %i %i", &i2, &i4, &i6);
    ck_assert_int_eq(i1, i2); ck_assert_int_eq(i3, i4); ck_assert_int_eq(i5, i6);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("-0xa2 y 02", "%i %*i %i", &i1, &i3);
    r2 = s21_sscanf("-0xa2 y 02", "%i %*i %i", &i2, &i4);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(i3, i4);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_proc) {
    int r1 = 0, r2 = 0;
    char proc1[100] = {0}, proc2[100] = {0};

    r1 = sscanf("%123.456", "%%%9s", proc1);
    r2 = s21_sscanf("%123.456", "%%%9s", proc2);
    ck_assert_str_eq(proc1, proc2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("123.456", "%%%9s", proc1);
    r2 = s21_sscanf("123.456", "%%%9s", proc2);
    ck_assert_str_eq(proc1, proc2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_p) {
    int r1 = 0, r2 = 0;
    void *p1 = 0, *p2 = 0;

    r1 = sscanf("0x123", "%4p", &p1);
    r2 = s21_sscanf("0x123", "%4p", &p2);
    ck_assert_ptr_eq(p1, p2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0xz123", "%4p", &p1);
    r2 = s21_sscanf("0xz123", "%4p", &p2);
    ck_assert_ptr_eq(p1, p2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0zx123", "%4p", &p1);
    r2 = s21_sscanf("0zx123", "%4p", &p2);
    ck_assert_ptr_eq(p1, p2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("z0x123", "%4p", &p1);
    r2 = s21_sscanf("z0x123", "%4p", &p2);
    ck_assert_ptr_eq(p1, p2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("-z0x123", "%4p", &p1);
    r2 = s21_sscanf("-z0x123", "%4p", &p2);
    ck_assert_ptr_eq(p1, p2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("-0x123", "%4p", &p1);
    r2 = s21_sscanf("-0x123", "%4p", &p2);
    ck_assert_ptr_eq(p1, p2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("123", "%4p", &p1);
    r2 = s21_sscanf("123", "%4p", &p2);
    ck_assert_ptr_eq(p1, p2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("0x12345", "%p", &p1);
    r2 = s21_sscanf("0x12345", "%p", &p2);
    ck_assert_ptr_eq(p1, p2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("123.456", "%p", &p1);
    r2 = s21_sscanf("123.456", "%p", &p2);
    ck_assert_ptr_eq(p1, p2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_n) {
    int n1 = 0, n2 = 0, r1 = 0, r2 = 0;
    short int n3 = 0, n4 = 0;
    long int n5 = 0, n6 = 0;

    r1 = sscanf("123.456", "123%hn", &n3);
    r2 = s21_sscanf("123.456", "123%hn", &n4);
    ck_assert_int_eq(n3, n4);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("123123.456", "123%ln", &n5);
    r2 = s21_sscanf("123123.456", "123%ln", &n6);
    ck_assert_int_eq(n5, n6);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("123.456", "%n", &n1);
    r2 = s21_sscanf("123.456", "%n", &n2);
    ck_assert_int_eq(n1, n2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("123123.456", "123%n", &n1);
    r2 = s21_sscanf("123123.456", "123%n", &n2);
    ck_assert_int_eq(n1, n2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("123 123.456", "123 %n", &n1);
    r2 = s21_sscanf("123 123.456", "123 %n", &n2);
    ck_assert_int_eq(n1, n2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("123 123.456", "123 %n", &n1);
    r2 = s21_sscanf("123 123.456", "123 %n", &n2);
    ck_assert_int_eq(n1, n2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("123 123.456", "123 %n", &n1);
    r2 = s21_sscanf("123 123.456", "123 %n", &n2);
    ck_assert_int_eq(n1, n2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_d) {
    int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0, d6 = 0, res1 = 0, res2 = 0;
    short int d7 = 0, d8 = 0, d9 = 0, d10 = 0;
    long int d11 = 0, d12 = 0, d13 = 0, d14 = 0;

    //  test %d 1
    res1 = s21_sscanf("0123 456 789", "%d %*d %002d", &d1, &d2);
    res2 = sscanf("0123 456 789", "%d %*d %002d", &d3, &d4);
    ck_assert_int_eq(res1, res2); ck_assert_int_eq(d1, d3); ck_assert_int_eq(d2, d4);

    //  test %d 2
    d1 = 0; d2 = 0; d3 = 0; d4 = 0; res1 = 0; res2 = 0;
    res1 = s21_sscanf("+1234567", "%3d%d", &d1, &d2);
    res2 = sscanf("+1234567", "%3d%d", &d3, &d4);
    ck_assert_int_eq(res1, res2); ck_assert_int_eq(d1, d3); ck_assert_int_eq(d2, d4);

    //  test %d 3
    d1 = 0; d2 = 0; d3 = 0; d4 = 0; res1 = 0; res2 = 0;
    res1 = s21_sscanf("1234567", "123%3d%d", &d1, &d2);
    res2 = sscanf("1234567", "123%3d%d", &d3, &d4);
    ck_assert_int_eq(res1, res2); ck_assert_int_eq(d1, d3); ck_assert_int_eq(d2, d4);

    // test %d 4
    d1 = 0; d2 = 0; d3 = 0; d4 = 0; d5 = 0; d6 = 0; res1 = 0; res2 = 0;
    res1 = s21_sscanf("-123 -4", "%3d%d %3d", &d1, &d2, &d3);
    res2 = sscanf("-123 -4", "%3d%d %3d", &d4, &d5, &d6);
    ck_assert_int_eq(res1, res2); ck_assert_int_eq(d1, d4); ck_assert_int_eq(d2, d5);
    ck_assert_int_eq(d3, d6);

    // test %d 5
    d1 = 0; d2 = 0; d3 = 0; d4 = 0; res1 = 0; res2 = 0;
    res1 = s21_sscanf("-21474836481 2147483648", "%d %d", &d1, &d2);
    res2 = sscanf("-21474836481 2147483648", "%d %d", &d3, &d4);
    ck_assert_int_eq(res1, res2); ck_assert_int_eq(d1, d3); ck_assert_int_eq(d2, d4);

    // test %d 6
    d1 = 0; d2 = 0; d3 = 0; d4 = 0; res1 = 0; res2 = 0;
    res1 = s21_sscanf("-2147483648      -000", "%d %d", &d1, &d2);
    res2 = sscanf("-2147483648      -000", "%d %d", &d3, &d4);
    ck_assert_int_eq(res1, res2); ck_assert_int_eq(d1, d3); ck_assert_int_eq(d2, d4);

    // test %d 7
    d1 = 0; d2 = 0; d3 = 0; d4 = 0; res1 = 0; res2 = 0;
    res1 = s21_sscanf("1 hi", "%d %d", &d1, &d2);
    res2 = sscanf("1 hi", "%d %d", &d3, &d4);
    ck_assert_int_eq(d1, d3);
    ck_assert_int_eq(d2, d4);
    ck_assert_int_eq(res1, res2);

    // short int
    res1 = s21_sscanf("12 +123", "%hd %3hd", &d7, &d9);
    res2 = sscanf("12 +123", "%hd %3hd", &d8, &d10);
    ck_assert_int_eq(d7, d8);
    ck_assert_int_eq(d9, d10);
    ck_assert_int_eq(res1, res2);

    // long int
    res1 = s21_sscanf("123456678 +1231234567", "%ld %8ld", &d11, &d13);
    res2 = sscanf("123456678 +1231234567", "%ld %8ld", &d12, &d14);
    ck_assert_int_eq(d11, d12);
    ck_assert_int_eq(d13, d14);
    ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_test_all) {
    int d1 = 0, d2 = 0, i1 = 0, i2 = 0, n1 = 0, n2 = 0, r1 = 0, r2 = 0;
    float e1 = 0, e2 = 0, E1 = 0, E2 = 0, f1 = 0, f2 = 0, g1 = 0, g2 = 0,
          G1 = 0, G2 = 0;
    unsigned o1 = 0, o2 = 0, u1 = 0, u2 = 0, x1 = 0, x2 = 0, X1 = 0, X2 = 0;
    void *p1 = 0, *p2 = 0;
    char s1[100], s2[100], c1, c2, proc1[100] = {0}, proc2[100] = {0};
    short hi1 = 0, hi2 = 0, hd1 = 0, hd2 = 0;
    unsigned long lo1 = 0, lo2 = 0, lu1 = 0, lu2 = 0;
    long double Le1 = 0, Le2 = 0, LE1 = 0, LE2 = 0, Lg1 = 0, Lg2 = 0, LG1 = 0,
                LG2 = 0;

    r1 = sscanf("123", "%d", &d1);
    r2 = s21_sscanf("123", "%d", &d2);
    ck_assert_int_eq(d1, d2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("123 amogus", "%d%9s", &d1, s1);
    r2 = s21_sscanf("123 amogus", "%d%9s", &d2, s2);
    ck_assert_int_eq(d1, d2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("123 amogus q", "%d%9s%c", &d1, s1, &c1);
    r2 = s21_sscanf("123 amogus q", "%d%9s%c", &d2, s2, &c2);
    ck_assert_int_eq(d1, d2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("4 123 amogus q", "%i%d%9s%c", &i1, &d1, s1, &c1);
    r2 = s21_sscanf("4 123 amogus q", "%i%d%9s%c", &i2, &d2, s2, &c2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(d1, d2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("4 123 amogus q 12e34", "%i%d%9s%c%e", &i1, &d1, s1, &c1, &e1);
    r2 = s21_sscanf("4 123 amogus q 12e34", "%i%d%9s%c%e", &i2, &d2, s2, &c2,
                    &e2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(d1, d2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(c1, c2);
    ck_assert_msg(e1 == e2, "floats not equals");
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("4 123 amogus q 12e34 43e21", "%i%d%9s%c%e%E", &i1, &d1, s1,
                &c1, &e1, &E1);
    r2 = s21_sscanf("4 123 amogus q 12e34 43e21", "%i%d%9s%c%e%E", &i2, &d2, s2,
                    &c2, &e2, &E2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(d1, d2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(c1, c2);
    ck_assert_msg(e1 == e2, "floats not equals");
    ck_assert_msg(E1 == E2, "floats not equals");
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("4 123 amogus q 12e34 43e21 13.37", "%i%d%9s%c%e%E%f", &i1, &d1,
                s1, &c1, &e1, &E1, &f1);
    r2 = s21_sscanf("4 123 amogus q 12e34 43e21 13,37", "%i%d%9s%c%e%E%f", &i2,
                    &d2, s2, &c2, &e2, &E2, &f2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(d1, d2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(c1, c2);
    ck_assert_msg(e1 == e2, "floats not equals");
    ck_assert_msg(E1 == E2, "floats not equals");
    ck_assert_msg(f1 == f2, "floats not equals");
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("4 123 amogus q 12e34 43e21 13.37 2.28", "%i%d%9s%c%e%E%f%g",
                &i1, &d1, s1, &c1, &e1, &E1, &f1, &g1);
    r2 = s21_sscanf("4 123 amogus q 12e34 43e21 13.37 2.28",
                    "%i%d%9s%c%e%E%f%g", &i2, &d2, s2, &c2, &e2, &E2, &f2, &g2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(d1, d2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(c1, c2);
    ck_assert_msg(e1 == e2, "floats not equals");
    ck_assert_msg(E1 == E2, "floats not equals");
    ck_assert_msg(f1 == f2, "floats not equals");
    ck_assert_msg(g1 == g2, "floats not equals");
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228",
                "%i%d%9s%c%e%E%f%g%G", &i1, &d1, s1, &c1, &e1, &E1, &f1, &g1,
                &G1);
    r2 = s21_sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228",
                    "%i%d%9s%c%e%E%f%g%G", &i2, &d2, s2, &c2, &e2, &E2, &f2,
                    &g2, &G2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(d1, d2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(c1, c2);
    ck_assert_msg(e1 == e2, "floats not equals");
    ck_assert_msg(E1 == E2, "floats not equals");
    ck_assert_msg(f1 == f2, "floats not equals");
    ck_assert_msg(g1 == g2, "floats not equals");
    ck_assert_msg(G1 == G2, "floats not equals");
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228",
                "%i%d%9s%c%e%E%f%g%G", &i1, &d1, s1, &c1, &e1, &E1, &f1, &g1,
                &G1);
    r2 = s21_sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228",
                    "%i%d%9s%c%e%E%f%g%G", &i2, &d2, s2, &c2, &e2, &E2, &f2,
                    &g2, &G2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(d1, d2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(c1, c2);
    ck_assert_msg(e1 == e2, "floats not equals");
    ck_assert_msg(E1 == E2, "floats not equals");
    ck_assert_msg(f1 == f2, "floats not equals");
    ck_assert_msg(g1 == g2, "floats not equals");
    ck_assert_msg(G1 == G2, "floats not equals");
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101",
                "%i%d%9s%c%e%E%f%g%G%o", &i1, &d1, s1, &c1, &e1, &E1, &f1, &g1,
                &G1, &o1);
    r2 = s21_sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101",
                    "%i%d%9s%c%e%E%f%g%G%o", &i2, &d2, s2, &c2, &e2, &E2, &f2,
                    &g2, &G2, &o2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(d1, d2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(c1, c2);
    ck_assert_msg(e1 == e2, "floats not equals");
    ck_assert_msg(E1 == E2, "floats not equals");
    ck_assert_msg(f1 == f2, "floats not equals");
    ck_assert_msg(g1 == g2, "floats not equals");
    ck_assert_msg(G1 == G2, "floats not equals");
    ck_assert_int_eq(o1, o2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854",
                "%i%d%9s%c%e%E%f%g%G%o%u", &i1, &d1, s1, &c1, &e1, &E1, &f1,
                &g1, &G1, &o1, &u1);
    r2 = s21_sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854",
                    "%i%d%9s%c%e%E%f%g%G%o%u", &i2, &d2, s2, &c2, &e2, &E2, &f2,
                    &g2, &G2, &o2, &u2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(d1, d2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(c1, c2);
    ck_assert_msg(e1 == e2, "floats not equals");
    ck_assert_msg(E1 == E2, "floats not equals");
    ck_assert_msg(f1 == f2, "floats not equals");
    ck_assert_msg(g1 == g2, "floats not equals");
    ck_assert_msg(G1 == G2, "floats not equals");
    ck_assert_int_eq(o1, o2);
    ck_assert_int_eq(u1, u2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab",
                "%i%d%9s%c%e%E%f%g%G%o%u%x", &i1, &d1, s1, &c1, &e1, &E1, &f1,
                &g1, &G1, &o1, &u1, &x1);
    r2 = s21_sscanf(
        "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab",
        "%i%d%9s%c%e%E%f%g%G%o%u%x", &i2, &d2, s2, &c2, &e2, &E2, &f2, &g2, &G2,
        &o2, &u2, &x2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(d1, d2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(c1, c2);
    ck_assert_msg(e1 == e2, "floats not equals");
    ck_assert_msg(E1 == E2, "floats not equals");
    ck_assert_msg(f1 == f2, "floats not equals");
    ck_assert_msg(g1 == g2, "floats not equals");
    ck_assert_msg(G1 == G2, "floats not equals");
    ck_assert_int_eq(o1, o2);
    ck_assert_int_eq(u1, u2);
    ck_assert_int_eq(x1, x2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf(
        "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21",
        "%i%d%9s%c%e%E%f%g%G%o%u%x%X", &i1, &d1, s1, &c1, &e1, &E1, &f1, &g1,
        &G1, &o1, &u1, &x1, &X1);
    r2 = s21_sscanf(
        "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21",
        "%i%d%9s%c%e%E%f%g%G%o%u%x%X", &i2, &d2, s2, &c2, &e2, &E2, &f2, &g2,
        &G2, &o2, &u2, &x2, &X2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(d1, d2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(c1, c2);
    ck_assert_msg(e1 == e2, "floats not equals");
    ck_assert_msg(E1 == E2, "floats not equals");
    ck_assert_msg(f1 == f2, "floats not equals");
    ck_assert_msg(g1 == g2, "floats not equals");
    ck_assert_msg(G1 == G2, "floats not equals");
    ck_assert_int_eq(o1, o2);
    ck_assert_int_eq(u1, u2);
    ck_assert_int_eq(x1, x2);
    ck_assert_int_eq(X1, X2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf(
        "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21",
        "%i%d%9s%c%e%E%f%g%G%o%u%x%X%p1", &i1, &d1, s1, &c1, &e1, &E1, &f1, &g1,
        &G1, &o1, &u1, &x1, &X1, &p1);
    r2 = s21_sscanf(
        "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21",
        "%i%d%9s%c%e%E%f%g%G%o%u%x%X%p2", &i2, &d2, s2, &c2, &e2, &E2, &f2, &g2,
        &G2, &o2, &u2, &x2, &X2, &p2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(d1, d2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(c1, c2);
    ck_assert_msg(e1 == e2, "floats not equals");
    ck_assert_msg(E1 == E2, "floats not equals");
    ck_assert_msg(f1 == f2, "floats not equals");
    ck_assert_msg(g1 == g2, "floats not equals");
    ck_assert_msg(G1 == G2, "floats not equals");
    ck_assert_int_eq(o1, o2);
    ck_assert_int_eq(u1, u2);
    ck_assert_int_eq(x1, x2);
    ck_assert_int_eq(X1, X2);
    ck_assert_ptr_eq(p1, p2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf(
        "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 "
        "shrek "
        "& amogus is sus?",
        "%i%d%9s%c%e%E%f%g%G%o%u%x%X%p%n%%", &i1, &d1, s1, &c1, &e1, &E1, &f1,
        &g1, &G1, &o1, &u1, &x1, &X1, &p1, &n1);
    r2 = s21_sscanf(
        "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21",
        "%i%d%9s%c%e%E%f%g%G%o%u%x%X%p%n%%", &i2, &d2, s2, &c2, &e2, &E2, &f2,
        &g2, &G2, &o2, &u2, &x2, &X2, &p2, &n2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(d1, d2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(c1, c2);
    ck_assert_msg(e1 == e2, "floats not equals");
    ck_assert_msg(E1 == E2, "floats not equals");
    ck_assert_msg(f1 == f2, "floats not equals");
    ck_assert_msg(g1 == g2, "floats not equals");
    ck_assert_msg(G1 == G2, "floats not equals");
    ck_assert_int_eq(o1, o2);
    ck_assert_int_eq(u1, u2);
    ck_assert_int_eq(x1, x2);
    ck_assert_int_eq(X1, X2);
    ck_assert_ptr_eq(p1, p2);
    ck_assert_int_eq(n1, n2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf(
        "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 "
        "shrek "
        "& amogus is sus?",
        "%i%d%9s%c%e%E%f%g%G%o%u%x%X%p%n%9s%%", &i1, &d1, s1, &c1, &e1, &E1,
        &f1, &g1, &G1, &o1, &u1, &x1, &X1, &p1, &n1, proc1);
    r2 = s21_sscanf(
        "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 "
        "shrek "
        "& amogus is sus?",
        "%i%d%9s%c%e%E%f%g%G%o%u%x%X%p%n%9s%%", &i2, &d2, s2, &c2, &e2, &E2,
        &f2, &g2, &G2, &o2, &u2, &x2, &X2, &p2, &n2, proc2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(d1, d2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(c1, c2);
    ck_assert_msg(e1 == e2, "floats not equals");
    ck_assert_msg(E1 == E2, "floats not equals");
    ck_assert_msg(f1 == f2, "floats not equals");
    ck_assert_msg(g1 == g2, "floats not equals");
    ck_assert_msg(G1 == G2, "floats not equals");
    ck_assert_int_eq(o1, o2);
    ck_assert_int_eq(u1, u2);
    ck_assert_int_eq(x1, x2);
    ck_assert_int_eq(X1, X2);
    ck_assert_ptr_eq(p1, p2);
    ck_assert_int_eq(n1, n2);
    ck_assert_str_eq(proc1, proc2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf(
        "4 123 amogusq 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 "
        "shrek "
        "& amogus is sus?",
        "%*i%12i%4d%20s%c%3e%7E%*i%1f%9g%5G%6o%12u%*x%11x%2X%10p%n%21s%%", &i1,
        &d1, s1, &c1, &e1, &E1, &f1, &g1, &G1, &o1, &u1, &x1, &X1, &p1, &n1,
        proc1);
    r2 = s21_sscanf(
        "4 123 amogusq 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 "
        "shrek "
        "& amogus is sus?",
        "%*i%12i%4d%20s%c%3e%7E%*i%1f%9g%5G%6o%12u%*x%11x%2X%10p%n%21s%%", &i2,
        &d2, s2, &c2, &e2, &E2, &f2, &g2, &G2, &o2, &u2, &x2, &X2, &p2, &n2,
        proc2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(d1, d2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(c1, c2);
    ck_assert_msg(e1 == e2, "floats not equals");
    ck_assert_msg(E1 == E2, "floats not equals");
    ck_assert_msg(f1 == f2, "floats not equals");
    ck_assert_msg(g1 == g2, "floats not equals");
    ck_assert_msg(G1 == G2, "floats not equals");
    ck_assert_int_eq(o1, o2);
    ck_assert_int_eq(u1, u2);
    ck_assert_int_eq(x1, x2);
    ck_assert_int_eq(X1, X2);
    ck_assert_ptr_eq(p1, p2);
    ck_assert_int_eq(n1, n2);
    ck_assert_str_eq(proc1, proc2);
    ck_assert_int_eq(r1, r2);

    r1 = sscanf(
        "4 123 amogusq 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 "
        "shrek "
        "& amogus is sus?",
        "%*i%12hi%4hd%20s%c%3Le%7LE%*i%1f%9Lg%5LG%6lo%12lu%*x%11x%2X%10p%n%21s%"
        "%",
        &hi1, &hd1, s1, &c1, &Le1, &LE1, &f1, &Lg1, &LG1, &lo1, &lu1, &x1, &X1,
        &p1, &n1, proc1);
    r2 = s21_sscanf(
        "4 123 amogusq 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 "
        "shrek "
        "& amogus is sus?",
        "%*i%12hi%4hd%20s%c%3Le%7LE%*i%1f%9Lg%5LG%6lo%12lu%*x%11x%2X%10p%n%21s%"
        "%",
        &hi2, &hd2, s2, &c2, &Le2, &LE2, &f2, &Lg2, &LG2, &lo2, &lu2, &x2, &X2,
        &p2, &n2, proc2);
    ck_assert_int_eq(hi1, hi2);
    ck_assert_int_eq(hd1, hd2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(c1, c2);
    ck_assert_msg(e1 == e2, "floats not equals");
    ck_assert_msg(E1 == E2, "floats not equals");
    ck_assert_msg(f1 == f2, "floats not equals");
    ck_assert_msg(g1 == g2, "floats not equals");
    ck_assert_msg(G1 == G2, "floats not equals");
    ck_assert_int_eq(lo1, lo2);
    ck_assert_int_eq(lu1, lu2);
    ck_assert_int_eq(x1, x2);
    ck_assert_int_eq(X1, X2);
    ck_assert_ptr_eq(p1, p2);
    ck_assert_int_eq(n1, n2);
    ck_assert_str_eq(proc1, proc2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test1) {
    char str1[100];
    char str2[100];

    void *p = 0x0;
    unsigned int n1 = 0, n2 = 0;
    int r1 =
        sprintf(str1, "%p%d%o%s%c%i%e%f%E%g%u%x%G%X%%%n%s", p, 25, 342, "aboba",
                'a', 123, 25.34, 4325.23434, 0.0000000123, 2.12345, 12345u,
                8342, 0.0000456, 1235, &n1, "hello my friend");
    int r2 =
        s21_sprintf(str2, "%p%d%o%s%c%i%e%f%E%g%u%x%G%X%%%n%s", p, 25, 342, "aboba",
                'a', 123, 25.34, 4325.23434, 0.0000000123, 2.12345, 12345u,
                8342, 0.0000456, 1235, &n2, "hello my friend");
//    int r1 =
//        sprintf(str1, "%d%o%s%c%i%e%f%E%g%u%x%G%X%n%p%%%s", 25, 342, "aboba",
//                'a', 123, 25.34, 4325.23434, 0.0000000123, 2.12345, 12345u,
//                8342, 0.0000456, 1235, &n1, p, "hello my friend");
//    int r2 =
//        s21_sprintf(str2, "%d%o%s%c%i%e%f%E%g%u%x%G%X%n%p%%%s", 25, 342,
//                    "aboba", 'a', 123, 25.34, 4325.23434, 0.0000000123, 2.12345,
//                    12345u, 8342, 0.0000456, 1235, &n2, p, "hello my friend");
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(n1, n2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test2) {
    char str1[1000];
    char str2[1000];
    int r1 = sprintf(str1, "%+-25.3d%25.15o%#10.f%015d", 252, 243, 256.34, 15);
    int r2 =
        s21_sprintf(str2, "%+-25.3d%25.15o%#10.f%015d", 252, 243, 256.34, 15);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test3) {
    char str1[100];
    char str2[100];
    int r1 = sprintf(str1, "%#+34.10g%#.10x%#15.1o%25.10s", 25.3456, 1234, 4567,
                     "HELLOMYDEARFRIEND");
    int r2 = s21_sprintf(str2, "%#+34.10g%#.10x%#15.1o%25.10s", 25.3456, 1234,
                         4567, "HELLOMYDEARFRIEND");
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test4) {
    char str1[100];
    char str2[100];
    void *p = (void *)43252342;
    int r1 = sprintf(str1, "%#24.f%-15.20i%20p%020u", 43253242.4342, 4567899, p,
                     43252342u);
    int r2 = s21_sprintf(str2, "%#24.f%-15.20i%20p%020u", 43253242.4342,
                         4567899, p, 43252342u);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
    char str3[50];
    char str4[100];
    int r3 = sprintf(str3, "%*.0f", 25, 25432.34345);
    int r4 = s21_sprintf(str4, "%*.0f", 25, 25432.34345);
    ck_assert_str_eq(str3, str4);
    ck_assert_int_eq(r3, r4);
}
END_TEST

START_TEST(s21_sprintf_test_d) {
    char str1[1000];
    char str2[1000];
    short h = 34;
    int r1 = sprintf(
        str1, "%-25.10d%-30.2d%10.12d%11d%*d%*.*d%+-25.*d%+10.2ld%-11.*hd", 253,
        335, 1234, 34, 10, 25, 5, 15, 345, 5, 666, 456789l, 5, h);
    int r2 = s21_sprintf(
        str2, "%-25.10d%-30.2d%10.12d%11d%*d%*.*d%+-25.*d%+10.2ld%-11.*hd", 253,
        335, 1234, 34, 10, 25, 5, 15, 345, 5, 666, 456789l, 5, h);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_i) {
    char str1[1000];
    char str2[1000];
    short h = 34;
    long l = 2353423523424;
    int r1 =
        sprintf(str1, "%+50.i%-10.20i%10.i%012i%*.*i%-10.*i%+10.1li%*.25hi",
                34567, 225, 5230, 125, 10, 5, 456, 10, 377, l, 12, h);
    int r2 =
        s21_sprintf(str2, "%+50.i%-10.20i%10.i%012i%*.*i%-10.*i%+10.1li%*.25hi",
                    34567, 225, 5230, 125, 10, 5, 456, 10, 377, l, 12, h);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_c) {
    char str1[1000];
    char str2[1000];
    wchar_t c1 = 'T', c2 = 'Z';
    int r1 = sprintf(str1, "%10c%-10c%25c%-30c%25c%*c%2c%*c%lc%-50lc", 'a', 'e',
                     'f', 'R', 'Q', 10, 'P', 'L', 20, 'x', c1, c2);
    int r2 = s21_sprintf(str2, "%10c%-10c%25c%-30c%25c%*c%2c%*c%lc%-50lc", 'a',
                         'e', 'f', 'R', 'Q', 10, 'P', 'L', 20, 'x', c1, c2);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_e) {
    char str1[1000];
    char str2[1000];
//    int r1 =
//        sprintf(str1, "%+-20e%010.*e%-*.16e%#025.10e%*.*e%*.15e%#010.*e%25.16e",
//                2543.43254, 10, 1012.34567, 15, -0.00123, 45678.342532, 10, 15,
//                11111.22, 16, -3245.3425342, 16, -0.00123, 235423424.43252);
//    int r2 = s21_sprintf(
//        str2, "%+-20e%010.*e%-*.16e%#025.10e%*.*e%*.15e%#010.*e%25.16e",
//        2543.43254, 10, 1012.34567, 15, -0.00123, 45678.342532, 10, 15,
//        11111.22, 16, -3245.3425342, 16, -0.00123, 235423424.43252);
    int r1 =
        sprintf(str1, "%+-20e%010.*e%-*.10e%#025.7e%*.*e%*.9e%#010.*e%25.16e",
                2543.43254, 10, 1012.34567, 15, -0.00123, 45678.342532, 10, 15,
                11111.22, 16, -3245.3425342, 10, -0.00123, 235423424.43252);
    int r2 = s21_sprintf(
        str2, "%+-20e%010.*e%-*.10e%#025.7e%*.*e%*.9e%#010.*e%25.16e",
        2543.43254, 10, 1012.34567, 15, -0.00123, 45678.342532, 10, 15,
        11111.22, 16, -3245.3425342, 10, -0.00123, 235423424.43252);    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_E) {
    char str1[1000];
    char str2[1000];
    int r1 = sprintf(str1, "%+-25.4E%25.*E%-*.10E%#02.E%*.*E%*.15E%*E%12.10E",
                     3456.4325, 8, 23452.43242, 5, -0.05234, 25.432523432, 10,
                     2, 53242.4242, 10, 456789.43242, 25, 1111122222.34567899,
                     2345678.23453242);
    int r2 = s21_sprintf(
        str2, "%+-25.4E%25.*E%-*.10E%#02.E%*.*E%*.15E%*E%12.10E", 3456.4325, 8,
        23452.43242, 5, -0.05234, 25.432523432, 10, 2, 53242.4242, 10,
        456789.43242, 25, 1111122222.34567899, 2345678.23453242);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_f) {
    char str1[1000];
    char str2[1000];
    int r1 = sprintf(
        str1,
        "%+-10.3f%+10.2f%15.10f%+*.6f%*.10f%-10.*f%25.*f%25.f%#+10.f%*.*f",
        2546.4324, 3452.4325, 5678.43256, 25, 456789.243242, 10,
        3456789123.43245, 2, 12345.6788, 1, 34.4325432, 4325678.43242,
        34567.2345432, 10, 2, 34567.43244);
    int r2 = s21_sprintf(
        str2,
        "%+-10.3f%+10.2f%15.10f%+*.6f%*.10f%-10.*f%25.*f%25.f%#+10.f%*.*f",
        2546.4324, 3452.4325, 5678.43256, 25, 456789.243242, 10,
        3456789123.43245, 2, 12345.6788, 1, 34.4325432, 4325678.43242,
        34567.2345432, 10, 2, 34567.43244);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_o) {
    char str1[1000];
    char str2[1000];
    unsigned short h = 253;
    unsigned long l = 4325234324242l;
    int r1 =
        sprintf(str1, "%-25.10o%-10o%#-30.2o%#*.10o%#*.*o%25.*o%#.10ho%*lo",
                12345, 6532, 43522, 10, 64342, 15, 2, 343, 6, 678, h, 10, l);
    int r2 = s21_sprintf(
        str2, "%-25.10o%-10o%#-30.2o%#*.10o%#*.*o%25.*o%#.10ho%*lo", 12345,
        6532, 43522, 10, 64342, 15, 2, 343, 6, 678, h, 10, l);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_x) {
    char str1[1000];
    char str2[1000];
    unsigned short h = 345;
    unsigned long l = 52342353242l;
    int r1 =
        sprintf(str1,
                "%x%-25x%#10x%#-10x%#10.5x%-25.34x%#-10.2x%*.*x%#*.10x%20.*"
                "x%#10.*x%*.5hx%10.25lx",
                235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15, 3452, 8,
                23452, 10, 34254, 3, 33334, 10, h, l);
    int r2 =
        s21_sprintf(str2,
                    "%x%-25x%#10x%#-10x%#10.5x%-25.34x%#-10.2x%*.*x%#*.10x%"
                    "20.*x%#10.*x%*.5hx%10.25lx",
                    235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15, 3452,
                    8, 23452, 10, 34254, 3, 33334, 10, h, l);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_X) {
    char str1[1000];
    char str2[1000];
    unsigned short h = 234;
    unsigned long l = 4325243132l;
    int r1 =
        sprintf(str1,
                "%X%-10X%15X%#-15X%#20.3X%-30.12X%#-12.3X%*.*X%#*.15X%21.*X%"
                "#12.*X%*.8hx%14.12lX",
                235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15, 3452, 8,
                23452, 10, 34254, 3, 33334, 10, h, l);
    int r2 = s21_sprintf(str2,
                         "%X%-10X%15X%#-15X%#20.3X%-30.12X%#-12.3X%*.*X%#*.15X%"
                         "21.*X%#12.*X%*.8hx%14.12lX",
                         235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15,
                         3452, 8, 23452, 10, 34254, 3, 33334, 10, h, l);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_u) {
    char str1[1000];
    char str2[1000];
    unsigned short h = 115;
    unsigned long l = 123325242342l;
    int r1 =
        sprintf(str1, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu",
                4321u, 34567u, 2342u, 12346u, 234542u, 10, 234523u, 10, 5,
                2345u, 20, 2432u, l, h);
    int r2 = s21_sprintf(
        str2, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu", 4321u,
        34567u, 2342u, 12346u, 234542u, 10, 234523u, 10, 5, 2345u, 20, 2432u, l,
        h);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_s) {
    char str1[1000];
    char str2[1000];
    wchar_t s[10] = {'h', 'e', 'l', 'l', 'o'};
    int r1 = sprintf(str1, "%s%23s%-15s%10.s%15.2s%16.*s%*.*s%*s%15ls%15.3ls",
                     "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", 10,
                     "QWERTY", 15, 4, "AAAAABOOOOOBAAA", 10, "ABOBAAAAA", s, s);
    int r2 =
        s21_sprintf(str2, "%s%23s%-15s%10.s%15.2s%16.*s%*.*s%*s%15ls%15.3ls",
                    "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", 10,
                    "QWERTY", 15, 4, "AAAAABOOOOOBAAA", 10, "ABOBAAAAA", s, s);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_p) {
    char str1[1000];
    char str2[1000];
    void *p1 = (void *)0x123456789;
    void *p2 = (void *)4325234;
    void *p3 = (void *)0x123f324b;
    void *p4 = (void *)432520;
    int r1 = sprintf(str1, "%p%20p%-15p%10p%-15p%*p%10p%*p", p1, p2, p3, p4, p2,
                     10, p3, p1, 10, p4);
    int r2 = s21_sprintf(str2, "%p%20p%-15p%10p%-15p%*p%10p%*p", p1, p2, p3, p4,
                         p2, 10, p3, p1, 10, p4);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_percent) {
    char str1[1000];
    char str2[1000];
    int r1 = sprintf(str1, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
    int r2 = s21_sprintf(str2, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_g) {
    char str1[1000];
    char str2[1000];
    int r1 = sprintf(
        str1, "%g%23g%-10g%015g%#10.5g%0#15.10g%+10.6g%#*.g%-10.*g%+#25.8g",
        2345.4324, 23445.2342, 1234.234242, 3456.3424, 0.00001234, -324234.234,
        2345.4234, 5, 23456.4324, 9, 234567.43242, 0.0000034);
    int r2 = s21_sprintf(
        str2, "%g%23g%-10g%015g%#10.5g%0#15.10g%+10.6g%#*.g%-10.*g%+#25.8g",
        2345.4324, 23445.2342, 1234.234242, 3456.3424, 0.00001234, -324234.234,
        2345.4234, 5, 23456.4324, 9, 234567.43242, 0.0000034);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_G) {
    char str1[1000];
    char str2[1000];
    int r1 = sprintf(
        str1,
        "%G%25G%#-15G%017G%#05.2G%#010.16G%+#8.6G%*.8G%#-10.*G%+#12.16G%*.*G",
        43242.43242, 123432.43242, 0000.1234, -34252.43242, 1234.5,
        111.432534243243242, 4324.43242, 25, -3213.43242, 16,
        -43.43242353242342, 111.24324242, 25, 5, 0.000000342);
    int r2 = s21_sprintf(
        str2,
        "%G%25G%#-15G%017G%#05.2G%#010.16G%+#8.6G%*.8G%#-10.*G%+#12.16G%*.*G",
        43242.43242, 123432.43242, 0000.1234, -34252.43242, 1234.5,
        111.432534243243242, 4324.43242, 25, -3213.43242, 16,
        -43.43242353242342, 111.24324242, 25, 5, 0.000000342);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

Suite *lib_suite(void) {
    Suite *s;
    s = suite_create("String s21 test cases");

    //  memchr
    TCase *tc_memchr;
    tc_memchr = tcase_create("memchr func");
    suite_add_tcase(s, tc_memchr);
    tcase_add_test(tc_memchr, s21_memchr_f);

    //  memcmp
    TCase *tc_memcmp;
    tc_memcmp = tcase_create("memcmp func");
    suite_add_tcase(s, tc_memcmp);
    tcase_add_test(tc_memcmp, s21_memcmp_f);

    //  memcpy
    TCase *tc_memcpy;
    tc_memcpy = tcase_create("memcpy func");
    suite_add_tcase(s, tc_memcpy);
    tcase_add_test(tc_memcpy, s21_memcpy_f);

    //  memmove
    TCase *tc_memmove;
    tc_memmove = tcase_create("memmove func");
    suite_add_tcase(s, tc_memmove);
    tcase_add_test(tc_memmove, s21_memmove_f);

    //  memset
    TCase *tc_memset;
    tc_memset = tcase_create("memset func");
    suite_add_tcase(s, tc_memset);
    tcase_add_test(tc_memset, s21_memset_f);

    //  strcat
    TCase *tc_strcat;
    tc_strcat = tcase_create("strcat func");
    suite_add_tcase(s, tc_strcat);
    tcase_add_test(tc_strcat, s21_strcat_f);

    //  strncat
    TCase *tc_strncat;
    tc_strncat = tcase_create("strncat func");
    suite_add_tcase(s, tc_strncat);
    tcase_add_test(tc_strncat, s21_strncat_f);

    //  strchr
    TCase *tc_strchr;
    tc_strchr = tcase_create("strchr func");
    suite_add_tcase(s, tc_strchr);
    tcase_add_test(tc_strchr, s21_strchr_f);

    //  strcmp
    TCase *tc_strcmp;
    tc_strcmp = tcase_create("strcmp func");
    suite_add_tcase(s, tc_strcmp);
    tcase_add_test(tc_strcmp, s21_strcmp_f);

    //  strncmp
    TCase *tc_strncmp;
    tc_strncmp = tcase_create("strncmp func");
    suite_add_tcase(s, tc_strncmp);
    tcase_add_test(tc_strncmp, s21_strncmp_f);

    //  strcpy
    TCase *tc_strcpy;
    tc_strcpy = tcase_create("strcpy func");
    suite_add_tcase(s, tc_strcpy);
    tcase_add_test(tc_strcpy, s21_strcpy_f);

    //  strncpy
    TCase *tc_strncpy;
    tc_strncpy = tcase_create("strncpy func");
    suite_add_tcase(s, tc_strncpy);
    tcase_add_test(tc_strncpy, s21_strncpy_f);

    //  strcspn
    TCase *tc_strcspn;
    tc_strcspn = tcase_create("strcspn func");
    suite_add_tcase(s, tc_strcspn);
    tcase_add_test(tc_strcspn, s21_strcspn_f);

    //  strerror
    TCase *tc_strerror;
    tc_strerror = tcase_create("strerror func");
    suite_add_tcase(s, tc_strerror);
    tcase_add_test(tc_strerror, s21_strerror_f);

    //  strlen
    TCase *tc_strlen;
    tc_strlen = tcase_create("strlen func");
    suite_add_tcase(s, tc_strlen);
    tcase_add_test(tc_strlen, s21_strlen_f);

    //  strpbrk
    TCase *tc_strpbrk;
    tc_strpbrk = tcase_create("strpbrk func");
    suite_add_tcase(s, tc_strpbrk);
    tcase_add_test(tc_strpbrk, s21_strpbrk_f);

    //  strrchr
    TCase *tc_strrchr;
    tc_strrchr = tcase_create("strrchr func");
    suite_add_tcase(s, tc_strrchr);
    tcase_add_test(tc_strrchr, s21_strrchr_f);

    //  strspn
    TCase *tc_strspn;
    tc_strspn = tcase_create("strspn func");
    suite_add_tcase(s, tc_strspn);
    tcase_add_test(tc_strspn, s21_strspn_f);

    //  strstr
    TCase *tc_strstr;
    tc_strstr = tcase_create("strstr func");
    suite_add_tcase(s, tc_strstr);
    tcase_add_test(tc_strstr, s21_strstr_f);

    //  strtok
    TCase *tc_strtok;
    tc_strtok = tcase_create("strtok func");
    suite_add_tcase(s, tc_strtok);
    tcase_add_test(tc_strtok, s21_strtok_f);

    //  to_upper
    TCase *tc_to_upper;
    tc_to_upper = tcase_create("to_upper func");
    suite_add_tcase(s, tc_to_upper);
    tcase_add_test(tc_to_upper, s21_to_upper_f);

    //  to_lower
    TCase *tc_to_lower;
    tc_to_lower = tcase_create("to_lower func");
    suite_add_tcase(s, tc_to_lower);
    tcase_add_test(tc_to_lower, s21_to_lower_f);

    //  insert
    TCase *tc_insert;
    tc_insert = tcase_create("insert func");
    suite_add_tcase(s, tc_insert);
    tcase_add_test(tc_insert, s21_insert_f);

    //  trim
    TCase *tc_trim;
    tc_trim = tcase_create("trim func");
    suite_add_tcase(s, tc_trim);
    tcase_add_test(tc_trim, s21_trim_f);

    //
    TCase *tc_chars;
    tc_chars = tcase_create("CHARS check");
    suite_add_tcase(s, tc_chars);
    tcase_add_test(tc_chars, s21_chars_f);

    //
    TCase *tc_nums;
    tc_nums = tcase_create("i d u check");
    suite_add_tcase(s, tc_nums);
    tcase_add_test(tc_nums, s21_nums_f);

    //
    TCase *tc_nums_2;
    tc_nums_2 = tcase_create("li hi check");
    suite_add_tcase(s, tc_nums_2);
    tcase_add_test(tc_nums, s21_nums2_f);

    //
    TCase *tc_nums_3;
    tc_nums_3 = tcase_create("f check");
    suite_add_tcase(s, tc_nums_3);
    tcase_add_test(tc_nums_3, s21_nums3_f);

    //  sscanf
    TCase *tc1_1 = tcase_create("Core");
    suite_add_tcase(s, tc1_1);
    tcase_add_test(tc1_1, sscanf_test_e);
    tcase_add_test(tc1_1, sscanf_test_l);
    tcase_add_test(tc1_1, sscanf_test_L);
    tcase_add_test(tc1_1, sscanf_test_u);
    tcase_add_test(tc1_1, sscanf_test_h);
    tcase_add_test(tc1_1, sscanf_test_s);
    tcase_add_test(tc1_1, sscanf_test_f);
    tcase_add_test(tc1_1, sscanf_test_o);
    tcase_add_test(tc1_1, sscanf_test_x);
    tcase_add_test(tc1_1, sscanf_test_i);
    tcase_add_test(tc1_1, sscanf_test_proc);
    tcase_add_test(tc1_1, sscanf_test_p);
    tcase_add_test(tc1_1, sscanf_test_n);
    tcase_add_test(tc1_1, sscanf_test_d);

    tcase_add_test(tc1_1, sscanf_test_all);
    tcase_add_test(tc1_1, s21_sprintf_test1);
    tcase_add_test(tc1_1, s21_sprintf_test2);
    tcase_add_test(tc1_1, s21_sprintf_test3);
    tcase_add_test(tc1_1, s21_sprintf_test4);
    tcase_add_test(tc1_1, s21_sprintf_test_d);
    tcase_add_test(tc1_1, s21_sprintf_test_i);
    tcase_add_test(tc1_1, s21_sprintf_test_c);
    tcase_add_test(tc1_1, s21_sprintf_test_e);
    tcase_add_test(tc1_1, s21_sprintf_test_E);
    tcase_add_test(tc1_1, s21_sprintf_test_f);
    tcase_add_test(tc1_1, s21_sprintf_test_o);
    tcase_add_test(tc1_1, s21_sprintf_test_x);
    tcase_add_test(tc1_1, s21_sprintf_test_X);
    tcase_add_test(tc1_1, s21_sprintf_test_u);
    tcase_add_test(tc1_1, s21_sprintf_test_s);
    tcase_add_test(tc1_1, s21_sprintf_test_p);
    tcase_add_test(tc1_1, s21_sprintf_test_percent);
    tcase_add_test(tc1_1, s21_sprintf_test_g);
    tcase_add_test(tc1_1, s21_sprintf_test_G);

    return s;
}

int main(void) {
    Suite *s;
    SRunner *sr;

    s = lib_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);

    return 0;
}
