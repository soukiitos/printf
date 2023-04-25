#include "main.h"
/**
 * init_par - reset buf and clear structures
 * @par: the structure's parameters
 * @args: The arguments variable
 *
 * Return: 0
 */
void init_par(par_t *par, va_list args)
{
	par->f_unsign = 0;
	par->f_plus = 0;
	par->f_space = 0;
	par->f_hash = 0;
	par->f_zero = 0;
	par->f_minus = 0;
	par->s_long = 0;
	par->s_short = 0;
	par->width = 0;
	par->precision = UINT_MAX;
	(void)args;
}
