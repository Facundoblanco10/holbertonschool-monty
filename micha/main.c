#include "monty.h"

/**
 *
 *
 *
 */
int main (int argc, char * argv[])
{
	FILE *name_of_file;
	int len = 255;
	int value = 0;
	int line = 1;
	char buf[256];
	char *token1;
	char *token2;
	char *buf_dup;
	stack_t **head = NULL;
	(void)argc;

	if (!argv[1])
	{
		printf("USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	name_of_file = fopen(argv[1], "r");

	if (name_of_file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buf, len, name_of_file) != NULL)
	{
		buf[256] = '\0';
		match_function(buf, line);
		line++;
	}
	fclose(name_of_file);

	return (0);
}

void match_function(char *buf, int line)
{
	char buf_dup = strdup(buf);
	char *token1 = strtok(buf_dup, " \t");
	instruction_t functions[] = {
		{"push", push()}
		{"pall", pall()}
		{"\0", NULL}
	};

	while (functions[i] != NULL)
	{
		if(strcmp(functions[i].opcode, token1) == 0)
		{
			functions[i].f(head, buf);
			return;
		}
	}
	printf("L%d: unknown instruction %s", line, token1);

}
void push(stack_t **head, char *buf)
{
	char buf_dup = strdup(buf);
	char *token1 = strtok(buf_dup, " \t");
	char *token2 = strtok(NULL, " \t");
	int value = atoi(token2);
	stack_t *n_node = malloc(sizeof(stack_t));

	if (!n_node)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	n_node->n = value;
	n_node->next = NULL;
	n_node->prev = NULL;
	if (*head = NULL)
	{
		*head = n_node;
		return;
	}
	(*head)->prev = n_node;
	n_node->next =  (*head);

}
