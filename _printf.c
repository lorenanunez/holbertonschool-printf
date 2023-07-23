#include "main.h"

/**
 * _printf - Formats and prints a formatted string.
 *
 * @format: A string including the patterns.
 * @...: A set of values to include in the formatted
 * string.
 *
 * Description: Recieves a string with format patterns
 * and a set of values, and then prints the formatted
 * string replacing the patterns with the values.
 *
 * Return: The length of the printed string.
 */

int _printf(const char *format, ...)
{
	int i, length = 0;
	va_list list;

	va_start(list, format);
	if (format == NULL)
	{
		va_end(list);
		return (-1);
	}
	for (i = 0; i < (int) strlen(format); i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
			{
				length += printByType(format[i + 1], list);
			}
			else
			{
				return (-1);
			}
			i++;
		}
		else
		{
			putchar(format[i]);
			length++;
		}
	}
	va_end(list);
	return (length);
}

/**
 * printByType - this function check for the type of format to be printed.
 *
 * @theChar: a char that should match with one of the keys.
 * @params: the argument list.
 *
 * Description: Recieves a char and a argument list then initialize
 * a struct with the keys to match with the recived char and their functions,
 * if there is a match between the key and theChar, the respective
 * function is called passing the list of arguments params as a parameter.
 * If there is not a match, print a % and the theChar.
 *
 * Return: The length of the printed string.
 */

int printByType(char theChar, va_list params)
{
	int position = 0;
	print_filter keys[] = {
		{"c", printCharacter},
		{"s", printString},
		{"i", printNumbers},
		{"d", printNumbers},
		{"%", printPercentaje},
		{NULL, NULL}
	};
	while (keys[position].type)
	{
		if (*(keys[position].type) == theChar)
		{
			return (keys[position].function(params));
		}
		position++;
	}
	if (keys[position].type == NULL)
	{
		write(1, "%", 1);
		write(1, &theChar, 1);
		return (2);
	}
	return (0);
}
