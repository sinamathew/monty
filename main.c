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
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file_ptr = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content_ptr = content;
		counter++;
		if (read_line > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	free_s(stack);
	fclose(file);

	return (0);
}
