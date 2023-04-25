#include "main.h"
/**
 * convert - convert functions
 * @n: A number
 * @i: An integer
 * @f: A flag's argument
 * @par: The structure's parameters
 *
 * Return: 0
 */
char *convert(long int n, int i, int f, par_t *par)
{
	char *p, sign = 0;
	static char b[50], *array;
	unsigned long num = n;
	(void)par;

	if (!(f & CONVERT_UNSIGNED) && n < 0)
	{
		num = -n;
		sign = '-';
	}
	array = f & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &b[49];
	*p = '\0';
	do {
		*--p = array[n % i];
		num /= i;
	} while (num != 0);
	if (sign)
		*--p = sign;
	return (p);
}
/**
 * print_u - Print unsigned integers
 * @args: The arguments
 * @par: The structure's parameters
 *
 * Return: 0
 */
int print_u(va_list args, par_t *par)
{
	unsigned long l;

	if (par->s_long)
		l = (unsigned long)va_arg(args, unsigned long);
	else if (par->s_short)
		l = (unsigned short int)va_arg(args, unsigned int);
	else
		l = (unsigned int)va_arg(args, unsigned int);
	par->f_unsign = 1;
	return (printf_num(convert(l, 10, CONVERT_UNSIGNED, par), par));
}
/**
 * print_p - Print the address
 * @args: The arguments
 * @par: The structure's parameters
 *
 * Return: 0
 */
int print_p(va_list args, par_t *par)
{
	char *str;
	unsigned long int n = va_arg(args, unsigned long int);

	if (!n)
		return (_puts("(nil)"));
	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, par);
	*--str = 'x';
	*--str = '0';
	return (printf_num(str, par));
}
