#include "monty.h"
/**
 *
 *
 *
 */
int main (int argc, char * argv[])
{
	FILE *name_of_file;
	char buf[256];
	int len = 255;
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
		printf("This is the line readed: %s", buf);


	fclose(name_of_file);

	return (0);
}
