#include <stdlib.h>
#include "main.h"

/**
 * create_array - creates an array of chars and initializes it
 * @size: size of the array
 * @c: character to initialize with
 *
 * Return: pointer to array, or NULL
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0)
		return (NULL);

	array = malloc(sizeof(char) * size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = c;

	return (array);
}

