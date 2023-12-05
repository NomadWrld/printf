#include "main.h"

/**
 * _itoa - Converts an integer to a string.
 * @n: The integer to be converted.
 * @str: The buffer to store the resulting string.
 * Return: The length of the string.
 */
int _itoa(int n, char *str)
{
	int i = 0, temp = 0;
	int is_negative = 0;
	int j;

	if (n == 0)
	{
		str[i++] = '0';
	}
	else if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}

	temp = n;
	while (temp != 0)
	{
		str[i++] = '0' + (temp % 10);
		temp /= 10;
	}

	if (is_negative)
		str[i++] = '-';

	for (j = 0; j < i / 2; j++)
	{
		char temp_char = str[j];

		str[j] = str[i - j - 1];
		str[i - j - 1] = temp_char;
	}

	str[i] = '\0';

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
 * _printf - A simplified printf function.
 * @format: The format string.
 * @...: Additional arguments.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	char *str, buf[11];
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
					_itoa(n, buf);
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
