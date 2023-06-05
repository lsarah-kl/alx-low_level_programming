#include "lists.h"

/**
 * pop_listint - Function that deletes the head of a linked list
 * @head: pointer to 1st element in the linked list
 * Return: the data inside the elements that was deleted, or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int num;

	if (!head || !*head)
		return (0);

	num = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (num);
}

