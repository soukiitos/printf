#include "main.h"
/**
 * _puts - print strings
 * @string: The string
 *
 * Return: 0
 */
int _puts(char *string)
{
	char *a = string;

	while (*string)
		_putchar(*string++);
	return (string - a);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
	static int i;
	static char buff[BUFF_SIZE];

	if (c == BUFF_FLUSH || i >= BUFF_SIZE)
	{
		write(1, buff, i);
		i = 0;
	}
	if (c != BUFF_FLUSH)
		buff[i++] = c;
	return (1);
}
