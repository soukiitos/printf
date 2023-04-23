#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * struct format - The stucture format for printf
 * @ch: A character
 * @f: A function for the struct format
 *
 */
typedef struct format
{
	char *ch;
	int (*f)(va_list);
} form;
int _putchar(char c);
int _printf(const char *format, ...);
int printf_c(va_list args);
int printf_s(va_list args);
int printf_pcent(va_list args);
int printf_d(va_list args);
int printf_i(va_list args);
int (*get(char c)(va_list args));
#endif
