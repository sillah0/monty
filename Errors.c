#include "monty.h"

/**
 * pushError - handles errors related to push operation
 * @fd: file of type FILE
 * @buffer: buffer
 * @line_number: line number to track
 * @stack: a pointer to stack of stack_t type
*/
void pushError(FILE *fd, char *buffer, unsigned int line_number,
		stack_t *stack)
{
	fprintf(stderr, "L%u: Usage: push integer\n", line_number);
	fclose(fd);
	free(buffer);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * not_ins - function is an error-handling routine for the case
 * when an unrecognized command is encountred
 * @fd: file to go through
 * @buffer: buffer
 * @line_number: line number to track
 * @stack: a pointer to stack of stack_t type
 * @cmd: command
*/
void not_ins(FILE *fd, char *buffer, unsigned int line_number,
		stack_t *stack, char *cmd)
{
	fprintf(stderr, "L%u: Unkown instruction %s\n", line_number, cmd);
	free(buffer);
	free_stack(stack);
	fclose(fd);
	exit(EXIT_FAILURE);
}
