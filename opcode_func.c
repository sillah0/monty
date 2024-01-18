#include "monty.h"

/**
 * pint_function - print top element in stack
 * @stack: a pointer to a pointer of stack_t type
 * @line_number: line number
*/
void pint_function(stack_t **stack, unsigned int line_number)
{

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		/**free_stack(*stack);*/
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *current = *stack;

		while (current)
		{
			printf("%d", current->n);
			if (current->next)
				printf(" ");
			current = current->next;
		}
		printf("\n");
	
	}
}
