#include "main.h"
/**
 * printf_c - Print characters
 * @args: The arguments
 * @par: The structure's parameters
 *
 * Return: 0
 */
int printf_c(va_list args, par_t *par)
{
	unsigned int pad = 1, som = 0, ch = (int) va_arg(args, int);
	char pad_char = ' ';

	if (par->f_minus)
		som += _putchar(ch);
	while (pad++ < par->width)
		som += _putchar(pad_char);
	if (!par->f_minus)
		som += _putchar(ch);
	return (som);
}
/**
 * printf_int - Print integers
 * @args: The arguments
 * @par: The structure's parameters
 *
 * Return: 0
 */
int printf_int(va_list args, par_t *par)
{
	long l;

	if (par->s_long)
		l = va_arg(args, long);
	else if (par->s_short)
		l = (short int) va_arg(args, int);
	else
		l = (int) va_arg(args, int);
	return (printf_num(convert(l, 10, 0, par), par));
}
/**
 * printf_s - Print strings
 * @args: The arguments
 * @par: The structure's parameters
 *
 * Return: 0
 */
int printf_s(va_list args, par_t *par)
{
	unsigned int pad = 0, som = 0, i = 0, j;
	char *str = va_arg(args, char *), pad_char = ' ';
	(void)par;

	switch ((int)(!str))
	{
		case 1:
			str = NULL_STRING;
	}
	j = pad = _strlen(str);
	if (par->precision < pad)
		j = pad = par->precision;
	if (par->f_minus)
	{
		if (par->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				som += _putchar(*str++);
		else
			som += _puts(str);
	}
	while (j++ < par->width)
		som += _putchar(pad_char);
	if (!par->f_minus)
	{
		if (par->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				som += _putchar(*str++);
		else
			som += _puts(str);
	}
	return (som);
}
/**
 * printf_percent - Print the percent
 * @args: The arguments
 * @par: The structure's parameters
 *
 * Return: 0
 */
int printf_percent(va_list args, par_t *par)
{
	(void)par;
	(void)args;

	return (_putchar('%'));
}
/**
 * printf_S - The specifier of format
 * @args: The arguments
 * @par: The structure's parameters
 *
 * Return: 0
 */
int printf_S(va_list args, par_t *par)
{
	int som = 0;
	char *h;
	char *str = va_arg(args, char *);

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			som += _putchar('\\');
			som += _putchar('x');
			h = convert(*str, 16, 0, par);
			if (!h[1])
				som += _putchar('0');
			som += _puts(h);
		}
		else
		{
			som += _putchar(*str);
		}
	}
	return (som);
}
