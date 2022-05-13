#include "monty.h"

/**
* opcode_choose - Choose the appropiate op_code
* @st_stack: stack where data will be saved
* @tokens: the token of the line read before
* @linu: line number
* Return: nothing
*/

void opcode_choose(stack_t **st_stack, char ***tokens, unsigned int linu)
{
void (*op_code)(stack_t **st_stack, unsigned int linu);
int i;

if (strcmp((*tokens)[0], "push") == 0)
	{
	for (i = 0; (*tokens)[i] != NULL; i++)
		{
		if (i == 1)
			{
			checknumber((*tokens)[i], linu);
			}

		}
		if (i == 1 && (*tokens)[i] == NULL)
			{
			fprintf(stderr, "L%u: usage: push integer\n", linu);
			exit(EXIT_FAILURE);
			}
	}
	op_code = choose_opcode((*tokens)[0]);
	if (op_code != NULL)
		{
		op_code(st_stack, linu);
		}
	else
		{
		fprintf(stderr, "L%u: unknown instruction %s\n", linu, (*tokens)[0]);
		exit(EXIT_FAILURE);
		}

}

/**
* choose_opcode - Choose the right opcode
* @code: the string number
* Return: nothing
*/

void (*choose_opcode(char *code))(stack_t **stack, unsigned int line_number)
{
int i;
instruction_t opcodes[] = {
	{"push", pushS},
	{"pall", printS},
	{"pint", pintS},
	{"pop", popS},
	{"swap", swapS},
	{"add", addS},
	{"nop", nopS},
	{"sub", subS},
	{"div", divS},
	{"mul", mulS},
	{"mod", modS},
	{"pchar", pcharS},
	{NULL, NULL}};

if (code[0] == '#')
	{
	return (comS);
	}
for (i = 0; opcodes[i].opcode != NULL; i++)
	{
	if (strcmp(code, opcodes[i].opcode) == 0)
		{
		return (opcodes[i].f);
		}
	}
return (opcodes[i].f);
}
