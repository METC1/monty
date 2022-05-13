#include "monty.h"

/**
 * checknumber - Check if the string is a number
 * @n: String number
 * @linu: line number
 * Return: nothing
 */

void checknumber(char *n, unsigned int linu)
{
int i;

for (i = 0; n[i] != '\0'; i++)
	{
	if (i == 0 && n[i] == '-')
		{
		continue;
		}
	else if (!((n[i] >= '0' && n[i] <= '9') || (n[i] == '-')))
		{
		fprintf(stderr, "L%u: usage: push integer\n", linu);
		exit(EXIT_FAILURE);
		}
	}
num = atoi(n);
}

/**
* deletenl - Delete the newline
* @buffer: buffer where dataline is stored
* Return: nothing
*/

void deletenl(char **buffer)
{
int i;

for (i = 0; (*buffer)[i] != '\0'; i++)
	{
	}
(*buffer)[i - 1] = '\0';

}
