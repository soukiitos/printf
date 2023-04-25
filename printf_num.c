#include "main.h"
/**
 * _isdigit - Check if the character is digit or not
 * @c: The character
 *
 * Return: 0
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/**
 * _strlen - THe length of strings
 * @str: The string
 *
 * Return: 0
 */
int _strlen(char *str)
{
	int i = 0;

	while (*str++)
		i++;
	return (i);
}
/**
 * printf_num - Print numbers
 * @s: The string
 * @par: The structure's parameters
 *
 * Return: 0
 */
int print_num(char *s, par_t *par)
{
	int negative = (!par->f_unsign && *s == '-');
	unsigned int i = _strlen(s);

	if (!par->precision && *s == '0' && !s[1])
		s = "";
	if (negative)
	{
		s++;
		i--;
	}
	if (par->precision != UINT_MAX)
		while (i++ < par->precision)
			*--s = '0';
	if (negative)
		*--s = '-';
	if (!par->f_minus)
		return (printf_rshift(s, par));
	else
		return (printf_lshift(s, par));
}
/**
 * printf_rshift - Print options
 * @s: The string
 * @par: The structure's parameter
 *
 * Return: 0
 */
int printf_rshift(char *s, par_t *par)
{
	char pad_char = ' ';
	unsigned int negative1, negative2, n = 0, i = _strlen(s);

	if (par->f_zero && !par->f_minus)
		pad_char = '0';
	negative 1 = negative2 = (!par->f_unsign && *s == '-');
	if (negative1 && i < par->width && pad_char == '0' && !par->f_minus)
		s++;
	else
		negative1 = 0;
	if ((par->f_plus && !negative2) ||
			(!par->f_plus && par->f_space && !negative2))
		i++;
	if (negative1 && pad_char == '0')
		n += _putchar('-');
	if (par->f_plus && !negative2 && pad_char == '0' && !par->f_unsign)
		n += _putchar('+');
	else if (!par->f_plus && par->f_space && !negative2 &&
			!par->f_unsign && par->f_zero)
		n += _putchar(' ');
	while (i++ < par->width)
		n += _putchar(pad_char);
	if (negative1 && pad_char == ' ')
		n += _putchar('-');
	if (par->f_plus && !negative2 && pad_char == ' ' && !par->f_unsign)
		n += _putchar('+');
	else if (!par->f_plus && par->f_space && !negative2 &&
			!par->f_unsign && !par->f_zero)
		n += _putchar(' ');
	n += _puts(s);
	return (n);
}
/**
 * printf_lshift - Print options
 * @s: The string
 * @par: The structure's parameters
 *
 * Return: 0
 */
int printf_lshift(char *s, par_t *par)
{
	char pad_char = ' ';
	unsigned int negative1, negative2, n = 0, i = _strlen(s);

	if (par->f_zero && !par->f_minus)
		pad_char = '0';
	negative1 = negative2 = (!par->f_unsign && *s == '-');
	if (negative1 && i < par->width && pad_char == '0' && !par->f_minus)
		s++;
	else
		negative1 = 0;
	if (par->f_plus && !negative2 && !par->f_unsign)
		n += _putchar('+'), i++;
	else if (par->f_space && !negative2 && !par->f_unsign)
		n += _putchar(' '), i++;
	n += _puts(s);
	while (i++ < par->width)
		n += _putchar(pad_char);
	return (n);
}
