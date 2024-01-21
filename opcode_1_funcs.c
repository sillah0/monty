#include "monty.h"

/**
 * add_function - adds 2 elemts of a stack
 * @stack: a pointer to a pointer
 * @line_number: line number
*/
void add_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: Can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}


/**
 * sub_function - diffrencebtwn 2 elements
 * @satck: a pointer
 * @line_number _ line number
*/
void sub_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temp->next->n -= temp->n;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
