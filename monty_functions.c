#include "monty.h"

/**
 * free_stack - function to free stack
 * @stack: head pointer
*/
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}


/**
 * isDigit - checks if is a digit
 * @arg: argument
 *
 * Return: 1 when string is digit
*/
int isDigit(char *arg)
{
	char *temp = arg;

	if (arg == NULL)
		return (0);
	if (*temp == '-')
		temp++;

	for (; *temp != '\0'; temp++)
	{
		if (*temp < '0' || *temp > '9')
		{
			return (0);
		}
	}
	return (1);
}
