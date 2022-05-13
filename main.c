#include "monty.h"
/**
 * main - Monty interpreter main Startpoint
 * @ac: argument count
 * @av: argument vector
 * Return: 0 if success, or any other value if not successfull
 */

int main(int ac, char **av)
{
char *file = av[1];
char *buffer = NULL;
char **tokens = NULL;
size_t len = 0;
size_t li_numb = 1;
int read_line;
stack_t *st_stack;
FILE *fd;

if (ac != 2)
	{
	printf("USAGE: monty file/n");
	exit(EXIT_FAILURE);
	}
else
	{
	fd = fopen(file, "r");
	if (fd == NULL)
		{
		printf("Error: Can't open file");
		exit(EXIT_FAILURE);
		}
	for (li_numb = 1; (read_line) != -1; li_numb++)
		{
		read_line = getline(&buffer, &len, fd);
		tokens_line(&buffer, &tokens, li_numb);
		if (tokens != NULL)
			{
			opcode_choose(&st_stack, &tokens, li_numb);
			}
		freetokens(&tokens);
		}
	fclose(fd);
	if (buffer != NULL)
		{
		free(buffer);
		}
	freest_stack(st_stack);
	}
return (0);
}

