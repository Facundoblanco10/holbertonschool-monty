#include "monty.h"

/**
 *
 *
 *
 */
int main (int argc, char * argv[])
{
	char *buf = NULL;
	size_t len = 0;
	FILE *namef;
	(void)argc;

	if (!argv[1])
	{
		printf("USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	if(access(argv[1], F_OK) == 0)
	{
		printf("Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	namef = fopen(argv[1], "r");

	if (!namef)
		printf("ERROR");

	getline(&buf, &len, namef);

	printf("\nthis is the getline: %s\n", buf);

	return (0);
}
