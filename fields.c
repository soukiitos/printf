#include "main.h"
/**
 * get_precs - get the precision
 * @p: The string
 * @par: The structure's parameters
 * @args: The arguments
 *
 * Return: 0
 */
char *get_precs(char *p, par_t *par, va_list args)
{
	int j = 0;

	if (*p != '.')
	{
		return (p);
	}
	if (*p == '*')
	{
		j = (int) va_arg(args, int);
		j++;
	}
	else
	{
		while (_isdigit(*p))
			j = j * 10 + (*p++ - '0');
	}
	par->precision = j;
	return (p);
}
