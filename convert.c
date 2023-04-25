#include "main.h"
/**
 * printf_x - Print unsigned hexadecimal numbers
 * @args: The arguments
 * @par: The structure's parameters
 *
 * Return: 0
 */
int printf_x(va_list args, par_t *par)
{
	char *str;
	int c = 0;
	unsigned long l;

	if (par->s_long)
		l = (unsigned long) va_arg(args, unsigned long);
	else if (par->s_short)
		l = (unsigned short int) va_arg(args, unsigned int);
	else
		l = (unsigned int) va_arg(args, unsigned int);
	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, par);
	if (par->f_hash && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	par->f_unsign = 1;
	return (c += printf_num(str, par));
}
/**
 * printf_X - Print unsigned HEXADECIMAL numbers
 * @args: The arguments
 * @par: The structure's parameters
 *
 * Return: 0
 */
int printf_X(va_list args, par_t *par)
{
	int c = 0;
	char *str;
	unsigned long l;

	if (par->s_long)
		l = (unsigned long) va_arg(args, unsigned long);
	else if (par->s_short)
		l = (unsigned short int) va_arg(args, unsigned int);
	else
		l = (unsigned int) va_arg(args, unsigned int);
	str = convert(l, 16, CONVERT_UNSIGNED, par);
	if (par->f_hash && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	par->f_unsign = 1;
	return (c += printf_num(str, par));
}
/**
 * printf_binary - Print unsigned binary
 * @args: The arguments
 * @par: The sttructure's parameters
 *
 * Return: 0
 */
int printf_binary(va_list args, par_t *par)
{
	int c = 0;
	unsigned int n = va_arg(args, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, par);

	if (par->f_hash && n)
		*--str = '0';
	par->f_unsign = 1;
	return (c += printf_num(str, par));
}
/**
 * printf_o - Print unsigned octal
 * @args: The arguments
 * @par: The structure's parameters
 *
 * Return: 0
 */
int printf_o(va_list args, par_t *par)
{
	int c = 0;
	char *str;
	unsigned long l;

	if (par->s_long)
		l = (unsigned long) va_arg(args, unsigned long);
	else if (par->s_short)
		l = (unsigned short int) va_arg(args, unsigned int);
	else
		l = (unsigned int) va_arg(args, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, par);
	if (par->f_hash && l)
		*--str = '0';
	par->f_unsign = 1;
	return (c += printf_num(str, par));
}
