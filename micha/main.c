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

	fgets(buf, len, name_of_file);


	fclose(name_of_file);

	printf("This is the line readed: %s", buf);
	return (0);
}
