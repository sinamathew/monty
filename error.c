#include "monty.h"

/**
 * usage_error - print usage error message and exit
 * Description: exit with EXIT_FAILURE
 *
 * By: Sina Mathew
 */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * file_error - print file open error message
 * @file: name of file that couldn't be opened
 *
 * By: Sina Mathew
 */
void file_error(const char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}

/**
 * unknown_instruction - print unknown instruction and exit
 * @line_no: line number at which the error occurred
 * @line: the line that's unknown
 *
 * By: Sina Mathew
 */
void unknown_instruction(unsigned int line_no, char *line)
{
	fprintf(stderr, "L%d: unknown instruction %s", line_no, line);
	exit(EXIT_FAILURE);
}
