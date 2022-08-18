#include "monty.h"
int value = 0;
/**
 *
 *
 *
 *
 */
int match_function(char *buf, int line, stack_t **head)
{
	int i = 0;
	char *buf_dup;
	char *token1 = NULL;
	char *token2 = NULL;
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"\0", NULL}
	};

	if (!buf)
		return (-1);
	buf_dup = strdup(buf);
	token1 = strtok(buf_dup, " \t\n");
	while (functions[i].opcode[0] != '\0' && token1 != NULL)
	{
		if(strcmp(functions[i].opcode, token1) == 0)
		{
			if (i == 0)
			{
				token2 = strtok(NULL, " \t\n");
				if (!token2)
				{
					dprintf(2, "L%d: usage: push integer\n", line);
					free(token2);
					free(token1);
					free(buf_dup);
					exit(EXIT_FAILURE);
				}
				else /*if(token2 es numero) */ 
					value = atoi(token2);
				/*
				else
				{
					dprintf(2, "L%d: usage: push integer\n", line);
					free(token1);
					free(token2);
					exit(EXIT_FAILURE);
				}*/
				
			}
			functions[i].f(head, line);
			free(buf_dup);
			return (0);
		}
		i++;
	}
	dprintf(2, "L%d: unknown instruction %s\n", line, token1);
	free(token1);
	free(buf_dup);
	exit(EXIT_FAILURE);
}
/**
 *
 *
 *
 */
int main(int argc, char * argv[])
{
	FILE *name_of_file;
	int len = 255;
	unsigned int line = 1;
	char buf[256];
	stack_t *head = NULL;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	name_of_file = fopen(argv[1], "r");
	if (name_of_file == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buf, len, name_of_file) != NULL)
	{
		buf[256] = '\0';
		if (match_function(buf, line, &head) == -1)
		{
			fclose(name_of_file);
			/* hacer un free del sack &head */
			return (1);
		}
		line++;
	}
	fclose(name_of_file);
	/* hacer un free del sack */
	free_stack(head);
	return (0);
}
/**
 *
 *
 *
 */
void push(stack_t **head, unsigned int line)
{
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
	if ((*head) != NULL)
	{
		(*head)->prev = n_node;
		n_node->next = (*head);
	}
	(*head) = n_node;
}
void pall(stack_t **head, unsigned int line)
{
	(void)line;

	while (*head)
	{
		printf("%d\n", (*head)->n);
		(*head) = (*head)->next;
	}
}
/*

void pint(stack_t **head, unsigned int line)
{
	if(*head)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line);
	}
	printf("%d\n", (*head)->n);
}
void pop(stack_t **head, unsigned int line)
{
	stack_t *node;

	if (*head)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line);
	}
	node = (*head);
	(*head) = (*head)->next;
	free(node);
}
void swap(stack_t **head, unsigned int line)
{
	unsigned int num_aux = 0;
	stack_t *aux;

	if(*head && (*head)->next)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line);
	}
	aux = (*head)->next;
	num_aux = aux->n;
	aux->n = (*head)->n;
	(*head)->n = num_aux;
}
*/
