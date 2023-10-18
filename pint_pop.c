#include "monty.h"
/**
 * _pint - prints value at the top of stack
 * @h: header
 * @n: value to be printed
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
 * _pop - removes top element of stack
 * @h: header
 * @n: line number
 */
void _pop(stack_t **h, unsigned int n)
{
	stack_t *temp;

	if (!*h)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", n);
		fclose(bus.file_ptr);
		free(bus.content_ptr);
		free_s(*h);
		exit(EXIT_FAILURE);
	}
	temp = *h;
	*h = temp->next;
	free(temp);
}
