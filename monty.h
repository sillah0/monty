#ifndef _MONTY_H_
#define _MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <stddef.h>



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int int_value;
extern FILE *fd;
extern char *buffer;



void push_function(stack_t **stack, unsigned int line_number);
void pall_function(stack_t **stack, unsigned int line_number);
void file_handler(char *file_path);
int executor(int line_number, char *command, char *arg, stack_t **stack);
void pushError(FILE *fd, char *buffer, unsigned int line_number, stack_t *stack);
void not_ins(FILE *fd, char *buffer, unsigned int line_number, stack_t *stack, char *cmd);
int isDigit(char *arg);
void free_stack(stack_t *stack);
void pint_function(stack_t **stack, unsigned int line_number);
void pop_function(stack_t **stack, unsigned int line_number);


#endif