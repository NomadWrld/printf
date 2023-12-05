#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

typedef int (*print_func)(va_list);

/**
 * struct format - Struct for format specifiers and
 *                 their corresponding functions
 * @symbol: The format specifier
 * @func: The function to handle the format specifier
 */
typedef struct format
{
	char *symbol;
	print_func func;
} format_t;

int _printf(const char *format, ...);
int _putchar(char c);
int parse_format(const char *format, va_list args);
int print_char(va_list list);
int print_string(va_list list);
int print_percent(va_list list);
int print_integer(va_list list);

#endif /* MAIN_H */
