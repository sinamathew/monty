#include "monty.h"
/**
 * _push - adds node to stack
 * @h: pointer to first node
 * @count: counts line number
 */
void _push(stack_t **h, unsigned int count)
{
	int i = 0, n, flag;

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
