#include "main.h"
/**
 * printf_fto - Print the addresses of characters
 * @start: The start
 * @stop: The stop
 * @beside: the except
 *
 * Return: 0
 */
int printf_fto(char *start, char *stop, char *beside)
{
	int i = 0;

	while (start <= stop)
	{
		if (start != beside)
			i += _putchar(*start);
		start++;
	}
	return (i);
}
/**
 * printf_rev - The reverse of strings
 * @args: The arguments
 * @par: The structure's parameters
 *
 * Return: 0;
 */
int printf_rev(va_list args, par_t *par)
{
	int len, i = 0;
	char *string = va_arg(args, char *);
	(void)par;

	if (string)
	{
		for (len = 0; *string; string++)
			len++;
		string--;
		for (; len > 0; len--, string--)
			i += _putchar(*string);
	}
	return (i);
}
/**
 * printf_rot13 - Print rot13
 * @args: The arguments
 * @par: The strusture's parameters
 *
 * Return: 0
 */
int printf_rot13(va_list args, par_t *par)
{
	int i, j, count = 0;
	char array[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(args, char *);
	(void)par;

	i = 0;
	j = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
				|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			j = a[i] - 65;
			count += _putchar(array[j]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
