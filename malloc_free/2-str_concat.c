#include <stdlib.h>
#include "main.h"

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to newly allocated string, or NULL
 */
char *str_concat(char *s1, char *s2)
{
	char *new;
	unsigned int i, j, len1 = 0, len2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	new = malloc(sizeof(char) * (len1 + len2 + 1));
	if (new == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		new[i] = s1[i];

	for (j = 0; j < len2; j++)
		new[i + j] = s2[j];

	new[i + j] = '\0';

	return (new);
}

