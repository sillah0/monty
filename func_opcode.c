#include "monty.h"
int int_value;

/**
 * push_function - function to push elements to slack
 * @stack: a pointer to a pointer of stack_t type
 * @line_number: line number
*/
void push_function(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	(void)line_number;

	if (stack == NULL)
		return;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = int_value;
	new->next = NULL;
	new->prev = NULL;

	if (*stack == NULL)
	{
		*stack = new;
	}
	else
	{
		(*stack)->prev = new;
		new->next = *stack;
		*stack = new;
	}
	/**printf("\n");*/
}

/**
 * pall_function - prints all values on the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
*/

void pall_function(stack_t **stack, unsigned int line_number)
{
	stack_t  *current = *stack;

	(void)line_number;

	if (stack && *stack)
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
}
/**
 * file_handler - function to handle files
 * @file_path: file path
*/
void file_handler(char *file_path)
{
	unsigned int retval = 0, line_number = 0;
	stack_t *stack = NULL;
	size_t buffsize = 0;
	char *command = NULL, *arg = NULL;

	FILE *fd;
	char *buffer;

	buffer = NULL;
	fd = fopen(file_path, "r");
	if (fd)
	{
		while (getline(&buffer, &buffsize, fd) != -1)
		{
			line_number++;
			command = strtok(buffer, " \n\t\r");
			if (command == NULL)
			{
				free(command);
				continue;
			}
			else if (*command == '#')
				continue;
			arg = strtok(NULL, " \n\t\r");
			retval = executor(line_number, command, arg, &stack);
			if (retval == 1)
				pushError(fd, buffer, line_number, stack);
			if (retval == 2)
				not_ins(fd, buffer, line_number, stack, command);
		}
		free(buffer);
		free_stack(stack);
		fclose(fd);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}
}

/**
 * executor - calls opcode function
 * @line_number: line number of commands
 * @command: opcode
 * @arg: argument command
 * @stack: stack
 *
 * Return: 1 if can't push and 2 if not opcode
*/
int executor(int line_number, char *command, char *arg, stack_t **stack)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push_function},
		{"pall", pall_function},
		{"pint", pint_function},
		{"pop", pop_function},
		{"swap", swap_function},
		{NULL, NULL}
	};

	while (ops[i].opcode)
	{
		if (!strcmp(ops[i].opcode, command))
		{
			if (!strcmp(ops[i].opcode, "push"))
			{
				if (isDigit(arg) == 1)
					int_value = atoi(arg);
				else
					return (1);
			}
			ops[i].f(stack, line_number);
			break;
		}
		i++;
	}
	if (!ops[i].opcode)
		return (2);
	return (0);
}
