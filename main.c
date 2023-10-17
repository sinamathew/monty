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

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	else
	{
		printf("All good\n");
	}

	return (0);
}
