#include "monty.h"

/**
 *
 *
 *
 */
int main (int argc, char * argv[])
{
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
}
