#include "main.h"

/**
 * printCharacter - Auxiliar function for _printf.
 *
 * @list: the argument list.
 *
 * Description: Prints only one character and increments
 * the amount of printed characters by 1.
 *
 * Return: 1.
 */

int printCharacter(va_list list)
{
	char c;

	c = va_arg(list, int);
	putchar(c);
	return (1);
}

/**
 * printString - Auxiliar function for _printf.
 *
 * @list: The argument list.
 *
 * Description: Prints a string and increases
 * the size of the printed characters by the size
 * of the printed string.
 *
 * Return: length of the string.
 */

int printString(va_list list)
{
	char *theString = va_arg(list, char*);
	int i;
	int count = 0;

	if (theString == NULL)
	{
		theString = "(null)";
	}
	for (i = 0; theString[i] != '\0'; i++)
	{
		putchar(theString[i]);
		count++;
	}
	return (count);
}

/**
 * printPercentaje - prints a %.
 *
 * @list: list of arguments (unused).
 *
 * Description: prints a %.
 *
 * Return: 1.
 */

int printPercentaje(__attribute__((unused)) va_list list)
{
	putchar('%');
	return (1);
}

/**
 * printNumbers - prints a number.
 *
 * @list: list of arguments.
 *
 * Description: prints a number.
 *
 * Return: 1.
 */

void printMinInt()
{
	char *string = "-2147483648";
	int i;
	for (i = 0; string[i] != '\0'; i++) {
		_putchar(string[i]);
	}
}

int printNumbers(va_list list)
{
	int count = 0, i, digit;
	int number = va_arg(list, int);
	char print_char;
	int num_digits;
	int position;

	if (number == INT_MIN)
	{
		printMinInt();
		return 11;
	}
	if (number < 0)
	{
		putchar('-');
		count++;
		number = -number;
	}
	if (number == 0)
	{
		write(1, "0", 1);
		count++;
	}
	else
	{
		num_digits = 0;
		position = number;
		while (position != 0)
		{
			num_digits++;
			position /= 10;
		}
		while (num_digits > 0)
		{
			int divisor = 1;
			for (i = 1; i < num_digits; i++)
			{
				divisor *= 10;
			}
			digit = number / divisor;
			print_char = digit + '0';
			putchar(print_char);
			count++;
			number %= divisor;
			num_digits--;
		}
 	}
	return (count);
}
