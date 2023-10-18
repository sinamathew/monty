#include "monty.h"

/**
 * _pstr - prints a string from the stack
 * @h: pointer to the head of the stack
 * 
 * By: Sina
 */
void _pstr(stack_t **h)
{
	stack_t *tmp = *h;

	while (tmp && tmp->n != 0 && isprint(tmp->n))
	{
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}
