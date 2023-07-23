#include "main.h"

/**
 * printCharacter - Auxiliar function for _printf.
 *
 * @list: the arument list.
 *
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
theString = "(null)";
for (i = 0; theString[i] != '\0'; i++)
{
putchar(theString[i]);
count++;
}
return (count);
}

