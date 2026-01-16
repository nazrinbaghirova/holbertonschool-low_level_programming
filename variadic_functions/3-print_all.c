
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything followed by a new line
 * @format: list of types of arguments passed to the function
 *
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	unsigned int i = 0;
	char *sep = "";

	if (format == NULL)
	{
		printf("\n");
		return;
	}

	va_start(ap, format);
	while (format[i])
		sep = print_by_format(format[i++], ap, sep);
	va_end(ap);
	printf("\n");
}
