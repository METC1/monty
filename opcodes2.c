#include "monty.h"

/**
  * addS - add the two top number of a stack
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */

void addS(stack_t **st_stack, unsigned int linu)
{
	stack_t *save;
	int i;

	if (*st_stack != NULL && (*st_stack)->next != NULL)
	{
		i = ((*st_stack)->n) + ((*st_stack)->next->n);
		save = (*st_stack)->next;
		free(*st_stack);
		save->n = i;
		save->prev = NULL;
		*st_stack = save;
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", linu);
		exit(EXIT_FAILURE);
	}
}

/**
  * nopS - do nothing
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */

void nopS(stack_t **st_stack, unsigned int linu)
{
	(void) st_stack;
	(void) linu;
}

/**
  * subS - sub the two top numbers of a stack
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */

void subS(stack_t **st_stack, unsigned int linu)
{
	stack_t *save;
	int i;

	if (*st_stack != NULL && (*st_stack)->next != NULL)
	{
		i = ((*st_stack)->next->n) - ((*st_stack)->n);
		save = (*st_stack)->next;
		free(*st_stack);
		save->n = i;
		save->prev = NULL;
		*st_stack = save;
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", linu);
		exit(EXIT_FAILURE);
	}
}

/**
  * divS - sub the two top numbers of a stack
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */

void divS(stack_t **st_stack, unsigned int linu)
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

		i = ((*st_stack)->next->n) / ((*st_stack)->n);
		save = (*st_stack)->next;
		free(*st_stack);
		save->n = i;
		save->prev = NULL;
		*st_stack = save;
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", linu);
		exit(EXIT_FAILURE);
	}
}

/**
  * mulS - sub the two top numbers of a stack
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */

void mulS(stack_t **st_stack, unsigned int linu)
{
	stack_t *save;
	int i;

	if (*st_stack != NULL && (*st_stack)->next != NULL)
	{
		i = ((*st_stack)->next->n) * ((*st_stack)->n);
		save = (*st_stack)->next;
		free(*st_stack);
		save->n = i;
		save->prev = NULL;
		*st_stack = save;
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", linu);
		exit(EXIT_FAILURE);
	}
}
