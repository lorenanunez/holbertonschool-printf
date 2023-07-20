#ifndef __HEADER__
#define __HEADER__

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);
void printCharacter(va_list list, int *lenght);
void printString(va_list list, int *length);
void printDigit(char *theDigit, int *lenght);
void printDecimal(char *theDecimal, int *lenght);
void printEscaped(char *theEscapedCharacter, int *lenght);
void printByType(const char *theChar, int *length, va_list params)

#endif