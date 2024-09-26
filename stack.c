#include "monty.h"

/**
 * is_number - Checks if a string contains only digits
 * @str: The string to be checked
 *
 * Return: 1 if the string is a valid number, 0 otherwise
 */
int is_number(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	/* Check if each character is a digit */
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
/**
 * push - Pushes an element to the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the file
 * @arg: command line argument
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_node;
	int n;

	/* Convert the argument to an integer and validate */
	if (arg == NULL || !is_number(arg) || arg[1] == "")
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		malloc_error();

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - Prints all values on the stack, starting from the top
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	(void)line_number;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * free_stack - Frees the stack
 * @stack: Pointer to the head of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
