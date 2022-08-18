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
	size_t j = 0;
	int i = 0;
	char *buf_dup = strdup(buf);
	char *token1 = strtok(buf_dup, " \t\n");
	char *token2 = NULL;
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{"add", add},
		{"\0", NULL}
	};

	if (!token1)
	{
		free(buf_dup);
		return (0);
	}
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
					free(buf_dup);
					return (-1);
				}
				else
				{
					for (j = 0; j < strlen(token2); j++)
					{
						if (!isdigit(token2[j]))
							value = 0;
						else if (j == strlen(token2) - 1)
							value = atoi(token2);
					}
					if (!value && strcmp(token2, "0") && strcmp(token2, "-0"))
					{
						dprintf(2, "L%d: usage: push integer\n", line);
						free(buf_dup);
						return (-1);
					}
				}
			}
			functions[i].f(head, line);
			free(buf_dup);
			return (0);
		}
		i++;
	}
	dprintf(2, "L%d: unknown instruction %s\n", line, token1);
	return (-1);
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
			free_stack(head);
			exit(EXIT_FAILURE);
        }
		line++;
	}
	fclose(name_of_file);
	free_stack(head);

	return (0);
}
