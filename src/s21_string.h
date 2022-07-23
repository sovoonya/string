#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#define s21_NULL ((void *)0)

typedef long unsigned s21_size_t;

#ifndef LINUX
#define s21_error_array                                                        \
    {                                                                          \
        "Operation not permitted", "No such file or directory",                \
            "No such process", "Interrupted system call",                      \
            "Input/output error", "Device not configured",                     \
            "Argument list too long", "Exec format error",                     \
            "Bad file descriptor", "No child processes",                       \
            "Resource deadlock avoided", "Cannot allocate memory",             \
            "Permission denied", "Bad address", "Block device required",       \
            "Resource busy", "File exists", "Cross-device link",               \
            "Operation not supported by device", "Not a directory",            \
            "Is a directory", "Invalid argument",                              \
            "Too many open files in system", "Too many open files",            \
            "Inappropriate ioctl for device", "Text file busy",                \
            "File too large", "No space left on device", "Illegal seek",       \
            "Read-only file system", "Too many links", "Broken pipe",          \
            "Numerical argument out of domain", "Result too large",            \
            "Resource temporarily unavailable", "Operation now in progress",   \
            "Operation already in progress", "Socket operation on non-socket", \
            "Destination address required", "Message too long",                \
            "Protocol wrong type for socket", "Protocol not available",        \
            "Protocol not supported", "Socket type not supported",             \
            "Operation not supported", "Protocol family not supported",        \
            "Address family not supported by protocol family",                 \
            "Address already in use", "Can't assign requested address",        \
            "Network is down", "Network is unreachable",                       \
            "Network dropped connection on reset",                             \
            "Software caused connection abort", "Connection reset by peer",    \
            "No buffer space available", "Socket is already connected",        \
            "Socket is not connected", "Can't send after socket shutdown",     \
            "Too many references: can't splice", "Operation timed out",        \
            "Connection refused", "Too many levels of symbolic links",         \
            "File name too long", "Host is down", "No route to host",          \
            "Directory not empty", "Too many processes", "Too many users",     \
            "Disc quota exceeded", "Stale NFS file handle",                    \
            "Too many levels of remote in path", "RPC struct is bad",          \
            "RPC version wrong", "RPC prog. not avail",                        \
            "Program version wrong", "Bad procedure for program",              \
            "No locks available", "Function not implemented",                  \
            "Inappropriate file type or format", "Authentication error",       \
            "Need authenticator", "Device power is off", "Device error",       \
            "Value too large to be stored in data type",                       \
            "Bad executable (or shared library)",                              \
            "Bad CPU type in executable", "Shared library version mismatch",   \
            "Malformed Mach-o file", "Operation canceled",                     \
            "Identifier removed", "No message of desired type",                \
            "Illegal byte sequence", "Attribute not found", "Bad message",     \
            "EMULTIHOP (Reserved)", "No message available on STREAM",          \
            "ENOLINK (Reserved)", "No STREAM resources", "Not a STREAM",       \
            "Protocol error", "STREAM ioctl timeout",                          \
            "Operation not supported on socket", "Policy not found",           \
            "State not recoverable", "Previous owner died",                    \
            "Interface output queue is full"                                   \
    }
#endif

#ifdef LINUX
#define s21_error_array                                                        \
    {                                                                          \
        "Operation not permitted", "No such file or directory",                \
            "No such process", "Interrupted system call",                      \
            "Input/output error", "No such device or address",                 \
            "Argument list too long", "Exec format error",                     \
            "Bad file descriptor", "No child processes",                       \
            "Resource temporarily unavailable", "Cannot allocate memory",      \
            "Permission denied", "Bad address", "Block device required",       \
            "Device or resource busy", "File exists",                          \
            "Invalid cross-device link", "No such device", "Not a directory",  \
            "Is a directory", "Invalid argument",                              \
            "Too many open files in system", "Too many open files",            \
            "Inappropriate ioctl for device", "Text file busy",                \
            "File too large", "No space left on device", "Illegal seek",       \
            "Read-only file system", "Too many links", "Broken pipe",          \
            "Numerical argument out of domain",                                \
            "Numerical result out of range", "Resource deadlock avoided",      \
            "File name too long", "No locks available",                        \
            "Function not implemented", "Directory not empty",                 \
            "Too many levels of symbolic links", "Unknown error 41",           \
            "No message of desired type", "Identifier removed",                \
            "Channel number out of range", "Level 2 not synchronized",         \
            "Level 3 halted", "Level 3 reset", "Link number out of range",     \
            "Protocol driver not attached", "No CSI structure available",      \
            "Level 2 halted", "Invalid exchange",                              \
            "Invalid request descriptor", "Exchange full", "No anode",         \
            "Invalid request code", "Invalid slot", "Unknown error 58",        \
            "Bad font file format", "Device not a stream",                     \
            "No data available", "Timer expired", "Out of streams resources",  \
            "Machine is not on the network", "Package not installed",          \
            "Object is remote", "Link has been severed", "Advertise error",    \
            "Srmount error", "Communication error on send", "Protocol error",  \
            "Multihop attempted", "RFS specific error", "Bad message",         \
            "Value too large for defined data type",                           \
            "Name not unique on network", "File descriptor in bad state",      \
            "Remote address changed",                                          \
            "Can not access a needed shared library",                          \
            "Accessing a corrupted shared library",                            \
            ".lib section in a.out corrupted",                                 \
            "Attempting to link in too many shared libraries",                 \
            "Cannot exec a shared library directly",                           \
            "Invalid or incomplete multibyte or wide character",               \
            "Interrupted system call should be restarted",                     \
            "Streams pipe error", "Too many users",                            \
            "Socket operation on non-socket", "Destination address required",  \
            "Message too long", "Protocol wrong type for socket",              \
            "Protocol not available", "Protocol not supported",                \
            "Socket type not supported", "Operation not supported",            \
            "Protocol family not supported",                                   \
            "Address family not supported by protocol",                        \
            "Address already in use", "Cannot assign requested address",       \
            "Network is down", "Network is unreachable",                       \
            "Network dropped connection on reset",                             \
            "Software caused connection abort", "Connection reset by peer",    \
            "No buffer space available",                                       \
            "Transport endpoint is already connected",                         \
            "Transport endpoint is not connected",                             \
            "Cannot send after transport endpoint shutdown",                   \
            "Too many references: cannot splice", "Connection timed out",      \
            "Connection refused", "Host is down", "No route to host",          \
            "Operation already in progress", "Operation now in progress",      \
            "Stale file handle", "Structure needs cleaning",                   \
            "Not a XENIX named type file", "No XENIX semaphores available",    \
            "Is a named type file", "Remote I/O error", "Disk quota exceeded", \
            "No medium found", "Wrong medium type", "Operation canceled",      \
            "Required key not available", "Key has expired",                   \
            "Key has been revoked", "Key was rejected by service",             \
            "Owner died", "State not recoverable",                             \
            "Operation not possible due to RF-kill",                           \
            "Memory page has hardware error"                                   \
    }
#endif

#define is_flag(ch) ((ch) == '-' || (ch) == '+' || (ch) == ' ' || (ch) == '#' || (ch) == '0')

#define is_len(ch) ((ch) == 'h' || (ch) == 'l' || (ch) == 'L')

#define is_digit(ch) ((ch) >= '0' && (ch) <= '9')

#define is_octal_digit(ch) ((ch) >= '0' && (ch) <= '7')

#define is_hex_digit(ch) (((ch) >= '0' && (ch) <= '9') || \
    (ch) == 'a' || (ch) == 'b' || (ch) == 'c' || (ch) == 'd' || (ch) == 'e' || (ch) == 'f' || \
    (ch) == 'A' || (ch) == 'B' || (ch) == 'C' || (ch) == 'D' || (ch) == 'E' || (ch) == 'F')

#define is_spec(ch) ((ch) == 'c' || \
    (ch) == 'd' || (ch) == 'i' || (ch) == 'f' || (ch) == 's' || (ch) == 'u' || (ch) == '%' || \
    (ch) == 'g' || (ch) == 'G' || (ch) == 'e' || (ch) == 'E' || (ch) == 'x' || (ch) == 'X' || \
    (ch) == 'o' || (ch) == 'n' || (ch) == 'p')

//  #define calloc(x, y) NULL

typedef struct Format {
    int flag_minus;
    int flag_plus;
    int flag_space;
    int flag_sharp;
    int flag_zero;
    int flag_error;
    int width;      //  ширина
    int tolerance;  //  точность
    char len;       //  h, l
    char spec;      // Спецификаторы: c, d, i, f, s, u, %
} FORMAT;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

int s21_sscanf(const char *str, const char *format, ...);
char *s21_string_handler(char *str, char *string, char *buffer_string,
                         int buffer_length, va_list args, int is_ignoring,
                         int width, char length, char specifier,
                         int *is_continue, int *result);
char *s21_string_to_octal(char *string, unsigned long long int *variable,
                          int width, int is_width_cutted);
char *s21_string_to_hex(char *string, unsigned long long int *variable,
                        int width, int is_width_cutted);
char *s21_string_to_decimal(char *string, unsigned long long int *variable,
                            int width, int is_width_cutted);
char *s21_d_handler(char *string, va_list args, int width, char length, int is_ignoring,
                    int *is_continue, int *result);
char *s21_o_handler(char *string, va_list args, int width, char length, int is_ignoring,
                    int *is_continue, int *result);
char *s21_x_handler(char *string, va_list args, int width, char length, char specifier,
                    int is_ignoring, int *is_continue, int *result);
char *s21_u_handler(char *string, va_list args, int width, char length, int is_ignoring,
                    int *is_continue, int *result);
char *s21_i_handler(char *string, va_list args, int width, char length, int is_ignoring,
                    int *is_continue, int *result);
char *s21_f_handler(char *string, va_list args, int width, char length, int is_ignoring,
                    int *is_continue, int *result);
char *s21_n_handler(char *string, char *str, char *buffer_string, va_list args, char length, int is_ignoring);
char *s21_c_handler(char *string, va_list args, char length, int is_ignoring);
char *s21_s_handler(char *string, va_list args, int width, char length, int is_ignoring);
void write_to_variable(va_list args, unsigned long long int *variable_pointer, char length);
void write_to_unsigned_variable(va_list args, unsigned long long int *variable_pointer, char length);

int s21_sprintf(char *str, const char *format, ...);
void s21_set_flag(FORMAT *FFormat, const char *format);
char *s21_format_param_to_str(char *str, s21_size_t *str_len, FORMAT *FFormat,
                              va_list *argList);
char *s21_str_to_int(const char *format, int *number, va_list *argList);
char *s21_reverse_str(char *str);

void s21_str_from_n(s21_size_t const *str_len, va_list *argList);
char *s21_str_from_perc(char *str, FORMAT *FFormat);
char *s21_str_from_p(char *str, va_list *argList, FORMAT *FFormat);
char *s21_str_from_f(char *str, va_list *argList, FORMAT *FFormat);
char *s21_str_from_eE(char *str, va_list *argList, FORMAT *FFormat);
char *s21_str_from_gG(char *str, va_list *argList, FORMAT *FFormat);
char *s21_str_from_s(char *str, va_list *argList, FORMAT *FFormat);
char *s21_str_from_c(char *str, va_list *argList, FORMAT *FFormat);
char *s21_str_from_u(char *str, va_list *argList, FORMAT *FFormat);
char *s21_str_from_d(char *str, va_list *argList, FORMAT *FFormat);
char *s21_str_from_o(char *str, va_list *argList, FORMAT *FFormat);
char *s21_str_from_xX(char *str, va_list *argList, FORMAT *FFormat);
char *s21_lf_to_str(char *str, long double number, FORMAT *FFormat);
char *s21_leE_to_str(char *str, long double number, FORMAT *FFormat);
char *s21_lgG_to_str(char *str, long double number, FORMAT *FFormat);

char *wch_to_str(char *str, wchar_t *wstr, s21_size_t len);
char *s21_lf_width_flag(char *str, FORMAT *FFormat);
char *s21_ll_width_flag(char *str, FORMAT *FFormat);
char *s21_sign_flag(char *str, FORMAT *FFormat);
char *s21_ll_tolerance(char *str, FORMAT *FFormat);
char *s21_ll_to_str(char *str, long long number);
char *s21_ul_to_str(char *str, unsigned long long number);
char *s21_ol_to_str(char *str, unsigned long long number, int prefix);
char *s21_hl_to_str(char *str, unsigned long long number, FORMAT *FFormat);
char *s21_ld_to_a(char *str, long double number, FORMAT *FFormat);
char *d_class_to_str(char *str, long double x, int tolerance);
long double s21_round(long double x, int tolerance);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
s21_size_t s21_trim_strspn_reverse(const char *str1, const char *str2);

#endif  //  SRC_S21_STRING_H_
