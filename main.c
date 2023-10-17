#include "monty.h"

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
int main(int ac, char **av)
{
	FILE *file;

	if (ac != 2)
		usage_error();

	file = fopen(av[1], "r");
	if (file == NULL)
		file_error(av[1]);

	/* File processing code goes here */
	/**
	 * don't know how to use the unknown_instruction() function yet
	 */

	fclose(file);

	return (0);
}
