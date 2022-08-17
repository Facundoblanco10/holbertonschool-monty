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
	int len = 255, c = 0;

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
		c++;
		get_op(buf, c);
	}

	fclose(name_of_file);

	return (0);
}
void get_op(char *buf, int c)
{
	char *token1 = strtok(buf, " \t");
	int val = 0;
	stack_t *head;

	head = NULL;
	if (!token1)
		return;
	if (strcmp(token1, "push") == 0)
	{
		val = push(buf, c);
		if (val != 0)
		{
			create_node(&head, val);
		}
	}
	printf("%s\n%d\n", token1, val);
	printf("This is the line readed: %s\n", buf);
}
int push(char *buf, int c)
{
	char *token2 = strtok(buf, " \t");
	int val = 0;

	token2 = strtok(NULL, " \t");
	if (token2[0] != '0')
	{
		val = atoi(token2);
		if (val == 0)
		{
			printf("L%d: usage: push integer", c);
			exit(EXIT_FAILURE);
		}
		return(val);
	}
	return (0);
}
stack_t *create_node(stack_t **head, int val)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));
	if (!newnode)
		return (NULL);
	newnode->n = val;
	if (!(*head))
	{
		newnode->next = *head;
		newnode->prev = NULL;
		*head = newnode;
	}
	else
	{
		newnode->next = *head;
		newnode->prev = NULL;
		(*head)->prev = newnode;
	}
	*head = newnode;
	return (newnode);
}
