#ifndef __HEADER__
#define __HEADER__

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <climits>

typedef struct print
{
char *type;
int (*function)(va_list types);
} print_filter;

int _putchar(char c);
void printMinInt(void);
int _printf(const char *format, ...);
int printCharacter(va_list list);
int printPercentaje(va_list list);
int printString(va_list list);
int printNumbers(va_list list);
int printByType(char theChar, va_list params);

#endif
