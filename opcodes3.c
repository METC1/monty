#include "monty.h"

/**
  * modS - sub the two top numbers of a stack
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */

void modS(stack_t **st_stack, unsigned int linu)
{
	stack_t *save;
	int i;

	if (*st_stack != NULL && (*st_stack)->next != NULL)
	{
		if ((*st_stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", linu);
			exit(EXIT_FAILURE);
		}

		i = ((*st_stack)->next->n) % ((*st_stack)->n);
		save = (*st_stack)->next;
		free(*st_stack);
		save->n = i;
		save->prev = NULL;
		*st_stack = save;
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", linu);
		exit(EXIT_FAILURE);
	}
}

/**
  * comS - do nothing
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */

void comS(stack_t **st_stack, unsigned int linu)
{
	(void) st_stack;
	(void) linu;
}

/**
  * pcharS - print the stack
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */
void pcharS(stack_t **st_stack, unsigned int linu)
{
	if (*st_stack != NULL)
	{
		if ((*st_stack)->n >= 0 && (*st_stack)->n <= 127)
			printf("%c\n", (*st_stack)->n);
		else
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", linu);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", linu);
		exit(EXIT_FAILURE);
	}
}
