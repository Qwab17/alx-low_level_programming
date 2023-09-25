#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - fxn that adds new node end of a lnkd list
 * @head: Double pointer to list_t list
 * @str: string to add to new node
 * Return: address of new element, or NULL if fail
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newnode;
	list_t *temp = *head;
	unsigned int len = 0;

	while (str[len])
		len++;

	newnode = malloc(sizeof(list_t));
	if (!newnode)
		return (NULL);
	newnode->str = strdup(str);
	newnode->len = len;
	newnode->next = NULL;

	if (*head == NULL)
	{
		*head = newnode;
		return (newnode);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = newnode;

	return (newnode);
}