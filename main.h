#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define BUFF_SIZE 1024
#define BUFF_FLUSH -1

#define CONVERT_UNSIGNED 2
#define CONVERT_LOWERCASE 1
#define NULL_STRING "(null)"

#define PAR_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/**
 * struct parameter - The structure paramaters of flag and specifier
 * @f_plus: for plus+  flag
 * @f_space: for space flag
 * @f_hash: for hashtag# flag
 * @f_zero: for zero0 flag
 * @f_minus: for minus- flag
 * @f_unsign: for unsingned values
 * @s_long: for l-modifier
 * @s_short: for h-modifier
 * @width: for the width field
 * @precision: for the precision field
 */
typedef struct parameter
{
	unsigned int f_plus	: 1;
	unsigned int f_space	: 1;
	unsigned int f_hash	: 1;
	unsigned int f_zero	: 1;
	unsigned int f_minus	: 1;
	unsigned int f_unsign	: 1;
	unsigned int s_long	: 1;
	unsigned int s_short	: 1;
	unsigned int width	: 1;
	unsigned int precision	: 1;
} par_t;

/**
 * struct specifier - A structure format of printf
 *
 * @specifier: The format.
 * @fn: The function associated.
 */
typedef struct specifier
{
	char *specifier;
	int (*fn)(va_list, par_t *);
} specifier_t;

/* printf.c */
int _printf(const char *format, ...);

/* _putchar.c */
int _putchar(char c);

/* put.c */
int _puts(char *string);
int _putchar(int c);

/* functions.c */
int printf_c(va_list args, par_t *par);
int printf_s(va_list args, par_t *par);
int printf_percent(va_list args, par_t *par);
int printf_d(va_list args, par_t *par);
int printf_i(va_list args, par_t *par);
int printf_S(va_list args, par_t *par);

/* convert.c */
int printf_binary(va_list args, par_t *par);
int printf_o(va_list args, par_t *par);
int printf_x(va_list args, par_t *par);
int printf_X(va_list args, par_t *par);

/* numbers.c */
int print_u(va_list args, par_t *par);
char *convert(long int n, int i, int f, par_t *par);
int print_p(va_list args, par_t *par);

/* printer.c */
int printf_rev(va_list args, par_t *par);
int printf_rot13(va_list args, par_t *par);
int printf_fto(char *start, char *stop, char *beside);

/* specifier.c */
int get_printf_func(char *str, va_list args, par_t *par);
int get_printf_mod(char *str, par_t *par);
char get_width(char *str, va_list args, par_t *par);
int get_printf_flag(char *str, par_t *par);
int (*get_printf_spec(char *str))(va_list args, par_t *par);

/* printf_num */
int printf_num(char *s, par_t *par);
int printf_rshift(char *s, par_t *par);
int printf_lshift(char *s, par_t *par);
int _strlen(char *str);
int _isdigit(int c);

/* parameter.c */
void init_par(par_t *par, va_list args);

/* fields.c */
char *get_precs(char *p, par_t *par, va_list args);

#endif
