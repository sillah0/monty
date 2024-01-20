#include "monty.h"

/**
 * pint_function - function to print the value at the top of a stack
 * @stack:  pointer to a pointer to a stack_t structure
 * @line_number: unsigned int reperesenting the line number where
 * pint operation is being performed
*/

void pint_function(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}
