#include "monty.h"

/**
 * _mod - computes the rest of the division of the second top element
 * by the top element
 *
 * @h: pointer to the head of the stack
 * @n: current line number in the Monty bytecode
 *
 * By: Sina Mathew
 */
void _mod(stack_t **h, unsigned int n)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", n);
		exit(EXIT_FAILURE);
	}
	if ((*h)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", n);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n %= (*h)->n;
	_pop(h, n);
}

/**
 * _mul - multiplies the second top element with the top element of the stack
 * @h: pointer to the head of the stack
 * @n: current line number in the Monty bytecode
 */
void _mul(stack_t **h, unsigned int n)
{
	if (*h == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n" n);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n *n (*h)->n;
	_pop(h, n);
}

