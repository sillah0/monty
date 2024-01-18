#include "monty.h"

/**
 * main - program entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: zeo (0)
*/
int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		file_handler(argv[1]);
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
