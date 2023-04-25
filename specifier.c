#include "main.h"
/**
 * get_printf_spec - specify the function's format
 * @str: The string
 *
 * Return: 0
 */
int (*get_printf_spec(char *str))(va_list args, par_t *par)
{
	specifier_t specifier[] = {{"c", printf_c},
		{"s", printf_s},
		{"%", printf_percent},
		{"d", printf_int},
		{"i", printf_int},
		{"b", printf_binary},
		{"o", printf_o},
		{"u", print_u},
		{"x", printf_x},
		{"X", printf_X},
		{"p", print_p},
		{"S", printf_S},
		{"r", printf_rev},
		{"R", printf_rot13},
		{NULL, NULL}};
	int i = 0;

	while (specifier[i].specifier)
	{
		if (*str == specifier[i].specifier[0])
		{
			return (specifier[i].fn);
		}
		i++;
	}
	return (NULL);
}
/**
 * get_printf_func - get the function's format
 * @str: The string
 * @args: The arguments
 * @par: The structure's parameters
 *
 * Return: 0
 */
int get_printf_func(char *str, va_list args, par_t *par)
{
	int (*fn)(va_list, par_t *) = get_printf_spec(str);

	if (fn)
		return (fn(args, par));
	return (0);
}
/**
 * get_printf_flag - get the function's flag
 * @str: The string
 * @par: The structure's parameters
 *
 * Return: 0
 */
int get_printf_flag(char *str, par_t *par)
{
	int i = 0;

	switch (*str)
	{
		case '+':
			i = par->f_plus = 1;
			break;
		case ' ':
			i = par->f_space = 1;
			break;
		case '#':
			i = par->f_hash = 1;
			break;
		case '0':
			i = par->f_zero = 1;
			break;
		case '-':
			i = par->f_minus = 1;
			break;
	}
	return (i);
}
/**
 * get_printf_mod - get the function's modifier
 * @str: The string
 * @par: The structure's parameters
 *
 * Return: 0
 */
int get_printf_mod(char *str, par_t *par)
{
	int i = 0;

	switch (*str)
	{
		case 'l':
			i = par->s_long = 1;
			break;
		case 'h':
			i = par->s_short = 1;
			break;
	}
	return (i);
}
/**
 * get_width - get the width
 * @str: The string
 * @args: The arguments
 * @par: The structure's parameters
 *
 * Return: 0
 */
char *get_width(char *str, par_t *par, va_list args)
{
	int j = 0;

	if (*str == '*')
	{
		j = (int) va_arg(args, int);
		str++;
	}
	else
	{
		while (_isdigit(*str))
			j = j * 10 + (*str++ - '0');
	}
	par->width = j;
	return (str);
}
