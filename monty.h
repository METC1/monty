#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
extern int num;

/**
 * struct stack_s - doubly linked list representation of a stac (or queue)
 * @n: integer
 * @prev: points to the previuos element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure for stack, queues, LIFO FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void pushS(stack_t **st_stack, unsigned int linu);
void printS(stack_t **st_stack, unsigned int linu);
void pintS(stack_t **st_stack, unsigned int linu);
void popS(stack_t **st_stack, unsigned int linu);
void swapS(stack_t **st_stack, unsigned int linu);
void addS(stack_t **st_stack, unsigned int linu);
void nopS(stack_t **st_stack, unsigned int linu);
void subS(stack_t **st_stack, unsigned int linu);
void divS(stack_t **st_stack, unsigned int linu);
void mulS(stack_t **st_stack, unsigned int linu);
void modS(stack_t **st_stack, unsigned int linu);
void comS(stack_t **st_stack, unsigned int linu);
void pcharS(stack_t **st_stack, unsigned int linu);

void tokens_line(char **buffer, char ***tokens, ssize_t r_line);
void opcode_choose(stack_t **st_stack, char ***tokens, unsigned int linu);
void freetokens(char ***tokens);
void freest_stack(stack_t *st_stack);
void deletenl(char **buffer);
void tokens_extract(char **buffer, char ***tokens);
void checknumber(char *n, unsigned int line_number);
void (*choose_opcode(char *code))(stack_t **st_stack, unsigned int linu);

#endif
