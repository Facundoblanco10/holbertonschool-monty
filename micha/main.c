#include "monty.h"
/**
 *
 *
 *
 */
int main (int argc, char * argv[])
{
	FILE *name_of_file;
	char buf[256], *token1, *token2;
	int len = 255, val = 0, c;
	(void)argc;

	if (!argv[1])
	{
		printf("USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	name_of_file = fopen(argv[1], "r");

	if (name_of_file == NULL)
	{
		printf("Error to open the file");
		exit(EXIT_FAILURE);
	}

	while (fgets(buf, len, name_of_file) != NULL)
	{
		strtok(buf, "\n");
		token1 = strtok(buf, " \t");
		token2 = strtok(NULL, " \t");
		if (token2 != '0')
		{
			val = atoi(token2);
			if (val == 0)
			{
				printf("L%d: usage: push integer", c)
				exit(EXIT_FAILURE)
			}
		}
		if (!token)
			break;

	printf("%s %d\n", token1, val);
		printf("This is the line readed: %s", token1);
	}

	fclose(name_of_file);

	return (0);
}
