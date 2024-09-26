#include "monty.h"

/**
 * execute_instruction - Parses and executes Monty bytecode instructions
 * @line: The line from the file
 * @stack: Pointer to the stack
 * @line_number: The current line number
 */
void execute_instruction(char *line, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	char *opcode;
	unsigned int i;
	i = 0;
	opcode = strtok(line, " \n");
	if (opcode == NULL || opcode[0] == '#')
		return;
	while (instructions[i].opcode)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}
	unknown_instruction_error(opcode, line_number);
}
