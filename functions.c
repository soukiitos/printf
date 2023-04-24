#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * printf_c - Print characters
 * @args: An argument's variable
 *
 * Return: 0
 */
int printf_c(va_list args)
{
	int i;

	i = (int) va_arg(args, int);
	return (_putchar(char c));
}
/**
 * printf_s - Print Strings
 * @args: An argument variable
 *
 * Return: 0
 */
int printf_s(va_list args)
{
	char *string;
	int i = 0, j = 0;

	va_start(args, i);
	string = (char) va_arg(args, char *);
	for (; string[i] != '\0'; i++)
	{
		_putchar(string[i]);
		j++;
	}
	va_end(args);
	return (j);
}
/**
 * printf_pcent - Print the Percent of a variable
 * @args: An argument's variable
 *
 * Return: 0
 */
int printf_pcent(va_list args)
{
	char *string;

	va_start(args, string);
	while (string)
	{
		if ((int) va_arg(args, int) == *string)
		{
			return (*string);
		}
	}
	va_end(args);
	return (*string);
}
