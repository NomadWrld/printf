#ifndef PRINTF_H
#define PRINTF_H 

#define BUFF_SIZE 1024

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

char *_strncpy(char *dest, const char *src, size_t n);
int _putchar(char c);
int _puts(char *str);
int _itoa(int n, char *str, int buf_size);
int _printf(const char *format, ...);

#endif /* PRINTF_H */
