#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int _putchar(char c);
int _puts(char *str);
int _itoa(int n, char *str);
int _printf(const char *format, ...);

#endif /* PRINTF_H */
