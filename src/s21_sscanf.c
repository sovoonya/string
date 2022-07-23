#include "s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
    char *string = s21_NULL;
    string = (char *)str;
    char *string_format = (char *)format;
    char buffer_string[1024] = "";
    int buffer_length = 0;
    int is_continue = 0;
    int result = 0;

    va_list args;
    va_start(args, format);

    if (str == s21_NULL || format == s21_NULL ||
        (int)s21_strlen(str) == 0 || (int) s21_strlen(format) ==0) {
        is_continue = 1;
        result = -1;
    }

    while (*string_format && is_continue == 0) {
        if (*string_format == '%') {
            int is_ignoring = 0;
            int width = 0;
            char length = '0';

            //  Работа с буфером перед %, 1/2
            if (buffer_length > 0) {
                buffer_string[buffer_length] = '\0';
            }

            string_format++;

            //  Считывание *
            if (*string_format == '*') {
                is_ignoring++;
                string_format++;
            }

            //  Считывание ширины
            if (is_digit(*string_format)) {
                width = *string_format - '0';
                string_format++;
                while (is_digit(*string_format)) {
                    width = *string_format - '0' + width * 10;
                    string_format++;
                }
            }

            //  Считывание длины
            if (is_len(*string_format)) {
                length = *string_format;
                string_format++;
            }

            //  Считывание спецификатора
            if (is_spec(*string_format)) {
                char specifier = *string_format;

                char *new_string_pointer = s21_string_handler(
                    (char *)str, string, buffer_string, buffer_length, args,
                    is_ignoring, width, length, specifier, &is_continue, &result);

                string = new_string_pointer;
                if (specifier != '%' && specifier != 'n' && is_ignoring == 0) {
                    result++;
                }
            }

            //  Работа с буфером перед %, 2/2
            if (buffer_length > 0) {
                buffer_string[0] = '\0';
                buffer_length = 0;
            }
        } else {
            //  Запись в буфер всех значений перед %
            buffer_string[buffer_length] = *string_format;
            buffer_length++;
        }

        string_format++;
    }

    va_end(args);

    return result;
}

char *s21_string_handler(char *str, char *string, char *buffer_string,
                         int buffer_length, va_list args, int is_ignoring,
                         int width, char length, char specifier,
                         int *is_continue, int *result) {
    // Обработка буфера
    s21_size_t strspn_res = s21_strspn(buffer_string, " ");
    int whitespace_length = (int) strspn_res;

    int flag = 0;
    //  Сравнение строки и буфера
    if (whitespace_length != buffer_length) {
        //  Удаление лишних пробелов в начале строки и в начале буфера
        int begin_space_number = (int)s21_strspn(string, " ");
        string += begin_space_number;

        int begin_space_number2 = (int)s21_strspn(buffer_string, " ");
        buffer_string += begin_space_number2;

        // Удаление пробелов в конце буфера
        int end_space_number = (int)s21_trim_strspn_reverse(buffer_string, " ");

        //  Сравнение символов в строке и буфере
        for (int i = 0; i < ((int)s21_strlen(buffer_string) - end_space_number);
             i++) {
            if (buffer_string[i] != string[i]) {
                flag++;
                is_continue += 1;
                *result -= 1;
            }
        }

        if (flag == 0) {
            string += (s21_strlen(buffer_string) - end_space_number);
        }
    } else if (whitespace_length > 0) {
        // Обработка ситуации, если в буфере одни пробелы
        int begin_space_number = (int)s21_strspn(string, " ");
        string += begin_space_number;
    }

    // Обработка спецификатора
    if (flag == 0) {
        switch (specifier) {
            case 'd': {
                char *new_string_pointer = s21_d_handler(string, args, width, length,
                                                         is_ignoring, is_continue, result);
                string = new_string_pointer;

                break;
            }
            case 'i': {
                char *new_string_pointer = s21_i_handler(string, args, width, length,
                                                         is_ignoring, is_continue, result);
                string = new_string_pointer;

                break;
            }
            case 'u': {
                char *new_string_pointer = s21_u_handler(string, args, width, length,
                                                         is_ignoring, is_continue, result);
                string = new_string_pointer;

                break;
            }
            case 'o': {
                char *new_string_pointer = s21_o_handler(string, args, width, length,
                                                         is_ignoring, is_continue, result);
                string = new_string_pointer;

                break;
            }
            case 'p':
            case 'x':
            case 'X': {
                char *new_string_pointer = s21_x_handler(string, args, width, length, specifier,
                                                         is_ignoring, is_continue, result);
                string = new_string_pointer;

                break;
            }
            case 'e':
            case 'E':
            case 'g':
            case 'G':
            case 'f': {
                char *new_string_pointer = s21_f_handler(string, args, width, length, is_ignoring,
                                                         is_continue, result);
                string = new_string_pointer;

                break;
            }
            case 'c': {
                char *new_string_pointer = s21_c_handler(string, args, length, is_ignoring);
                string = new_string_pointer;

                break;
            }
            case 's': {
                char *new_string_pointer = s21_s_handler(string, args, width, length, is_ignoring);
                string = new_string_pointer;

                break;
            }
            case 'n': {
                char *new_string_pointer = s21_n_handler(string, str, buffer_string, args,
                                                         length, is_ignoring);
                string = new_string_pointer;

                break;
            }
            case '%': {
                int begin_space_number = (int)s21_strspn(string, " ");
                string += begin_space_number;

                if (*string == '%') {
                    string++;
                } else {
                    *is_continue += 1;
                }

                break;
            }
        }
    }

    return string;
}

char *s21_string_to_octal(char *string, unsigned long long int *variable,
                          int width, int is_width_cutted) {
    *variable = 0;
    char temp_string[1024] = "\0";
    int temp_counter = 0;

    if (width > 0) {
        while (is_octal_digit(*string) &&
               temp_counter < width - is_width_cutted) {
            temp_string[temp_counter] = *string;
            temp_counter++;
            string++;
        }
    } else {
        while (is_octal_digit(*string)) {
            temp_string[temp_counter] = *string;
            temp_counter++;
            string++;
        }
    }

    for (int i = temp_counter - 1, j = 1; i > -1; i--, j *= 8) {
        unsigned long long int temp_number = temp_string[i] - '0';
        temp_number *= j;
        *variable += temp_number;
    }

    return string;
}

char *s21_string_to_hex(char *string, unsigned long long int *variable,
                        int width, int is_width_cutted) {
    *variable = 0;
    char temp_string[1024] = "\0";
    int temp_counter = 0;

    if (width > 0) {
        while (is_hex_digit(*string) &&
               temp_counter < width - is_width_cutted) {
            temp_string[temp_counter] = *string;
            temp_counter++;
            string++;
        }
    } else {
        while (is_hex_digit(*string)) {
            temp_string[temp_counter] = *string;
            temp_counter++;
            string++;
        }
    }

    for (int i = temp_counter - 1, j = 1; i > -1; i--, j *= 16) {
        unsigned long long int temp_number = temp_string[i] - '0';

        if (temp_number > 9) {
            switch (temp_string[i]) {
                case 'a':
                case 'A': {
                    temp_number = 10;
                    break;
                }
                case 'b':
                case 'B': {
                    temp_number = 11;
                    break;
                }
                case 'c':
                case 'C': {
                    temp_number = 12;
                    break;
                }
                case 'd':
                case 'D': {
                    temp_number = 13;
                    break;
                }
                case 'e':
                case 'E': {
                    temp_number = 14;
                    break;
                }
                case 'f':
                case 'F': {
                    temp_number = 15;
                    break;
                }
            }
        }

        temp_number *= j;
        *variable += temp_number;
    }

    return string;
}

char *s21_string_to_decimal(char *string, unsigned long long int *variable,
                            int width, int is_width_cutted) {
    if (width > 0) {
        int counter = 0;

        if (is_digit(*string) && counter < width - is_width_cutted) {
            *variable = *string - '0';
            string++;
            counter++;
        }

        while (is_digit(*string) && counter < width - is_width_cutted) {
            *variable = *string - '0' + *variable * 10;
            string++;
            counter++;
        }
    } else {
        *variable = *string - '0';
        string++;

        while (is_digit(*string)) {
            *variable = *string - '0' + *variable * 10;
            string++;
        }
    }

    return string;
}

char *s21_d_handler(char *string, va_list args, int width, char length, int is_ignoring,
                    int *is_continue, int *result) {
    // Убираем лишние пробелы в строке
    int begin_space_number = (int)s21_strspn(string, " ");
    string += begin_space_number;

    int is_width_cutted = 0;
    int is_negative = 0;

    // Если символ - '-', то ставим флаг
    if (*string == '-') {
        is_negative++;
        string++;
        is_width_cutted++;
    } else if (*string == '+') {
        string++;
        is_width_cutted++;
    }

    // Если символ - число, то считываем его
    if (is_digit(*string)) {
        unsigned long long int temp_variable;
        unsigned long long int *variable_pointer = &temp_variable;

        char *new_string_pointer = s21_string_to_decimal(string, variable_pointer, width, is_width_cutted);
        string = new_string_pointer;

        if (is_negative == 1) {
            *variable_pointer *= -1;
        }

        if (is_ignoring == 0) {
            write_to_variable(args, variable_pointer, length);
        }
    } else {
        *is_continue = 1;

        if (is_ignoring == 0) {
            *result -= 1;
        }
    }

    return string;
}

char *s21_o_handler(char *string, va_list args, int width, char length, int is_ignoring,
                    int *is_continue, int *result) {
    // Убирем лишние пробелы в строке
    int begin_space_number = (int)s21_strspn(string, " ");
    string += begin_space_number;

    int is_width_cutted = 0;
    int is_negative = 0;

    // Если символ - '-', то ставим флаг
    if (*string == '-') {
        is_negative++;
        string++;
        is_width_cutted++;
    } else if (*string == '+') {
        string++;
        is_width_cutted++;
    }

    // Если символ - восьмеричное число, то считываем его
    if (is_octal_digit(*string)) {
        unsigned long long int temp_variable;
        unsigned long long int *variable_pointer = &temp_variable;

        char *new_string_pointer = s21_string_to_octal(
                string, variable_pointer, width, is_width_cutted);
        string = new_string_pointer;

        if (is_negative == 1) {
            *variable_pointer *= -1;
        }

        if (is_ignoring == 0) {
            write_to_unsigned_variable(args, variable_pointer, length);
        }
    } else {
        *is_continue = 1;

        if (is_ignoring == 0) {
            *result -= 1;
        }
    }

    return string;
}

char *s21_x_handler(char *string, va_list args, int width, char length, char specifier,
                    int is_ignoring, int *is_continue, int *result) {
    // Убирем лишние пробелы в строке
    int begin_space_number = (int)s21_strspn(string, " ");
    string += begin_space_number;

    int is_width_cutted = 0;
    int is_negative = 0;
    int is_start_from_zero = 0;

    // Если символ - '-', то ставим флаг
    if (*string == '-') {
        is_negative++;
        string++;
        is_width_cutted++;
    } else if (*string == '+') {
        string++;
        is_width_cutted++;
    }

    if (*string == '0') {
        string++;
        is_width_cutted++;
        is_start_from_zero++;

        if (*string == 'x' || *string == 'X') {
            string++;
            is_width_cutted++;
        }
    }

    // Если символ - шестнадцатиричное число, то считываем его
    if (is_hex_digit(*string)) {
        unsigned long long int temp_variable;
        unsigned long long int *variable_pointer = &temp_variable;

        char *new_string_pointer = s21_string_to_hex(
                string, variable_pointer, width, is_width_cutted);
        string = new_string_pointer;

        if (is_negative == 1) {
            *variable_pointer *= -1;
        }

        if (is_ignoring == 0) {
            if (specifier == 'p') {
                void **variable = va_arg(args, void **);
                *variable = (void *) (0x0 + *variable_pointer);
            } else {
                write_to_unsigned_variable(args, variable_pointer, length);
            }
        }
    } else if (is_start_from_zero == 1) {
        unsigned long long int temp_variable = 0;
        unsigned long long int *variable_pointer = &temp_variable;

        if (is_ignoring == 0) {
            if (specifier == 'p') {
                void **variable = va_arg(args, void **);
                *variable = (void *) (0x0 + *variable_pointer);
            } else {
                write_to_unsigned_variable(args, variable_pointer, length);
            }
        }
    } else {
        *is_continue = 1;

        if (is_ignoring == 0) {
            *result -= 1;
        }
    }

    return string;
}

char *s21_u_handler(char *string, va_list args, int width, char length, int is_ignoring,
                    int *is_continue, int *result) {
    // Убирем лишние пробелы в строке
    int begin_space_number = (int)s21_strspn(string, " ");
    string += begin_space_number;

    int is_width_cutted = 0;
    int is_negative = 0;

    // Если символ - '-', то ставим флаг
    if (*string == '-') {
        is_negative++;
        string++;
        is_width_cutted++;
    } else if (*string == '+') {
        string++;
        is_width_cutted++;
    }

    // Если символ - число, то считываем его
    if (is_digit(*string)) {
        unsigned long long int temp_variable;
        unsigned long long int *variable_pointer = &temp_variable;

        char *new_string_pointer =
                s21_string_to_decimal(string, variable_pointer, width, is_width_cutted);
        string = new_string_pointer;

        if (is_negative == 1) {
            *variable_pointer *= -1;
        }

        if (is_ignoring == 0) {
            write_to_unsigned_variable(args, variable_pointer, length);
        }
    } else {
        *is_continue = 1;

        if (is_ignoring == 0) {
            *result -= 1;
        }
    }

    return string;
}

char *s21_i_handler(char *string, va_list args, int width, char length, int is_ignoring,
                    int *is_continue, int *result) {
    // Убирем лишние пробелы в строке
    int begin_space_number = (int)s21_strspn(string, " ");
    string += begin_space_number;

    int is_negative = 0;
    int is_width_cutted = 0;

    // Если символ - '-', то ставим флаг
    if (*string == '-') {
        is_negative++;
        string++;
        is_width_cutted++;
    } else if (*string == '+') {
        string++;
        is_width_cutted++;
    }

    if (*string == '0') {
        string++;
        is_width_cutted++;

        if (*string == 'x' || *string == 'X') {
            string++;
            is_width_cutted++;

            if (is_hex_digit(*string)) {
                unsigned long long int temp_variable;
                unsigned long long int *variable_pointer = &temp_variable;

                char *new_string_pointer = s21_string_to_hex(
                        string, variable_pointer, width, is_width_cutted);
                string = new_string_pointer;

                if (is_negative == 1) {
                    *variable_pointer *= -1;
                }

                if (is_ignoring == 0) {
                    write_to_variable(args, variable_pointer, length);
                }
            }
        } else if (is_octal_digit(*string)) {
            unsigned long long int temp_variable;
            unsigned long long int *variable_pointer = &temp_variable;

            char *new_string_pointer = s21_string_to_octal(
                    string, variable_pointer, width, is_width_cutted);
            string = new_string_pointer;

            if (is_negative == 1) {
                *variable_pointer *= -1;
            }

            if (is_ignoring == 0) {
                write_to_variable(args, variable_pointer, length);
            }
        } else {
            // Первый символ 0. Второй символ - не х и не 8 число
            unsigned long long int temp_variable = 0;
            unsigned long long int *variable_pointer = &temp_variable;

            if (is_ignoring == 0) {
                write_to_variable(args, variable_pointer, length);
            }
        }
    } else if (is_digit(*string)) {
        unsigned long long int temp_variable;
        unsigned long long int *variable_pointer = &temp_variable;

        char *new_string_pointer =
                s21_string_to_decimal(string, variable_pointer, width, is_width_cutted);
        string = new_string_pointer;

        if (is_negative == 1) {
            *variable_pointer *= -1;
        }

        if (is_ignoring == 0) {
            write_to_variable(args, variable_pointer, length);
        }
    } else {
        // Первый символ не число и не 0
        *is_continue = 1;

        if (is_ignoring == 0) {
            *result -= 1;
        }
    }

    return string;
}

char *s21_f_handler(char *string, va_list args, int width, char length, int is_ignoring,
                    int *is_continue, int *result) {
    // Убираем лишние пробелы в строке
    int begin_space_number = (int)s21_strspn(string, " ");
    string += begin_space_number;

    int is_negative = 0;
    int is_width_cutted = 0;

    // Если символ - '-', то ставим флаг
    if (*string == '-') {
        is_negative++;
        string++;
        is_width_cutted++;
    }  else if (*string == '+') {
        string++;
        is_width_cutted++;
    }

    // Если символ - число, то считываем его
    long double temp_variable = 0;
    long double *variable_pointer = &temp_variable;
    int width_counter = 0;
    int integer_part_exist = 0;

    if (!(is_digit(*string)) && *string != '.') {
        *is_continue = 1;

        if (is_ignoring == 0) {
            *result -= 1;
        }
    } else {
        if (width > 0) {
            if (is_digit(*string) && width_counter < width - is_width_cutted) {
                *variable_pointer = *string - '0';
                string++;
                width_counter++;
                integer_part_exist++;
            }

            while (is_digit(*string) && width_counter < width - is_width_cutted) {
                *variable_pointer = *string - '0' + *variable_pointer * 10;
                string++;
                width_counter++;
            }
        } else if (is_digit(*string)) {
            *variable_pointer = *string - '0';
            string++;
            integer_part_exist++;

            while (is_digit(*string)) {
                *variable_pointer = *string - '0' + *variable_pointer * 10;
                string++;
            }
        }

        //  Если символ '.', то считываем цифры после '.'
        if (*string == '.' && (width == 0 || width_counter < width - is_width_cutted)) {
            int number_length_counter = 0;
            long double number_after_dot;

            width_counter++;
            string++;

            if (width > 0) {
                if (is_digit(*string) && width_counter < width - is_width_cutted) {
                    number_after_dot = *string - '0';
                    string++;
                    number_length_counter++;
                    width_counter++;

                    while (is_digit(*string) && width_counter < width - is_width_cutted) {
                        number_after_dot =
                                *string - '0' + number_after_dot * 10.0;
                        string++;
                        number_length_counter++;
                        width_counter++;
                    }

                    for (int i = 0; i < number_length_counter; i++) {
                        number_after_dot *= 0.1;
                    }

                    *variable_pointer += number_after_dot;
                } else if (integer_part_exist == 0) {
                    *is_continue = 1;

                    if (is_ignoring == 0) {
                        *result -= 1;
                    }
                }
            } else if (is_digit(*string)) {
                number_after_dot = *string - '0';
                string++;
                number_length_counter++;

                while (is_digit(*string)) {
                    number_after_dot =
                            *string - '0' + number_after_dot * 10.0;
                    string++;
                    number_length_counter++;
                }

                for (int i = 0; i < number_length_counter; i++) {
                    number_after_dot *= 0.1;
                }

                *variable_pointer += number_after_dot;
            } else if (integer_part_exist == 0) {
                *is_continue = 1;

                if (is_ignoring == 0) {
                    *result -= 1;
                }
            }
        }

        if ((*string == 'e' || *string == 'E') &&
            (width == 0 || width_counter < width - is_width_cutted)) {
            width_counter++;
            string++;

            if ((*string == '+' || is_digit(*string)) &&
                (width == 0 || width_counter < width - is_width_cutted)) {
                if (*string == '+') {
                    string++;
                    width_counter++;
                }

                int temp_number;

                if (is_digit(*string) &&
                    (width == 0 || width_counter < width - is_width_cutted)) {
                    temp_number = *string - '0';
                    string++;
                    width_counter++;

                    if (width > 0) {
                        while (is_digit(*string) && width_counter < width - is_width_cutted) {
                            temp_number = *string - '0' + temp_number * 10.0;
                            string++;
                            width_counter++;
                        }
                    } else {
                        while (is_digit(*string)) {
                            temp_number = *string - '0' + temp_number * 10;
                            string++;
                        }
                    }

                    for (int i = 0; i < temp_number; i++) {
                        *variable_pointer *= 10;
                    }
                }
            } else if (*string == '-' && (width == 0 || width_counter < width - is_width_cutted)) {
                string++;
                width_counter++;

                int temp_number;

                if (is_digit(*string) &&
                    (width == 0 || width_counter < width - is_width_cutted)) {
                    temp_number = *string - '0';
                    string++;
                    width_counter++;

                    if (width > 0) {
                        while (is_digit(*string) &&
                               width_counter < width - is_width_cutted) {
                            temp_number =
                                    *string - '0' + temp_number * 10.0;
                            string++;
                            width_counter++;
                        }
                    } else {
                        while (is_digit(*string)) {
                            temp_number =
                                    *string - '0' + temp_number * 10;
                            string++;
                        }
                    }

                    for (int i = 0; i < temp_number; i++) {
                        *variable_pointer *= 0.1;
                    }
                }
            }
        }
    }

    if (is_negative == 1) {
        *variable_pointer *= -1;
    }

    if (is_ignoring == 0) {
        if (length == 'L') {
            long double *variable = va_arg(args, long double *);
            *variable = (long double)*variable_pointer;
        } else if (length == 'l') {
            double *variable = va_arg(args, double *);
            *variable = (double)*variable_pointer;
        } else {
            float *variable = va_arg(args, float *);
            *variable = (float)*variable_pointer;
        }
    }

    return string;
}

char *s21_c_handler(char *string, va_list args, char length, int is_ignoring) {
    if (is_ignoring == 0) {
        if (length == 'l' || length == 'L') {
            wchar_t *variable = va_arg(args, wchar_t *);
            *variable = *string;
        } else {
            char *variable = va_arg(args, char *);
            *variable = *string;
        }
    } else {
        if (length == 'l' || length == 'L') {
            wchar_t temp_variable;
            wchar_t *variable = &temp_variable;
            *variable = *string;
        } else {
            char temp_variable;
            char *variable = &temp_variable;
            *variable = *string;
        }
    }

    string++;

    return string;
}

char *s21_s_handler(char *string, va_list args, int width, char length, int is_ignoring) {
    int begin_space_number = (int)s21_strspn(string, " ");
    string += begin_space_number;

    if (length == 'l' || length == 'L') {
        int i = 0;
        wchar_t temp_variable[1024] = L"";
        wchar_t *variable;

        if (is_ignoring == 0) {
            variable = va_arg(args, wchar_t *);
        } else {
            variable = temp_variable;
        }

        if (width > 0) {
            while (*string != ' ' && *string != '\0' && i < width) {
                variable[i] = *string;
                i++;
                string++;
            }
        } else {
            while (*string != ' ' && *string != '\0') {
                variable[i] = *string;
                i++;
                string++;
            }
        }

        variable[i] = '\0';
    } else {
        int i = 0;
        char temp_variable[1024] = "";
        char *variable;

        if (is_ignoring == 0) {
            variable = va_arg(args, char *);
        } else {
            variable = temp_variable;
        }

        if (width > 0) {
            while (*string != ' ' && *string != '\0' && i < width) {
                variable[i] = *string;
                i++;
                string++;
            }
        } else {
            while (*string != ' ' && *string != '\0') {
                variable[i] = *string;
                i++;
                string++;
            }
        }

        variable[i] = '\0';
    }

    return string;
}

char *s21_n_handler(char *string, char *str, char *buffer_string, va_list args,
                    char length, int is_ignoring) {
    unsigned long long int temp_variable;
    unsigned long long int *variable_pointer = &temp_variable;

    int buffer_length = (int)s21_strlen(buffer_string);
    *variable_pointer = string - str;

    if (*string == ' ' && buffer_string[buffer_length - 1] == ' ') {
        *variable_pointer += 1;
    }

    if (is_ignoring == 0) {
        write_to_variable(args, variable_pointer, length);
    }

    return string;
}

void write_to_variable(va_list args, unsigned long long int *variable_pointer, char length) {
    if (length == 'h') {
        short int *variable = va_arg(args, short int *);
        *variable = (short int)*variable_pointer;
    } else if (length == 'l') {
        long int *variable = va_arg(args, long int *);
        *variable = (long int)*variable_pointer;
    } else {
        int *variable = va_arg(args, int *);
        *variable = (int)*variable_pointer;
    }
}

void write_to_unsigned_variable(va_list args, unsigned long long int *variable_pointer, char length) {
    if (length == 'h') {
        unsigned short int *variable =
        va_arg(args, unsigned short int *);
        *variable = (unsigned short int)*variable_pointer;
    } else if (length == 'l') {
        unsigned long int *variable =
        va_arg(args, unsigned long int *);
        *variable = (unsigned long int)*variable_pointer;
    } else {
        unsigned int *variable = va_arg(args, unsigned int *);
        *variable = (unsigned int)*variable_pointer;
    }
}
