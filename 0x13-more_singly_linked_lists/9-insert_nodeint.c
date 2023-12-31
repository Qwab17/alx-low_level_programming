#include "lists.h"

/**
 * insert_nodeint_at_index - function that inserts a new node
 * @head: pointer to the first node
 * @indx: index to add new node
 * @n: data to insert
 * Return: pointer to new node, or NULL
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int indx, int n)
{
	unsigned int i;
	listint_t *new;
	listint_t *temp = *head;

	new = malloc(sizeof(listint_t));
	if (!new || !head)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (indx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	for (i = 0; temp && i < indx; i++)
	{
		if (i == indx - 1)
		{
			new->next = temp->next;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}
