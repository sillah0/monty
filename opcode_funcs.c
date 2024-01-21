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

/**
 * pop_function - function that removes the top element from stack
 * @stack: pointer to a pointer to the stack
 * @line_number:represents line number where function is called
*/
void pop_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
		*stack = temp->next;
		if (temp->next)
			(*stack)->prev = NULL;
		else
			*stack = NULL;
		free(temp);
	}
}

/**
 * swap_function - function to swap two top elements
 * @stack: a pointer to a pointer
 * @line_number: line number to track
*/
void swap_function(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int i;

	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	i = temp->n;
	temp->n = temp->next->n;
	temp->next->n = i;
}
