#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to pointer to the head of the list
 * @idx: index where the new node should be added (starts at 0)
 * @n: value to store in the new node
 *
 * Description: This function inserts a new node into a doubly linked list
 * at the specified index. It handles insertion at the beginning, middle,
 * or end of the list. Returns NULL if the index is out of range.
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *curr, *node;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	curr = *h;
	while (curr != NULL && i < idx - 1)
	{
		curr = curr->next;
		i++;
	}

	if (curr == NULL)
		return (NULL);

	if (curr->next == NULL)
		return (add_dnodeint_end(h, n));

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);

	node->n = n;
	node->prev = curr;
	node->next = curr->next;
	curr->next->prev = node;
	curr->next = node;

	return (node);
}
