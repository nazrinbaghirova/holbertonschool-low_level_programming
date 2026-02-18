#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * create_node - creates a new node for the hash table
 * @key: key
 * @value: value
 *
 * Return: pointer to new node, or NULL on failure
 */
static hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (!node)
		return (NULL);

	node->key = strdup(key);
	node->value = strdup(value);
	if (!node->key || !node->value)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	return (node);
}

/**
 * hash_table_set - adds or updates an element in a hash table
 * @ht: hash table
 * @key: key (cannot be empty)
 * @value: value (will be duplicated)
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node;
	unsigned long int index;
	char *value_dup;

	if (!ht || !key || !*key || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
		{
			value_dup = strdup(value);
			if (!value_dup)
				return (0);
			free(node->value);
			node->value = value_dup;
			return (1);
		}
		node = node->next;
	}

	node = create_node(key, value);
	if (!node)
		return (0);

	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}
