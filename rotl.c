#include "monty.h"

/**
 * _rotl - Rotates the stack to the top
 * @h: Double pointer to the head of the stack
 * @n: current line number in the Monty bytecode file
 */
void _rotl(stack_t **h, unsigned int n)
{
	stack_t *temp, *j;
	(void) n;

	temp = *h;
	if (*h == NULL || (*h)->next == NULL)
		return;
	j = (*h)->next;
	j = (*h)->prev;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *h;
	(*h)->next = NULL;
	(*h)->prev = temp;
	(*h) = j;
}
