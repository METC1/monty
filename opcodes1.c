#include "monty.h"

int num;

/**
  * pushS - push a number in a stack
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */

void pushS(stack_t **st_stack, unsigned int linu)
{
	stack_t *new = malloc(sizeof(stack_t));
	(void) linu;

	if (new == NULL)
		return;
	new->n = num;
	new->prev = NULL;
	new->next = NULL;
	if (*st_stack != NULL)
	{
		new->next = *st_stack;
		(*st_stack)->prev = new;
	}
	*st_stack = new;
}
/**
  * printS - print the stack
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */
void printS(stack_t **st_stack, unsigned int linu)
{
	stack_t *save = *st_stack;

	(void) linu;
	if (*st_stack == NULL)
		return;
	while (save != NULL)
	{
		printf("%d\n", save->n);
		save = save->next;
	}
}
/**
  * pintS - print the top of the stack
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */
void pintS(stack_t **st_stack, unsigned int linu)
{
	if (*st_stack != NULL)
		printf("%d\n", (*st_stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", linu);
		exit(EXIT_FAILURE);
	}
}

/**
  * popS - delete the top of the stack
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */
void popS(stack_t **st_stack, unsigned int linu)
{
	stack_t *save;

	if (*st_stack != NULL)
	{
		save = (*st_stack)->next;
		free(*st_stack);
		*st_stack = save;
		if (*st_stack != NULL)
			(*st_stack)->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", linu);
		exit(EXIT_FAILURE);
	}
}

/**
  * swapS - delete the top of the stack
  * @st_stack: The stack
  * @linu: line of code
  * Return: nothing
  */
void swapS(stack_t **st_stack, unsigned int linu)
{
	stack_t *save;
	int i;

	if (*st_stack != NULL && (*st_stack)->next != NULL)
	{
		save = (*st_stack)->next;
		i = (*st_stack)->n;

		(*st_stack)->n = save->n;
		save->n = i;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", linu);
		exit(EXIT_FAILURE);
	}
}
