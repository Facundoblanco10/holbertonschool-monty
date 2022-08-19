#include "monty.h"
int value = 0;
/**
 * setvalue - check if token2 is a number
 * @token2: is the argument of the push instruction
 * Return: void
 */
void setvalue(char *token2)
{
	size_t j = 0;

	for (j = 0; j < strlen(token2); j++)
	{
		if (!(isdigit(token2[j])))
			value = 0;
		else if (j == strlen(token2) - 1)
			value = atoi(token2);
	}
}
/**
 * ckecktoken2 - check if token2 is valid input
 * @token2: the argument passed to push function
 * @line: the actual line
 * Return: return -1 if token2 is invalid
 */
int ckecktoken2(char *token2, int line)
{
	if (!token2)
	{
		dprintf(2, "L%d: usage: push integer\n", line);
		return (-1);
	}
	else
	{
		setvalue(token2);
		if (!value && strcmp(token2, "0") && strcmp(token2, "-0"))
		{
			dprintf(2, "L%d: usage: push integer\n", line);
			return (-1);
		}
	}
	return (0);
}
/**
 * match_function - find and execute the right function
 * @buf: the instruction to execute
 * @line: the number of line
 * @head: a pointer to the first node of the stack_t
 * Return: -1 if fails, and 0 in success
 */
int match_function(char *buf, int line, stack_t **head)
{
	int i = 0;
	char *buf_dup = strdup(buf);
	char *token1 = strtok(buf_dup, " \t\n"), *token2 = NULL;
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
		if (strcmp(functions[i].opcode, token1) == 0)
		{
			if (strcmp(token1, "push") == 0)
			{
				token2 = strtok(NULL, " \t\n");
				if (ckecktoken2(token2, line) == -1)
				{
					free(buf_dup);
					return (-1);
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
 * main - the main function
 * @argc: the leng of argv
 * @argv: the arguments passed to main
 * Return: always 0
 */
int main(int argc, char *argv[])
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
