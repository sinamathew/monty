#include "monty.h"

/**
 * _pint - prints value at the top of stack
 * @h: header
 * @n: value to be printed
 *
 * By: Elmi
 */
void _pint(stack_t **h, unsigned int n)
{
	if (!*h)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", n);
		fclose(bus.file_ptr);
		free(bus.content_ptr);
		free_s(*h);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}

/**
 * _pop - removes the top element from the stack
 * @stack: pointer to the head of the stack
 * @line_num: current line number in the Monty bytecode
 *
 * By: Sina
 */
void _pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	free(temp);
}

/**
 * _sub - subtracts the top element of the stack from the second top element
 * of the stack
 * @h: points to pointer that points to the head of the element
 * @n: line number
 *
 * By: Sina
 */
void _sub(stack_t **h, unsigned int n)
{
	int result;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", n);
		exit(EXIT_FAILURE);
	}

	result = (*h)->next->n - (*h)->n;
	_pop(h, n);
	(*h)->n = result;
}
