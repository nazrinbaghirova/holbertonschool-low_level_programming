#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_arg - prints one argument depending on the format specifier
 * @c: specifier character
 * @ap: variadic list
 * @sep: separator string to print before the value
 *
 * Return: new separator string
 */
static char *print_arg(char c, va_list ap, char *sep)
{
	char *str;

	switch (c)
	{
		case 'c':
			printf("%s%c", sep, va_arg(ap, int));
			return (", ");
		case 'i':
			printf("%s%d", sep, va_arg(ap, int));
			return (", ");
		case 'f':
			printf("%s%f", sep, va_arg(ap, double));
			return (", ");
		case 's':
			str = va_arg(ap, char *);
			if (str == NULL)
				str = "(nil)";
			printf("%s%s", sep, str);
			return (", ");
		default:
			return (sep);
	}
}

/**
 * print_all - Prints anything based on a format string
 * @format: list of types of arguments passed to the function
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i;
	char *sep;

	if (format == NULL)
	{
		printf("\n");
		return;
	}

	va_start(ap, format);

	i = 0;
	sep = "";

	while (format[i] != '\0')
	{
		sep = print_arg(format[i], ap, sep);
		i++;
	}

	va_end(ap);
	printf("\n");
}

