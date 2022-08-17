#include "monty.h"
int value = 0;
/**
 *
 *
 *
 *
 */
void match_function(char *buf, int line, stack_t **head)
{
	int i = 0;
	char *buf_dup = strdup(buf);
	char *token1 = strtok(buf_dup, " \t\n");
	char *token2 = NULL;
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"\0", NULL}
	};

	while (functions[i].opcode[0] != '\0')
	{
		if(strcmp(functions[i].opcode, token1) == 0)
		{
			if (strcmp(token1, "push") == 0)
			{
				token2 = strtok(NULL, " \t\n");
				if (!token2)
				{
					dprintf(2, "L%d: usage: push integer\n", line);
					free(token2);
				}
				else
					value = atoi(token2);
			}
			free(token1);
			functions[i].f(head, line);
			return;
		}
		i++;
	}
	dprintf(2, "L%d: unknown instruction %s\n", line, token1);
	return;
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
	(void)argc;

	if (!argv[1])
	{
		dprintf(2, "USAGE: monty file");
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
		match_function(buf, line, &head);
		line++;
	}
	fclose(name_of_file);

	return (0);
}
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
void pall(stack_t **head, unsigned int line)
{
	int c = 0;

	(void) line;
	while (*head)
	{
		printf("%d\n", (*head)->n);
		c++;
		(*head) = (*head)->next;
	}
}
