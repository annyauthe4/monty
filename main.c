#include "monty.h"

/**
 * main - Entry point for Monty interpreter
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, EXIT_FAILURE on error
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
		usage_error();
	file = fopen(argv[1], "r");
	if (file == NULL)
		file_error(argv[1]);

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		execute_instruction(line, &stack, line_number)
	}

	free(line);
	fclose(file);
	free_stack(stack);

	return (0);
}
