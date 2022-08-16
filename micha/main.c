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
	int value;
	int line = 1;
	char buf[256];
	char *token1;
	char *token2;
	char *buf;
	char *buf_dup;
	(void)argc;

	instruction_t functions[] = {
		{"push", push()}
		{"pall", pall()}
		{"\0", NULL}
	};

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
		token1 = strtok(buf_dup, " \t");
		token2 = strtok(NULL, " \t");
		value = atoi(token2);

		while (functions[i] != NULL)
		{
			if(strcmp(functions[i][0], token1) == 0)
			{
				/* ejecutar la funcion correspondiente */
			}
		}
		printf("L%d: unknown instruction %s", line, token1);
		line++;
	}
	fclose(name_of_file);

	return (0);
}
