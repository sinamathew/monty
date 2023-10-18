#include "monty.h"

/**
 * _pstr - prints a string from the stack
 * @h: pointer to the head of the stack
 * @n: Unused
 *
 * By: Sina
 */
void _pstr(stack_t **h, unsigned int n)
{
	stack_t *tmp = *h;

	(void)n;

	while (tmp && tmp->n != 0 && isprint(tmp->n))
	{
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}
