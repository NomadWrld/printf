#include "main.h"

/**
 * _putchar - Writes a character to the standard output (stdout)
 * @c: The character to be written.
 * Return: The number of characters written.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Writes a string to the standard output (stdout)
 * @str: The string to be written.
 * Return: The number of characters written.
 */
int _puts(char *str)
{
	int count = 0;
	char *ptr = str;

	while (ptr && *ptr)
	{
		count += _putchar(*ptr);
		ptr++;
	}

	return (count);
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

	while (n != 0)
	{
		str[--i] = '0' + (n % 10);
		n /= 10;
	}

	return (i);
}

/**
 * _printf - A simplified printf function.
 * @format: The format string.
 * @...: Additional arguments.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	char *str, buf[11];
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
					str = va_arg(args, char *);
					count += _puts(str);
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
	return (count);
}