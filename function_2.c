#include "monty.h"
/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @head: pointer to the first node in a list.
 * @line: number of the line.
 */
void pint(stack_t **head, unsigned int line)
{
	if (!(*head))
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * pop - removes the top element of the stack.
 * @head: pointer to the first node in a list.
 * @line: number of the line.
 */
void pop(stack_t **head, unsigned int line)
{
	stack_t *node;

	if (!(*head))
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	node = (*head);
	(*head) = (*head)->next;
	free(node);
}
/**
 * swap - swaps the top two elements of the stack.
 * @head: pointer to the first node in a list.
 * @line: number of the line.
 */
void swap(stack_t **head, unsigned int line)
{
	unsigned int num_aux = 0;
	stack_t *aux;

	if (!(*head) || !((*head)->next))
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	aux = (*head)->next;
	num_aux = aux->n;
	aux->n = (*head)->n;
	(*head)->n = num_aux;
}
/**
 * add - adds the top two elements of the stack.
 * @head: pointer to the first node in a list.
 * @line: number of the line.
 */
void add(stack_t **head, unsigned int line)
{
	stack_t *aux = (*head);

	if (!(*head) || !((*head)->next))
	{
		dprintf(2, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	(*head) = (*head)->next;
	(*head)->n = (*head)->n + aux->n;
	(*head)->prev = NULL;
	free(aux);
}
