#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
    void *res = s21_NULL;
    const unsigned char *p = str;

    for (s21_size_t i = 0; i < n && (unsigned char *)res == s21_NULL; i++) {
        if (p[i] == c) {
            res = (void *)(p + i);
        }
    }

    return res;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    const unsigned char *p1 = str1;
    const unsigned char *p2 = str2;

    int res = 0;

    for (s21_size_t i = 0; i < n && res == 0; i++) {
        if (p1[i] != p2[i]) {
            res = p1[i] - p2[i];
        }
    }

    return res;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    unsigned char *p1 = dest;
    const unsigned char *p2 = src;

    for (s21_size_t i = 0; i < n; i++) {
        p1[i] = p2[i];
    }

    return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    unsigned char *p1 = dest;
    const unsigned char *p2 = src;
    unsigned char temp[n];

    for (s21_size_t i = 0; i < n; i++) {
        temp[i] = p2[i];
    }

    for (s21_size_t i = 0; i < n; i++) {
        p1[i] = temp[i];
    }

    return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
    unsigned char *p = str;

    for (s21_size_t i = 0; i < n; i++) {
        p[i] = c;
    }

    return str;
}

char *s21_strcat(char *dest, const char *src) {
    s21_size_t destlen = s21_strlen(dest);
    s21_size_t srclen = s21_strlen(src);
    s21_size_t i = 0;

    for (; i < srclen; i++) {
        dest[destlen + i] = src[i];
    }

    dest[destlen + i] = '\0';

    return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    s21_size_t destlen = s21_strlen(dest);
    s21_size_t srclen = s21_strlen(src);
    s21_size_t i = 0;
    int flag = 0;

    while (i < n && flag == 0) {
        if (i < srclen) {
            dest[destlen + i] = src[i];
            i++;
        } else {
            flag = 1;
        }
    }

    dest[destlen + i] = '\0';

    return dest;
}

char *s21_strchr(const char *str, int c) {
    s21_size_t strlen = s21_strlen(str);
    char *res = s21_NULL;

    for (s21_size_t i = 0; i < strlen && res == s21_NULL; i++) {
        if (str[i] == c) {
            res = (char *)&str[i];
        }
    }

    return res;
}

int s21_strcmp(const char *str1, const char *str2) {
    s21_size_t strlen1 = s21_strlen(str1);
    s21_size_t strlen2 = s21_strlen(str2);
    s21_size_t max_length = strlen1 > strlen2 ? strlen1 : strlen2;
    int res = 0;

    for (size_t i = 0; i < max_length && res == 0; i++) {
        if (str1[i] != str2[i]) {
            res = str1[i] - str2[i];
        }
    }

    return res;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    int res = 0;

    for (s21_size_t i = 0; i < n && res == 0; i++) {
        if (str1[i] != str2[i]) {
            res = str1[i] - str2[i];
        }
    }

    return res;
}

char *s21_strcpy(char *dest, const char *src) {
    s21_size_t srclen = s21_strlen(src);

    for (s21_size_t i = 0; i < srclen + 1; i++) {
        dest[i] = src[i];
    }

    return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    s21_size_t srclen = s21_strlen(src);

    for (s21_size_t i = 0; i < n; i++) {
        if (i > srclen - 1) {
            dest[i] = '\0';
        } else {
            dest[i] = src[i];
        }
    }

    return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t str1len = s21_strlen(str1);
    s21_size_t str2len = s21_strlen(str2);
    int is_continue = 0;
    s21_size_t res = 0;

    for (s21_size_t i = 0; i < str1len && is_continue == 0; i++) {
        int inner_res = 0;

        for (s21_size_t j = 0; j < str2len && inner_res == 0; j++) {
            if (str1[i] == str2[j]) {
                inner_res++;
            }
        }

        if (inner_res != 0) {
            is_continue++;
            res--;
        }

        res++;
    }

    return res;
}

char *s21_strerror(int errnum) {
    static char error_message[200];
    char *error_array[] = s21_error_array;
    s21_strcpy(error_message, error_array[errnum - 1]);
    return error_message;
}

s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    for (; str[len]; len++) continue;

    return len;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    s21_size_t str1len = s21_strlen(str1);
    s21_size_t str2len = s21_strlen(str2);
    char *res = s21_NULL;

    for (s21_size_t i = 0; i < str1len && res == s21_NULL; i++) {
        for (s21_size_t j = 0; j < str2len && res == s21_NULL; j++) {
            if (str1[i] == str2[j]) {
                res = (char *)&str1[i];
            }
        }
    }

    return res;
}

char *s21_strrchr(const char *str, int c) {
    s21_size_t strlen = s21_strlen(str);
    char *res = s21_NULL;

    for (s21_size_t i = 0; i < strlen + 1; i++) {
        if (str[i] == c) {
            res = (char *)&str[i];
        }
    }

    return res;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t str1len = s21_strlen(str1);
    s21_size_t str2len = s21_strlen(str2);
    int is_continue = 0;
    s21_size_t res = 0;

    for (s21_size_t i = 0; i < str1len && is_continue == 0; i++) {
        int inner_res = 0;

        for (s21_size_t j = 0; j < str2len && inner_res == 0; j++) {
            if (str1[i] == str2[j]) {
                inner_res++;
            }
        }

        if (inner_res == 0) {
            is_continue++;
            res--;
        }

        res++;
    }

    return res;
}

char *s21_strstr(const char *haystack, const char *needle) {
    s21_size_t haystack_length = s21_strlen(haystack);
    s21_size_t needle_length = s21_strlen(needle);
    char *result = s21_NULL;

    if (needle_length == 0) {
        result = (char *)haystack;
    }

    for (s21_size_t i = 0; i < haystack_length; i++) {
        if (haystack[i] == needle[0]) {
            int counter = 0;
            s21_size_t j = i;
            s21_size_t k = 0;

            while (k < needle_length && counter == 0) {
                if (!haystack[j]) {
                    counter = 1;
                }

                if (haystack[j] == needle[k] && counter == 0) {
                    j++;
                    k++;
                } else {
                    counter = 1;
                }
            }

            if (counter == 0) {
                result = (char *)&haystack[i];
            }
        }
    }

    return result;
}

char *s21_strtok(char *str, const char *delim) {
    static char *last = s21_NULL;
    char *begin_part = s21_NULL;
    char *next_part = s21_NULL;

    if (str != s21_NULL) {
        s21_size_t strlen = s21_strlen(str);
        s21_size_t non_delims_num = s21_strspn(str, delim);

        if (non_delims_num != 0) {
            if (non_delims_num == strlen) {
                begin_part = s21_NULL;
            } else {
                begin_part = &str[non_delims_num];
            }
        } else {
            if (non_delims_num == strlen) {
                begin_part = s21_NULL;
            } else {
                begin_part = str;
            }
        }

        if (begin_part != s21_NULL) {
            char *first_entry = s21_strpbrk(begin_part, delim);

            if (first_entry == s21_NULL) {
                last = s21_NULL;
            } else {
                *first_entry = '\0';

                if (*(first_entry + 1) != '\0') {
                    last = (first_entry + 1);
                }
            }
        }
    } else {
        if (last == s21_NULL) {
            next_part = s21_NULL;
        } else {
            s21_size_t strlen = s21_strlen(last);
            s21_size_t non_delims_num = s21_strspn(last, delim);

            if (non_delims_num != 0) {
                if (non_delims_num == strlen) {
                    next_part = s21_NULL;
                } else {
                    next_part = (last + non_delims_num);
                }
            } else {
                next_part = last;
            }

            if (next_part != s21_NULL) {
                char *next_entry = s21_strpbrk(next_part, delim);

                if (next_entry == s21_NULL) {
                    last = s21_NULL;
                } else {
                    *next_entry = '\0';

                    if (*(next_entry + 1) != '\0') {
                        last = (next_entry + 1);
                    } else {
                        last = s21_NULL;
                    }
                }
            }
        }
    }

    return str != s21_NULL ? begin_part : next_part;
}

void *s21_to_upper(const char *str) {
    char *dst = s21_NULL;
    s21_size_t lenght = s21_strlen(str) + 1;
    dst = calloc((s21_strlen(str) + 1), sizeof(char));

    if (dst != s21_NULL) {
        s21_strcpy(dst, str);
        for (s21_size_t i = 0; i < lenght; i++) {
            if (dst[i] >= 97 && dst[i] <= 122) {
                dst[i] = (char) (dst[i] - 32);
            }
        }
    }

    return (void *)dst;
}

void *s21_to_lower(const char *str) {
    char *dst = s21_NULL;
    s21_size_t lenght = s21_strlen(str) + 1;
    dst = calloc((s21_strlen(str) + 1), sizeof(char));

    if (dst != s21_NULL) {
        s21_strcpy(dst, str);
        for (s21_size_t i = 0; i < lenght; i++) {
            if (dst[i] >= 65 && dst[i] <= 90) {
                dst[i] = (char) (dst[i] + 32);
            }
        }
    }

    return (void *)dst;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *pointer = s21_NULL;

    if (src != s21_NULL && str != s21_NULL) {
        s21_size_t src_length = s21_strlen(src);
        s21_size_t str_length = s21_strlen(str);
        s21_size_t memory_size = src_length + str_length + 1;

        if (start_index <= src_length) {
            pointer = calloc(memory_size, sizeof(char));

            if (pointer != s21_NULL) {
                for (s21_size_t i = 0; i < start_index; i++) {
                    pointer[i] = src[i];
                }

                for (s21_size_t i = 0; i < str_length; i++) {
                    pointer[i + start_index] = str[i];
                }

                for (s21_size_t i = 0; i < src_length - start_index; i++) {
                    pointer[i + start_index + str_length] =
                        src[i + start_index];
                }

                pointer[memory_size - 1] = '\0';
            }
        }
    }

    return pointer;
}

void *s21_trim(const char *src, const char *trim_char) {
    char *pointer = s21_NULL;

    if (src != s21_NULL) {
        s21_size_t length = s21_strlen(src);

        if (trim_char == s21_NULL) {
            trim_char = " ";
        }

        s21_size_t begin_trim_num = s21_strspn(src, trim_char);
        s21_size_t end_trim_num = s21_trim_strspn_reverse(src, trim_char);

        if (length != begin_trim_num) {
            pointer = calloc(length - begin_trim_num - end_trim_num + 1, sizeof(char));
        } else {
            pointer = calloc(1, sizeof(char));
        }

        if (pointer != s21_NULL) {
            if (length != begin_trim_num) {
                for (s21_size_t i = 0;
                     i < length - begin_trim_num - end_trim_num; i++) {
                    pointer[i] = src[i + begin_trim_num];
                }

                pointer[length - begin_trim_num - end_trim_num] = '\0';
            } else {
                pointer[0] = '\0';
            }
        }
    }

    return pointer;
}

s21_size_t s21_trim_strspn_reverse(const char *str1, const char *str2) {
    s21_size_t str1len = s21_strlen(str1);
    s21_size_t str2len = s21_strlen(str2);
    int is_continue = 0;
    int res = 0;

    for (int i = (int) str1len - 1; i > -1 && is_continue == 0; i--) {
        int inner_res = 0;

        for (s21_size_t j = 0; j < str2len && inner_res == 0; j++) {
            if (str1[i] == str2[j]) {
                inner_res++;
            }
        }

        if (inner_res == 0) {
            is_continue++;
            res--;
        }

        res++;
    }

    return res;
}
