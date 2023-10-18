#ifndef MONTY_H
#define MONTY_H

/*---MACRO---*/
#define _POSIX_C_SOURCE 200809L
#define MAX 50

/*---HEADERS---*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>


/*---TYPEDEF---*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct Bus - variables
 * @argument: value
 * @file_ptr: pointer to monty file
 * @content_ptr: content
 * @lifi_flag: flag change
 *
 */
typedef struct Bus
{
	char *argument;
	FILE *file_ptr;
	char *content_ptr;
	int lifi_flag;
} bus_t;


/*---GLB_VAR---*/
extern bus_t bus;


/*---PROTOTYPES---*/
void usage_error(void);
void free_s(stack_t *h);
void _pstr(stack_t **h, unsigned int n);
void file_error(const char *file);
void add_dnode(stack_t **head, int n);
void add_dnode_end(stack_t **head, int n);
void _push(stack_t **h, unsigned int count);
void _pall(stack_t **head, unsigned int n);
void _pint(stack_t **h, unsigned int n);
void _pop(stack_t **h, unsigned int n);
void _swap(stack_t **h, unsigned int n);
void _add(stack_t **h, unsigned int n);
void _nop(stack_t **h, unsigned int n);
void _sub(stack_t **h, unsigned int n);
void _div(stack_t **h, unsigned int n);
void _mod(stack_t **h, unsigned int n);
void _mul(stack_t **h, unsigned int n);
void _pchar(stack_t **h, unsigned int n);
void unknown_instruction(unsigned int line_no, char *line);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);

#endif /*MAIN_H*/
