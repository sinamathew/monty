#include "monty.h"

bus_t bus;

/**
 * main - the monty main code
 * @ac: argument counter
 * @av: argumnet vector
 *
 * Return: 0 on success, exit with exit status EXIT_FAILURE on error
 *
 * Description: Monty Byte Code
 *
 * By: Sina & Elmi
 */
int main(int ac, char *av[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (ac != 2)
	{
		usage_error();
	}

	file = fopen(av[1], "r");
	bus.file_ptr = file;

	if (!file)
	{
		file_error(av[1]);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content_ptr = content;
		count++;
		if (read_line > 0)
		{
			execute(content, &stack, count, file);
		}
		free(content);
	}
	free_s(stack);
	fclose(file);

	return (0);
}
