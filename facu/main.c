#include "monty.h"
#include <stdio.h>

/**
 *
 *
 *
 */
int main (int argc, char * argv[])
{
	int input;
	char buf[1024];
	size_t len = 0;
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
	if (!namef)
	{
		printf("ERROR");
		exit(EXIT_FAILURE);
	}
	
	input = open(argv[1], O_RDONLY);
	char_save = read(input,buf,1024);
	return (0);
}
