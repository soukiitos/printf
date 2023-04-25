#include "main.h"
/**
 * _printf - Print the output according to format
 * @format: The format for printf
 *
 * Return: 0
 */
int _printf(const char *format, ...)
{
	char *p, *start;
	va_list args;
	int sum = 0;
	par_t par = par_init;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (*p; p = (char *)format; p++)
	{
		init_par(&par, args);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = P;
		p++;
		for (; get_printf_flag(p, &par); p++)
		{
			;
		}
		p = get_width(p, &par, args);
		p = get_precs(p, &par);
		if (get_printf_mod(p, &par))
			p++;
		if (!get_printf_spec(p))
			sum += printf_fto(start, p, par.s_long || par.s_short ? p - 1 : 0);
		else
			suum += get_printf_func(p, args, &par);
	}
	_putchar(BUFF_FLUSH);
	va_end(args);
	return (sum);
}
