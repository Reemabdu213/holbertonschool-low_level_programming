#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * update_existing_key - updates value if key exists
 * @ht: the hash table
 * @key: the key
 * @value: new value
 * @index: index in hash table
 *
 * Return: 1 if key found and updated, 0 otherwise
 */
int update_existing_key(hash_table_t *ht, const char *key,
			const char *value, unsigned long int index)
{
	hash_node_t *temp = ht->array[index];

	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = strdup(value);
			if (temp->value == NULL)
				return (-1);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

/**
 * create_new_node - creates a new hash node
 * @key: the key
 * @value: the value
 *
 * Return: pointer to new node, or NULL on failure
 */
hash_node_t *create_new_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	return (new_node);
}

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table
 * @key: the key (cannot be empty string)
 * @value: the value associated with the key
 *
 * Return: 1 if succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node;
	int result;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	result = update_existing_key(ht, key, value, index);
	if (result == 1)
		return (1);
	if (result == -1)
		return (0);

	new_node = create_new_node(key, value);
	if (new_node == NULL)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
