#include "monty.h"

/**
 * _rotl - Rotates the stack to the top
 * @h: Double pointer to the head of the stack
 * @n: current line number in the Monty bytecode file
 */
void _rotl(stack_t **h, unsigned int n)
{
	stack_t *new_top, *old_top;

	if (*h && (*h)->next)
	{
		old_top = *h;
		new_top = old_top->next;
		old_top->next = NULL;
		old_top->prev = NULL;
		new_top->prev = NULL;
		*h = new_top;

		while (new_top->next)
			new_top = new_top->next;

		new_top->next = old_top;
		old_top->prev = new_top;
	}
	else
	{
		fprintf(stderr, "L%d: can't rotl, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
}
