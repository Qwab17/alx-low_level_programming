#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - fxn that add new node at the beging of lnkd list
 * @head: Double pointer to the list_t list
 * @str: New string to add to node
 * Return: address of new element, or NULL if fail
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *newnode;
	unsigned int len = 0;

	while (str[len])
		len++;
	newnode = malloc(sizeof(list_t));
	if (!newnode)
		return (NULL);

	newnode->str = strdup(str);
	newnode->len = len;
	newnode->next = (*head);
	(*head) = newnode;

	return (*head);
}
