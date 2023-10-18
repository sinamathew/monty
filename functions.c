#include "monty.h"

/**
* free_s - frees a doubly linked list
* @h: head of the stack
*/
void free_s(stack_t *h)
{
	stack_t *temp;

	temp = h;
	while (h)
	{
		temp = h->next;
		free(h);
		h = temp;
	}
}

/**
 * add_dnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void add_dnode(stack_t **head, int n)
{

	stack_t *newnode, *temp;

	temp = *head;
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp)
		temp->prev = newnode;
	newnode->n = n;
	newnode->next = *head;
	newnode->prev = NULL;
	*head = newnode;
}

/**
 * add_dnode_end - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void add_dnode_end(stack_t **head, int n)
{
	stack_t *newnode, *temp;

	temp = *head;
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		printf("Error\n");
	}
	newnode->n = n;
	newnode->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	else if (!temp)
	{
		*head = newnode;
		newnode->prev = NULL;
	}
	else
	{
		temp->next = newnode;
		newnode->prev = temp;
	}
}
