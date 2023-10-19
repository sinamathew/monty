#include "monty.h"

/**
 * _rotl - Rotates the stack to the top
 * @h: Double pointer to the head of the stack
 * @n: current line number in the Monty bytecode file
 */
void _rotl(stack_t **h, unsigned int n)
{
	stack_t *temp;
	(void) n;

	temp = *h;
	if (*h == NULL || (*h)->next == NULL)
		return;

	temp = *h;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *h;
	(*h)->next = NULL;
	(*h)->prev = temp;
	(*h) = temp;
}
/**
  *_rotr- rotates the stack to the bottom
  *@h: stack head
  *@n: line_number
  *Return: no return
 */
void _rotr(stack_t **h, unsigned int n)
{
	stack_t *c;
	(void) n;

	c = *h;
	if (*h == NULL || (*h)->next == NULL)
	{
		return;
	}
	while (c->next)
	{
		c = c->next;
	}
	c->next = *h;
	c->prev->next = NULL;
	c->prev = NULL;
	(*h)->prev = c;
	(*h) = c;
}
