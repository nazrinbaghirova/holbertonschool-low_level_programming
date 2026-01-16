#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_one - prints one argument based on format character
 * @c: format character
 * @ap: argument list
 * @sep: separator string
 *
 * Return: new separator string
 */
static const char *print_one(char c, va_list ap, const char *sep)
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

/**
 * print_all - prints anything, followed by a new line
 * @format: list of types of arguments passed to the function
 *
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	const char *sep = "";

	if (format == NULL)
	{
		printf("\n");
		return;
	}

	va_start(ap, format);
	while (format[i] != '\0')
	{
		sep = print_one(format[i], ap, sep);
		i++;
	}
	va_end(ap);

	printf("\n");
}
