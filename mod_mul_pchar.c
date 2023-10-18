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

/**
 * _pchar - prints the character at the top of the stack as an ASCII character
 * @h: pointer to the head of the stack
 * @n: current line number in the Monty bytecode
 *
 * By: Sina
 */
void _pchar(stack_t **h, unsigned int n)
{
	int ascii_value;

	if (*h == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", n);
		exit(EXIT_FAILURE);
	}
	ascii_value = (*h)->n;
	if (ascii_value < 32 || ascii_value > 126)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", n);
		exit(EXIT_FAILURE);
	}
	putchar(ascii_value);
	putchar('\n');
}
