#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * get - A predefined function to read strings
 * @c: A character
 *
 * Return: 0
 */
int (*get(char c))(va_list args)
{
	int i;
	char array[] = {{"c", printf_c},
		{"s", printf_s},
		{"%", printf_pcent},
		{NULL, NULL}};

	for (i = 0; array[i].ch; i++)
	{
		if (c == array[i].ch[0])
		{
			return (array[i].f);
		}
	}
	return (NULL);
}
