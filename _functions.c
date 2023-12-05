#include "main.h"

/**
 * print_char - Prints a single character
 * @list: List of arguments
 * Return: Number of characters printed
 */
int print_char(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}

/**
 * print_string - Prints a string
 * @list: List of arguments
 * Return: Number of characters printed
 */
int print_string(va_list list)
{
	int i = 0;
	char *str = va_arg(list, char *);

	if (str == NULL)
		str = "(null)";
	while (str[i])
		_putchar(str[i++]);
	return (i);
}

/**
 * print_percent - Prints a percent symbol
 * @list: List of arguments (void)
 * Return: Number of characters printed
 */
int print_percent(va_list list)
{
	(void)list;
	_putchar('%');
	return (1);
}

/**
 * print_integer - Prints an integer
 * @list: List of arguments
 * Return: Number of characters printed
 */
int print_integer(va_list list)
{
	int num = va_arg(list, int), length = 0, divider = 1;
	unsigned int number;

	if (num < 0)
	{
		length += _putchar('-');
		number = num * -1;
	}
	else
		number = num;
	while (number / divider > 9)
		divider *= 10;
	for (; divider > 0; divider /= 10)
	{
		length += _putchar('0' + (number / divider));
		number %= divider;
	}
	return (length);
}

/**
 * _putchar - Writes a character to stdout
 * @c: The character to write
 * Return: On success, the number of characters written.
 *         On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
