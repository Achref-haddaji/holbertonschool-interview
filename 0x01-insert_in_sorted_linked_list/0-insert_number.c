#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * insert_node -  print a Linkedlist.
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: number of the nodes
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, **tmp;

	tmp = head;
	new_node = malloc(sizeof(listint_t));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->n = number;

	while ((*tmp) && (*tmp)->n < number)
	{
		tmp = &(*tmp)->next;
	}
	new_node->next = (*tmp);
	(*tmp) = new_node;
	return (new_node);
}
