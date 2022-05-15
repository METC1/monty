#include "monty.h"

/**
 * tokens_line - Extract tokens from line
 * @buffer: buffer where line of text is stored
 * @r_line: number of characters read on line
 * @tokens: tokens to use
 * Return: not yet determined
 */

void tokens_line(char **buffer, char ***tokens, ssize_t r_line)
{
	int i;

	if (r_line > 0)
		{
		for (i = 0; (*buffer)[i] == ' ' || (*buffer)[i] == '\t'; i++)
			{
			if ((*buffer)[i + 1] == '\n')
				return;

			}

		}
	if (**buffer != '\n')
		{
		deletenl(buffer);
		tokens_extract(buffer, tokens);
		}

}
/**
 * tokens_extract - Extract tokens from line
 * @buffer: buffer where line of text is stored
 * @tokens: tokens to use
 * Return: not yet determined
 */
void tokens_extract(char **buffer, char ***tokens)
{
char *token = NULL;
char *delim = " \n\t";
int number;
int i;

token = strtok(*buffer, delim);
if (strcmp(token, "push") == 0)
	{
	number = 3;
	}
else
	{
	number = 2;
	}
*tokens = malloc(sizeof(char *) * number);
for (i = 0; token != NULL && i <= number - 2; i++)
	{
	(*tokens)[i] = token;
	token = strtok(NULL, delim);

	}
(*tokens)[i] = NULL;
}
/**
 * freetokens - Frees the tokens
 * @tokens: tokens to be freed
 * Return: nothing
 */
void freetokens(char ***tokens)
{
if (*tokens != NULL)
	{
	free(*tokens);
	*tokens = NULL;
	}

}

/**
 * freest_stack - frees the stack
 * @st_stack: stack to be freed
 * Return: nothing
 */
void freest_stack(stack_t *st_stack)
{
stack_t *savepoin;

if (st_stack != NULL)
	{
	while (st_stack != NULL)
		{
		savepoin = st_stack->next;
		free(st_stack);
		st_stack = savepoin;
		}
	}
}
