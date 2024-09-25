#include "monty.h"

/**
 * usage_error - Prints usage error message and exits
 */
void usage_error(void)
{
    fprintf(stderr, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
}

/**
 * file_error - Prints file error message and exits
 * @filename: Name of the file that couldn't be opened
 */
void file_error(char *filename)
{
    fprintf(stderr, "Error: Can't open file %s\n", filename);
    exit(EXIT_FAILURE);
}

/**
 * malloc_error - Prints malloc error message and exits
 */
void malloc_error(void)
{
    fprintf(stderr, "Error: malloc failed\n");
    exit(EXIT_FAILURE);
}

/**
 * unknown_instruction_error - Prints unknown instruction error and exits
 * @opcode: Opcode that is unknown
 * @line_number: Line number where the error occurred
 */
void unknown_instruction_error(char *opcode, unsigned int line_number)
{
    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}
