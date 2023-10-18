#include "monty.h"
/**
 * _swap - swaps elemnts of stack
 *  @h: header
 *  @n: line count;
 */
void _swap(stack_t **h, unsigned int n)
{
	stack_t *temp;
	int length = 0, j;

	temp = *h;
	while (temp)
	{
		temp = temp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", n);
		fclose(bus.file_ptr);
		free(bus.content_ptr);
		free_s(*h);
		exit(EXIT_FAILURE);
	}
	temp = *h;
	j = temp->n;
	temp->n = temp->next->n;
	temp->next->n = j;
}
/**
 * _add - add first two elements of stack
 * @h: header
 * @n: line count
 */
void _add(stack_t **h, unsigned int n)
{
	stack_t *temp;
	int length = 0, j;

	temp = *h;
	while (temp)
	{
		temp = temp->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", n);
		fclose(bus.file_ptr);
		free(bus.content_ptr);
		free_s(*h);
		exit(EXIT_FAILURE);
	}
	temp = *h;
	j = temp->n + temp->next->n;
	temp->next->n = j;
	*h = temp->next;
	free(temp);
}
/**
 * _nop - nothing
 * @h: header
 * @n: line count
 */
void _nop(stack_t **h, unsigned int n)
{
	(void) n;
	(void) h;
}
