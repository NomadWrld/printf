#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * _itoa - Converts an integer to a string.
 * @n: The integer to be converted.
 * @str: The buffer to store the resulting string.
 * @buf_size: The size of the buffer.
 * Return: The length of the string.
 */
int _itoa(int n, char *str, int buf_size)
{
	int i = 0, temp = 0, is_neg = 0, j = 0;
	char *buffer = NULL;

	if (buf_size <= 0)
		return (0);
	buffer = (char *)malloc(buf_size);
	if (buffer == NULL)
		return (0);

	if (n == 0)
		buffer[i++] = '0';
	else if (n < 0)
	{
		is_neg = 1;
		n = -n;
	}
	temp = n;
	while (temp != 0)
	{
		buffer[i++] = '0' + (temp % 10);
		temp /= 10;

		if (i >= buf_size - 1)
			break;
	}
	if (is_neg)
		buffer[i++] = '-';

	for (j = 0; j < i / 2; j++)
	{
		char temp_char = buffer[j];

		buffer[j] = buffer[i - j - 1];
		buffer[i - j - 1] = temp_char;
	}
	buffer[i] = '\0';
	strncpy(str, buffer, buf_size);
	free(buffer);

	return (i);
}
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
 * _strncpy - Copies at most n characters from src to dest.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of characters to copy.
 * Return: A pointer to the destination string.
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return dest;
}

/**
 * _printf - A simplified printf function.
 * @format: The format string.
 * @...: Additional arguments.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	char *str, buf[1024];
	int i = 0, n = 0, count = 0;
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
					count += _itoa(n, buf, sizeof(buf));
					count += _puts(buf);
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

