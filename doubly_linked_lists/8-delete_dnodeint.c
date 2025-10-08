/* ===== 8-delete_dnodeint.c ===== */
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at a given index
 * @head: pointer to pointer to head of the list
 * @index: index of the node to delete (starts at 0)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	node = *head;

	/* delete head */
	if (index == 0)
	{
		*head = node->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(node);
		return (1);
	}

	/* move to target node */
	while (node != NULL && i < index)
	{
		node = node->next;
		i++;
	}

	if (node == NULL)
		return (-1);

	/* relink around node */
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;

	free(node);
	return (1);
}

