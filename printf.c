#include <stdarg.h>
#include <stdio.h>
int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int count = 0;
for (const char *c = format; *c; ++c) 
{
if (*c == '%')
{
++c;
switch (*c)
{
case 'c':
putchar(va_arg(args, int));
++count;
break;
case 's':
onst char *str = va_arg(args, const char *);
while (*str) 
{
putchar(*str++);
++count;
}
break;
case '%':
putchar('%');
++count;
break;
}
} 
else 
{
putchar(*c);
++count;
}
}
va_end(args);
return count;
}
