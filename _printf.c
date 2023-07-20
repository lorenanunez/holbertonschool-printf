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
		return (0);
	}
	for (i = 0; i < (int) strlen(format); i++)
	{
		char theChar = format[i];
		
		if (theChar == 37 && format[i + 1] != '\0')
		{
			printByType(&format[i + 1], &length, list);
			i++;
		}
		else
		{
			printCharacter(&theChar, &length);
			length++;
		}
	}
	return (length);
}

/**
 * printByType - Auxiliar function for _printf.
 *
 * @theChar: The character to decide which function
 * to call.
 * @length: The total of printed characters.
 *
 * Description: Decides which function to call in
 * order to print based on the given character.
 *
 * Return: Always void.
*/

void printByType(const char *theChar, int *length, va_list params)
{
	switch (*theChar)
	{
		case 'c':
			printCharacter(params, length);
		break;
		case 's':
			printString(params, length);
		break;
 	/*	case 'd':
			printString(param, length);
		break;
	case 'i':
			printDigit(param, length);
		break; */
		default:
			printCharacter(theChar, length);
		break;
	}
}

/**
 * printCharacter - Auxiliar function for _printf.
 *
 * @theChar: The character to print.
 * @length: The total of printed characters.
 *
 * Description: Prints only one character and increments
 * the amount of printed characters by 1.
 *
 * Return: Always void.
*/

void printCharacter(va_list list, int *lenght)
{
	write(STDOUT_FILENO, va_arg(list, char), 1);
	lenght++;
}

/**
 * printString - Auxiliar function for _printf.
 *
 * @theString: The string to print.
 * @length: The total of printed characters.
 *
 * Description: Prints a string and increases
 * the size of the printed characters by the size
 * of the printed string.
 *
 * Return: Always void.
*/

void printString(va_list list, int *length)
{
	char *theString = va_arg(list, char*);
	size_t stringLenght = strlen(theString);
	
	write(STDOUT_FILENO, theString, stringLenght);
	*length += stringLenght;
}

int main()
{
    int largo = _printf("Nombre es %c %s %s", 'U', "Nunez", "Lorena");
	printf("\nlargo = %d\n", largo);
    return (0);
}


