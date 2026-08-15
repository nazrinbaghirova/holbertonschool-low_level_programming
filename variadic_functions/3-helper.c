#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_by_format - prints arg based on format and returns next separator
 * @c: format specifier
 * @ap: argument list
 * @sep: current separator
 *
 * Return: updated separator
 */
char *print_by_format(char c, va_list ap, char *sep)
{
	char *s;

	if (c == 'c')
		return (printf("%s%c", sep, (char)va_arg(ap, int)), ", ");
	if (c == 'i')
		return (printf("%s%d", sep, va_arg(ap, int)), ", ");
	if (c == 'f')
		return (printf("%s%f", sep, va_arg(ap, double)), ", ");
	if (c == 's')
	{
		s = va_arg(ap, char *);
		if (s == NULL)
			s = "(nil)";
		printf("%s%s", sep, s);
		return (", ");
	}
	return (sep);
}
