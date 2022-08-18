#include "monty.h"
/**
 *
 *
 *
 */
void push(stack_t **head, unsigned int line)
{
	stack_t *aux;
	stack_t *n_node;
	(void)line;

	n_node = malloc(sizeof(stack_t));
	if (!n_node)
	{
		dprintf(2, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	n_node->n = value;
	n_node->next = NULL;
	n_node->prev = NULL;
	if ((*head) == NULL)
	{
		*head = n_node;
		return;
	}
	aux = (*head);
	aux->prev = n_node;
	n_node->next = aux;
	(*head) = n_node;
}
/**
 *
 *
 *
 *
 */
void pall(stack_t **head, unsigned int line)
{
	int c = 0;
	stack_t *print = *head;

	(void) line;
	while (print)
	{
		printf("%d\n", print->n);
		c++;
		print = print->next;
	}
}
/**
 *
 *
 *
 */
void nop(stack_t **head, unsigned int line)
{
	(void)head;
	(void)line;
}
