#include "monty.h"

/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[MAX] = {
				{"push", _push}, {"pall", _pall},
				{"pint", _pint}, {"pop", _pop},
				{"swap", _swap}, {"add", _add},
				{"nop", _nop}, {"sub", _sub},
				{"div", _div}, {"mul", _mul},
				{"mod", _mod}, {"pchar", _pchar},
				{"pstr", _pstr}, {"rotl", _rotl},
				{"rotr", _rotr},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	if (content == NULL || *content == '\0'
			|| strncmp(content, "#", 1) == 0)
		return 0;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.argument = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		unknown_instruction(counter, op);
		fclose(file);
		free(content);
		free_s(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
