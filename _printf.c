#include "main.h"

/**
 * process_format - Processes the format string and variable arguments.
 * @format: The format string containing the conversion specifiers.
 * @args: The variable argument list.
 * @buf: The buffer used for integer to string conversion.
 *
 * Return: The number of characters printed.
 */
int process_format(const char *format, va_list args, char *buf)
{
	char *str;
	int i = 0, n = 0, count = 0;

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

	return (count);
}

/**
 * _printf - A simplified printf function implementation.
 * @format: The format string containing the conversion specifiers.
 *
 * This function prints the formatted output to the standard output.
 * It supports the following conversion specifiers: %c, %s, %%, %d, and %i.
 *
 * Return: The number of characters printed, or -1 if an error occurs.
 */
int _printf(const char *format, ...)
{
	char *buf = NULL;
	int count = 0;
	va_list args;

	buf = (char *)malloc(BUFF_SIZE);
	if (buf == NULL)
		return (-1);
	va_start(args, format);

	count = process_format(format, args, buf);

	va_end(args);
	free(buf);
	return (count);
}
