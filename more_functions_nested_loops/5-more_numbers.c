#include "main.h"

/**
 * more_numbers - prints numbers from 0 to 14 ten times
 *
 * Return: Nothing.
 */
void more_numbers(void)
{
	int row;
	int i;

	for (row = 0; row < 10; row++)
	{
		for (i = 0; i <= 14; i++)
		{
			if (i >= 10)
				_putchar((i / 10) + '0');

			_putchar((i % 10) + '0');
		}

		_putchar('\n');
	}
}
