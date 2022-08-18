#include "monty.h"
/**
 * free_stack - free all the nodes in a list
 * @head: point to the first node in a list
 */
void free_stack(stack_t *head)
{
	stack_t *next_node = NULL;

	while (head)
	{
		next_node = head->next;
		free(head);
		head = next_node;
	}
}
