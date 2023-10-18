#include "monty.h"
/**
 * _push - adds node to stack
 * @h: pointer to first node
 * @count: counts line number
 */
void _push(stack_t **h, unsigned int count)
{
	int i = 0, n, flag = 0;

	if (bus.argument)
	{
		if (bus.argument[0] == '-')
			i++;
		for (; bus.argument[i] != '\0'; i++)
		{
			if (bus.argument[i] > 57 || bus.argument[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(bus.file_ptr);
			free(bus.content_ptr);
			free_s(*h);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(bus.file_ptr);
		free(bus.content_ptr);
		free_s(*h);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.argument);
	if (bus.lifi_flag == 0)
		add_dnode(h, n);
	else
		add_dnode_end(h, n);
}

/**
 * _pall - prints stack
 * @head: pointer to first node
 * @n: unused
 */
void _pall(stack_t **head, unsigned int n)
{
	stack_t *temp;
	(void)n;

	temp = *head;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _div - divides the second top element by the top element of the stack
 * @h: pointer to the head of the stack
 * @n: current line number in the Monty bytecode
 *
 * By: Sina Mathew
 */
void _div(stack_t **h, unsigned int n)
{
	int result;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", n);
		exit(EXIT_FAILURE);
	}

	if ((*h)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", n);
		exit(EXIT_FAILURE);
	}

	result = (*h)->next->n / (*h)->n;
	_pop(h, n);
	(*h)->n = result;

}
