#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	return (0);
}

#include "main.h"

/**
 * _putchar - Writes a character to the standard output (stdout)
 * @c: The character to be written.
 * Return: The number of characters written.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _puts - Writes a string to the standard output (stdout)
 * @str: The string to be written.
 * Return: The number of characters written.
 */
int _puts(char *str)
{
	if (str == NULL)
		return 0;

	int count = 0;
	char *ptr = str;

	while (*ptr)
	{
		count += _putchar(*ptr);
		ptr++;
	}

	return count;
}

/**
 * _itoa - Converts an integer to a string.
 * @n: The integer to be converted.
 * @str: The buffer to store the resulting string.
 * Return: The length of the string.
 */
int _itoa(int n, char *str)
{
	int i = 0, temp = 0;
	// Buffer size check
	if (n == 0)
		str[i++] = '0';
	else if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}

	temp = n;
	while (temp != 0)
	{
		temp /= 10;
		i++;
	}

	str[i] = '\0';

	// Buffer size check
	while (n != 0)
	{
		str[--i] = '0' + (n % 10);
		n /= 10;
	}

	return i;
}

/**
 * _printf - A simplified printf function.
 * @format: The format string.
 * @...: Additional arguments.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	char buf[11];
	int i = 0, len = 0, n = 0, count = 0;
	va_list args;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += _puts(va_arg(args, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				case 'd':
				case 'i':
					n = va_arg(args, int);
					len = _itoa(n, buf);
					count += _puts(buf + len);
					break;
				default:
					count += _putchar('%');
					count += _putchar(format[i]);
					break;
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return count;
}

#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int _putchar(char c);
int _puts(char *str);
int _itoa(int n, char *str);
int _printf(const char *format, ...);

#endif /* PRINTF_H */

