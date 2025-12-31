#include "main.h"
#include <limits.h>

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: integer value
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	unsigned int num = 0;
	unsigned int limit;

	/* find first digit, track signs before digits */
	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}

	/* limit depends on sign: INT_MAX or (INT_MAX + 1) for INT_MIN */
	if (sign == -1)
		limit = (unsigned int)INT_MAX + 1U;
	else
		limit = (unsigned int)INT_MAX;

	/* build number without overflowing */
	while (s[i] >= '0' && s[i] <= '9')
	{
		unsigned int digit = (unsigned int)(s[i] - '0');

		if (num > (limit - digit) / 10)
		{
			num = limit;
			break;
		}
		num = num * 10 + digit;
		i++;
	}

	if (sign == -1)
	{
		if (num == (unsigned int)INT_MAX + 1U)
			return (INT_MIN);
		return (-(int)num);
	}

	return ((int)num);
}
