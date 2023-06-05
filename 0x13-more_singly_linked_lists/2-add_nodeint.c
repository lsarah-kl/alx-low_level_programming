#include "lists.h"

/**
 * add_nodeint -Function that adds a new node in the beginning of  linked list
 * @head: pointer to the first node in list
 * @n: data to bo inserted in that new node
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}

