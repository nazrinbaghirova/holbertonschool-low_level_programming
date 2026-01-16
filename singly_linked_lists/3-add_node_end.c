#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: address of the pointer to the head of the list
 * @str: string to duplicate and store in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *tmp;
	unsigned int len = 0;
	char *dup;

	if (head == NULL || str == NULL)
		return (NULL);

	dup = strdup(str);
	if (dup == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		free(dup);
		return (NULL);
	}

	new_node->str = dup;
	new_node->len = len;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = new_node;

	return (new_node);
}
