#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to pointer to head of the list
 * @idx: index where the new node should be added (starts at 0)
 * @n: value to store in the new node
 * Return: address of the new node, or NULL on failure / out of range
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *curr, *node;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);

	/* add at beginning (works even if *h == NULL) */
	if (idx == 0)
		return (add_dnodeint(h, n));

	/* traverse to the node BEFORE the target index */
	curr = *h;
	while (curr != NULL && i < idx - 1)
	{
		curr = curr->next;
		i++;
	}

	/* idx out of range */
	if (curr == NULL)
		return (NULL);

	/* append at end */
	if (curr->next == NULL)
		return (add_dnodeint_end(h, n));

	/* insert in the middle */
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

