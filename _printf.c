#include "main.h"

/**
 * _printf - Custom implementation of printf function
 * @format: The format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int count;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	count = parse_format(format, args);
	va_end(args);
	return (count);
}

/**
 * process_format - Processes the format specifier and prints accordingly
 * @format: The format string
 * @i: The current index in the format string
 * @args: List of variadic arguments
 * @formats: Array of format specifiers and corresponding functions
 *
 * Return: Number of characters printed
 */
int process_format(const char *format, int i, va_list args, format_t *formats)
{
	int j, char_count = 0;

	for (j = 0; formats[j].symbol; j++)
	{
		if (format[i] == *formats[j].symbol)
		{
			char_count = formats[j].func(args);
			break;
		}
	}

	if (formats[j].symbol == NULL)
	{
		_putchar('%');
		_putchar(format[i]);
		char_count += 2;
	}

	return (char_count);
}

/**
 * parse_format - Processes the format string and the list
 *                of arguments to print a formatted string accordingly.
 * @format: The format string
 * @args: List of variadic arguments
 *
 * Return: Number of characters printed
 */
int parse_format(const char *format, va_list args)
{
	format_t formats[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{NULL, NULL}
	};

	int i = 0, char_count = 0, printed_chars = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);

			char_count = process_format(format, i, args, formats);

			if (char_count == -1)
				return (-1);
			printed_chars += char_count;
		}
		else
		{
			_putchar(format[i]);
			printed_chars++;
		}
		i++;
	}
	return (printed_chars);
}
