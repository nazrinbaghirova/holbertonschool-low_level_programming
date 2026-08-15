#include "main.h"
#include <limits.h>

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: integer
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	unsigned int num = 0;

	while (s[i] && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		if (num > (unsigned int)(INT_MAX / 10) ||
		    (num == (unsigned int)(INT_MAX / 10) && (s[i] - '0') > 7))
		{
			if (sign == -1)
				return (INT_MIN);
			return (INT_MAX);
		}
		num = num * 10 + (s[i] - '0');
		i++;
	}

	return (sign * num);
}
